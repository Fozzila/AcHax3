#include "includes.h"
DWORD playerLoop()
{
    float bestdistToCenter = FLT_MAX;
    DWORD bestPlayerInCheck = NULL;
    Vector2 calcAngle;
    float dist2;
    
    for (unsigned int i = 0; i < frame::offsets::playerNum(); i++)
    {
        DWORD current_player = *(DWORD*)(frame::offsets::playerList() + 0x4 * i);
        
        if (current_player)
        {
            if (*(int*)(current_player + 0x0338) == 0)
            {
                if (current_player != frame::offsets::playerAddress())
                {
                    if (frame::teamCheck(current_player))
                    {
                        entity* current_player_ent = (entity*)(current_player);
                        if (current_player_ent)
                        {
                            if (current_player_ent->Health < 120 || current_player_ent->Health > -1)
                            {
                                calcAngle = CalcAngle(frame::offsets::playerPtr()->localPlayerPtr->HeadPos, current_player_ent->HeadPos);
                                dist2 = Get2DDistance(frame::viewAngle(), calcAngle);

                                if (dist2 < bestdistToCenter)
                                {
                                    bestdistToCenter = dist2;
                                    bestPlayerInCheck = current_player;
                                }
                            }
                        }
                    }
                    

                }
            }
        }
    }
    if (bestPlayerInCheck != NULL)
    {
        return bestPlayerInCheck;
    }
}



void aimbotF()
{
    Vector2 angle;
    entity* bestEnt = (entity*)playerLoop();
    if (bestEnt->Health < 200 || bestEnt->Health > -1)
    {
        angle = CalcAngle(frame::offsets::playerPtr()->localPlayerPtr->HeadPos, bestEnt->HeadPos);
        frame::offsets::playerPtr()->localPlayerPtr->viewAngle.x = angle.x;
        frame::offsets::playerPtr()->localPlayerPtr->viewAngle.y = angle.y;
    }
}



void mainLoop()
{
    hookSwap();
    frame::log("Hook Success!");
    while (true)
    {
        // TOGGLES
        if (true) 
        {
            // INF HEALTH
            if (GetAsyncKeyState(VK_F1) & 1) 
            {
                frame::healthToggle = !frame::healthToggle;
                if (frame::healthToggle)
                    frame::log("Inf Health: On");
                else
                    frame::log("Inf Health: Off");
                if (frame::healthToggle == false)
                    frame::offsets::playerPtr()->localPlayerPtr->Health = 100;
            } 
            // INF RIFLE AMMO
            if (GetAsyncKeyState(VK_F2) & 1) 
            {
                frame::AmmoToggle = !frame::AmmoToggle;
                if (frame::AmmoToggle)
                    frame::log("Inf Rifle Ammo: On");
                else
                    frame::log("Inf Rifle Ammo: Off");
                if (frame::AmmoToggle == false)
                    frame::offsets::playerPtr()->localPlayerPtr->RifleAmmo = 20;
            } 
            // INF PISTOL AMMO
            if (GetAsyncKeyState(VK_F3) & 1)
            {
                frame::pistolToggle = !frame::pistolToggle;
                if (frame::pistolToggle)
                    frame::log("Inf Pistol Ammon: On");
                else
                    frame::log("Inf Pistol Ammon: Off");
                if (frame::pistolToggle == false)
                    frame::offsets::playerPtr()->localPlayerPtr->PistolAmmo = 10;

            }
            // RAPID FIRE
            if (GetAsyncKeyState(VK_F4) & 1)
            {
                frame::rapidFireToggle = !frame::rapidFireToggle;
                if (frame::rapidFireToggle)
                    frame::log("Rapid Fire: On");
                else
                    frame::log("Rapid Fire: Off");
            }
            // INCREASED JUMP
            if (GetAsyncKeyState(VK_F5) & 1) 
            {
                frame::increasedJump = !frame::increasedJump;
                if (frame::increasedJump)
                    frame::log("Jump+: On");
                else
                    frame::log("Jump+: Off");
                if (frame::increasedJump == false)
                    frame::offsets::playerPtr()->localPlayerPtr->Health = 100;
            }
            // AIMBOT
            if (GetAsyncKeyState(VK_F6) & 1) 
            {
                frame::aimbot = !frame::aimbot;
                if (frame::aimbot)
                    frame::log("Aimbot[F]: On");
                else
                    frame::log("Aimbot[F]: Off");
            }
            // RECOIL
            if (GetAsyncKeyState(VK_F7) & 1)
            {
                frame::recoil = !frame::recoil;
                if (frame::recoil)
                    frame::log("Recoil: On");
                else
                    frame::log("Recoil: Off");
            }

            // CLOSE
            if (GetAsyncKeyState(VK_END) & 1) 
            {
                frame::warn("Cheat Closing: 3");
                Sleep(1000);
                frame::warn("Cheat Closing: 2");
                Sleep(1000);
                frame::warn("Cheat Closing: 1");
                Sleep(1000);
                break;
            }
            // DEBUG
            if (GetAsyncKeyState(VK_INSERT) & 1)
            {
                frame::debug = !frame::debug;
                if (frame::debug)
                    frame::log("Debug: On");
                else
                    frame::log("Debug: Off");
            }
        } 
        // WRITING FROM TOGGLES
        if (true)
        {
            if (frame::debug)
            {
                if (GetAsyncKeyState(VK_F10))
                {
                    string beam = toString(frame::offsets::playerPtr()->localPlayerPtr->Health);
                    frame::log(beam);
                }

            }
            if (frame::healthToggle)
                frame::offsets::playerPtr()->localPlayerPtr->Health = 999; // MEMORY WRITING FREEZING
            if (frame::AmmoToggle)
                frame::offsets::playerPtr()->localPlayerPtr->RifleAmmo = 999; // MEMORY WRITING FREEZING
            if (frame::pistolToggle)
                frame::offsets::playerPtr()->localPlayerPtr->PistolAmmo = 999; // MEMORY WRITING FREEZING
            if (frame::rapidFireToggle)
                frame::offsets::playerPtr()->localPlayerPtr->primaryTimer = 50; // MEMORY WRITING FREEZING
            if (frame::increasedJump && GetAsyncKeyState(0x20))
                    frame::offsets::playerPtr()->localPlayerPtr->BodyPos.z += 0.05; // MEMORY WRITING FREEZING
            if (frame::recoil)
                frame::offsets::playerPtr()->localPlayerPtr->recoilXspeedY.x -= frame::offsets::playerPtr()->localPlayerPtr->recoilXspeedY.x *= FLT_TRUE_MIN;
            if (frame::aimbot && GetAsyncKeyState(VK_KEY_F))
                    aimbotF();
        }
        Sleep(1);
    }
}