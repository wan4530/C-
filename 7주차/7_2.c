#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
typedef struct point {
	int x;
	int y;
}POINT;
int main(void){
	struct point p1 = { 10,10 };
	POINT p2 = { 20,20 };
	POINT* p3 = &p2;

	printf("p1.x = %d, p1.y = %d\n", p1.x, p1.y);
	printf("p2.x = %d, p2.y = %d\n", p2.x, p2.y);
	printf("p3->x = %d, p3->y = %d\n", p3->x, p3->y);

	p3 = &p1;
	printf("p3->x = %d, p3->y = %d\n", (*p3).x, (*p3).y);
	return 0;
}