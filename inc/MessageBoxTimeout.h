#if defined(WIN32) || defined(WIN64)

#include <windows.h>
#include <tchar.h>

/*
 * MessageBoxTimeout API
 * License : This article, along with any associated source code and files, is licensed under The Code Project Open License (CPOL)
**/

//Functions & other definitions required-->
typedef int (__stdcall *MSGBOXAAPI)(IN HWND hWnd, 
        IN LPCSTR lpText, IN LPCSTR lpCaption, 
        IN UINT uType, IN WORD wLanguageId, IN DWORD dwMilliseconds);
typedef int (__stdcall *MSGBOXWAPI)(IN HWND hWnd, 
        IN LPCWSTR lpText, IN LPCWSTR lpCaption, 
        IN UINT uType, IN WORD wLanguageId, IN DWORD dwMilliseconds);

int MessageBoxTimeoutA(IN HWND hWnd, IN LPCSTR lpText, 
    IN LPCSTR lpCaption, IN UINT uType, 
    IN WORD wLanguageId, IN DWORD dwMilliseconds);
int MessageBoxTimeoutW(IN HWND hWnd, IN LPCWSTR lpText, 
    IN LPCWSTR lpCaption, IN UINT uType, 
    IN WORD wLanguageId, IN DWORD dwMilliseconds);

#ifdef UNICODE
    #define MessageBoxTimeout MessageBoxTimeoutW
#else
    #define MessageBoxTimeout MessageBoxTimeoutA
#endif 

#define MB_TIMEDOUT 32000

#endif
