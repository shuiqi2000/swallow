#include <windows.h>
#include <tchar.h>
#include "targetver.h"
#include "ServerPanel.h"
#include <winsvc.h>

/*  Declare Windows procedure  */
INT_PTR CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
DWORD RemoveService();
DWORD InstallService();
DWORD CallUpService();
DWORD HaltService();

char ServiceName[1024]="Control Service2";
char ServiceDisplayName[1024]="Control Service2";
char Calling[1024]="E:\\swallow\\Server\\Server.exe";
bool serviceStatus = true;
int WINAPI WinMain (HINSTANCE hThisInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpszArgument,
                    int nFunsterStil)
{
    SERVICE_STATUS status;
    SC_HANDLE Service,scm;
    BOOL success;
    scm = OpenSCManager(NULL,NULL,SC_MANAGER_ENUMERATE_SERVICE);
    Service = OpenService(scm,ServiceName,SERVICE_ALL_ACCESS|DELETE);

    success = QueryServiceStatus(Service,&status);
    if (status.dwCurrentState != SERVICE_RUNNING ){
      serviceStatus = false;  
    }else{
      serviceStatus = true;  
    }

    DialogBoxParam(hThisInstance, 
     MAKEINTRESOURCE(IDD_SERVERPANEL),
     0, 
     WindowProcedure,
     _ttoi(lpszArgument));
     
    return 0;
}

INT_PTR CALLBACK WindowProcedure (HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
        if (serviceStatus) { 
          SetDlgItemText(hDlg, IDCONTROLBUTTON, TEXT("Í£Ö¹"));
        } else {
          SetDlgItemText(hDlg, IDCONTROLBUTTON, TEXT("Æô¶¯"));  
        }
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDCONTROLBUTTON)
		{
            if (serviceStatus) {
              HaltService();
              serviceStatus = !serviceStatus;
              SetDlgItemText(hDlg, IDCONTROLBUTTON, TEXT("Æô¶¯"));
            } else {
              CallUpService();
              serviceStatus = !serviceStatus;
              SetDlgItemText(hDlg, IDCONTROLBUTTON, TEXT("Í£Ö¹"));  
            }
			return (INT_PTR)TRUE;
		} else if (LOWORD(wParam) == IDCANCEL){
            EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
        }
		
		break;
	}
	return (INT_PTR)FALSE;
}

// return Error
DWORD InstallService()
{
	SC_HANDLE hdlSCM = OpenSCManager(NULL, NULL, SC_MANAGER_CREATE_SERVICE);

 

	if (hdlSCM == NULL) return ::GetLastError();
 
	SC_HANDLE hdlServ = CreateService(
		hdlSCM,                    // SCManager database 
		ServiceName,               // name of service 
		ServiceDisplayName,        // service name to display 
		SERVICE_ALL_ACCESS,  // desired access 
		SERVICE_WIN32_OWN_PROCESS | SERVICE_INTERACTIVE_PROCESS, // service type 
		SERVICE_AUTO_START,        // start type 
		SERVICE_ERROR_NORMAL,      // error control type 
		Calling,                   // service's binary Path name
		NULL,                      // no load ordering group 
		NULL,                      // no tag identifier 
		NULL,                      // no dependencies 
		NULL,                      // LocalSystem account 
		NULL);                     // no password 
 
	DWORD Ret = 0;
	if (hdlServ == NULL) Ret = ::GetLastError();
    CloseServiceHandle(hdlServ);
	return Ret;
}


// return Error
DWORD RemoveService()
{
	SC_HANDLE hdlSCM = OpenSCManager(NULL, NULL, STANDARD_RIGHTS_REQUIRED);
 
	if (hdlSCM == NULL) return ::GetLastError();

	SC_HANDLE hdlServ = OpenService(hdlSCM, ServiceName, DELETE);
	
	DWORD Ret = 0;
	if (::DeleteService(hdlServ) == FALSE) Ret = ::GetLastError();
	CloseServiceHandle(hdlServ);
	return Ret;
}

// return Error
DWORD CallUpService()
{
	SC_HANDLE hdlSCM = OpenSCManager(NULL, NULL, STANDARD_RIGHTS_REQUIRED);
 
	if (hdlSCM == NULL) return ::GetLastError();

	SC_HANDLE hdlServ = OpenService(hdlSCM, ServiceName, SERVICE_START);

	DWORD Ret = 0;
	if (::StartService(hdlServ, 0, NULL) == FALSE) Ret = ::GetLastError();
	CloseServiceHandle(hdlServ);
	return Ret;
}


// return Error
DWORD HaltService()
{
	SC_HANDLE hdlSCM = OpenSCManager(NULL, NULL, STANDARD_RIGHTS_REQUIRED);
 
	if (hdlSCM == NULL) return ::GetLastError();

	SC_HANDLE hdlServ = OpenService(hdlSCM, ServiceName, SERVICE_STOP);

	SERVICE_STATUS ServStat;
	DWORD Ret = 0;
	if (::ControlService(hdlServ, SERVICE_CONTROL_STOP, &ServStat) == FALSE) Ret = ::GetLastError();
	CloseServiceHandle(hdlServ);
	return Ret;
}
