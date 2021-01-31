#include "includes.h"
bool esp = false;
typedef BOOL(__stdcall* twglSwapBuffers) (HDC hDc);

twglSwapBuffers owglSwapBuffers;
bool unHook()
{
    mem::Patch((BYTE*)GetProcAddress(GetModuleHandle(L"opengl32.dll"), "wglSwapBuffers") , (BYTE*)"\x66\x90\x55\x88\xEC", 5);
    return true;
}
BOOL __stdcall hkwglSwapBuffers(HDC hDc)
{
    if (GetAsyncKeyState(VK_F8) & 1)
    {
        esp = !esp;
        if (esp) {
            frame::log("ESP: On");
        }
        else
        {
            frame::log("ESP: Off");
        }


    }
    
   
    DWORD viewMatrix = 0x501AE8;
    float matrix[16];
    Vector2 enemyW2Spoint;
    Vector2 headLoco;
    Vector2 localizedScreenSize = { 1600, 900 };
    Vector2 centerLocalizedScreenSize = { 1600/2, 900/2 };
    
    static GLubyte color[3] =
    {
        255,0,255
    };
    if (esp)
    {
        for (unsigned int i = 0; i < frame::offsets::playerNum(); i++)
        {
            memcpy(&matrix, (PBYTE*)viewMatrix, sizeof(matrix));
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
                                    if (WorldToScreen(current_player_ent->BodyPos, enemyW2Spoint, matrix, localizedScreenSize.x, localizedScreenSize.y))
                                    {
                                        WorldToScreen(current_player_ent->HeadPos, headLoco, matrix, localizedScreenSize.x, localizedScreenSize.y);
                                        if (playerClosestToCursor() == current_player)
                                        {
                                            color[0] = (GLubyte)255;
                                            color[1] = (GLubyte)255;
                                            color[2] = (GLubyte)255;
                                        }
                                        tracer(centerLocalizedScreenSize, headLoco, color);
                                        color[0] = 255;
                                        color[1] = 0;
                                        color[2] = 0;
                                    }
                                }
                            }
                        }
 
                    }
                }
            }
        }

    }
	return owglSwapBuffers(hDc);
}

void hookSwap()
{
	owglSwapBuffers = (twglSwapBuffers)GetProcAddress(GetModuleHandle(L"opengl32.dll"), "wglSwapBuffers");
	owglSwapBuffers = (twglSwapBuffers)mem::TrampHook32((BYTE*)owglSwapBuffers, (BYTE*)hkwglSwapBuffers, 5);
	
}
