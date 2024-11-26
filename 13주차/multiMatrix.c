#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 100
#define COL 100
void input2DArray(int array[][100], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			array[i][j] = rand() % 1000;
		}
	}
}
void print2DArray(int array[][100], int row, int col) {
	printf("=========================\n");
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("[%4d] ", array[i][j]);
		}
		printf("\n");
	}
}
void addMatrix(int s1[][100], int s2[][100], int target[][100], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			target[i][j] = s1[i][j] + s2[i][j];
		}
	}
}
void subMatrix(int s1[][100], int s2[][100], int target[][100], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			target[i][j] = s1[i][j] - s2[i][j];
		}
	}
}
int multiArray(int s1[][100], int s2[][100], int target[][100], int row1, int col1, int row2, int col2) {
	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < col2; j++) {
			target[i][j] = 0;
			for (int h = 0; h < col1; h++) {
				target[i][j] += s1[i][h] * s2[h][j];
			}
		}
	}
}
int main(int argc, char* argv[]) {

	int matrix1[ROW][COL];
	int matrix2[ROW][COL];
	int result[ROW][COL];
	int row1, col1;
	int row2, col2;
	int targetRow, targetCol;
	printf("input matrix 1 row & col : ");
	scanf("%d %d", &row1, &col1);
	printf("input matrix 2 row & col : ");
	scanf("%d %d", &row2, &col2);
	input2DArray(matrix1, row1, col1);
	input2DArray(matrix2, row2, col2);

	if (col1 == row2) {
		printf("ok\n");
		multiArray(matrix1, matrix2, result, row1, col1, row2, col2);
	}
	else printf("no\n");
	
	//subMatrix(matrix1, matrix2, result, row, col);
	//print2DArray(matrix1, row, col);
	//print2DArray(matrix2, row, col);
	print2DArray(result, row1, col2);

	return 0;
}