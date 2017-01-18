#ifndef DANA_VIDEO_H
#define DANA_VIDEO_H

#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum _dana_video_cmd_e {
    DANAVIDEOCMD_DEVDEF,
    DANAVIDEOCMD_DEVREBOOT,
    DANAVIDEOCMD_GETSCREEN,
    DANAVIDEOCMD_GETALARM,
    DANAVIDEOCMD_GETBASEINFO,
    DANAVIDEOCMD_GETCOLOR,
    DANAVIDEOCMD_GETFLIP,
    DANAVIDEOCMD_GETFUNLIST,
    DANAVIDEOCMD_GETNETINFO,
    DANAVIDEOCMD_GETPOWERFREQ,
    DANAVIDEOCMD_GETTIME,
    DANAVIDEOCMD_GETWIFIAP,
    DANAVIDEOCMD_GETWIFI,
    DANAVIDEOCMD_PTZCTRL,
    DANAVIDEOCMD_SDCFORMAT,
    DANAVIDEOCMD_SETALARM,//15
    DANAVIDEOCMD_SETCHAN,
    DANAVIDEOCMD_SETCOLOR,
    DANAVIDEOCMD_SETFLIP,
    DANAVIDEOCMD_SETNETINFO,
    DANAVIDEOCMD_SETPOWERFREQ,
    DANAVIDEOCMD_SETTIME,
    DANAVIDEOCMD_SETVIDEO,
    DANAVIDEOCMD_SETWIFIAP,
    DANAVIDEOCMD_SETWIFI,
    DANAVIDEOCMD_STARTAUDIO,
    DANAVIDEOCMD_STARTTALKBACK,
    DANAVIDEOCMD_STARTVIDEO,
    DANAVIDEOCMD_STOPAUDIO, 
    DANAVIDEOCMD_STOPTALKBACK,
    DANAVIDEOCMD_STOPVIDEO,
    DANAVIDEOCMD_RECLIST,
    DANAVIDEOCMD_RECPLAY,
    DANAVIDEOCMD_RECSTOP,
    DANAVIDEOCMD_RECACTION,
    DANAVIDEOCMD_RECSETRATE,
    DANAVIDEOCMD_RECPLANGET,
    DANAVIDEOCMD_RECPLANSET,
    DANAVIDEOCMD_EXTENDMETHOD,
    DANAVIDEOCMD_SETOSD,
    DANAVIDEOCMD_GETOSD,
    DANAVIDEOCMD_SETCHANNAME,
    DANAVIDEOCMD_GETCHANNAME,

    DANAVIDEOCMD_RESOLVECMDFAILED,

    DANAVIDEOCMD_CALLPSP = 66,
    DANAVIDEOCMD_GETPSP,
    DANAVIDEOCMD_SETPSP,
    DANAVIDEOCMD_SETPSPDEF,
    
    DANAVIDEOCMD_GETLAYOUT = 70,
    DANAVIDEOCMD_SETCHANADV,

    DANAVIDEOCMD_SETICR = 78,
    DANAVIDEOCMD_GETICR,

    DANAVIDEOCMD_GETSDCSTATUS = 82,
    DANAVIDEOCMD_GETVIDEO  = 83,

} dana_video_cmd_t;

typedef void* pdana_video_conn_t;

typedef struct _dana_video_callback_funs_s {
    uint32_t (*danavideoconn_created)(pdana_video_conn_t danavideoconn);
    void (*danavideoconn_aborted)(pdana_video_conn_t danavideoconn);
    void (*danavideoconn_command_handler)(pdana_video_conn_t danavideoconn, dana_video_cmd_t cmd, uint32_t trans_id, void* cmd_arg, uint32_t cmd_arg_len); 

} dana_video_callback_funs_t;

// called when ipc recved p2pserver's heartbeat response
typedef void (*danavideo_hb_is_ok_callback_t) (void);

// called when ipc check that the conn with p2p2server is not avliable
typedef void (*danavideo_hb_is_not_ok_callback_t) (void);

