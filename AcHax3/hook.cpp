#include "includes.h"
typedef BOOL(__stdcall* twglSwapBuffers) (HDC hDc);

twglSwapBuffers owglSwapBuffers;

BOOL __stdcall hkwglSwapBuffers(HDC hDc)
{
    Vector2 screensize = frame::screenSize();
    DWORD viewMatrix = 0x501AE8;
    float matrix[16];
    Vector2 enemyW2Spoint;
    memcpy(&matrix, (PBYTE*)viewMatrix, sizeof(matrix));
    const GLubyte color[3] =
    {
        255,0,255
    };
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
                                if (WorldToScreen(current_player_ent->BodyPos, enemyW2Spoint, matrix, screensize.x, screensize.y)) 
                                {
                                   
                                    DrawOutline(enemyW2Spoint.x + 100, enemyW2Spoint.y, 50, 100, 1, color);
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
