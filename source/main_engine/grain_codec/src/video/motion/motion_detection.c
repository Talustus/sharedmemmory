
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <pthread.h>
#include <signal.h>
#include "gmlib.h"
#include "motion_detection.h"
#include "parsing_mv_data.c"
#include "log.h"
#include "sdk_struct.h"

extern EventCallback	mEventCallback ;  //�¼��ص�

int ircut_flag =0;
//0 ���л��ɱ���  1 ���л� ���ɱ���
int ircut_flag_set(int flag)
{
	ircut_flag=flag;
}

int oldtime = 0;
int md_ir_flag = 0;
int md_mode=0;
int md_old_mode=0;
int md_check_num=0;




int bindfd_to_mdt_idx(void *bindfd);
pthread_mutex_t  mapping_mutex;
static int cap_motion_init_ok[MAX_CAP_MD_NUM] = {0};
static int user_motion_size[MAX_CAP_MD_NUM] = {0};
struct mdt_user_t mdt_param[MAX_CAP_MD_NUM];
struct mdt_res_t active[MAX_CAP_MD_NUM];

#if(M_DEBUG == 1)
static int display_region_info_internal(void *bindfd)

{
    int r_idx;
    int mdt_idx;
    int ret = 0;

    mdt_idx = bindfd_to_mdt_idx(bindfd);
    if (mdt_idx == -1)
    {
        printf("The array depth of mdt_param was not enough for bindfd(0x%p)\n", bindfd);
        ret = -1;
        goto err_ext;
    }
    for (r_idx = 0; r_idx < MAX_SUBREGION_NUM; r_idx++)
    {
        if (mdt_param[mdt_idx].mdt_alg.sub_region[r_idx].is_enabled == 1)
        {
            if (mdt_param[mdt_idx].mdt_alg.sub_region[r_idx].start_block_x != -1)
            {
                printf("[region %d] sx=%d ex=%d sy=%d ey=%d th=%d\n", r_idx,
                       mdt_param[mdt_idx].mdt_alg.sub_region[r_idx].start_block_x,
                       mdt_param[mdt_idx].mdt_alg.sub_region[r_idx].end_block_x,
                       mdt_param[mdt_idx].mdt_alg.sub_region[r_idx].start_block_y,
                       mdt_param[mdt_idx].mdt_alg.sub_region[r_idx].end_block_y,
                       mdt_param[mdt_idx].mdt_alg.sub_region[r_idx].alarm_th);
            }
        }
    }

err_ext:

    return ret;
}
#endif

static int close_sub_region_internal(void *bindfd, int reg_idx)
{
    int ret = 0;
    int mdt_idx;
    int r_idx;

    mdt_idx = bindfd_to_mdt_idx(bindfd);
    if (mdt_idx == -1)
    {
        printf("The array depth of mdt_param was not enough for bindfd(0x%p)\n", bindfd);
        ret = -1;
        goto err_ext;
    }

    if (reg_idx >= MAX_SUBREGION_NUM)
    {
        printf("region idx is bigger than definition (MAX:%d), bindfd(0x%p)\n", MAX_SUBREGION_NUM,
               bindfd);
        ret = -1;
        goto err_ext;
    }

    r_idx = reg_idx; //1-1 mapping
    mdt_param[mdt_idx].mdt_alg.sub_region[r_idx].is_enabled = 0;
    mdt_param[mdt_idx].mdt_alg.sub_region[r_idx].start_block_x = -1;
    mdt_param[mdt_idx].mdt_alg.sub_region[r_idx].start_block_y = -1;
    mdt_param[mdt_idx].mdt_alg.sub_region[r_idx].end_block_x   = -1;
    mdt_param[mdt_idx].mdt_alg.sub_region[r_idx].end_block_y   = -1;
    mdt_param[mdt_idx].mdt_alg.sub_region[r_idx].alarm_th      = 100;
    mdt_param[mdt_idx].mdt_alg.sub_region[r_idx].alarm = -5;

err_ext:

    return ret;
}