// called when need upgrade rom
typedef void (*danavideo_upgrade_rom_callback_t) (const char* rom_path,  const char *rom_md5, const uint32_t rom_size); // ��λ Byte

// called when need autoset
typedef void (*danavideo_autoset_callback_t) (const uint32_t power_freq, const int64_t now_time, const char *time_zone, const char *ntp_server1, const char *ntp_server2);
// ��ԴƵ�� 0 50Hz,  1 60Hz
// now_time ��λs
// time_zone ʱ��
// NTP ������1 2


// called when need setwifi
// setwifi���������,һ����ͨ��command_handler��ȡ������
//                   һ����ͨ���ص�����(����ģʽ)
//                   ������������ģʽ
//                   DanaAirLink
//              ip_type  0: fixed 1:dhcp
//              enc_type ��danavideo_cmd.h
typedef void (*danavideo_local_setwifiap_callback_t) (const uint32_t ch_no, const uint32_t ip_type, const char *ipaddr, const char *netmask, const char *gateway, const char *dns_name1, const char *dns_name2, const char *essid, const char *auth_key, const uint32_t enc_type);

// called when need local auth
// 0 succeeded
// 1 failed
typedef uint32_t (*danavideo_local_auth_callback_t) (const char *user_name, const char *user_pass);

// called when create a new conf or update a exited conf
typedef void (*danavideo_conf_created_or_updated_t) (const char *conf_absolute_pathname);

// called when need get the connected wifi wifi-quality [0-100] (if no wifi set to 0)
typedef uint32_t (*danavideo_get_connected_wifi_quality_callback_t) ();

// called when recv productsetdeviceinfo 
typedef void (*danavideo_productsetdeviceinfo_callback_t) (const char *model, const char *sn, const char *hw_mac);

typedef enum _danavideo_msg_type {
   audio_stream = 0x20000000,
   video_stream = 0x40000000,
   extend_data   = 0x60000000,
   pic_stream   = 0x80000000,
} danavideo_msg_type_t;

typedef enum _danavideo_codec_type {
    H264    = 1,
    MPEG    = 2,
    MJPEG   = 3,
    H265    = 4,
    H265_HISILICON    = 5,
    MJPEG_DIFT        = 6,
    G711A   = 101,
    ULAW    = 102,
    G711U   = 103,
    PCM     = 104,
    ADPCM   = 105,
    G721    = 106,
    G723    = 107,
    G726_16 = 108,
    G726_24 = 109,
    G726_32 = 110,
    G726_40 = 111,
    AAC     = 112,
    JPG     = 200,
} danavidecodec_t;

typedef struct _dana_packet_s {
    char    *data;
    int32_t   len;
} dana_packet_t;

typedef struct _dana_audio_packet_s {
    char  *data;
    int32_t len;
    danavidecodec_t  codec; // ��Ƶ����
} dana_audio_packet_t;


// ����������Ƶ���ͻ���
// Ĭ��2M,���2M
void lib_danavideo_set_maximum_buffering_data_size(const int32_t size);

// ��������lib_danavideo_start��ʱʱ��,
void lib_danavideo_set_startup_timeout(const uint32_t timeout_sec);

void lib_danavideo_set_hb_is_ok(danavideo_hb_is_ok_callback_t fun);
void lib_danavideo_set_hb_is_not_ok(danavideo_hb_is_not_ok_callback_t fun);

void lib_danavideo_set_upgrade_rom(danavideo_upgrade_rom_callback_t fun);

void lib_danavideo_set_autoset(danavideo_autoset_callback_t fun);

void lib_danavideo_set_local_setwifiap(danavideo_local_setwifiap_callback_t fun);

void lib_danavideo_set_local_auth(danavideo_local_auth_callback_t fun);

void lib_danavideo_set_conf_created_or_updated(danavideo_conf_created_or_updated_t fun);

void lib_danavideo_set_get_connected_wifi_quality(danavideo_get_connected_wifi_quality_callback_t fun);

