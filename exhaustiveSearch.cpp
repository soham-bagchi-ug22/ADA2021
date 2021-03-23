#include <iostream>
#include <string>
using namespace std;

bool checkSum(int p, int arr[], int t, int size){
	if(t - arr[p] == 0){
		return true;
	}
	else if(t - arr[p] < 0 || p == size){
		if(p == size) return false;
		else return (false+checkSum(p + 1, arr, t, size));
	}
	else{
		return (checkSum(p + 1, arr, t - arr[p], size)+checkSum(p + 1, arr, t, size));
	}
}

int main(){
	int size1, size2;
	cin >> size1;
	int numArr[size1];
	for(int i = 0; i < size1; i++){
		cin >> numArr[i];
	}
	cin >> size2;
	int checkArr[size2];
	for(int i = 0; i < size2; i++){
		cin >> checkArr[i];
	}
	for(int i = 0; i < size2; i++){
		bool temp = checkSum(0, numArr, checkArr[i], size1);
		if(temp == true){
			cout << "yes\n";
		}
		else{
			cout << "no\n";
		}
	}
	return 0;
}
