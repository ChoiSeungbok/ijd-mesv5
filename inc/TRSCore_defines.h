#ifndef _TRSCORE_DEFINES_H
#define _TRSCORE_DEFINES_H

// Defines //////////////////////////////////////////////////////////////////////////////////

#include <LOGCore_defines.h>

#define _TRS_NAME_SIZE              100     // TRSNODE NAME SIZE (Fixed)

#define OUT_STATUSVALUE             "STATUSVALUE"
#define OUT_MSGCODE                 "MSGCODE"
#define OUT_MSG                     "MSG"
#define OUT_MSGCATE                 "MSGCATE"
#define OUT_FIELDMSG                "FIELDMSG"
#define OUT_DBERRMSG                "DBERRMSG"

#define IN_PASSPORT                 "PASSPORT"
#define IN_LANGUAGE                 "LANGUAGE"
#define IN_FACTORY                  "FACTORY"
#define IN_USERID                   "USERID"
#define IN_PASSWORD                 "PASSWORD"
#define IN_PROCSTEP                 "PROCSTEP"
#define IN_LOGLEVEL                 "LOGLEVEL"

#define INTERNAL_MEMBER_PREFIX      "__"

#define XML_NAMESPACE_SEPARATOR     '|'

#define XML_TAG_MSG                 "MESSAGE"

#define XML_TAG_VERSION             "Version"
#define XML_MSG_NAME_TAG            "Name"

#define XML_TAG_BODY                "B"
#define XML_TAG_DATA                "D"
#define XML_TAG_LIST                "L"

#define XML_TAG_ARRAY               "A"
#define XML_TAG_ITEM                "ITM"
#define XML_TAG_ARRAYTYPE           "AT"

#define XML_TAG_NAME                "N"
#define XML_TAG_TYPE                "T"
#define XML_TAG_SIZE                "S"
#define XML_TAG_ENCRYPT             "E"
#define XML_TAG_DATEFORMAT          "DF"
#define XML_TAG_NULL                "NL"

#define XML_VALUE_TYPE_STRING       "S"
#define XML_VALUE_TYPE_CHAR         "C"
#define XML_VALUE_TYPE_BOOLEAN      "BL"
#define XML_VALUE_TYPE_BINARY       "B"
#define XML_VALUE_TYPE_UBYTE        "U1"
#define XML_VALUE_TYPE_USHORT       "U2"
#define XML_VALUE_TYPE_UINT         "U4"
#define XML_VALUE_TYPE_ULONG        "U8"
#define XML_VALUE_TYPE_FLOAT        "F4"
#define XML_VALUE_TYPE_DOUBLE       "F8"
#define XML_VALUE_TYPE_BYTE         "I1"
#define XML_VALUE_TYPE_SHORT        "I2"
#define XML_VALUE_TYPE_INT          "I4"
#define XML_VALUE_TYPE_LONG         "I8"
#define XML_VALUE_TYPE_DATETIME     "D"
#define XML_VALUE_TYPE_BLOB         "BO"

// Enumerations /////////////////////////////////////////////////////////////////////////////

typedef enum{
    EMPTY,
    ELEMENT,
    ATTRIBUTE,
    TEXT
} TRSNodeType;

typedef enum{
    MESMSG,
    HEADER,
    BODY
} XML_CURRENT_PART;

typedef enum{
    NONE,
    DATA,
    ITEM,
    LIST,
    ARRAY,
} XML_CURRENT_TAG;

// TRSNODE Value Casting Type ( TRSNode Value is void pointer type)
typedef enum{       
    DT_INT              = MP_INT,
    DT_FLOAT            = MP_FLT,
    DT_DOUBLE           = MP_DBL,
    DT_CHAR             = MP_CHR,
    DT_STRING           = MP_STR,
    DT_NSTRING          = MP_NSTR,
    DT_NOVALUESTRING    = MP_NVST,
    DT_LONG             = MP_LNG,

    DT_BOOLEAN          = 101,
    DT_BINARY           = 102,
    DT_UBYTE            = 103,
    DT_USHORT           = 104,
    DT_UINT             = 105,
    DT_ULONG            = 106,
    DT_BYTE             = 107,
    DT_SHORT            = 108,
    DT_DATETIME         = 109,
    DT_BLOB             = 110,

    DT_LIST             = 121,
    DT_ARRAY            = 122,
    DT_ITEM             = 123,

    DT_OBJECT           = 201 // Internal transfer data type. No generate xml
} TRSDataType;

