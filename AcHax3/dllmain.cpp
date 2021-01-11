// dllmain.cpp : Defines the entry point for the DLL application.
#include "includes.h"

void intro()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (FOREGROUND_GREEN)); 
    std::cout << "Loading\r";
    Sleep(500);
    std::cout << "Loading.\r";
    Sleep(500);
    std::cout << "Loading..\r";
    Sleep(500);
    std::cout << "Loading...\r";
    Sleep(500);
    std::cout << " \r";
    if ((DWORD)GetModuleHandleA(NULL))
    {
        std::cout << "Success! Got Game Handle: " << std::hex << (DWORD)(GetModuleHandle(NULL));
    }
    Sleep(2000);
    std::cout << "                                                                     \r";
    std::cout << "\r Welcome To The Cheat!                                             \n";
    std::cout << "Make A Selection Below \n";
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~ \n";
    std::cout << "[F1] Health \n";
    std::cout << "[F2] Rifle Ammo \n";
    std::cout << "[F3] Pistol Ammo \n";
    std::cout << "[F4] Rapid Fire \n";
    std::cout << "[F5] Jump+ \n";
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~ \n";
    
}








DWORD WINAPI MainThread(HMODULE hModule)
{
    AllocConsole();
    FILE* f = nullptr;
    freopen_s(&f, "CONOUT$", "w", stdout);



    intro();
    mainLoop();

    if (f != nullptr)
        fclose(f);
    FreeConsole();
    FreeLibraryAndExitThread(hModule, 0);
    return 0;
}
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    {
        HANDLE hThread = CreateThread(nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(MainThread), hModule, 0, nullptr);
        if (hThread)
            CloseHandle(hThread);
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

