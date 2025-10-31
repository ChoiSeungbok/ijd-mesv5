#ifndef _EDC_XML_PARSER
#define _EDC_XML_PARSER

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAX_TAG_NAME_LENGTH     128
#define MAX_ATTRIBUTE_COUNT     32

enum
{
    XML_SUCCESS = 0,
    XML_ERR,
    XML_NO_INSTANCE,
    XML_NO_DATA,
    XML_TAG_NOT_COMPLETE,
    XML_NOT_WELL_FORMED,

    //element type
    XML_START_DOCUMENT,
    XML_END_DOCUMENT,
    XML_START_ELEMENT,
    XML_END_ELEMENT,
    XML_CHARACTERS,
    XML_COMMENT,
    XML_NONE_ELEMENT

};

// EDC Structure

#define XML_TAG_PROPERTY    ("PROPERTY")
#define XML_TAG_ANAME       ("NAME")
#define XML_TAG_VALUE       ("VALUE")
#define XML_TAG_COLSET      ("COLSET")
#define XML_TAG_CHARACTER   ("CHARACTER")
#define XML_TAG_UNIT        ("UNIT")
#define XML_TAG_EDC         ("EDC")
#define XML_TAG_ATYPE       ("TYPE")

typedef struct _EDCDataSet_Col_Char_Unit_Value
{
    int value_seq;
    char data_value[25];
    struct _EDCDataSet_Col_Char_Unit_Value *pEDCDataSet_Col_Char_Unit_Value_Next;
} EDCDataSet_Col_Char_Unit_Value;

typedef struct _EDCDataSet_Col_Char_Unit
{
    int unit_seq;
    char unit_id[25];
    char value_type;
    int value_count;
    EDCDataSet_Col_Char_Unit_Value *pEDCDataSet_Col_Char_Unit_Value_Top;
    struct _EDCDataSet_Col_Char_Unit *pEDCDataSet_Col_Char_Unit_Next;
} EDCDataSet_Col_Char_Unit;

typedef struct _EDCDataSet_Col_Char
{
    int char_seq;
    char char_id[25];
    int unit_count;
    EDCDataSet_Col_Char_Unit *pEDCDataSet_Col_Char_Unit_Top;
    struct _EDCDataSet_Col_Char *pEDCDataSet_Col_Char_Next;
} EDCDataSet_Col_Char;

typedef struct _EDCDataSet_Col
{
    int col_set_seq;
    char col_set_id[25];
    int col_set_version[3];
    int char_count;
    EDCDataSet_Col_Char *pEDCDataSet_Col_Char_Top;
    struct _EDCDataSet_Col *pEDCDataSet_Col_Next;
} EDCDataSet_Col;

typedef struct _EDCDataSet_Property
{
    int property_seq;
    char property_name[MAX_TAG_NAME_LENGTH];
    char property_value[MAX_TAG_NAME_LENGTH];
    struct _EDCDataSet_Property *pEDCDataSet_Property_Next;
} EDCDataSet_Property;

typedef struct _EDCDataSet
{
    char s_edc_type[10];
    char s_sys_time[14];
    char s_lot_id[25];
    char s_oper[10];
    char s_meas_res_id[20];
    char s_proc_res_id[20];
    char s_recipe_id[25];
    int i_recipe_version;
    char s_meas_comment[100];
    char s_start_date[30];
    char s_end_date[30];
    char s_bin_group[30];
    char s_test_id[25];
    char cur_tag[MAX_TAG_NAME_LENGTH];
    int property_count;
    EDCDataSet_Property *pEDCDataSet_Property_Top;
    int colset_count;
    EDCDataSet_Col *pEDCDataSet_Col_Top;
    // Current Information
    EDCDataSet_Property *pEDCDataSet_Property_Cur;
    EDCDataSet_Col *pEDCDataSet_Col_Cur;
    EDCDataSet_Col_Char *pEDCDataSet_Col_Char_Cur;
    EDCDataSet_Col_Char_Unit *pEDCDataSet_Col_Char_Unit_Cur;
    EDCDataSet_Col_Char_Unit_Value *pEDCDataSet_Col_Char_Unit_Value_Cur;

} EDCDataSet;