#define XDT_MINT    MP_MINT   // eXtra Data Type for MINT to add field message
#define XDT_MFLT    MP_MFLT   // eXtra Data Type for MFLOAT to add field message
#define XDT_MDBL    MP_MDBL   // eXtra Data Type for MDOUBLE to add field message
#define XDT_MCHR    MP_MCHR   // eXtra Data Type for MCHAR to add field message
#define XDT_MSTR    MP_MSTR   // eXtra Data Type for MSTRING to add field message
#define XDT_MLNG    MP_MLNG   // eXtra Data Type for MLONG to add field message
#define XDT_MBOOL   MP_MBOOL  // eXtra Data Type for MBOOLEAN to add field message
#define XDT_MBIN    MP_MBIN   // eXtra Data Type for MBINARY to add field message
#define XDT_MSHT    MP_MSHT   // eXtra Data Type for MSHORT to add field message
#define XDT_MBYT    MP_MBYT   // eXtra Data Type for MBYTE to add field message
#define XDT_MUBYT   MP_MUBYT  // eXtra Data Type for MUBYTE to add field message
#define XDT_MUSHT   MP_MUSHT  // eXtra Data Type for MUSHORT to add field message
#define XDT_MUINT   MP_MUINT  // eXtra Data Type for MUINT to add field message
#define XDT_MULNG   MP_MULNG  // eXtra Data Type for MULONG to add field message
#define XDT_MDATE   MP_MDATE  // eXtra Data Type for MDATETIME to add field message

// Structs //////////////////////////////////////////////////////////////////////////////////

typedef struct TRSNODE_EXTRA_INFO
{
    char            FlexHeadFilterFlag;
    char**          Headers;
    unsigned int    HeaderCount;
} TRSNodeExtraInfo;

typedef struct TRSNODE TRSNode;

typedef struct TRSNODE_LIST
{
    char            *Name;
    int             Count;
    TRSNode**       Items;
    unsigned short  P1;
    unsigned short  P2;
    int             AC;
} TRSNodeList;

// Element TRSNode
struct TRSNODE
{
    char                    *Name;
    TRSNodeType             NodeType;
    TRSNode*                Parent;

    TRSDataType             ValueType;
    TRSDataType             ArrayType;

    union 
    {
        char                c;   // Char, Byte
        char*               s;   // String, Datetime
        unsigned char*      bo;  // Blob
        unsigned char       u1;  // Unsigned Byte, Binary
        unsigned short      u2;  // Unsigned Short
        unsigned int        u4;  // Unsigned Int
        unsigned long       u8;  // Unsigned Long
        float               f4;  // Float
        double              f8;  // Double
        short               i2;  // Short
        int                 i4;  // Int, Boolean
        long                i8;  // Long
        void*               obj; // Object
    } Value;

    unsigned int            Length;

    int                     MemberCount;
    TRSNode**               Members;
    int                     ListCount;
    TRSNodeList**           List;
    int                     SCount;
    TRSNode**               SItems;

    TRSNodeExtraInfo*       ExtraInfo;
    char                    ConvertedFromAttrFlag;
    char                    EncryptFlag;
    char                    InternalFlag;
    char                    NullFlag;

    char*                   DateTimeFormat;
    char*                   OriginDateTime;
    long                    BlobSize;
};

typedef    struct
{
    TRSNode*                Body;
    TRSNode*                Current;
    XML_CURRENT_PART        Part;    
    XML_CURRENT_TAG         Tag;    
    int                     Depth;    // XML tree depth

    char                    ValueName[_TRS_NAME_SIZE];
    TRSDataType             ArrayType;
    TRSDataType             ValueType;
    int                     ItemCount;
    TRSNode*                LastMember;
    int                     LastMemberDepth;
    char                    EncryptFlag;
    char                    NullFlag;
    char                    DateTimeFormat[100];
} ParseData;

typedef struct
{
    char*        String;
    char*        Current;
} XmlStrData;

#endif 
