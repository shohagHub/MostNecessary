// Combination.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#define SIZE 10
int output[SIZE];
int N;
int R;

/*
There is 1to5 5 no's if we take 3 how many combination is possilbe

formula N  R = N! / R!(N - R)! 
		 C
*/


void reset(){
	int i;
	for (i = 0; i < SIZE; i++){
		output[i] = 0;
	}
}

void printResult(){
	int i;
	for (i = 0; i < R; i++)
		printf("%d", output[i]);
	printf("\n");
}

void combination(int level, int index){
	if (level == R){
		printResult();
		return;
	}
	int i;
	for (i = index; i <= N; i++){
		output[level] = i;
		combination(level + 1, i + 1);
	}
}

int main(){
	N = 5;//
	R = 3;
	combination(0, 1);
	return 0;
}
