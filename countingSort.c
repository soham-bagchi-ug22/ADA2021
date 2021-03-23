#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArr(int B[], int N){
	for(int i = 0; i < N - 1; i++){
		printf("%d ", B[i]); 
	}
	printf("%d\n", B[N-1]);
}

void countingSort(int A[], int N, int K){
	int *sArr = (int *) calloc(K, (sizeof(int)));
	for(int i = 0; i < N; i++){
		sArr[A[i]]++;
	}
	//printArr(sArr, K);
	for(int i = 1; i < K; i++){
		sArr[i] += sArr[i-1];
	}
	//printArr(sArr, K);
	int fArr[N];
	memset(fArr, 0, N*sizeof(int));
	//printArr(fArr, N);
	for(int i = N - 1; i >= 0; i--){
		fArr[sArr[A[i]]-1] = A[i];
		sArr[A[i]]--;
	}
	printArr(fArr, N);
}


int findMax(int a[], int s){
	int temp = a[0];
	for(int i = 1; i < s; i++){
		if(a[i] > temp) temp = a[i];
	}
	return temp;
}

int main(){
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	int k = findMax(arr, n);
	//printf("%d\n", k);
	countingSort(arr, n, k + 1);
}