void lib_danavideo_set_productsetdeviceinfo(danavideo_productsetdeviceinfo_callback_t fun);

uint32_t lib_danavideo_linked_version(void);
char * lib_danavideo_linked_version_str(uint32_t version);

char * lib_danavideo_deviceid_from_conf(const char *danale_path);

char * lib_danavideo_deviceid();

// ***���ؼ����˿�***
// ��lib_danavideo_start֮ǰ ���� ���������õĶ˿�(�̶�ģʽ�� ���߷ǹ̶�ģʽ������ѡ��)
// ��lib_danavideo_start֮�� ���� ��Ĭ�ϻ�����34102 Ȼ���ж����ö˿��Ƿ��34102��ͬ �������ͬ���ر�34102 �����û����õĶ˿�,����ֱ�ӷ���

void lib_danavideo_set_listen_port(const bool listen_port_fixed, const uint16_t listen_port);
uint16_t lib_danavideo_get_listen_port(); 


// ���������ļ�
// ������lib_danavideo_init����֮��ſ��Ե���
// ���ָ����Ŀ¼�������ļ����ڲ������Ч���򲻻ᴴ��
// ��������´���һ�������ļ�
// ������
bool lib_danavideo_create_on_check_conf();

// ���·������ݽӿ� 
// ����lib_danavideoconn_send 
// ȡ��danavideo_msg_max_size
// ȡ��lib_danavideo_packet_create
//     lib_danavideo_packet_destroy
//     lib_danavideoconn_sendvideomsg
//     lib_danavideoconn_sendaudiomsg
//     lib_danavideoconn_sendpicmsg
// ����danavideo_msg_type_t ��rec_stream���Ϊextend_data ��֧��extend_data�ķ���
// ֧�ַ���video audio pic extend_data
bool lib_danavideoconn_send(pdana_video_conn_t danavideoconn, const danavideo_msg_type_t msg_type, const danavidecodec_t codec, const uint8_t ch_no, const uint8_t is_keyframe, const uint32_t timestamp, const char* data, const uint32_t data_len, const uint32_t timeout_usec);

dana_audio_packet_t* lib_danavideoconn_readaudio(pdana_video_conn_t danavideoconn, uint32_t timeout_usec); // call lib_danavideo_audio_packet_destroy to free
void lib_danavideo_audio_packet_destroy(dana_audio_packet_t *danaaudiomsg);

// lib_danavideo_init�����Զ����������ļ� �������ļ�������(����Ч)ʱֱ�ӷ���false
bool lib_danavideo_init(const char *danale_path, const char *agent_user, const char *agent_pass, const char *chip_code, const char *scheme_code, const char *product_code, dana_video_callback_funs_t *danavideocallbackfuns);

uint32_t lib_danavideo_set_userdata(pdana_video_conn_t danavideoconn, void *userdata);

uint32_t lib_danavideo_get_userdata(pdana_video_conn_t danavideoconn, void **userdata);

bool lib_danavideo_start();

bool lib_danavideo_cmd_exec_response(pdana_video_conn_t danavideoconn, const dana_video_cmd_t cmd, char* error_method, const uint32_t trans_id, const uint32_t code, const char* code_msg); 

