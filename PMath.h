#pragma once

struct float2 {

	float x;
	float y;

	float2(): x(0.0f), y(0.0f){

	}

	float2(float xx, float yy) : x(xx), y(yy) {

	}

	float2& operator=(const float2& r) {
		x = r.x;
		y = r.y;
	}

	float2 operator+ (const float2& r) const{
		return { x + r.x, y + r.y };
	}

	bool operator==(const float2& r) const{
		return (x == r.x && y == r.y);
	}

	float2 operator-(const float2& r) {
		return {x-r.x, y-r.y };
	}



};



struct float3{
	float x;
	float y;
	float z;
};




float Dot(float2 l, float2 r){
	return (l.x * r.x) + (l.y * r.y);
}

float Dot(float3 l, float3 r) {
	return (l.x * r.x) + (l.y * r.y) + (l.z * r.z);
}

struct Line2D {
	float2 start;
	float2 end;
};

struct Line3D {
	float3 start;
	float3 end;
};

struct Circle2D {
	float2 center;
	float radius;
};

struct Circle3D {
	float3 center;
	float radius;
};


bool Collide(Circle2D a, Circle2D b) {

}

bool Collide(Circle3D a, Circle3D b) {

}

struct Ray3D {
	float3 origin;
	float3 direction;
};

struct Sphere {
	float3 position;
	float radius;
};