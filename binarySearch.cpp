#include <iostream>
#include <string>

using namespace std;

bool binarySearch(int arr[], int n, int term){
	int low = 0;
	int high = n;
	while(low <= high){
		int m = (low+high)/2;
		if(arr[m] < term) low = m + 1;
		else if(arr[m] == term){
			return true;
		}
		else high = m - 1;
	}
	return false;
}

int checkLists(int a[], int n, int b[], int m){
	int count = 0;
	int checkVal = 0;
	for(int i = 0; i < m; i++){
		if(binarySearch(a, n, b[i])){
			count++;
		}
	}
	return count;
}

int main(){
	int size1, size2;
	cin >> size1;
	int a1[size1];
	for(int i = 0; i < size1; i++){
		cin >> a1[i];
	}
	cin >> size2;
	int a2[size2];
	for(int i = 0; i < size2; i++){
		cin >> a2[i];
	}
	cout << checkLists(a1, size1, a2, size2) << endl;
	return 0;
}
