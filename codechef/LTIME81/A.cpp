//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
void solve(){
	int n, k;
	cin >> n >> k;
	char a[n];
	for(int i = 0; i< n; i++){
		cin >> a[i];
	}
	int count = 0;
	for(int i = n-1; i >= n-k; i--){
		if(a[i] == 'T'){
			a[i] = '1';
		}else{
			a[i] = '1';
			for(int j = i-1; j >= 0; j--){
				if(a[j] == 'T')
					a[j] = 'H';
				else
					a[j] = 'T';
			}	
		}
	}
	//int count = 0;
	for(int i = 0; i < n ;i++){
		if(a[i] == '1') break;
		if(a[i] == 'H')
		count++;
	}
	cout << count << endl;
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1;
		cin >> t;
		while(t--){
			solve();
		}
	return 0;
}
