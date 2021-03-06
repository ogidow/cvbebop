#pragma once
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <string>
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <bitset>
#include <cstring>
#include <boost\asio.hpp>
#include <boost\array.hpp>
#include <boost\bind.hpp>
#include <boost\thread.hpp>
#include <boost\bind.hpp>
#include <math.h>
#include <fstream>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\opencv.hpp>

extern "C" { 
        #include <libavcodec/avcodec.h> 
        #include <libavformat/avformat.h> 
        #include <libswscale/swscale.h> 
}

using namespace std;
namespace asio = boost::asio;

#define DISCOVERY_PORT 44444
// eARCOMMANDS_ID_PROJECT
#define ARCOMMANDS_ID_PROJECT_COMMON 0
#define ARCOMMANDS_ID_PROJECT_ARDRONE3 1 
// eARCOMMANDS_ID_ARDRONE3_CLASS
#define ARCOMMANDS_ID_ARDRONE3_CLASS_PILOTING 0
#define ARCOMMANDS_ID_ARDRONE3_CLASS_ANIMATIONS 5
#define ARCOMMANDS_ID_ARDRONE3_CLASS_CAMERA 1
#define ARCOMMANDS_ID_ARDRONE3_CLASS_MEDIARECORD 7
#define ARCOMMANDS_ID_ARDRONE3_CLASS_MEDIARECORDSTATE 8
#define ARCOMMANDS_ID_ARDRONE3_CLASS_MEDIARECORDEVENT 3
#define ARCOMMANDS_ID_ARDRONE3_CLASS_PILOTINGSTATE 4
#define ARCOMMANDS_ID_ARDRONE3_CLASS_NETWORK 13
#define ARCOMMANDS_ID_ARDRONE3_CLASS_NETWORKSTATE 14
#define ARCOMMANDS_ID_ARDRONE3_CLASS_PILOTINGSETTINGS 2
#define ARCOMMANDS_ID_ARDRONE3_CLASS_PILOTINGSETTINGSSTATE 6
#define ARCOMMANDS_ID_ARDRONE3_CLASS_SPEEDSETTINGS 11
#define ARCOMMANDS_ID_ARDRONE3_CLASS_SPEEDSETTINGSSTATE 12
#define ARCOMMANDS_ID_ARDRONE3_CLASS_NETWORKSETTINGS 9
#define ARCOMMANDS_ID_ARDRONE3_CLASS_NETWORKSETTINGSSTATE 10
#define ARCOMMANDS_ID_ARDRONE3_CLASS_SETTINGS 15
#define ARCOMMANDS_ID_ARDRONE3_CLASS_SETTINGSSTATE 16
#define ARCOMMANDS_ID_ARDRONE3_CLASS_DIRECTORMODE 17
#define ARCOMMANDS_ID_ARDRONE3_CLASS_DIRECTORMODESTATE 18
#define ARCOMMANDS_ID_ARDRONE3_CLASS_PICTURESETTINGS 19
#define ARCOMMANDS_ID_ARDRONE3_CLASS_PICTURESETTINGSSTATE 20
#define ARCOMMANDS_ID_ARDRONE3_CLASS_MEDIASTREAMING 21
#define ARCOMMANDS_ID_ARDRONE3_CLASS_MEDIASTREAMINGSTATE 22
#define ARCOMMANDS_ID_ARDRONE3_CLASS_GPSSETTINGS 23
#define ARCOMMANDS_ID_ARDRONE3_CLASS_GPSSETTINGSSTATE 24
#define ARCOMMANDS_ID_ARDRONE3_CLASS_CAMERASTATE 25
#define ARCOMMANDS_ID_ARDRONE3_CLASS_ANTIFLICKERING 29
#define ARCOMMANDS_ID_ARDRONE3_CLASS_ANTIFLICKERINGSTATE 30

// eARCOMMANDS_ID_ARDRONE3_PILOTINGSTATE_CMD
#define ARCOMMANDS_ID_ARDRONE3_PILOTINGSTATE_CMD_FLATTRIMCHANGED 0
#define ARCOMMANDS_ID_ARDRONE3_PILOTINGSTATE_CMD_FLYINGSTATECHANGED 1
#define ARCOMMANDS_ID_ARDRONE3_PILOTINGSTATE_CMD_ALERTSTATECHANGED 2
#define ARCOMMANDS_ID_ARDRONE3_PILOTINGSTATE_CMD_NAVIGATEHOMESTATECHANGED 3
#define ARCOMMANDS_ID_ARDRONE3_PILOTINGSTATE_CMD_POSITIONCHANGED 4
#define ARCOMMANDS_ID_ARDRONE3_PILOTINGSTATE_CMD_SPEEDCHANGED 5
#define ARCOMMANDS_ID_ARDRONE3_PILOTINGSTATE_CMD_ATTITUDECHANGED 6
#define ARCOMMANDS_ID_ARDRONE3_PILOTINGSTATE_CMD_AUTOTAKEOFFMODECHANGED 7
#define ARCOMMANDS_ID_ARDRONE3_PILOTINGSTATE_CMD_ALTITUDECHANGED 8
#define ARCOMMANDS_ID_ARDRONE3_PILOTINGSTATE_CMD_MAX 9

