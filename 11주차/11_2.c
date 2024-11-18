#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#include <stdlib.h>

typedef struct point {
	int x;
	int y;
}POINT;
int main(void){
	POINT* points;
	int count;
	scanf("%d", &count);

	points = (POINT*)malloc(sizeof(POINT) * count);

	for (int i = 0; i < count; i++) {
		points[i].x = rand() % 100;
		points[i].y = rand() % 100;
	}
	for (int i = 0; i < count; i++) {
		printf("x - %d, y - %d\n", points[i].x, points[i].y);
	}
	free(points);
}