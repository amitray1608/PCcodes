#include<bits/stdc++.h>
using namespace std;

int main(){
	int k, r;
		cin >> k >> r;
	int sum = 1;
	int i ;
	for( i = 1; i<=10; i++){
		sum =(k*i);
		if(sum%10 == r || sum%10 ==0){
			break;
		}
	}
	cout << i << endl;
		
}