// eARCOMMANDS_ID_ARDRONE3_ANIMATIONS_CMD;
#define ARCOMMANDS_ID_ARDRONE3_ANIMATIONS_CMD_FLIP 0
#define ARCOMMANDS_ID_ARDRONE3_ANIMATIONS_CMD_MAX 1

// eARCOMMANDS_ARDRONE3_PILOTINGSTATE_FLYINGSTATECHANGED_STATE;
#define ARCOMMANDS_ARDRONE3_PILOTINGSTATE_FLYINGSTATECHANGED_STATE_LANDED 0
#define ARCOMMANDS_ARDRONE3_PILOTINGSTATE_FLYINGSTATECHANGED_STATE_TAKINGOFF 1
#define ARCOMMANDS_ARDRONE3_PILOTINGSTATE_FLYINGSTATECHANGED_STATE_HOVERING 2
#define ARCOMMANDS_ARDRONE3_PILOTINGSTATE_FLYINGSTATECHANGED_STATE_FLYING 3
#define ARCOMMANDS_ARDRONE3_PILOTINGSTATE_FLYINGSTATECHANGED_STATE_LANDING 4
#define ARCOMMANDS_ARDRONE3_PILOTINGSTATE_FLYINGSTATECHANGED_STATE_EMERGENCY 5
#define ARCOMMANDS_ARDRONE3_PILOTINGSTATE_FLYINGSTATECHANGED_STATE_MAX 6

// eARCOMMANDS_ARDRONE3_ANIMATIONS_FLIP_DIRECTION;
#define ARCOMMANDS_ARDRONE3_ANIMATIONS_FLIP_DIRECTION_FRONT 0
#define ARCOMMANDS_ARDRONE3_ANIMATIONS_FLIP_DIRECTION_BACK 1
#define ARCOMMANDS_ARDRONE3_ANIMATIONS_FLIP_DIRECTION_RIGHT 2
#define ARCOMMANDS_ARDRONE3_ANIMATIONS_FLIP_DIRECTION_LEFT 3
#define ARCOMMANDS_ARDRONE3_ANIMATIONS_FLIP_DIRECTION_MAX 4

// eARCOMMANDS_ID_COMMON_CLASS
#define ARCOMMANDS_ID_COMMON_CLASS_NETWORK 0
#define ARCOMMANDS_ID_COMMON_CLASS_NETWORKEVENT 1
#define ARCOMMANDS_ID_COMMON_CLASS_SETTINGS 2
#define ARCOMMANDS_ID_COMMON_CLASS_SETTINGSSTATE 3
#define ARCOMMANDS_ID_COMMON_CLASS_COMMON 4
#define ARCOMMANDS_ID_COMMON_CLASS_COMMONSTATE 5
#define ARCOMMANDS_ID_COMMON_CLASS_OVERHEAT 6
#define ARCOMMANDS_ID_COMMON_CLASS_OVERHEATSTATE 7
#define ARCOMMANDS_ID_COMMON_CLASS_CONTROLLERSTATE 8
#define ARCOMMANDS_ID_COMMON_CLASS_WIFISETTINGS 9
#define ARCOMMANDS_ID_COMMON_CLASS_WIFISETTINGSSTATE 10
#define ARCOMMANDS_ID_COMMON_CLASS_MAVLINK 11
#define ARCOMMANDS_ID_COMMON_CLASS_MAVLINKSTATE 12
#define ARCOMMANDS_ID_COMMON_CLASS_CALIBRATION 13
#define ARCOMMANDS_ID_COMMON_CLASS_CALIBRATIONSTATE 14
#define ARCOMMANDS_ID_COMMON_CLASS_CAMERASETTINGSSTATE 15
#define ARCOMMANDS_ID_COMMON_CLASS_GPS 16
#define ARCOMMANDS_ID_COMMON_CLASS_FLIGHTPLANSTATE 17
#define ARCOMMANDS_ID_COMMON_CLASS_FLIGHTPLANEVENT 19
#define ARCOMMANDS_ID_COMMON_CLASS_ARLIBSVERSIONSSTATE 18