bool lib_danavideo_cmd_setvideo_response(pdana_video_conn_t danavideoconn, const uint32_t trans_id, uint32_t code, const char* code_msg, const uint32_t fps);
bool lib_danavideo_cmd_startvideo_response(pdana_video_conn_t danavideoconn, const uint32_t trans_id, uint32_t code, const char* code_msg, const uint32_t fps);
// audio_codec Ĭ�� G711A  (danavidecodec_t)
// sample_rate Ĭ�� 8000Hz
// sample_bit  Ĭ�� 16bit
// track       Ĭ�� mono   (1 mono; 2 stereo)
bool lib_danavideo_cmd_startaudio_response(pdana_video_conn_t danavideoconn, const uint32_t trans_id, uint32_t code, const char* code_msg, const uint32_t *audio_codec, const uint32_t *sample_rate, const uint32_t *sample_bit, const uint32_t *track);
bool lib_danavideo_cmd_getalarm_response(pdana_video_conn_t danavideoconn, const uint32_t trans_id, uint32_t code, const char* code_msg, const uint32_t motion_detection, const uint32_t opensound_detection, const uint32_t openi2o_detection, const uint32_t smoke_detection, const uint32_t shadow_detection, const uint32_t other_detection);
bool lib_danavideo_cmd_getbaseinfo_response(pdana_video_conn_t danavideoconn, const uint32_t trans_id, uint32_t code, const char* code_msg, const char *dana_id, const char *api_ver, const char *sn, const char *device_name, const char *rom_ver, const uint32_t device_type, const uint32_t ch_num, const uint64_t sdc_size, const uint64_t sdc_free, const size_t work_channel_count, const uint32_t *work_channel); // dana_id < 49; api_ver < 129; sn < 129; device_name < 129; rom_ver < 129 work_channel <=48// DONE
bool lib_danavideo_cmd_getcolor_response(pdana_video_conn_t danavideoconn, const uint32_t trans_id, uint32_t code, const char* code_msg, const uint32_t brightness, const uint32_t contrast, const uint32_t saturation, const uint32_t hue);
bool lib_danavideo_cmd_getflip_response(pdana_video_conn_t danavideoconn, const uint32_t trans_id, uint32_t code, const char* code_msg, const uint32_t flip_type);
bool lib_danavideo_cmd_getfunlist_response(pdana_video_conn_t danavideoconn, const uint32_t trans_id, uint32_t code, const char* code_msg, const uint32_t methodes_count, const char **methodes); // methodes_count <= 160
bool lib_danavideo_cmd_getnetinfo_response(pdana_video_conn_t danavideoconn, const uint32_t trans_id, uint32_t code, const char* code_msg, const uint32_t ip_type, const char *ipaddr, const char *netmask, const char *gateway, const uint32_t dns_type, const char *dns_name1, const char *dns_name2, const uint32_t http_port); // ipaddr < 16; netmask < 16; gataway < 16; dns_type < 10; dns_name1 < 16; dns_name2 < 16
bool lib_danavideo_cmd_getpowerfreq_response(pdana_video_conn_t danavideoconn, const uint32_t trans_id, uint32_t code, const char* code_msg, const uint32_t freq);
bool lib_danavideo_cmd_gettime_response(pdana_video_conn_t danavideoconn, const uint32_t trans_id, uint32_t code, const char* code_msg, const int64_t now_time, const char *time_zone, const char *ntp_server_1, const char *ntp_server_2); // time_zone < 65

typedef struct _libdanavideo_wifiinfo_s {
    char essid[33];
    uint32_t enc_type;
    uint32_t quality;
} libdanavideo_wifiinfo_t;

bool lib_danavideo_cmd_getwifiap_response(pdana_video_conn_t danavideoconn, const uint32_t trans_id, uint32_t code, const char* code_msg, const uint32_t wifi_device, const uint32_t wifi_list_count, const libdanavideo_wifiinfo_t *wifi_list); // wifi_list_count <= 20;  essid < 33
bool lib_danavideo_cmd_getwifi_response(pdana_video_conn_t danavideoconn, const uint32_t trans_id, uint32_t code, const char* code_msg, const char *essid, const char *auth_key, const uint32_t enc_type); // essid < 33; auth_key < 65
bool lib_danavideo_cmd_starttalkback_response(pdana_video_conn_t danavideoconn, const uint32_t trans_id, uint32_t code, const char* code_msg, const uint32_t audio_codec, const uint32_t * sample_rate, const uint32_t *sample_bit, const uint32_t *track);


typedef struct _libdanavideo_reclist_recordinfo_s {
    int64_t start_time;
    uint32_t length;
    uint32_t record_type;
} libdanavideo_reclist_recordinfo_t;

bool lib_danavideo_cmd_reclist_response(pdana_video_conn_t danavideoconn, const uint32_t trans_id, uint32_t code, const char* code_msg, const uint32_t rec_lists_count, const libdanavideo_reclist_recordinfo_t *rec_lists); // rec_lists_count <= 35

