// dllmain.cpp : Defines the entry point for the DLL application.
#include "includes.h"
float getMarix()
{
    DWORD viewMatrix = 0x501AE8;
    float matrix[16];
    memcpy(&matrix, (PBYTE*)viewMatrix, sizeof(matrix));
}
DWORD WINAPI MainThread(HMODULE hModule)
{
    AllocConsole();
    FILE* f = nullptr;
    freopen_s(&f, "CONOUT$", "w", stdout);













    MainClass* playerPtr = (MainClass*)((DWORD)GetModuleHandleA(NULL) + 0x109B74);
    std::cout << "Welcome To The Cheat! \n";
    std::cout << "Make A Selection Below \n";
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~ \n";
    std::cout << "[F1] Health \n";
    std::cout << "[F2] Rifle Ammo \n";
    std::cout << "[F3] Rifle Ammo \n";

    bool healthToggle = false;
    bool AmmoToggle = false;
    bool pistolToggle = false;
    bool debug = true;
    while (true)
    {

        if (GetAsyncKeyState(VK_F1) & 1)
        {
            healthToggle = !healthToggle;
            std::cout << healthToggle;
            if (healthToggle == false)
                playerPtr->localPlayerPtr->Health = 100;
        }
        if (GetAsyncKeyState(VK_F2) & 1)
        {
            AmmoToggle = !AmmoToggle;
            std::cout << AmmoToggle;
            if (AmmoToggle == false)
                playerPtr->localPlayerPtr->RifleAmmo = 20;
        }
        if (GetAsyncKeyState(VK_F3) & 1)
        {
            pistolToggle = !pistolToggle;
            std::cout << pistolToggle;
            if (pistolToggle == false)
                playerPtr->localPlayerPtr->PistolAmmo = 10;
        }
        if (GetAsyncKeyState(VK_END) & 1)
            break;
        if (healthToggle)
            playerPtr->localPlayerPtr->Health = 999;
        if (AmmoToggle)
            playerPtr->localPlayerPtr->RifleAmmo = 999;
        if (pistolToggle)
            playerPtr->localPlayerPtr->PistolAmmo = 999;
        if (GetAsyncKeyState(VK_INSERT) & 1)
        {
            debug = !debug;
            if (debug)
                std::cout << "\n Debug: On \n";
            else
                std::cout << "\n Debug: Off \n";
        }
        if(debug)
        {
            if (GetAsyncKeyState(VK_F10))
            {
                playerPtr->localPlayerPtr->primaryTimer = 0;
            }
        }
    }
















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

