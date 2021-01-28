#pragma once
#include "includes.h"
#define string std::string
#define toString(x) std::to_string(x)
namespace frame
{
	

	static bool healthToggle = false;
	static bool AmmoToggle = false;
	static bool pistolToggle = false;
	static bool rapidFireToggle = false;
	static bool increasedJump = false;
	static bool aimbot = false;
	static bool recoil = false;
	static bool debug = false;
	class offsets
	{
	public:
		static int playerNum();
		static DWORD playerAddress();
		static MainClass* playerPtr();
		static DWORD playerList();
	};
	static Vector2 screenSize()
	{
		return { (float)*(int*)((DWORD)GetModuleHandleA(NULL) + 0x110C94), (float)*(int*)((DWORD)GetModuleHandleA(NULL) + 0x110C98) };
	}
	Vector2 viewAngle();
	Vector2 centerScreen();
	static float getMarix();
	float teamCheck(DWORD ent);
	void log(string);
	void warn(const char* warn);
	bool isTeamGame();

}