extern EDCDataSet* CreateEDCDataSet();
extern void DestroyEDCDataSet(EDCDataSet *pEDCDataSet);
extern int GetPropertyByName(EDCDataSet *pEDCDataSet, char* sName, char* sData);
extern int GetPropertyBySeq(EDCDataSet *pEDCDataSet, int iSeq, char* sData);
extern EDCDataSet_Col* GetColSetByName(EDCDataSet *pEDCDataSet, char* sName);
extern EDCDataSet_Col* GetColSetBySeq(EDCDataSet *pEDCDataSet, int iSeq);
extern EDCDataSet_Col_Char* GetCharacterBySeq(EDCDataSet_Col *pColSet, int iSeq);
extern EDCDataSet_Col_Char* GetCharacterByName(EDCDataSet_Col *pColSet, char *sName);
extern EDCDataSet_Col_Char* GetCharacterByColSet(EDCDataSet_Col *pColSet, int iCharSeq);
extern EDCDataSet_Col_Char_Unit* GetUnitBySeq(EDCDataSet_Col_Char *pCharacter, int iSeq);
extern EDCDataSet_Col_Char_Unit* GetUnitByColSet(EDCDataSet_Col *pColSet, int iCharSeq, int iUnitSeq);
extern EDCDataSet_Col_Char_Unit_Value* GetValueBySeq(EDCDataSet_Col_Char_Unit *pUnit, int iSeq);
extern EDCDataSet_Col_Char_Unit_Value* GetValueByColSet(EDCDataSet_Col *pColSet, char* sCharacter, int iUnitSeq, int iValueSeq);

// XML Parser

typedef struct _Attributes 
{
    char key[MAX_TAG_NAME_LENGTH];
    char value[MAX_TAG_NAME_LENGTH];

} Attributes;

typedef void (*startDocument)(EDCDataSet *pEDCDataSet);
typedef void (*startElement)(EDCDataSet *pEDCDataSet, const char* tagName, Attributes *attributes, int attribCount);
typedef void (*characters)(EDCDataSet *pEDCDataSet, const char* data, int length);
typedef void (*endElement)(EDCDataSet *pEDCDataSet, const char* tagName);
typedef void (*endDocument)(EDCDataSet *pEDCDataSet);

typedef struct _XMLParser
{
    const char *__xml__;
    int length;
    int __offset__;
    startDocument   __sd__;
    startElement    __se__;
    characters      __ch__;
    endElement      __ee__;
    endDocument     __ed__;

} XMLParser, *pXMLParser;

extern XMLParser* SP_createXMLParser();
extern void SP_destroyXMLParser(pXMLParser sax);
extern void SP_setDocument(pXMLParser sax, const char* xml, int length);
extern void SP_setCallbackFunc(pXMLParser sax, int funcType, void *func);
extern int SP_parse(pXMLParser sax, EDCDataSet *pEDCDataSet);

extern int __parseTag__(pXMLParser sax, EDCDataSet *pEDCDataSet, int offset, int endIndex);
extern int __searchCharacter__(pXMLParser sax, int startIndex, char key);

extern void EDCStartDocument(EDCDataSet *pEDCDataSet);
extern void EDCStartElement(EDCDataSet *pEDCDataSet, const char* tagName, Attributes *attributes, int attribCount);
extern void EDCCharacters(EDCDataSet *pEDCDataSet, const char* data, int length);
extern void EDCEndElement(EDCDataSet *pEDCDataSet, const char* tagName);
extern void EDCEndDocument(EDCDataSet *pEDCDataSet);

#endif //_EDC_XML_PARSER