static int set_sub_region_internal(void *bindfd, int reg_idx, struct mdt_reg_t *sub_region)
{
    int blk_w_num;
    int blk_h_num;
    int s_block_x;
    int s_block_y;
    int e_block_x;
    int e_block_y;
    int r_idx;
    int ret = 0;
    int mdt_idx;

    mdt_idx = bindfd_to_mdt_idx(bindfd);
    if (mdt_idx == -1)
    {
        printf("The array depth of mdt_param was not enough for bindfd(0x%p)\n", bindfd);
        ret = -1;
        goto err_ext;
    }

    if (reg_idx >= MAX_SUBREGION_NUM)
    {
        printf("region idx is bigger than definition (MAX:%d), bindfd(0x%p)\n", MAX_SUBREGION_NUM,
               bindfd);
        ret = -1;
        goto err_ext;
    }

    r_idx = reg_idx; //1-1 mapping
    blk_w_num = mdt_param[mdt_idx].mdt_alg.mb_w_num;
    blk_h_num = mdt_param[mdt_idx].mdt_alg.mb_h_num;

    s_block_x = sub_region->start_block_x;
    s_block_y = sub_region->start_block_y;
    e_block_x = sub_region->end_block_x;
    e_block_y = sub_region->end_block_y;
	//warning("s_block_x[%d]  s_block_y[%d]  e_block_x[%d]   e_block_y[%d]\n",s_block_x,s_block_y,e_block_x,e_block_y);
    if ((s_block_x < 0) || (s_block_y < 0) || (e_block_x < 0) || (e_block_y < 0))
    {
        printf("sub region start/end block index must >= 0, at bindfd(0x%p)\n", bindfd);
        ret = -1;
        goto err_ext;
    }

    if ((s_block_x > blk_w_num) || (e_block_x > blk_w_num) ||
            (s_block_y > blk_h_num) || (e_block_y > blk_h_num))
    {
        printf("sub region start/end block index must < max block index, at bindfd(0x%p) blk_w_num [%d] blk_h_num[%d]\n",
               bindfd,blk_w_num,blk_h_num);
        ret = -1;
        goto err_ext;
    }

    mdt_param[mdt_idx].mdt_alg.sub_region[r_idx].start_block_x = sub_region->start_block_x;
    mdt_param[mdt_idx].mdt_alg.sub_region[r_idx].start_block_y = sub_region->start_block_y;
    mdt_param[mdt_idx].mdt_alg.sub_region[r_idx].end_block_x   = sub_region->end_block_x;
    mdt_param[mdt_idx].mdt_alg.sub_region[r_idx].end_block_y   = sub_region->end_block_y;
    mdt_param[mdt_idx].mdt_alg.sub_region[r_idx].alarm_th      = sub_region->alarm_th;
    mdt_param[mdt_idx].mdt_alg.sub_region[r_idx].alarm = -5;

err_ext:

    return ret;
}
//�ƶ�������ݷ��� ȷ���ƶ�����Ƿ���
int capture_sub_region_alg(struct mdt_user_t *mdt_param, struct mdt_res_t *active)
{
    int r_idx, x, y;
    int blk_w_num = (mdt_param->mdt_alg.u_width + (mdt_param->mdt_alg.u_mb_width - 1)) /
                    mdt_param->mdt_alg.u_mb_width;
//#if M_DEBUG
    int blk_h_num = (mdt_param->mdt_alg.u_height + (mdt_param->mdt_alg.u_mb_height - 1)) /
                    mdt_param->mdt_alg.u_mb_height;
//#endif
	//warning("blk_w_num is  %d   blk_h_num  is  %d \n",blk_w_num,blk_h_num);

    if (mdt_param->mdt_alg.frame_count < mdt_param->mdt_alg.training_time)
    {
    	//printf("zw00000000000000000000000000000000000000000000000000000\n");
        for (r_idx = 0; r_idx < MAX_SUBREGION_NUM; r_idx++)//MAX_SUBREGION_NUM
            if (mdt_param->mdt_alg.sub_region[r_idx].start_block_x != -1)
                mdt_param->mdt_alg.sub_region[r_idx].alarm = MOTION_IS_TRAINING;
        return 0;
    }

    for (r_idx = 0; r_idx < MAX_SUBREGION_NUM; r_idx++)//MAX_SUBREGION_NUM jyjyjy
    {	
		//warning("start_bx:[%d],start_by:[%d],end_bx:[%d],end_by:[%d],alarm_th:[%d]\n",
		//		mdt_param->mdt_alg.sub_region[r_idx].start_block_x,mdt_param->mdt_alg.sub_region[r_idx].start_block_y,mdt_param->mdt_alg.sub_region[r_idx].end_block_x,mdt_param->mdt_alg.sub_region[r_idx].end_block_y,mdt_param->mdt_alg.sub_region[r_idx].alarm_th);
        if (mdt_param->mdt_alg.sub_region[r_idx].start_block_x == -1)
        {
            //  this sub region not enable
        }
        else
        {
            int start_bx = mdt_param->mdt_alg.sub_region[r_idx].start_block_x;
            int start_by = mdt_param->mdt_alg.sub_region[r_idx].start_block_y;
            int end_bx   = mdt_param->mdt_alg.sub_region[r_idx].end_block_x;
            int end_by   = mdt_param->mdt_alg.sub_region[r_idx].end_block_y;
            int alarm_th = mdt_param->mdt_alg.sub_region[r_idx].alarm_th;
            int block_count = 0;
            int block_num = 0;
            int block_idx = 0;

            for (y = start_by; y <= end_by; y++)
            {
                for (x = start_bx; x <= end_bx; x++)
                {
                    block_idx = y * blk_w_num + x;
                    if (active->active_flag[block_idx] == 0)
                        block_count++;
                    block_num++;
                }
            }
			//warning("Montion Detected--->[%d]*100 ???? [%d]*(100-%d)   %d>%d\n",block_count,block_num ,alarm_th,block_count * 100, block_num * (100 - alarm_th));
            if (block_count * 100 > block_num * (100 - alarm_th))
            {
            	warning("Montion Detected--->[%d]*100 ???? [%d]*(100-%d)   %d>%d\n",block_count,block_num ,alarm_th,block_count * 100, block_num * (100 - alarm_th));
                mdt_param->mdt_alg.sub_region[r_idx].alarm = MOTION_DETECTED;
				

				sdk_event_t event;
				time_t seconds;
				seconds = time((time_t *)NULL);
				//seconds = seconds-(8*60*60);
				event.enevt_type = SDK_EVENT_MOTION;
				event.event_time = seconds;
				event.result = 1;
				
				if(mEventCallback != NULL)
				{
					//warning("%d   -   %d     =    %d\n",event.event_time,oldtime,event.event_time - oldtime);	
#if 0
				
					if((event.event_time - oldtime) > 15)//	 ʮ������
					{
						warning("Motion Event pull\n");	
						//usleep(200*1000);
						//if(0 == ircut_flag) 
							
						
						oldtime = event.event_time;
					}
#else
				if((event.event_time - oldtime) > 1)//	 ʮ������
				{
					oldtime = event.event_time;
					usleep(300*1000);
					if (get_light_sensor_value())
					{
						md_mode = 1;
					}
					else
					{
						md_mode = 0;
					}
					
					if(0 == md_mode)
					{
						if(md_old_mode != md_mode)
    					{
    						 md_ir_flag=1;
							 md_old_mode = 0;
							 ircut_flag=1;
    					}
    	
					}
					else if(1 == md_mode)
					{
						if(md_old_mode != md_mode)
    					{
    						 md_ir_flag=1;
    						 md_old_mode = 1;
							 ircut_flag=1;
    					}
					}
					 if(0== md_ir_flag)
					 {
					 	mEventCallback((void *)(&event));//��������
						warning("Motion Event pull\n");	
					 }
					 else
					 {
					 	while(1)
					 	{
					 		md_check_num++;
							//printf("++++++++++++++++ md_check_num  is %d\n",md_check_num);
							usleep(200*1000);
							if(15 == md_check_num)  
							{
								warning("ir_cut change  md invalid \n");
								md_ir_flag=0;
								ircut_flag=0;
								md_check_num=0;
								break;
							}
					 	}	
					 }
				} 
#endif				
				}
				else
				{
					warning("event pull is NULL\n");
				}


            }
            else
                mdt_param->mdt_alg.sub_region[r_idx].alarm = NO_MOTION;
        }
    }

#if M_DEBUG
    printf("blk_info\n");
    for (y = 0; y < blk_h_num; y++)
    {
        for (x = 0; x < blk_w_num; x++)
        {
            printf("%d",active->active_flag[y * blk_w_num + x]);
        }
        printf("\n");
    }
#endif

    return 0;
}

