// 2ndLargest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#include <limits.h>
void print2ndLargest(int arr[], int arr_size){
	int i, first, second;
	//
	if (arr_size < 2){
		printf("Invalid input");
		return;
	}

	first = second = INT_MIN;

	for (i = 0; i < arr_size; i++){
		/*If current element is smaller than the first then*/
		if (arr[i] > first){
			second = first;
			first = arr[i];
		}
		else if (arr[i] > second && arr[i] < first)
			second = arr[i];
	}
	printf("The second largest element is: %d\n", second);
}

int main(){
	int arr[] = { 123, 2 }; 
	printf("array size: %d -- Element size: %d", sizeof(arr), sizeof(arr[0]));

	int arr_size = sizeof(arr) / sizeof(arr[0]);
	print2ndLargest(arr, arr_size);
	return 0;
}
