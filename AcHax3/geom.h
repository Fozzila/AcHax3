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

	intVector2(int x, int y) :x(x), y(y) {}

	int x, y;
};
struct Vector4 { float x, y, z, w; };
Vector3 CalcAngle(const Vector3& src, const Vector3& dst);
float Get3DDistance(Vector3 playerPosition, Vector3 enemyPosition);
bool WorldToScreen(Vector3 pos, Vector2& screen, float matrix[16], int windowWidth, int windowHeight);
float Get2DDistance(Vector2 pos1, Vector2 pos2);