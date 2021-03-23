#include <iostream>
#include <string>

using namespace std;

int checkLists(int a[], int n, int b[], int m){
	int count = 0;
	int checkVal = 0;
	if(n < m){
		for(int i = 0; i < n; i++){
			checkVal = a[i];
			for(int j = 0; j < m; j++){
				if(checkVal == b[j]){
					count++;
					break;
				}
			}
		}
	} else {
		for(int i = 0; i < m; i++){
			checkVal = b[i];
			for(int j = 0; j < n; j++){
				if(checkVal == a[j]){
					count++;
					break;
				}
			}
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