typedef struct _libdanavideo_recplanget_recplan_s {
    uint32_t record_no;
    size_t week_count; // <= 7  ��ʾweek�������м���
    uint32_t week[7];
    char start_time[33]; // ʱ:��:�� 12:12:12
    char end_time[33];
    uint32_t status;
} libdanavideo_recplanget_recplan_t;

bool lib_danavideo_cmd_recplanget_response(pdana_video_conn_t danavideoconn, const uint32_t trans_id, uint32_t code, const char* code_msg, const uint32_t rec_plans_count, const libdanavideo_recplanget_recplan_t *rec_plans); // rec_plans_count <= 3

typedef struct _libdanavideo_osdinfo_s {
    uint32_t chan_name_show;
    uint32_t show_name_x;
    uint32_t show_name_y;

    uint32_t datetime_show;
    uint32_t show_datetime_x;
    uint32_t show_datetime_y;
    uint32_t show_format;
    uint32_t hour_format;
    uint32_t show_week;
    uint32_t datetime_attr;

    uint32_t custom1_show;
    char     show_custom1_str[45];
    uint32_t show_custom1_x;
    uint32_t show_custom1_y;

    uint32_t custom2_show;
    char     show_custom2_str[45];
    uint32_t show_custom2_x;
    uint32_t show_custom2_y;
} libdanavideo_osdinfo_t;

bool lib_danavideo_cmd_getosd_response(pdana_video_conn_t danavideoconn, const uint32_t trans_id, uint32_t code, const char * code_msg, const libdanavideo_osdinfo_t *osdinfo);

bool lib_danavideo_cmd_getchanname_response(pdana_video_conn_t danavideoconn, const uint32_t trans_id, uint32_t code, const char * code_msg, const char *chan_name);

typedef struct _libdanavideo_pspinfo_s {
    uint32_t psp_id;
    char psp_name[60];
    bool psp_default;
    bool is_set;
} libdanavideo_pspinfo_t;

bool lib_danavideo_cmd_getpsp_response(pdana_video_conn_t danavideoconn, const uint32_t trans_id, uint32_t code, const char * code_msg, const uint32_t total, const uint32_t psp_count, const libdanavideo_pspinfo_t *psp); // psp_count <=10

bool lib_danavideo_cmd_getlayout_response(pdana_video_conn_t danavideoconn, const uint32_t trans_id, uint32_t code, const char * code_msg, const uint32_t matrix_x, const uint32_t matrix_y, const size_t chans_count, const uint32_t chans[64], const uint32_t layout_change, const uint32_t chan_pos_change, const size_t use_chs_count, const uint32_t use_chs[98]);

bool lib_danavideo_cmd_geticr_response(pdana_video_conn_t danavideoconn, const uint32_t trans_id, uint32_t code, const char * code_msg, const uint32_t mode);

bool lib_danavideo_cmd_getsdcstatus_response(pdana_video_conn_t danavideoconn, const uint32_t trans_id, uint32_t code, const char * code_msg, const uint32_t status, const uint32_t *format_progress, const uint32_t *sd_size, const uint32_t *sd_free);
bool lib_danavideo_cmd_getvideo_response(pdana_video_conn_t danavideoconn, const uint32_t trans_id, uint32_t code, const char * code_msg, const uint32_t video_quality);

bool lib_danavideo_stop();

bool lib_danavideo_deinit();


/////////////////////////////////////// ������ ////////////////////////////////////////

