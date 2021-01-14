// Created with ReClass.NET 1.2 by KN4CK3R
#pragma once
#include "includes.h"
class MainClass
{
public:
	class entity* localPlayerPtr; //0x0000
	char pad_0004[60]; //0x0004
}; //Size: 0x0040

class entity
{
public:
	char pad_0000[4]; //0x0000
	Vector3 HeadPos; //0x0004
	char pad_0010[36]; //0x0010
	Vector3 BodyPos; //0x0034
	Vector2 viewAngle; //0x0040
	char pad_0048[4]; //0x0048
	Vector2 recoilXspeedY; //0x004C
	char pad_0054[40]; //0x0054
	int32_t IsGrounded; //0x007C
	char pad_0080[120]; //0x0080
	int32_t Health; //0x00F8
	char pad_00FC[24]; //0x00FC
	int32_t PistolReserve; //0x0114
	char pad_0118[16]; //0x0118
	int32_t RifleReserve; //0x0128
	char pad_012C[16]; //0x012C
	int32_t PistolAmmo; //0x013C
	char pad_0140[16]; //0x0140
	int32_t RifleAmmo; //0x0150
	char pad_0154[36]; //0x0154
	int32_t primaryTimer; //0x0178
	char pad_017C[1000]; //0x017C
}; //Size: 0x0564