/*
 * @brief capture motion detection algorithm
 *
 * @fn int do_capture_motion(gm_cap_md_info_t *cap_motion, struct mdt_user_t *mdt_param,
                       struct mdt_res_t *active, int mdt_idx)
 * @param cap_motion motion data buffer the region you want to detect motion
 * @param mdt_param motion detection parameters
 * @param active result of motion detection
 * @param mdt_idx motion data channel num
 * @return 1 on motion detected, 0 on motion unreliable, 2 on motion undetected, <0 on motion error
*/
static int do_capture_motion(gm_cap_md_info_t *cap_motion, struct mdt_user_t *mdt_param,
                             struct mdt_res_t *active, int mdt_idx)
{
    int ret = MOTION_IS_READY;

    if (cap_motion_init_ok[mdt_idx] == 0)
    {
        printf("capture motion not initial\n");
        ret = MOTION_INIT_ERROR;
        goto err_ext;
    }

    if ((mdt_param->mv_param.k_height == cap_motion->md_dim.height) &&
            (mdt_param->mv_param.k_width == cap_motion->md_dim.width) &&
            (cap_motion->is_valid == 1))
    {
        if (mdt_param->mdt_alg.frame_count < mdt_param->mdt_alg.training_time)
        {
            mdt_param->mdt_alg.frame_count++;
        }
    }
    else
    {
        mdt_param->mdt_alg.frame_count = 0;
        mdt_param->mv_param.k_height = cap_motion->md_dim.height;
        mdt_param->mv_param.k_width = cap_motion->md_dim.width;
        mdt_param->mv_param.k_mb_height = cap_motion->md_mb.height;
        mdt_param->mv_param.k_mb_width = cap_motion->md_mb.width;
    }

