/******************************************************************************************
* Copyright (C) 2000-2002 Miracom Inc.
* All rights reserved.
* For more information, please contact: Miracom Inc., Seoul, Korea
*
* File name : transceiverx.h
*
* Release : transceiverx.h	1.1 
*
* Release Information :
* 
******************************************************************************************/

#ifndef _TRANSCEIVERX_INCLUDE_
#define _TRANSCEIVERX_INCLUDE_

#include <stdio.h>

#if defined(WIN32) || defined(_WIN32_WCE)
#include <windows.h>
#endif /*	defined(WIN32) || defined(_WIN32_WCE) */

#if defined(__cplusplus)
extern "C" {
#endif

/* wild character considered types */

#if !defined(_WIDECHARACTER_CONSIDERED_TYPES)
#define _WIDECHARACTER_CONSIDERED_TYPES

#if !defined(WIN32) && !defined(_WIN32_WCE)
typedef char            TCHAR;
typedef TCHAR *         LPTSTR;
typedef const TCHAR *   LPCTSTR;
#define _T(x)           x
#endif /* !defined(WIN32) && !defined(_WIN32_WCE) */

#endif /* !defined(_WIDECHARACTER_CONSIDERED_TYPES) */

/* primitive type definitions by bit length */

#if !defined(_BITLENGTH_SPECIFIED_TYPES)
#define _BITLENGTH_SPECIFIED_TYPES

typedef char        Int8;
typedef short       Int16;
typedef int         Int32;

#if defined(WIN32) || defined(_WIN32_WCE)
typedef LONGLONG	Int64;
#else
typedef long long   Int64;
#endif /*	defined(WIN32) || defined(_WIN32_WCE) */

typedef float       Float32;
typedef double      Float64;

typedef Int32       Bool32;

#define False32     0
#define True32      (!False32)

#define Null_Ptr    ((void*)0x0)
#define Nul_Value   (0x0)

#endif /* !defined(_BITLENGTH_SPECIFIED_TYPES) */

#if defined(WIN32) || defined(_WIN32_WCE)
#else
typedef unsigned char byte;
#endif /* defined(WIN32) || defined(_WIN32_WCE) */

/* one-o-one specific definitions */

#define DT_NONE						0x00
#define	DT_UNICAST  				0x01
#define	DT_MULTICAST  				0x02
#define	DT_REQUEST  				0x03
#define	DT_REPLY  					0x04
#define	DT_GUARANTEED_UNICAST 		0x05
#define	DT_GUARANTEED_MULTICAST  	0x06

#define DT_GUARANTEED_CONFIRM_FLAG	0x10


#define	SESSION_DISPATCH_MODE_FLAG			0x01
#define	SESSION_DOMAIN_MODE_FLAG			0x02

#define SESSION_MODE_DISPATCH_PUSH			0x00
#define SESSION_MODE_DISPATCH_PULL			0x01
#define SESSION_MODE_DOMAIN_INTER_STATION	0x00
#define SESSION_MODE_DOMAIN_INNER_STATION	0x02

/* one-o-one specific types */

typedef int IOIStatus;

typedef void*        IOIHandle;
typedef IOIHandle    IOISession;
typedef IOIHandle    IOIMessage;
typedef IOIHandle    IOITimer;
typedef IOIHandle    IOIMap;

typedef IOIHandle    HTransformer;
typedef IOIHandle    HInputStream;
typedef IOIHandle    HOutputStream;
typedef IOIHandle    HStreamBuffer;

#if defined(WIN32) || defined(_WIN32_WCE)
#include "windows.h"
#include "winsock.h"
#else
#define SOCKET	int
#endif /* defined(WIN32) || defined(_WIN32_WCE) */

/* Callback functions prototype */

typedef void (*IOIOnTrace)(int code, IOIHandle issuer, void* arg1, void* arg2, LPCTSTR desc );
typedef void (*IOIOnReceive)(IOIHandle issuer, IOIMessage receive);
typedef void (*IOIOnReply)(IOIHandle issuer, IOIMessage request, IOIMessage reply, void* hint);
typedef void (*IOIOnTimeout)(IOIHandle issuer, IOIMessage request, void* hint);
typedef void (*IOIOnManagement)(int code, void* content, void* hint);
typedef void (*IOITimerHandler)(IOITimer timer);
typedef void (*IOIOnConnect)(IOIHandle issuer);
typedef void (*IOIOnDisconnect)(IOIHandle issuer);

/* Global functions for Initialization ,Termination & etc */

IOIStatus 	IOIInit( LPCTSTR process_name , unsigned short port );
IOIOnTrace	IOISetTraceHandler(IOIOnTrace ontrace);
IOIStatus 	IOITerm(void);
IOIStatus 	IOISetProcessName(LPCTSTR name);
LPCTSTR	  	IOIGetProcessName();
LPCTSTR   	IOIErrorLookup(int error);
int       	IOIGetLastError();
void      	IOISetLastError(int error);

/* Timer management */

IOITimer	IOITimerCreate(long interval, Bool32 repeat, IOITimerHandler handler);
void		IOITimerDestroy(IOITimer timer);
void		IOITimerSetInterval(IOITimer timer, long interval);
void		IOITimerSetRepeat(IOITimer timer, Bool32 repeat);
void		IOITimerSetHandler(IOITimer timer, IOITimerHandler handler);

/* Functions for Session management */

IOISession 	IOISessionCreate(LPCTSTR session_id, int mode);
IOIStatus	IOISessionDestroy(IOISession session);
IOISession	IOISessionCreateEx( LPCTSTR session_id, int mode, LPCTSTR connect_string );
IOIStatus	IOISessionDestroyEx(IOISession session);

IOIStatus	IOISessionSetBindAddress(IOISession session, LPCTSTR bindaddr);
void		IOISessionSetDefaultTimeToLive(IOISession session, long ttl);
void   		IOISessionSetAutoRecoveryCount(IOISession session, int count);

IOIOnReceive	IOISessionSetGMulticastHandler(IOISession session, IOIOnReceive ondata);
IOIOnReceive	IOISessionSetGUnicastHandler(IOISession session, IOIOnReceive ondata);

IOIOnReceive	IOISessionSetMulticastHandler(IOISession session, IOIOnReceive ondata);
IOIOnReceive	IOISessionSetUnicastHandler(IOISession session, IOIOnReceive ondata);
IOIOnReceive	IOISessionSetRequestHandler(IOISession session, IOIOnReceive ondata);

IOIOnManagement IOISetManagementHandler(IOIOnManagement onmanage);
IOIOnReply	IOISessionSetReplyHandler(IOISession session, IOIOnReply onreply);
IOIOnTimeout	IOISessionSetTimeoutHandler(IOISession session, IOIOnTimeout ontimeout);
IOIOnConnect	IOISessionSetConnectHandler( IOISession session, IOIOnConnect onconnect);
IOIOnDisconnect IOISessionSetDisconnectHandler( IOISession session, IOIOnDisconnect ondisconnect);

Bool32		IOISessionIsConnected( IOISession session );
IOIStatus	IOISessionConnect(IOISession session, LPCTSTR connect_string);
IOIStatus	IOISessionDisconnect(IOISession session);

IOIStatus	IOISessionCreateLocalQueue( IOISession session, LPTSTR path, LPTSTR queueName, Bool32 autoDelivery );
void		IOISessionDestroyLocalQueue( IOISession session );

IOIStatus	IOITuneMulticast(IOISession session, LPCTSTR channel);
IOIStatus	IOITuneUnicast(IOISession session, LPCTSTR channel);
IOIStatus	IOITuneGuaranteedMulticast(IOISession session, LPCTSTR queue);
IOIStatus	IOITuneGuaranteedUnicast(IOISession session, LPCTSTR queue);
IOIStatus	IOIUntuneMulticast(IOISession session, LPCTSTR channel);
IOIStatus	IOIUntuneUnicast(IOISession session, LPCTSTR channel);
IOIStatus	IOIUntuneGuaranteedMulticast(IOISession session, LPCTSTR queue);
IOIStatus	IOIUntuneGuaranteedUnicast(IOISession session, LPCTSTR queue);

IOIStatus	IOISendMessage(IOISession session, IOIMessage message);

IOIStatus	IOISendUnicast(IOISession session, IOIMessage message);
IOIStatus	IOISendMulticast(IOISession session, IOIMessage message);
IOIStatus	IOISendRequestAsync(IOISession session, IOIMessage message, void* hint);
IOIMessage	IOISendRequest(IOISession session, IOIMessage message);
IOIStatus	IOISendReply(IOISession session, IOIMessage request, IOIMessage reply);
IOIStatus 	IOISendGuaranteedMulticast(IOISession session, LPCTSTR queue, IOIMessage message);
IOIStatus 	IOISendGuaranteedUnicast(IOISession session, LPCTSTR queue, IOIMessage message);
IOIStatus	IOISendConfirm(IOISession session, IOIMessage message, Bool32 confirm);

Bool32		IOIMessageConfirmRequired( IOIMessage message );
Bool32		IOIMessageIsAutoConfirmMessage( IOIMessage message );
Bool32		IOIMessageIsGuaranteedMessage( IOIMessage message );
IOIMessage	IOIGetMessage(IOISession session, long wait);

/*20050320 add*/
IOIStatus	IOISharedInit(LPCTSTR session_name , LPCTSTR connect_string);
IOIStatus	IOISharedTerm(void);
IOIMessage	IOISharedSendRequest(IOIMessage message);
void *		IOISharedSendRequestFlat(int sentinel, LPCTSTR request_message, LPCTSTR channel, long ttl, long *reply_length, int *rtn_code, IOIMessage *reply_message);

/* Functions for Message management */

#define IOIZ_NO_COMPRESSION         0
#define IOIZ_BEST_SPEED             1
#define IOIZ_BEST_COMPRESSION       9
#define IOIZ_DEFAULT_COMPRESSION  (-1)

Bool32 IOIMessageIsCompressMode( IOIMessage msg );

IOIMessage	IOIMessageCreate(void);
void		IOIMessageDestroy( IOIMessage message );
IOIMessage	IOIMessageCreateReply(IOIMessage request);

long		IOIMessageAddRef(IOIMessage message);
long		IOIMessageRelease(IOIMessage message);
long 		IOIMessageReleaseSAFE(int sentinels, IOIMessage message, int sentinele);

LPCTSTR		IOIMessageGetCreator(IOIMessage message);

long		IOIMessageGetID(IOIMessage message);
LPCTSTR		IOIMessageGetChannel(IOIMessage message);
void*		IOIMessageGetData(IOIMessage message, int* length);
long		IOIMessageGetTTL(IOIMessage message);
int			IOIMessageGetEncodingType(IOIMessage message);
int			IOIMessageGetCompressMode(IOIMessage message);
IOIMessage	IOIMessageGetCorrelation(IOIMessage message);

void		IOIMessageSetDelivery(IOIMessage message, int mode); /* unicast, multicast, request, reply */

void		IOIMessageSetID(IOIMessage message, long setid);
void		IOIMessageSetChannel(IOIMessage message, LPCTSTR channel);
void		IOIMessageSetQueue(IOIMessage message, LPCTSTR queue);
void		IOIMessageSetData(IOIMessage message, void* data, int length);
void		IOIMessageSetDataStream(IOIMessage message, HStreamBuffer streamBuffer);

void		IOIMessageSetTTL(IOIMessage message, long ttl);
void		IOIMessageSetEncodingType(IOIMessage message, long type);
void		IOIMessageSetCompressMode(IOIMessage message, long mode);
void		IOIMessageSetCorrelation(IOIMessage message, IOIMessage corr);

int			IOIMessageGetDelivery(IOIMessage message); /* unicast, multicast, request, reply */

int 		IOIMessageGetInfoSize(IOIMessage message);

IOIStatus 	IOIMessageGetInfoKey(IOIMessage message, int index, LPTSTR* key, int* type);

IOIStatus 	IOIMessageGetCharInfo(IOIMessage message, LPCTSTR key, short* value);
IOIStatus 	IOIMessageGetByteInfo(IOIMessage message, LPCTSTR key, char* value);
IOIStatus 	IOIMessageGetShortInfo(IOIMessage message, LPCTSTR key, short* value);
IOIStatus 	IOIMessageGetLongInfo(IOIMessage message, LPCTSTR key, long* value);
IOIStatus 	IOIMessageGetFloatInfo(IOIMessage message, LPCTSTR key, float* value);
IOIStatus 	IOIMessageGetDoubleInfo(IOIMessage message, LPCTSTR key, double* value);

IOIStatus 	IOIMessageGetStringInfo(IOIMessage message, LPCTSTR key, short* len, LPTSTR* value);
IOIStatus 	IOIMessageGetBytesInfo(IOIMessage message, LPCTSTR key, short* len, char** value);
IOIStatus 	IOIMessageGetShortsInfo(IOIMessage message, LPCTSTR key, short* len, short** value);
IOIStatus 	IOIMessageGetLongsInfo(IOIMessage message, LPCTSTR key, short* len, long** value);
IOIStatus 	IOIMessageGetFloatsInfo(IOIMessage message, LPCTSTR key, short* len, float** value);
IOIStatus 	IOIMessageGetDoublesInfo(IOIMessage message, LPCTSTR key, short* len, double** value);

IOIStatus 	IOIMessageAddCharInfo(IOIMessage message, LPCTSTR key, short value);
IOIStatus 	IOIMessageAddByteInfo(IOIMessage message, LPCTSTR key, char value);
IOIStatus 	IOIMessageAddShortInfo(IOIMessage message, LPCTSTR key, short value);
IOIStatus 	IOIMessageAddLongInfo(IOIMessage message, LPCTSTR key, long value);
IOIStatus 	IOIMessageAddFloatInfo(IOIMessage message, LPCTSTR key, float value);
IOIStatus 	IOIMessageAddDoubleInfo(IOIMessage message, LPCTSTR key, double value);

IOIStatus 	IOIMessageAddStringInfo(IOIMessage message, LPCTSTR key, short len, LPCTSTR value);
IOIStatus 	IOIMessageAddBytesInfo(IOIMessage message, LPCTSTR key, short len, char* value);
IOIStatus 	IOIMessageAddShortsInfo(IOIMessage message, LPCTSTR key, short len, short* value);
IOIStatus 	IOIMessageAddLongsInfo(IOIMessage message, LPCTSTR key, short len, long* value);
IOIStatus 	IOIMessageAddFloatsInfo(IOIMessage message, LPCTSTR key, short len, float* value);
IOIStatus 	IOIMessageAddDoublesInfo(IOIMessage message, LPCTSTR key, short len, double* value);

IOIStatus 	IOIMessageRemoveInfo(IOIMessage message, LPCTSTR key);
/*message trace*/
void		IOIMessageTracePrint( LPCTSTR title , IOIMessage msg );

/* Functions for Utility (MAP) */

IOIMap    	IOIMapCreate();
void    	IOIMapDestroy(IOIMap q);
void*   	IOIMapGet(IOIMap q, LPTSTR key_name );
int         IOIMapAdd(IOIMap q, LPTSTR pkey_name , void* item, Int32 type );
int         IOIMapRemove(IOIMap q, LPTSTR key_name );
void    	IOIMapRemoveAll(IOIMap q);
int         IOIMapGetSize(IOIMap q);


/*IOIStatus old type define*/
/* Status values returned by IOI Functions */

#define IOI_SUCCESS							0x00
#define IOI_UNDEFINED_ERROR					0x00
#define IOI_ERROR_MESSAGE_BEGIN				-0x01
#define IOISS_E_CREATE_SESSION_FAIL			-0x01
#define IOISS_E_INVALID_CONNECTSTRING 		-0x02
#define IOISS_E_NOT_SESSION					-0x03
#define IOISS_E_CHANNEL_NOT_EXIST			-0x04
#define IOISS_E_CHANNEL_DUPLICATED			-0x05
#define IOIRQ_E_NOT_REQUEST					-0x06
#define IOICH_E_INVALID_CHANNELID			-0x07
#define IOICH_E_ID_TOO_LONG					-0x08
#define IOISS_E_SESSION_DESTROIED			-0x09
#define IOI_E_NULL_POINTER					-0x0A
#define IOIRQ_E_SYNC_REQUEST_TIMEDOUT		-0x0B
#define IOI_E_ALREADY_INITIALIZED			-0x0C
#define IOI_E_NOT_INITIALIZED				-0x0D
#define IOI_E_ALLOC_TLS_FAILED				-0x0E
#define IOI_E_HOME_NOT_DEFINED				-0x0F
#define IOI_E_INFORMATION_NOT_FOUND			-0x10
#define IOI_E_INFORMATION_TYPE_NOT_MATCH	-0x11
#define IOI_E_INFORMATION_KEY_DUPLICATE		-0x12
#define IOI_E_OUT_OF_BOUNDS					-0x13
#define IOI_E_INFO_ALLOCATION_FAIL			-0x14
#define	IOIRQ_E_NULL_MESSAGE				-0x15
#define	IOI_E_NOT_DIRECTORY					-0x16
#define IOI_E_LOCAL_STATION_NOT_FOUND		-0x17
#define IOIMF_E_NOT_INITIALIZED				-0x18
#define IOIMF_E_FAIL_EXIT					-0x19
#define IOIACK_E_NULL_MESSAGE				-0x1A
#define IOIACK_E_INVALID_MESSAGE			-0x1B /**/
#define IOIACK_E_INITIALIZED				-0x1C
#define IOIZ_COMPRESS_FAIL					-0x1D
#define IOIX_E_CHANNEL_NOTFOUND_TUNER		-0x1E
#define IOI_E_PUT_QUEUE_MESSAGE				-0x1F
#define IOI_ERROR_MESSAGE_QUEUE				-0x20
#define IOI_E_PROPERTY_SETTING				-0x21
#define IOI_E_NOT_PING_MESSAGE				-0x22
#define IOI_ERROR_CONNECTION_FAILED			-0x23
#define IOI_ERROR_MESSAGE_END				-0x24
#define IOI_ERROR_NOT_QUEUE					0x1CD
/* Status new values returned by IOI Functions */

#define IOIX_SUCCESS						0x00

#define IOIX_ERROR_MESSAGE_BEGIN			( -1000 )
#define IOIX_MESSAGE_BEGIN					IOIX_ERROR_MESSAGE_BEGIN
#define IOIX_FAIL							( IOIX_MESSAGE_BEGIN - 1 )
#define IOIX_WAIT_TIMEOUT					( IOIX_MESSAGE_BEGIN - 2 )
#define IOIX_E_SESSION_INVALID				( IOIX_MESSAGE_BEGIN - 3 )
#define IOIX_E_SESSION_NULL					( IOIX_MESSAGE_BEGIN - 4 )
#define IOIX_E_SESSION_ID_DUPLICATED		( IOIX_MESSAGE_BEGIN - 5 )
#define IOIX_E_SESSION_WRONG_FUNCTION_CALL	( IOIX_MESSAGE_BEGIN - 6 )
#define IOIX_E_CHANNEL_INVALID				( IOIX_MESSAGE_BEGIN - 7 )
#define IOIX_E_CHANNEL_DUPLICATED			( IOIX_MESSAGE_BEGIN - 8 )
#define IOIX_E_MESSAGE_INVALID				( IOIX_MESSAGE_BEGIN - 9 )
#define IOIX_E_MESSAGE_NULL					( IOIX_MESSAGE_BEGIN - 10 )

#define IOIX_INFO_MESSAGE_BEGIN				( -5000 )		

#define IOIX_MAX_LIMIT						( -1000  )
#define IOIX_MIN_LIMIT						( -10000 )

#if defined(WIN32) || defined(_WIN32_WCE)
HANDLE IOIGetSessionInterface( IOISession session );
void IOISetSessionInterface( IOISession session , HANDLE pinterface );

HANDLE	IOIGetMessageInterface( IOIMessage message );
void	IOISetMessageInterface( IOIMessage message , HANDLE pinterface );

#endif /* defined(WIN32) && !defined(_WIN32_WCE) */


/* Ix primitive type */
#define		IX_NULL				0
#define		IX_BYTE				1
#define		IX_SHORT			2
#define		IX_INT				3
#define		IX_LONG				4
#define		IX_FLOAT			5
#define		IX_DOUBLE			6
#define		IX_STRING			7
#define		IX_BYTE_ARRAY		8
#define		IX_SHORT_ARRAY		9
#define		IX_INT_ARRAY		10
#define		IX_LONG_ARRAY		11
#define		IX_FLOAT_ARRAY		12
#define		IX_DOUBLE_ARRAY		13
#define		IX_STRING_ARRAY		14
#define		IX_ENUM				15
#define		IX_MAP				16
#define		IX_OBJECT			17
#define		IX_MAX				18

#define SIZE_OF_IX_BYTE		sizeof( byte )
#define SIZE_OF_IX_SHORT	sizeof( Int16 )
#define SIZE_OF_IX_INT		sizeof( Int32 )
#define SIZE_OF_IX_LONG		sizeof( Int64 )
#define SIZE_OF_IX_FLOAT	sizeof( Float32 )
#define SIZE_OF_IX_DOUBLE	sizeof( Float64 )

typedef char	IX_TYPE;


typedef struct tagIxBtree *			HBTREE;
typedef struct tagIxBtree_node * 	HBTREENODE;
typedef struct tagIxBtree			IxBtree;
typedef struct tagIxBtree_node		IxBtree_node;

typedef struct tagIxArray			IxArray;
typedef struct tagIxBtree * 		IxMap;

typedef struct tagIxObject			IxObject;
typedef struct tagIxObject			IxComparable;

struct tagIxArray
{
	Int32		cnt;
	IX_TYPE		type;
	void	*	pval;
};

struct tagIxObject
{
	IX_TYPE		type;
	union tagValue
	{
		byte		vbyte;
		Int16		vshort;
		Int32		vint;
		Int64		vlong;
		Float32		vfloat;
		Float64		vdouble;
		TCHAR *		vstring;
		IxArray		varray;
		IxMap		vmap;
		void	*	pvobject;
	} v;
};

typedef Int32 (*fdef_IxCompare)( IxComparable , IxComparable );

struct tagIxBtree 
{
	IxBtree_node*	head;
	Int32			size;
	fdef_IxCompare	compare;
};

struct tagIxBtree_node
{
	IxBtree_node*		bigger;
	IxBtree_node*		smaller;
	IxComparable		key;
	IxObject			item;
};



/*transdata*/

#define E_PARSE_PARAMETER_ERROR	-1
#define PARSE_SUCCESS		0
#define E_PARSE_TYPE		1
#define E_PARSE_SCANBYTE	2
#define E_PARSE_BYTE		3
#define E_PARSE_SHORT		5
#define E_PARSE_INT			6
#define E_PARSE_LONG		7
#define E_PARSE_FLOAT		8
#define E_PARSE_DOUBLE		9
#define E_PARSE_STRING		10
#define E_PARSE_ARRAY		11
#define E_PARSE_MAP			20
#define E_PARSE_OBJECT		30


IxArray	array_null();
Bool32	array_create( IxArray * pba , IX_TYPE type , void * pdata , Int32 size );
Bool32	array_destroy( IxArray * ba );
Bool32	object_destroy( IxObject * obj );

Float64 array_getdouble( IxArray * pba , Int32 index );

void transformer_printMsgMap( TCHAR * name , IxMap value );
void transformer_printMsgObject( IxObject * key , IxObject * item );
/* object */

IxObject object_null();
Bool32 object_is_null( IxObject * obj );
Bool32 object_replace( IxObject * pdest , IxObject * psrc );

IxObject	object_create_byte( byte b );
IxObject	object_create_short( Int16 b );
IxObject	object_create_int( Int32 b );
IxObject	object_create_long( Int64 b );
IxObject	object_create_float( Float32 b );
IxObject	object_create_double( Float64 b );
IxObject	object_create_string( TCHAR * b );
IxObject	object_create_array( IxArray b );
IxObject	object_create_map( IxMap b );
IxObject	object_create_string2( TCHAR * b );
IxObject	object_create_array2( IxArray b );
IxObject	object_create_map2( IxMap b );

IxObject	object_create_pvoid( void * b , Int32 size );

HTransformer	CreateWriteTransformer	( HOutputStream output );
HTransformer	CreateReadTransformer	( HInputStream in );
HTransformer	CreateByteTransformer	( IxArray * pixarray );
HTransformer	CreateMessageTransformer ( IOIMessage message );

Bool32			DestroyTransformer		( HTransformer hixt );
Bool32			DestroyMessageTransformer( HTransformer hixt );
int TransformerGetLastError( HTransformer htransformer );

HStreamBuffer	CreateStreamSocketBuffer	( SOCKET s );
HStreamBuffer	CreateStreamFileBuffer		( FILE * f );
HStreamBuffer	CreateStreamByteBuffer		( IOIHandle hint , IX_TYPE type , Int32 capacity , Int16 growth , Int32 array_capacity );

Bool32			DestroyStreamBuffer			( HStreamBuffer hstreambuffer );
IxArray			StreamBuffer_GetBytes		( HStreamBuffer hstreambuffer );
void*			StreamBuffer_GetBinary		( HStreamBuffer hstreambuffer );
int				StreamBuffer_GetSize		( HStreamBuffer hstreambuffer );
IX_TYPE			StreamBuffer_GetType		( HStreamBuffer hstreambuffer );

HOutputStream	CreateOutputStream			( HStreamBuffer hstreambuffer );
Bool32			DestroyOutputStream			( HOutputStream houtputstream );

HInputStream	CreateInputStream		( HStreamBuffer pstreambuffer );
HInputStream	CreateSocketInputStream	( HStreamBuffer pstreambuffer , SOCKET s );
HInputStream	CreateFileInputStream	( HStreamBuffer pstreambuffer , FILE * f );
Bool32			DestroyInputStream		( HStreamBuffer pinputstream );


void WriteMsgByte		( HTransformer hixt , byte value );
void WriteMsgShort		( HTransformer hixt , Int16 value );
void WriteMsgInt		( HTransformer hixt , Int32 value );
void WriteMsgLong		( HTransformer hixt , Int64 value );
void WriteMsgLong2		( HTransformer hixt , Int32 value );
void WriteMsgFloat		( HTransformer hixt , Float32 value );
void WriteMsgDouble		( HTransformer hixt , Float64 value );
void WriteMsgString		( HTransformer hixt , TCHAR * value );
void WriteMsgSizedString( HTransformer hixt , TCHAR * value , Int32 size );
void WriteMsgArray		( HTransformer hixt , IxArray * value );
void WriteMsgMap		( HTransformer hixt , IxMap value );
void WriteMsgNull		( HTransformer hixt );
void WriteMsgObject		( HTransformer hixt , IxObject * value );
void WriteMsgBoolean	( HTransformer hixt , Bool32 value);
void WriteMsgBinary		( HTransformer hixt , byte * value , Int32 len);
void WriteMsgStackArray ( HTransformer hixt , byte * value , Int32 len );
void WriteMsgChar		( HTransformer hixt , char value );

byte		ReadMsgByte		( HTransformer hixt );
Int16		ReadMsgShort	( HTransformer hixt );
Int32		ReadMsgInt		( HTransformer hixt );
Int64		ReadMsgLong		( HTransformer hixt );
Int32		ReadMsgLong2	( HTransformer hixt );
Float32		ReadMsgFloat	( HTransformer hixt );
void		ReadMsgFloat2	( HTransformer hixt , Float32 *pOut);
Float64		ReadMsgDouble	( HTransformer hixt );
TCHAR *		ReadMsgString	( HTransformer hixt );
void *		ReadMsgString2	( HTransformer hixt );
Int32		ReadMsgStringParam	( HTransformer hixt , TCHAR * param , Int32 len );
Int32		ReadMsgSizedString( HTransformer hixt , TCHAR * param , Int32 size );
Int32		ReadMsgStringPadding( HTransformer hixt , TCHAR * param , Int32 len , int padding_char );
IxArray		ReadMsgArray	( HTransformer hixt );
IxMap		ReadMsgMap		( HTransformer hixt );
void		ReadMsgNull		( HTransformer hixt );
IxObject	ReadMsgObject	( HTransformer hixt );
Bool32		ReadMsgBoolean	( HTransformer hixt );
byte *		ReadMsgBinary	( HTransformer hixt , Int32 *len );
Int32		ReadMsgBinaryParam( HTransformer hixt , byte * param , Int32 len );		
void		ReadMsgStackArray( HTransformer hixt , byte *outval , Int32 len );
char		ReadMsgChar		( HTransformer hixt );

typedef int (*PARSE_CALLBACK)( HTransformer htransformer , Int32 error , void * hint );
PARSE_CALLBACK IOIParseErrorCallback( PARSE_CALLBACK error_parse );

IxArray		IOIMessageGetDataArray( IOIMessage msg );
void		IOIFree( void* pVal );
TCHAR *		GetStringFromLong( void * pValue );

/* Table transformer */

typedef struct vector_node vector_node;

struct vector_node {
	vector_node*	prev;
	vector_node*	next;
	void*	item;
};

typedef struct vector vector;

struct vector {
	vector_node* head;
	vector_node* tail;
	unsigned int size;
};

vector* vector_create();
void vector_destroy(vector* v);
void* vector_get(vector* v, unsigned int idx);
vector_node* vector_put(vector* v, unsigned int pos, void* item);
vector_node* vector_add(vector* v, void* item);
void* vector_remove(vector* v, vector_node* node);
void* vector_remove_at(vector* v, unsigned int idx);
void vector_remove_all(vector* v);
unsigned int vector_size(vector* v);

#define TYPE_BYTE		0
#define TYPE_CHAR		1
#define TYPE_SHORT	2
#define TYPE_INT		3
#define TYPE_LONG		4
#define TYPE_FLOAT	5
#define TYPE_DOUBLE	6
#define TYPE_STRING	7
#define TYPE_BYTES	8

#define TABLE_COLUMN_NAME_MAX 64

struct TableTransformer {
  vector *column;
  vector *records;
};

struct  ColumnInformation {
	TCHAR name[TABLE_COLUMN_NAME_MAX];
	short type;
	IxObject *data;
};

struct TableRecord {
	vector *column;
	vector *data;
};
  
typedef struct TableTransformer TableTransformer;
typedef struct TableRecord TableRecord;
typedef struct ColumnInformation ColumnInformation;

/**
 * create table transformer
 */
TableTransformer* TableTransformer_create(void);
/**
 * add column to table transformer
 */
void TableTransformer_putColumn(TableTransformer* table, TCHAR* name, short type, void *data);
/**
 * create table record from table transformer
 */
TableRecord* TableTransformer_createRecord(TableTransformer* table);
/**
 * add record to transformer
 */
void TableTransformer_addRecord(TableTransformer *table, TableRecord *record);
/* get record count */
Int32 TableTransformer_getRecordCount(TableTransformer *table);
/**
 * get a record from table transformer at index
 */
TableRecord *TableTransformer_getRecord(TableTransformer *table, int index);
/**
 * build table transformer from data array
 */
void TableTransformer_parseData(TableTransformer *table, IOIMessage msg);
/**
 * get stream transformer from table transformer
 */
HTransformer TableTransformer_getStreamTransformer(TableTransformer *table);
/**
 * get bytes(IxArray) from table transformer
 */
void TableTransformer_getBytes(TableTransformer *table, IOIMessage msg);
/**
 * get column label from table transformer
 */
TCHAR* TableTransformer_getColumn(TableTransformer *table, int index);
/**
 * get comumn size from table transformer
 */
int TableTransformer_getColumnCount(TableTransformer *table);
/**
 * destroy table transformer (free allocated memory)
 */
void TableTransformer_destroy(TableTransformer *table);
/**
 * create column information (record meta) 
 */
ColumnInformation* ColumnInformation_create();
/**
 * destroy column information
 */
void ColumnInformation_destroy(ColumnInformation*);

/**
 * TableRecord class
 */
TableRecord* TableRecord_create(TableTransformer *table);
void TableRecord_addByte(TableRecord* record, byte value);
void TableRecord_addChar(TableRecord* record, TCHAR value);
void TableRecord_addShort(TableRecord* record, Int16 value);
void TableRecord_addInt(TableRecord* record, Int32 value);
void TableRecord_addLong(TableRecord* record, Int64 value);
void TableRecord_addFloat(TableRecord* record, Float32 value);
void TableRecord_addDouble(TableRecord* record, Float64 value);
void TableRecord_addString(TableRecord* record, TCHAR* value);
void TableRecord_addBytes(TableRecord* record, byte *value, Int32 len);

byte TableRecord_getByte(TableRecord* record, int index);
TCHAR TableRecord_getChar(TableRecord* record, int index);
Int16 TableRecord_getShort(TableRecord* record, int index);
Int32 TableRecord_getInt(TableRecord* record, int index);
Int64 TableRecord_getLong(TableRecord* record, int index);
Float32 TableRecord_getFloat(TableRecord* record, int index);
Float64 TableRecord_getDouble(TableRecord* record, int index);
TCHAR* TableRecord_getString(TableRecord* record, int index);
Int32 TableRecord_getBytes(TableRecord* record, int index, byte* buff);

void CreatePing(void* session);
void* SetHolder(void* hold);
void* SetPing();
void* SetPong();
void* onconnected();

void Set_fallbackToPrimary(Bool32 flag);
void Set_autoReconnect(Bool32 flag);
void Set_resendOnError(Bool32 flag);
void Set_pingTimeout(Int32 time);
void Set_pingInterval(Int32 time);
Bool32 Get_fallbackToPrimary();
Bool32 Get_autoReconnect();
Bool32 Get_resendOnError();
Bool32 Get_pingTimeout();
Bool32 Get_pingInterval();


#ifdef  __cplusplus
}
#endif

#endif /* _TRANSCEIVERX_INCLUDE_ */