typedef enum _danavideo_device_type_e {
    DANAVIDEO_DEVICE_IPC = 1,
    DANAVIDEO_DEVICE_DVR,
    DANAVIDEO_DEVICE_NVR,
    DANAVIDEO_DEVICE_DVR_NO_MIX_NO_MULTI_CHANNEL, // ��֧��0ͨ��(��·��Ƶ�ϳ�), ��֧�ֶ�·��Ƶͬʱ����
    DANAVIDEO_DEVICE_NVR_NO_MIX_NO_MULTI_CHANNEL, // ��֧��0ͨ��(��·��Ƶ�ϳ�), ��֧�ֶ�·��Ƶͬʱ����
    DANAVIDEO_DEVICE_DVR_NO_MIX_MULTI_CHANNEL,   // ��֧��0ͨ��(��·��Ƶ�ϳ�), ֧�ֶ�·��Ƶͬʱ����
    DANAVIDEO_DEVICE_NVR_NO_MIX_MULTI_CHANNEL,   // ��֧��0ͨ��(��·��Ƶ�ϳ�), ֧�ֶ�·��Ƶͬʱ����
    DANAVIDEO_DEVICE_DVR_SPLIT,     // ֧��0ͨ��(��·��Ƶ�ϳ�),֧�ֲ��������
    DANAVIDEO_DEVICE_NVR_SPLIT,     // ֧��0ͨ��(��·��Ƶ�ϳ�),֧�ֲ��������
    DANAVIDEO_DEVICE_Unknown_type = -1,
} danavideo_device_type_t;

bool lib_danavideo_util_setdeviceinfo(const danavideo_device_type_t device_type, const uint32_t channel_num, const char *rom_ver, const char *api_ver, const char *rom_md5); // rom_ver < 129; api_ver < 129; rom_md5 < 65

typedef enum _dana_video_feature_e {
    // Ӳ������
    DANAVIDEO_FEATURE_HAVE_BATTERY          = 4097, // ���
    DANAVIDEO_FEATURE_HAVE_GPS              = 4098, // GPS
    DANAVIDEO_FEATURE_HAVE_PIR              = 4099, // PIR ����  (���� ���� rf433)
    DANAVIDEO_FEATURE_HAVE_G_SENSOR         = 4100, // ���ٶȴ�����
    DANAVIDEO_FEATURE_HAVE_GYRO_SENSOR      = 4101, // �����Ǵ�����
    DANAVIDEO_FEATURE_HAVE_TEMP_SENSOR      = 4102, // �¶ȴ�����
    DANAVIDEO_FEATURE_HAVE_HUMIDITY_SENSOR  = 4103, // ʪ�ȴ�����
    DANAVIDEO_FEATURE_HAVE_MOBILENET        = 4104, // 3G/4G֧��
    DANAVIDEO_FEATURE_HAVE_PTZ_L_R          = 4105, // ��̨֧��(����)
    DANAVIDEO_FEATURE_HAVE_PTZ_U_D          = 4106, // ��̨֧��(����)
    DANAVIDEO_FEATURE_HAVE_PTZ_L_R_U_D      = 4107, // ��̨֧��(����,����)
    DANAVIDEO_FEATURE_HAVE_PTZ_DD           = 4108, // ��̨֧��(8��֧��)
    DANAVIDEO_FEATURE_HAVE_WIPER            = 4109, // ��ˢ
    DANAVIDEO_FEATURE_HAVE_ZOOM_LENS        = 4110, // �佹 ?
    DANAVIDEO_FEATURE_HAVE_ENLARGING_LENS   = 4111, // �䱶 ?
    DANAVIDEO_FEATURE_HAVE_SD               = 4112, // SD��֧��
    DANAVIDEO_FEATURE_HAVE_MIC              = 4113, // MIC֧��
    DANAVIDEO_FEATURE_HAVE_SPEAKER          = 4114, // �Խ�֧��(����)
    DANAVIDEO_FEATURE_HAVE_BLE_HEADSET      = 4115, // ��������֧��
    DANAVIDEO_FEATURE_HAVE_PSP              = 4138, // ֧��Ԥ�õ� 
    DANAVIDEO_FEATURE_HAVE_FISHEYE          = 4139, // ֧������ 
    DANAVIDEO_FEATURE_HAVE_1_WAY_VOICE	    = 4146, //֧�ֵ��������Խ�
    DANAVIDEO_FEATURE_HAVE_FISHEYE_JIEGAO2  = 4147, //֧�ֽݸ�����2
    
    // ��չ����
    DANA_VIDEO_HAVE_CLOUD_STORAGE           = 8193, // �ƴ洢
    DANA_VIDEO_HAVE_PERSONAL_STORAGE        = 8194, // ���˴洢
    DANA_VIDEO_HAVE_SMART_HOME              = 8195, // ���ܼҾ��пع���(���й���Ҿ����ܰ����豸�Ĺ���)
    DANA_VIDEO_HAVE_UPGRADE                 = 8196, // �̼���������
} dana_video_feature_t;