    mdt_param->mv_param.active_flag = active->active_flag;
    mdt_param->mv_param.active_num = 0;

    ret = parsing_mv_data((unsigned char *)cap_motion->md_buf,
                          &mdt_param->mv_param,
                          mdt_param->mdt_alg.u_width,
                          mdt_param->mdt_alg.u_height,
                          mdt_param->mdt_alg.u_mb_width,
                          mdt_param->mdt_alg.u_mb_height,
                          mdt_param->mdt_alg.sensitive_th,
                          mdt_param->mdt_alg.frame_count,
                          mdt_param->mdt_alg.mb_w_num,
                          mdt_param->mdt_alg.mb_h_num,
                          mdt_idx);
    if (ret < 0)
    {
        ret = MOTION_PARSING_ERROR;
        goto err_ext;
    }
    active->active_num = mdt_param->mv_param.active_num;

    ret = capture_sub_region_alg(mdt_param, active);
    if (ret < 0)
    {
        ret = MOTION_ALGO_ERROR;
        goto err_ext;
    }

    if (mdt_param->mdt_alg.frame_count < mdt_param->mdt_alg.training_time)
    {
        ret = MOTION_IS_TRAINING;
        goto err_ext;
    }
    else
    {
        ret = MOTION_IS_READY;
        goto err_ext;
    }

err_ext:

    return ret;
}

