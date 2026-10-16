
#pragma once

class point{
public:
float x;
float y;
point(float x0=0, float y0 = 0){
	x = x0;
	y = y0;
	}	
};

typedef struct Matrix2{
	point a;
	point b;
}Matrix2;

Matrix2 operator -(Matrix2 me){
	return Matrix2{{me.b.y, -1*me.a.y},{-1*me.b.x, me.a.x}};
}

point mirrored_speed(Matrix2 A, point speed){
	Matrix2 A_reverse = -A;
	A.b.y = -A.b.y;
	point temporary{speed.x * A.a.x + speed.y * A.a.y, speed.x * A.b.x + speed.y * A.b.y};
	return point{temporary.x * A_reverse.a.x + temporary.y * A_reverse.a.y, temporary.x * A_reverse.b.x + temporary.y * A_reverse.b.y};
}