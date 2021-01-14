#pragma once
struct Matrix4x4 { float matrix[16]; };
struct intVector3
{

	int x, y, z;
};
struct Vector3
{

	float x, y, z;
};
struct Vector2
{

	float x, y;
};

struct intVector2
{



	int x, y;
};
struct Vector4 { float x, y, z, w; };
Vector2 CalcAngle(const Vector3& src, const Vector3& dst);
float Get3DDistance(Vector3 playerPosition, Vector3 enemyPosition);
bool WorldToScreenForAimbot(Vector3 pos, Vector2& screen, float matrix[16], int windowWidth, int windowHeight);
float Get2DDistance(Vector2 pos1, Vector2 pos2);