static int capture_motion_init(struct mdt_user_t *mdt_param, struct mdt_res_t *active, int mdt_idx)
{
    int ret = 0;
    int u_height;
    int u_width;
    int u_mb_height;
    int u_mb_width;
    int blk_h_num;
    int blk_w_num;
    int user_motion_size_init;
    int r_idx;

    u_height    = mdt_param->mdt_alg.u_height;
    u_width     = mdt_param->mdt_alg.u_width;
    u_mb_height = mdt_param->mdt_alg.u_mb_height;
    u_mb_width  = mdt_param->mdt_alg.u_mb_width;
    blk_h_num   = (u_height + (u_mb_height - 1)) / u_mb_height;
    blk_w_num   = (u_width + (u_mb_width - 1)) / u_mb_width;
    mdt_param->mdt_alg.mb_h_num = blk_h_num;
    mdt_param->mdt_alg.mb_w_num = blk_w_num;
    user_motion_size_init = blk_h_num * blk_w_num;

    mdt_param->mv_param.k_height = 0;
    mdt_param->mv_param.k_width = 0;
    mdt_param->mv_param.k_mb_height = 0;
    mdt_param->mv_param.k_mb_width = 0;

    active->active_flag = (unsigned char *)malloc(sizeof(unsigned char) * user_motion_size_init);
    if (active->active_flag == NULL)
    {
        ret = MOTION_INIT_ERROR;
        goto err_ext;
    }
    memset(active->active_flag, 0, sizeof(unsigned char) * user_motion_size_init);
    active->active_num = 0;

    mdt_param->mdt_alg.sub_region = (struct mdt_reg_t *)malloc(sizeof(struct mdt_reg_t) *
                                    MAX_SUBREGION_NUM);
    if (mdt_param->mdt_alg.sub_region == NULL)
    {
        ret = MOTION_INIT_ERROR;
        goto err_ext;
    }
	#if 1
    for (r_idx = 0; r_idx < MAX_SUBREGION_NUM; r_idx++)
    {
        mdt_param->mdt_alg.sub_region[r_idx].is_enabled = 0;
        mdt_param->mdt_alg.sub_region[r_idx].start_block_x = -1;
        mdt_param->mdt_alg.sub_region[r_idx].start_block_y = -1;
        mdt_param->mdt_alg.sub_region[r_idx].end_block_x = -1;
        mdt_param->mdt_alg.sub_region[r_idx].end_block_y = -1;
        mdt_param->mdt_alg.sub_region[r_idx].alarm_th = 100;
        mdt_param->mdt_alg.sub_region[r_idx].alarm = -5;
    }
	#endif

    ret = parsing_mv_initial(mdt_param->mdt_alg.mb_w_num, mdt_param->mdt_alg.mb_h_num, mdt_idx);
    if (ret < 0)
    {
        parsing_mv_end(&mdt_param->mv_param, mdt_idx);
        ret = MOTION_INIT_ERROR;
        goto err_ext;
    }

    cap_motion_init_ok[mdt_idx] = 1;
    user_motion_size[mdt_idx] = user_motion_size_init;

err_ext:

    return 0 ;
}

static int capture_motion_update(struct mdt_user_t *mdt_param, struct mdt_res_t *active, int mdt_idx)
{
    int ret = 0;
    int blk_h_num;
    int blk_w_num;
    int user_motion_size_update;

    if (cap_motion_init_ok[mdt_idx] == 0)
    {
        printf("capture motion not initial\n");
        ret = MOTION_INIT_ERROR;
        goto err_ext;
    }

    blk_h_num   = mdt_param->mdt_alg.mb_h_num;
    blk_w_num   = mdt_param->mdt_alg.mb_w_num;
    user_motion_size_update = blk_h_num * blk_w_num;

    if (user_motion_size[mdt_idx] < user_motion_size_update)
    {
        free(active->active_flag);
        active->active_flag = (unsigned char *) malloc(sizeof(unsigned char) *
                              user_motion_size_update);
        if (active->active_flag == NULL)
        {
            ret = MOTION_INIT_ERROR;
            goto err_ext;
        }

        user_motion_size[mdt_idx] = user_motion_size_update;
    }

    mdt_param->mv_param.k_height = 0;
    mdt_param->mv_param.k_width = 0;
    mdt_param->mv_param.k_mb_height = 0;
    mdt_param->mv_param.k_mb_width = 0;

    memset(active->active_flag, 0, sizeof(unsigned char) * user_motion_size_update);
    active->active_num = 0;

    ret = parsing_mv_initial(mdt_param->mdt_alg.mb_w_num, mdt_param->mdt_alg.mb_h_num, mdt_idx);
    if (ret < 0)
    {
        parsing_mv_end(&mdt_param->mv_param, mdt_idx);
        ret = MOTION_INIT_ERROR;
        goto err_ext;
    }

err_ext:

    return ret;
}

