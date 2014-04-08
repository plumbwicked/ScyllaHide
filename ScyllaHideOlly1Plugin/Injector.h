#include <windows.h>
#include "..\HookLibrary\HookMain.h"
#include "..\InjectorCLI\DynamicMapping.h"

struct HideOptions
{
    int PEB;
    int NtSetInformationThread;
    int NtQuerySystemInformation;
    int NtQueryInformationProcess;
    int NtQueryObject;
    int NtYieldExecution;
    int GetTickCount;
    int OutputDebugStringA;
    int BlockInput;
    int ProtectDrx;
    int NtUserFindWindowEx;
    int NtUserBuildHwndList;
    int NtUserQueryWindow;
    int NtSetDebugFilterState;
    int NtClose;
};

void startInjectionProcess(HANDLE hProcess, BYTE * dllMemory, bool newProcess);
void startInjection(DWORD targetPid, const WCHAR * dllPath, bool newProcess);
BYTE * ReadFileToMemory(const WCHAR * targetFilePath);
void FillExchangeStruct(HANDLE hProcess, HOOK_DLL_EXCHANGE * data);


//olly definitions
extern "C" void _Addtolist(long addr,int highlight,char *format,...);
extern "C" void _Message(unsigned long addr,char *format,...);
extern "C" void _Error(char *format,...);
extern "C" int _Pluginwriteinttoini(HINSTANCE dllinst,char *key,int value);
extern "C" int _Pluginreadintfromini(HINSTANCE dllinst,char *key,int def);
