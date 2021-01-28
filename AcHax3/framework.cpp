#include "includes.h"
int consoleLineLog = 1;
int consoleLineWarn = 1;

DWORD frame::offsets::playerList()
{
	return *(DWORD*)(0x50F4F8);
}
Vector2 frame::viewAngle()
{
	return frame::offsets::playerPtr()->localPlayerPtr->viewAngle;
}
MainClass* frame::offsets::playerPtr()
{
	return (MainClass*)((DWORD)GetModuleHandleA(NULL) + 0x109B74);
}
DWORD frame::offsets::playerAddress()
{
	return *(DWORD*)((DWORD)GetModuleHandleA(NULL) + 0x109B74);
}
int frame::offsets::playerNum()
{
	return (int)*(DWORD*)(0x50F500);
}
Vector2 frame::centerScreen()
{
	Vector2 screenSize = { (float)*(int*)((DWORD)GetModuleHandleA(NULL) + 0x110C94), (float)*(int*)((DWORD)GetModuleHandleA(NULL) + 0x110C98) };
	return { screenSize.x / 2, screenSize.y / 2 };
}
float frame::getMarix()
{
	DWORD viewMatrix = 0x501AE8;
	float matrix[16];
	memcpy(&matrix, (PBYTE*)viewMatrix, sizeof(matrix));
}
float frame::teamCheck(DWORD ent)
{
	int playerTeam = *(int*)(frame::offsets::playerAddress() + 0x32C);
	if (playerTeam == 1)
	{
		if (*(int*)(ent + 0x32C) != *(int*)(frame::offsets::playerAddress() + 0x32C))
		{
			return true;
		}
	}
	else if (playerTeam == 0)
	{
		if (*(int*)(ent + 0x32C) != *(int*)(frame::offsets::playerAddress() + 0x32C))
		{
			return true;
		}
	}
	return false;
}
void frame::log(string print)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (FOREGROUND_GREEN));
	std::cout << "[" << (float)consoleLineLog << "] " << print << "\n";
	consoleLineLog += 1;
}
void frame::warn(const char* warn)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (FOREGROUND_RED));
	std::cout << "[" << (float)consoleLineWarn << "] " << warn << "\n";
	SetConsoleTextAttribute(hConsole, (FOREGROUND_GREEN));
	consoleLineWarn += 1;
}
bool frame::isTeamGame()
{
	int gameMode = *(int*)GetModuleHandleA(NULL) + 0x10F49C;
	if (gameMode == 7 || gameMode == 20 || gameMode == 21)
	{
		return true;
	}
	else
	{
		return false;
	}
}