static int capture_motion_end(int mdt_idx)
{

    cap_motion_init_ok[mdt_idx] = 0;

    if (mdt_param[mdt_idx].mdt_alg.sub_region != NULL)
    {
        free(mdt_param[mdt_idx].mdt_alg.sub_region);
        mdt_param[mdt_idx].mdt_alg.sub_region = NULL;
    }

    if (active[mdt_idx].active_flag != NULL)
    {
        free(active[mdt_idx].active_flag);
        active[mdt_idx].active_flag = NULL;
    }

    cap_motion_init_ok[mdt_idx] = 0;
    user_motion_size[mdt_idx] = 0;

    parsing_mv_end(&mdt_param[mdt_idx].mv_param, mdt_idx);

    return 0;
}

int bindfd_to_mdt_idx(void *bindfd)
{
    int mdt_idx;

    pthread_mutex_lock(&mapping_mutex);

    for (mdt_idx = 0; mdt_idx < MAX_CAP_MD_NUM; mdt_idx++)
    {
        if (mdt_param[mdt_idx].bindfd == bindfd)
            break;
    }
    if (mdt_idx >= MAX_CAP_MD_NUM)
    {
        for (mdt_idx = 0; mdt_idx < MAX_CAP_MD_NUM; mdt_idx++)
        {
            if (mdt_param[mdt_idx].bindfd == NULL)
            {
                mdt_param[mdt_idx].bindfd = bindfd;
                break;
            }
        }
        if (mdt_idx >= MAX_CAP_MD_NUM)
        {
            printf("Error, find no available mdt_idx, out of resource\n");
            mdt_idx = -1;
            goto err_ext;
        }
    }

err_ext:

    pthread_mutex_unlock(&mapping_mutex);

    return mdt_idx;
}

int mdt_idx_to_cap_md_idx(int mdt_idx, gm_multi_cap_md_t *cap_md, int num_cap_md)
{
    int cap_md_idx;
    int ret = 0;

    pthread_mutex_lock(&mapping_mutex);

    for (cap_md_idx = 0; cap_md_idx < num_cap_md; cap_md_idx++)
    {
    	//printf("---------------------------->111111111111111111\n");
        if(mdt_param[mdt_idx].bindfd == cap_md[cap_md_idx].bindfd)
        {
        	//printf("---------------------------->2222222222222222222\n");
            break;
        }
    }

    if (cap_md_idx >= num_cap_md)
        ret = -1;
    else
        ret = cap_md_idx;

    pthread_mutex_unlock(&mapping_mutex);
	//printf("Moiton   detection   return    ret%d\n",ret);
    return ret;
}

int motion_detection_init(int max_width, int max_height)
{
    int mdt_idx;
    int ret = 0;

    pthread_mutex_init(&mapping_mutex, NULL);
    for (mdt_idx = 0; mdt_idx < MAX_CAP_MD_NUM; mdt_idx++)
    {
        /*motion detection*/
        pthread_mutex_init(&mdt_param[mdt_idx].mdt_mutex, NULL);
        mdt_param[mdt_idx].mdt_alg.u_height = max_height;
        mdt_param[mdt_idx].mdt_alg.u_width = max_width;
        mdt_param[mdt_idx].mdt_alg.u_mb_height = 32;
        mdt_param[mdt_idx].mdt_alg.u_mb_width = 32;
        mdt_param[mdt_idx].mdt_alg.training_time = 15;
        mdt_param[mdt_idx].mdt_alg.frame_count = 0;
        mdt_param[mdt_idx].mdt_alg.sensitive_th = 80;
        mdt_param[mdt_idx].mdt_alg.mb_w_num = 0;
        mdt_param[mdt_idx].mdt_alg.mb_h_num = 0;
        mdt_param[mdt_idx].bindfd = NULL;

        ret = capture_motion_init(&mdt_param[mdt_idx], &active[mdt_idx], mdt_idx);
        if (ret < 0)
        {
            printf("MD_Test: capture_motion_info_init error at mdt_idx(%d)\n", mdt_idx);
            capture_motion_end(mdt_idx); //motion detectione end
            ret = -1;
            continue;
        }
		
    }

    return ret;
}

