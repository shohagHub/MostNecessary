// Sorting.cpp : Defines the entry point for the console application.
//

// MergeSort.cpp : Defines the entry point for the console application.
//


#include <stdio.h>
#define SIZE 100
int Input[SIZE], Case, B[SIZE];
int N, found;

void binarySearch2(int low, int high){

}

void readCase(){
	scanf("%d", &N);
	int i;
	scanf("%d", &found);
	for (i = 0; i < N; i++)
		scanf("%d", &Input[i]);
	printf("");
}
int Ans;
void binarySearch(int low, int high){
	int mid;
	if (low < high){
		mid = low + (high - low) / 2;
		if (Input[mid] == found)
			Ans = mid;
		else if (Input[mid] < found)
			binarySearch(mid + 1, high);
		else
			binarySearch(low, mid);
	}
	else{
		if (Input[low] == found)
			Ans = low;
		else
			Ans = -1;
		return;
	}
}

void merge(int low, int mid, int high){
	int l1, l2, i;
	l1 = low; l2 = mid + 1;
	i = low;
	while (l1 <= mid && l2 <= high){
		if (Input[l1] <= Input[l2])
			B[i++] = Input[l1++];
		else
			B[i++] = Input[l2++];
	}

	while (l1 <= mid)
		B[i++] = Input[l1++];
	while (l2 <= high)
		B[i++] = Input[l2++];
	/*Now copy B to A*/
	for (i = low; i <= high; i++)
		Input[i] = B[i];
}

void mergeSort(int low, int high){
	int mid;
	if (low < high){
		mid = low + (high - low) / 2;
		mergeSort(low, mid);
		mergeSort(mid + 1, high);
		merge(low, mid, high);
	}
	else
		return;
}

void solveCase(){
	Ans = -1;
	//found = Input[N - 1];
	mergeSort(0, N - 1);
	binarySearch(0, N - 1);
}

void print(){
	int i;
	for (i = 0; i < N; i++)
		printf("%d ", Input[i]);
	printf("\n");
}

void printCase(){
	printf("#%d: \n", Case);
	print();
	printf("Searching %d found in %d\n", found, Ans);
}

int main(){
	freopen("binarysearch-input.txt", "r", stdin);
	/*int a = 3 / 2;
	printf("%d", a);
	printf("%d", 1 / 2);*/
	int T;
	scanf("%d", &T);
	for (Case = 1; Case <= T; Case++){
		readCase();
		solveCase();
		printCase();
	}
	return 0;
}