bool lib_danavideo_util_setdevicefeature(const size_t feature_list_count, const dana_video_feature_t feature_list[152]); // feature_list <= 152


// �ϱ���Ϣ
// ��Ӹ澯��Ϣ�ȼ�ѡ��  alarm_level
// �淶����澯��Ϣ����  msg_type
typedef enum _dana_video_pushmsg_alarm_level_e {
   DANA_VIDEO_PUSHMSG_ALARM_LEVEL_1 = 1,    //  ��
   DANA_VIDEO_PUSHMSG_ALARM_LEVEL_2 = 2,    //  ��
   DANA_VIDEO_PUSHMSG_ALARM_LEVEL_3 = 3,    //  ��
} dana_video_pushmsg_alarm_level_t;
typedef enum _dana_video_pushmsg_msg_type_e {
    DANA_VIDEO_PUSHMSG_MSG_TYPE_MOTION_DETECT   = 1,    //  �ƶ����
    DANA_VIDEO_PUSHMSG_MSG_TYPE_SOUND_DETECT    = 2,    //  �������
    DANA_VIDEO_PUSHMSG_MSG_TYPE_IR              = 3,    //  ����
    DANA_VIDEO_PUSHMSG_MSG_TYPE_OTHER           = 4,    //  ����
    DANA_VIDEO_PUSHMSG_MSG_TYPE_BODY_SENSOR     = 10,   //  �����Ӧ
    DANA_VIDEO_PUSHMSG_MSG_TYPE_SMOKE_SENSOR    = 11,   //  ����̽��
    DANA_VIDEO_PUSHMSG_MSG_TYPE_DOOR_SENSOR     = 12,   //  �ŴŴ�
    DANA_VIDEO_PUSHMSG_MSG_TYPE_GLASS_BREAK     = 13,   //  ��������
    DANA_VIDEO_PUSHMSG_MSG_TYPE_COMBUSTIBLEGAS_EXCEEDED = 14,   // ��ȼ���峬��
    DANA_VIDEO_PUSHMSG_MSG_TYPE_DOOR_BELL       = 15,   // ���屻����/ ��Ҫ�ϱ��ƴ洢¼��
    DANA_VIDEO_PUSHMSG_MSG_TYPE_DEMOLITION      = 16,   // ��ٱ���
    DANA_VIDEO_PUSHMSG_MSG_TYPE_LOW_BATTERY     = 17,   // �͵�������
    DANA_VIDEO_PUSHMSG_MSG_TYPE_PASSWD_INCORRECT = 18,   // �������澯
    DANA_VIDEO_PUSHMSG_MSG_TYPE_SOS             = 19,   // SOS
    DANA_VIDEO_PUSHMSG_MSG_TYPE_WATERLOGGING    = 20,   // ˮ�ո澯
    DANA_VIDEO_PUSHMSG_MSG_TYPE_DEV_OFFLINE     = 21,   // �豸���߸澯
    DANA_VIDEO_PUSHMSG_MSG_TYPE_DEV_ONLINE      = 22,   // ������ʾ
    DANA_VIDEO_PUSHMSG_MSG_TYPE_BATTERY_POWERED = 23,   // �豸ʹ�õ����ʾ��Ϣ
    DANA_VIDEO_PUSHMSG_MSG_TYPE_SENSOR_DETECT   = 31,   // ̽ͷ�澯
    DANA_VIDEO_PUSHMSG_MSG_TYPE_VLOST           = 32,   // ��Ƶ��ʧ�澯
    DANA_VIDEO_PUSHMSG_MSG_TYPE_VMASK           = 33,   // ��Ƶ�ڵ��澯
    DANA_VIDEO_PUSHMSG_MSG_TYPE_DISKFULL        = 34,   // �������澯
    DANA_VIDEO_PUSHMSG_MSG_TYPE_DISKERR         = 35,   // ���̴���澯
    DANA_VIDEO_PUSHMSG_MSG_TYPE_DISK_NO_FORMAT  = 36,   // ����δ��ʽ���澯
    DANA_VIDEO_PUSHMSG_MSG_TYPE_GARAGE_DOOR_TOGGLE  =  41,  // ������״̬�л�[����״̬δ֪]
    DANA_VIDEO_PUSHMSG_MSG_TYPE_GARAGE_DOOR_CLOSE   =  42,  // �����Źر� 
    DANA_VIDEO_PUSHMSG_MSG_TYPE_GARAGE_DOOR_OPEN    =  43,  // �����Ŵ�
    DANA_VIDEO_PUSHMSG_MSG_TYPE_DOOR_BELL_PUSH      =  51,   // ���屻����/ ���ƴ洢�޷�,�����ڴ���App�򿪺��н���
    DANA_VIDEO_PUSHMSG_MSG_TYPE_SYS_MSG         = 99,   //  ϵͳ��Ϣ(���������)
} dana_video_pushmsg_msg_type_t;