int motion_detection_end(void)
{
    int mdt_idx;
    int ret = 0;

    for (mdt_idx = 0; mdt_idx < MAX_CAP_MD_NUM; mdt_idx++)
    {
        /*motion detection end*/
        pthread_mutex_destroy(&mdt_param[mdt_idx].mdt_mutex);
        ret = capture_motion_end(mdt_idx);
        if (ret < 0)
        {
            printf("MD_Test: capture_motion_end error at mdt_idx(%d)\n", mdt_idx);
            ret = -1;
            continue;
        }
    }
    pthread_mutex_destroy(&mapping_mutex);
    return ret;
}

int motion_detection_update(void *bindfd,  mdt_alg_t *mdt_alg)
{
    int ret = 0;
    int mdt_idx;
    int mb_cell_size_ori;
    int mb_cell_size_new;
    int reg_idx;
    int sub_region_num;

    mdt_idx = bindfd_to_mdt_idx(bindfd);
    if (mdt_idx == -1)
    {
        printf("The array depth of mdt_param was not enough for bindfd(0x%p)\n", bindfd);
        ret = -1;
        return ret;
    }

    pthread_mutex_lock(&mdt_param[mdt_idx].mdt_mutex);
    mdt_param[mdt_idx].mdt_alg.u_height = mdt_alg->u_height;
    mdt_param[mdt_idx].mdt_alg.u_width = mdt_alg->u_width;
    mdt_param[mdt_idx].mdt_alg.u_mb_height = mdt_alg->u_mb_height;
    mdt_param[mdt_idx].mdt_alg.u_mb_width = mdt_alg->u_mb_width;
    mdt_param[mdt_idx].mdt_alg.training_time = mdt_alg->training_time;
    mdt_param[mdt_idx].mdt_alg.frame_count = mdt_alg->frame_count;
    mdt_param[mdt_idx].mdt_alg.sensitive_th = mdt_alg->sensitive_th;
    mdt_param[mdt_idx].bindfd = bindfd;

    mb_cell_size_ori = sizeof(unsigned char) * mdt_param[mdt_idx].mdt_alg.mb_w_num *
                       mdt_param[mdt_idx].mdt_alg.mb_h_num;
    mb_cell_size_new = sizeof(unsigned char) * mdt_alg->mb_w_num * mdt_alg->mb_h_num;

    if (mb_cell_size_new == 0)
    {
        printf("Error, mb_w_num(%d) * mb_h_num(%d) = 0 at bindfd(0x%p)\n", mdt_alg->mb_w_num,
               mdt_alg->mb_h_num, bindfd);
        ret = -1;
        goto err_ext;
    }

    mdt_param[mdt_idx].mdt_alg.mb_w_num = mdt_alg->mb_w_num;
    mdt_param[mdt_idx].mdt_alg.mb_h_num = mdt_alg->mb_h_num;

    sub_region_num = mdt_alg->sub_region_num;
    for (reg_idx = 0 ; reg_idx < sub_region_num; reg_idx++)
    {
        if (mdt_alg->sub_region[reg_idx].is_enabled == 0)
            close_sub_region_internal(bindfd, reg_idx);
        else
            set_sub_region_internal(bindfd, reg_idx, mdt_alg->sub_region);
    }

#if(M_DEBUG==1)
    display_region_info_internal(bindfd);
#endif

    ret = capture_motion_update(&mdt_param[mdt_idx], &active[mdt_idx], mdt_idx);
    if (ret < 0)
    {
        printf("MD_Test: capture_motion_info_init error at mdt_idx(%d), bindfd(0x%p)\n", mdt_idx,
               bindfd);
        capture_motion_end(mdt_idx); //motion detectione end �ƶ�������
        ret = -1;
        goto err_ext;
    }

err_ext:
    pthread_mutex_unlock(&mdt_param[mdt_idx].mdt_mutex);

    return ret;
}

