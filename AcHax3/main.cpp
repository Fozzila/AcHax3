#include "includes.h"

MainClass* playerPtr = (MainClass*)((DWORD)GetModuleHandleA(NULL) + 0x109B74);
bool healthToggle = false;
bool AmmoToggle = false;
bool pistolToggle = false;
bool rapidFireToggle = false;
bool increasedJump = false;
bool debug = false;
float consoleLineLog = 1;
float consoleLineWarn = 1;
int playerNum = *(int*)(DWORD)(0x50F500);
int getNumOfPlayers()
{
    return (int)*(DWORD*)(0x50F500);

}
Vector2 screenSize()
{
    return { (float)*(int*)((DWORD)GetModuleHandleA(NULL) + 0x110C94), (float)*(int*)((DWORD)GetModuleHandleA(NULL) + 0x110C98) };
}
float getMarix()
{
    DWORD viewMatrix = 0x501AE8;
    float matrix[16];
    memcpy(&matrix, (PBYTE*)viewMatrix, sizeof(matrix));
}
void log(const char* print)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (FOREGROUND_GREEN));
    std::cout << "[" << (float)consoleLineLog << "] " << print << "\n";
    consoleLineLog += 1;
}
void warn(const char* warn)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (FOREGROUND_RED));
    std::cout << "[" << (float)consoleLineWarn << "] " << warn << "\n";
    SetConsoleTextAttribute(hConsole, (FOREGROUND_GREEN));
    consoleLineWarn += 1;

}
void playerLoop()
{
    int playerNum = *(int*)(DWORD)(0x50F500);
    DWORD player_list = 0x50F4F8;
    for (unsigned int i = 0; i < playerNum; i++)
    {
        DWORD current_player = *(DWORD*)(player_list + 0x4 * i);
        entity* current_player_ent = (entity*)(current_player);
        log(current_player_ent->Health);
    }
}
void mainLoop()
{
    while (true)
    {







        if (GetAsyncKeyState(VK_F1) & 1) // INF HEALTH
        {
            healthToggle = !healthToggle;
            if (healthToggle)
                log("Inf Health: On");
            else
                log("Inf Health: Off");
            if (healthToggle == false)
                playerPtr->localPlayerPtr->Health = 100;
        }
        if (GetAsyncKeyState(VK_F2) & 1) // INF RIFLE AMMO
        {
            AmmoToggle = !AmmoToggle;
            if (AmmoToggle)
                log("Inf Rifle Ammo: On");
            else
                log("Inf Rifle Ammo: Off");
            if (AmmoToggle == false)
                playerPtr->localPlayerPtr->RifleAmmo = 20;
        }
        if (GetAsyncKeyState(VK_F3) & 1) // INF PISTOL AMMO
        {
            pistolToggle = !pistolToggle;
            if (pistolToggle)
                log("Inf Pistol Ammon: On");
            else
                log("Inf Pistol Ammon: Off");
            if (pistolToggle == false)
                playerPtr->localPlayerPtr->PistolAmmo = 10;

        }
        if (GetAsyncKeyState(VK_F4) & 1) // RAPID FIRE
        {
            rapidFireToggle = !rapidFireToggle;
            if (rapidFireToggle)
                log("Rapid Fire: On");
            else
                log("Rapid Fire: Off");
        }
        if (GetAsyncKeyState(VK_F5) & 1) // INCREASED JUMP
        {
            increasedJump = !increasedJump;
            if (increasedJump)
                log("Jump+: On");
            else
                log("Jump+: Off");
            if (increasedJump == false)
                playerPtr->localPlayerPtr->Health = 100;
        }
        if (GetAsyncKeyState(VK_END) & 1) // CLOSE
        {
            warn("Cheat Closing: 3");
            Sleep(1000);
            warn("Cheat Closing: 2");
            Sleep(1000);
            warn("Cheat Closing: 1");
            Sleep(1000);
            break;
        }









        if (healthToggle)
            playerPtr->localPlayerPtr->Health = 999; // MEMORY WRITING FREEZING
        if (AmmoToggle)
            playerPtr->localPlayerPtr->RifleAmmo = 999; // MEMORY WRITING FREEZING
        if (pistolToggle)
            playerPtr->localPlayerPtr->PistolAmmo = 999; // MEMORY WRITING FREEZING
        if (rapidFireToggle)
            playerPtr->localPlayerPtr->primaryTimer = 50; // MEMORY WRITING FREEZING
        if (GetAsyncKeyState(0x20))
            if(increasedJump)
                playerPtr->localPlayerPtr->BodyPos.z += 0.05; // MEMORY WRITING FREEZING
        if (GetAsyncKeyState(VK_INSERT) & 1)
        {
            debug = !debug;
            if (debug)
                log("Debug: On");
            else
                log("Debug: Off");
        }
        if (debug)
        {
            playerLoop();
        }








        Sleep(1);
    }
}