// eARCOMMANDS_ID_ARDRONE3_PILOTING_CMD
#define ARCOMMANDS_ID_ARDRONE3_PILOTING_CMD_FLATTRIM 0
#define ARCOMMANDS_ID_ARDRONE3_PILOTING_CMD_TAKEOFF 1
#define ARCOMMANDS_ID_ARDRONE3_PILOTING_CMD_PCMD 2
#define ARCOMMANDS_ID_ARDRONE3_PILOTING_CMD_LANDING 3
#define ARCOMMANDS_ID_ARDRONE3_PILOTING_CMD_EMERGENCY 4
#define ARCOMMANDS_ID_ARDRONE3_PILOTING_CMD_NAVIGATEHOME 5
#define ARCOMMANDS_ID_ARDRONE3_PILOTING_CMD_AUTOTAKEOFFMODE 6
#define ARCOMMANDS_ID_ARDRONE3_PILOTING_CMD_MAX 7

// eARCOMMANDS_ID_COMMON_COMMON_CMD
#define ARCOMMANDS_ID_COMMON_COMMON_CMD_ALLSTATES 0
#define ARCOMMANDS_ID_COMMON_COMMON_CMD_CURRENTDATE 1
#define ARCOMMANDS_ID_COMMON_COMMON_CMD_CURRENTTIME 2
#define ARCOMMANDS_ID_COMMON_COMMON_CMD_REBOOT 3
#define ARCOMMANDS_ID_COMMON_COMMON_CMD_MAX 4

// eARCOMMANDS_ID_COMMON_COMMONSTATE_CMD;
#define ARCOMMANDS_ID_COMMON_COMMONSTATE_CMD_ALLSTATESCHANGED 0
#define ARCOMMANDS_ID_COMMON_COMMONSTATE_CMD_BATTERYSTATECHANGED 1
#define ARCOMMANDS_ID_COMMON_COMMONSTATE_CMD_MASSSTORAGESTATELISTCHANGED 2
#define ARCOMMANDS_ID_COMMON_COMMONSTATE_CMD_MASSSTORAGEINFOSTATELISTCHANGED \3
#define ARCOMMANDS_ID_COMMON_COMMONSTATE_CMD_CURRENTDATECHANGED 4
#define ARCOMMANDS_ID_COMMON_COMMONSTATE_CMD_CURRENTTIMECHANGED 5
#define ARCOMMANDS_ID_COMMON_COMMONSTATE_CMD_MASSSTORAGEINFOREMAININGLISTCHANGED 6
#define ARCOMMANDS_ID_COMMON_COMMONSTATE_CMD_WIFISIGNALCHANGED 6
#define ARCOMMANDS_ID_COMMON_COMMONSTATE_CMD_SENSORSSTATESLISTCHANGED 7
#define ARCOMMANDS_ID_COMMON_COMMONSTATE_CMD_MAX 8

// eARMEDIA_ENCAPSULER_CODEC
#define CODEC_UNKNNOWN 0
#define CODEC_VLIB 1
#define CODEC_P264 2
#define CODEC_MPEG4_VISUAL 3
#define CODEC_MPEG4_AVC 4
#define CODEC_MOTION_JPEG 5

// eARMEDIA_ENCAPSULER_FRAME_TYPE;
#define ARMEDIA_ENCAPSULER_FRAME_TYPE_UNKNNOWN 0
#define ARMEDIA_ENCAPSULER_FRAME_TYPE_I_FRAME 1
#define ARMEDIA_ENCAPSULER_FRAME_TYPE_P_FRAME 2
#define ARMEDIA_ENCAPSULER_FRAME_TYPE_JPEG 3
#define ARMEDIA_ENCAPSULER_FRAME_TYPE_MAX 4

// libARNetworkAL/Includes/libARNetworkAL/ARNETWORKAL_Manager.h
#define ARNETWORKAL_MANAGER_DEFAULT_ID_MAX 256

// eARNETWORK_MANAGER_INTERNAL_BUFFER_ID
#define ARNETWORK_MANAGER_INTERNAL_BUFFER_ID_PING 0
#define ARNETWORK_MANAGER_INTERNAL_BUFFER_ID_PONG 1
#define ARNETWORK_MANAGER_INTERNAL_BUFFER_ID_MAX 3

