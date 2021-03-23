#include <iostream>

using namespace std;

int comparisoncount = 0;

void merge(int arr[], int left, int mid, int right){
	int n1 = mid - left;
	int n2 = right - mid;
	int arr_L[n1+1], arr_R[n2+1];
	for(int i = 0; i < n1; i++){
		arr_L[i] = arr[left + i];
	}
	for(int i = 0; i < n2; i++){
		arr_R[i] = arr[mid + i];
	}
	arr_L[n1] = 1000000000;
	arr_R[n2] = 1000000000;
	int i = 0;
	int j = 0;
	for(int k = left; k < right; k++){
		comparisoncount++;
		if(arr_L[i] <= arr_R[j]){
			arr[k] = arr_L[i];
			i++;
		}
		else{
			arr[k] = arr_R[j];
			j++;
		}
	}
}

void mergesort(int arr[], int left, int right){
	if(left + 1 < right){
		int mid = (left + right)/2;
		mergesort(arr, left, mid);
		mergesort(arr, mid, right);
		merge(arr, left, mid, right);
	}
}

int main(){
	int n;
	cin >> n;
	int A[n];
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	mergesort(A, 0, n);
	for(int i = 0; i < n; i++){
		if(i < n-1)
			cout << A[i] << " ";
		else
			cout << A[i] << endl;
	}
	cout << comparisoncount << endl;
}