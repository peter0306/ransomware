#pragma once
#include<Windows.h>
#include <stdio.h>
#include <tchar.h>

void LaunchIE(LPTSTR);
void LaunchIE(LPTSTR lpURL) //L:l
{
    STARTUPINFO siStartupInfoApp;
    PROCESS_INFORMATION piProcessInfoApp;
    TCHAR acCommand[1024];
    _stprintf_s(acCommand,
        _T("\"C:\\Program Files\\Internet Explorer\\iexplore.exe\" \"%s\""), lpURL);
        
    ZeroMemory(&siStartupInfoApp, sizeof(siStartupInfoApp));
    ZeroMemory(&piProcessInfoApp, sizeof(piProcessInfoApp));
    siStartupInfoApp.cb = sizeof(siStartupInfoApp);
    if (!CreateProcess(
        NULL,
        acCommand,
        NULL,
        NULL,
        FALSE,
        CREATE_NEW_CONSOLE,
        NULL,
        NULL,
        &siStartupInfoApp,
        &piProcessInfoApp))
    {
        return;
    }
    WaitForSingleObject(piProcessInfoApp.hProcess, 0);
    CloseHandle(piProcessInfoApp.hProcess);
    CloseHandle(piProcessInfoApp.hThread);
}

int main()
{  
    
    cout << "§A¦n";
}