int motion_detection_handling(gm_multi_cap_md_t *cap_md, struct mdt_result_t *mdt_result,
                              int num_cap_md)
{
    int ret = 0;
    int mdt_idx;
    int cap_md_idx;
    int result;
    int reg_idx;
    int r_idx;

    for (mdt_idx = 0; mdt_idx < MAX_CAP_MD_NUM; mdt_idx++)
    {
    		
    	//test
    	mdt_param[mdt_idx].bindfd= get_video_bind_handle(0,0);//g_motion_handle.motion_fd;
	    //end
        pthread_mutex_lock(&mdt_param[mdt_idx].mdt_mutex);
        cap_md_idx = mdt_idx_to_cap_md_idx(mdt_idx, cap_md, num_cap_md);
        if (cap_md_idx < 0)
        {
            pthread_mutex_unlock(&mdt_param[mdt_idx].mdt_mutex);
            continue;
        }
        if (cap_md[cap_md_idx].bindfd != mdt_param[mdt_idx].bindfd)
        {
            printf("check bindfd failed between cap_md and mdt_param at cap_md_bindfd(0x%p), "
                   " mdt_param_bindfd(0x%p), mdt_idx(%d)\n", cap_md[cap_md_idx].bindfd,
                   mdt_param[mdt_idx].bindfd, mdt_idx);
            mdt_result[cap_md_idx].bindfd = NULL;
            mdt_result[cap_md_idx].ch_result = MOTION_INIT_ERROR;
            pthread_mutex_unlock(&mdt_param[mdt_idx].mdt_mutex);
            continue;
        }
        if (cap_md[cap_md_idx].retval < 0)
        {
            printf("Error to get capure motion data from this bindfd(0x%p).\n",
                   cap_md[cap_md_idx].bindfd);
            mdt_result[cap_md_idx].bindfd = cap_md[cap_md_idx].bindfd;
            mdt_result[cap_md_idx].ch_result = MOTION_DATA_ERROR;
            pthread_mutex_unlock(&mdt_param[mdt_idx].mdt_mutex);
            continue;
        }
        if (cap_md[cap_md_idx].cap_md_info.is_valid == 0)
        {
            printf("Motion data has not been ready! please get it again at bindfd(0x%p).\n",
                   cap_md[cap_md_idx].bindfd);
            mdt_result[cap_md_idx].bindfd = cap_md[cap_md_idx].bindfd;
            mdt_result[cap_md_idx].ch_result = NO_MOTION;
            pthread_mutex_unlock(&mdt_param[mdt_idx].mdt_mutex);
            continue;
        }
	
        result = do_capture_motion(&cap_md[cap_md_idx].cap_md_info, &mdt_param[mdt_idx],
                                   &active[mdt_idx], mdt_idx);
        mdt_result[cap_md_idx].bindfd = cap_md[cap_md_idx].bindfd;
        mdt_result[cap_md_idx].ch_result = result;
        for (reg_idx = 0; reg_idx < mdt_result[cap_md_idx].sub_region_num; reg_idx++)
        {
            r_idx = reg_idx; //1-1 mapping
            mdt_result[cap_md_idx].sub_region[reg_idx].reg_result =
                mdt_param[mdt_idx].mdt_alg.sub_region[r_idx].alarm;
			//printf("mdt_param[mdt_idx].mdt_alg.sub_region[r_idx].alarm  ------->is %d\n",mdt_param[mdt_idx].mdt_alg.sub_region[r_idx].alarm);
        }
        pthread_mutex_unlock(&mdt_param[mdt_idx].mdt_mutex);
    }
    return ret;
}

