#include <iostream>
using namespace std;

void printArr(int A[], int N, int x){
	//int n = sizeof(A)/sizeof(A[0]);
	for(int i = 0; i < N - 1; i++){
		if(i != x)
			cout << A[i] << " ";
		else
			cout << "[" << A[i] << "] ";
	}
	cout << A[N - 1] << endl;
}

void partition(int A[], int p, int r){
	int temp;
	int x = A[r];
	int i = p - 1;
	for(int j = p; j < r; j++){
		temp = -999;
		if(A[j] <= x){
			i++;
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	temp = A[i + 1];
	A[i + 1] = A[r];
	A[r] = temp;
	printArr(A, r - p + 1, i + 1);
}

int main(){
	int n;
	cin >> n;
	int A[n];
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	partition(A, 0, n-1);
	return 0;
}