bool lib_danavideo_util_pushmsg(const uint32_t ch_no, const uint32_t alarm_level, const uint32_t msg_type, const char *msg_title, const char *msg_body, const int64_t cur_time, const uint32_t att_flag, const char *att_path, const char *att_type, const uint32_t record_flag, const int64_t start_time, const uint32_t time_len, const uint32_t save_site, const char *save_path);

bool lib_danavideo_local_searchapp(const char *check_data, const uint32_t encrypt_flag);


// ��������
void lib_danavideo_smart_conf_init();
void lib_danavideo_smart_conf_parse(const int16_t *audio, int32_t size); // PCM ��Ƶ����: 16λ�з�����������Ƶ�ʱ���Ϊ48000 ���� 44100
// ���°汾��Ҫ44100,��֧��˫��ͨ��

// �û�ֱ�Ӳ��Ÿ���������
//
// ��Ҫע��,�û���������danale�����ļ�·��
// ����ִ��һ��lib_danavideo_init
void lib_danavideo_smart_conf_set_danalepath(const char *danale_path);

// ��������,�����Ҫ�����������Լ��İ����ϵ���  �Ƽ�ֵ��0x2400 ������0x8000
void lib_danavideo_smart_conf_set_volume(const uint32_t volume);

typedef void (*danavideo_smart_conf_response_callback_t) (const char *audio, size_t size);
void lib_danavideo_set_smart_conf_response(danavideo_smart_conf_response_callback_t fun);

// DanaAirLink
// ��Ҫ������danale�����ļ�·��(����ִ��һ��lib_danavideo_init) 
bool danaairlink_set_danalepath(const char *danale_path);

typedef enum _danaairlink_chip_type_e {
    DANAAIRLINK_CHIP_TYPE_NORMAL,
    DANAAIRLINK_CHIP_TYPE_MT7601,
    DANAAIRLINK_CHIP_TYPE_RLT8188,
    DANAAIRLINK_CHIP_TYPE_AP6212,
    DANAAIRLINK_CHIP_TYPE_UNKNOW = -1,
} danaairlink_chip_type_t;
bool danaairlink_init(const danaairlink_chip_type_t chip_type, const char *if_name);

// ÿ����Ҫ����DanaAirLink����״̬����Ҫ����һ�θ÷���
// Ҳ�����ص�����(danavideo_local_setwifiap_callback_t)��������,��Ҫ�ٴν�������״̬ʱ����ø÷���
bool danaairlink_start_once(); 
bool danaairlink_stop();
bool danaairlink_deinit();

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
