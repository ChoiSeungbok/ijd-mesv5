/****************************************************************
*
*   Program ID  : MESplus Main Application Library
*
*   File Name   : MANCore_services.h
*
*   Description : MESplus Main services header
*
*   Functions   :
*
*   Special Logic Notes  :
*
*   Modification History :
*
*   DATE             AUTHOR         DESCRIPTION
*  --------------   -------------- ------------------------------
*   2009/11/09       Aiden          Create
*
***************************************************************/

#ifndef _MANCORE_SERVICES_H
#define _MANCORE_SERVICES_H

extern int MES_Stop_Process(TRSNode *in_node);
extern int ADM_Change_EnvValues(TRSNode *in_node);
extern int ADM_Check_Process(TRSNode *in_node);
extern int ADM_Init_Shared_Pool(TRSNode *in_node);

#endif /* _MANCORE_SERVICES_H */