// eARNETWORKAL_FRAME_TYPE
#define ARNETWORKAL_FRAME_TYPE_UNINITIALIZED 0
#define ARNETWORKAL_FRAME_TYPE_ACK 1
#define ARNETWORKAL_FRAME_TYPE_DATA 2
#define ARNETWORKAL_FRAME_TYPE_DATA_LOW_LATENCY 3
#define ARNETWORKAL_FRAME_TYPE_DATA_WITH_ACK 4
#define ARNETWORKAL_FRAME_TYPE_MAX 5

// ARNETWORKAL_Frame_t identifiers
#define BD_NET_CD_NONACK_ID 10
#define BD_NET_CD_ACK_ID 11
#define BD_NET_CD_EMERGENCY_ID 12
#define BD_NET_CD_VIDEO_ACK_ID 13
#define BD_NET_DC_VIDEO_DATA_ID 125
#define BD_NET_DC_EVENT_ID 126
#define BD_NET_DC_NAVDATA_ID 127

#define BD_NET_DC_VIDEO_FRAG_SIZE 1000
#define BD_NET_DC_VIDEO_MAX_NUMBER_OF_FRAG 128

#define ARCOMMANDS_ID_ARDRONE3_CAMERA_CMD_ORIENTATION 0

#define BD_RAW_FRAME_BUFFER_SIZE 50
#define BD_RAW_FRAME_POOL_SIZE 50



class bebopCommand
{
	typedef struct{
		UINT8 type;
		UINT8 id;
		UINT8 seq;
		UINT32 size;
		UINT8 *data;

	}netFrame;

	typedef struct{
		UINT16 frameNumber;
		UINT8 frameFlags;
		UINT8 fragmentNumber;
		UINT8 fragmentPerFrame;
		UINT8 *frame;
		int frameSize;
	}streamFrame;

	typedef struct {
		UINT16 frameNumber;
		UINT8 *frameACK;
		UINT8 *frame;
		int frameSize;
		
	}arStreamFrame;

	typedef struct{
		UINT8 *cmd;
		int typeSize;
		int size;
	}command;

	typedef struct{
		UINT16 frameNumber;
		UINT8 *packetsACK;
	}ackPacket;

	typedef struct {
		UINT32 size;
		UINT8 *data;
		
	}rawFrame;

	typedef struct {
		rawFrame **freeRawFramePool;
		int rawFramePoolCapacity;
		int lastRawFrameFreeIdx;
		rawFrame **rawFrameFifo;
		int fifoReadIdx;
		int fifoWriteIdx;
	}videoDatas;

	typedef struct {
		int flag;
		int roll;
		int pitch;
		int yaw;
		int gaz;
		float psi;
	} pcmd;

	typedef struct {
		AVCodec *codec;
		AVCodecContext *codecCtx;
		AVFrame *decodedFrame;
		AVFrame *decodedFrameRBG;
		AVPacket avpkt;
		SwsContext *convertCtx;
		UINT8 *outputData;
		uchar *buffer;
		int outputDataSize;	
	}ffmpegDecoder;

	asio::ip::udp::socket d2cSocket;
	asio::ip::udp::socket c2dSocket;
	string droneIp;

private:	
	
	void generateAllStates();
	command createAck(netFrame networkFrame);
	void reciveData(const boost::system::error_code& error, std::size_t len);
	void startReceive();
	void setSendPCMDTask();
	command networkFrameGenerator(command cmd, int type = ARNETWORKAL_FRAME_TYPE_DATA, int id = BD_NET_CD_NONACK_ID);
	netFrame netFrameParser(char* frame);
	streamFrame parseStreamFrame(netFrame data);
	command createARStreamACK(streamFrame streamFrame);
	void initVideoDatas(videoDatas *datas);
	ffmpegDecoder *createFfmpegDecoder();

	void writePacket(command packet, std::string ip = "192.168.42.1");
	command createPong(netFrame networkFrame);
	void videoStreming();
	void takeOff();
	void sendPCMD();
	
	command generatePCMD();
	void initPCMD();

	//�ϐ�
	boost::array<char, 2048> recvBuffer;
	asio::ip::udp::endpoint remoteEndpoint;
	std::vector<int> seq;
	arStreamFrame _arStreamFrame;
	ffmpegDecoder *decoder;
	std::ofstream ofs;
	pcmd _pcmd;
	IplImage *img;
	
	



public:
	

	bebopCommand(string ip, int c2dPort, int d2cPort, asio::io_service& io_service);
	~bebopCommand(void);
	UINT32 toUInt32(char* byte, int index);
	UINT16 toUInt16(UINT8 *byte, int index);
	void arrayCopy(UINT8 *source, int sourceIndex, UINT8 *dest, int destIndex, int len);
	
	int handshake();
	
	
};