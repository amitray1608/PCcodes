//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
int siz = 1e8+1;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve(){
	bool arr[siz];
	memset(arr, true, sizeof arr);
	for(int i = 2; i*i < siz; i++){
		if(arr[i]){
			for(int j = i*i; j < siz; j += i){
				arr[j] = false;
			}
		}
	}	
	int x = 100;
	for(int i = 2; i < siz; i++){
		if(arr[i]){
			if(x == 100){
				cout << i << endl;
				x = 1;
			}else
				x++;
		}
	}
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1;
		//cin >> t;
		while(t--){
			solve();
		}
	return 0;
}
