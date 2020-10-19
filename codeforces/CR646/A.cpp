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
	int a[n], odd = 0, even = 0;
	int sum = 0;
	for(int &i : a){
		cin >> i;
		sum += i;
		if(i&1)
			odd++;
		else
			even++;
	}
	//vague approach
	if(odd == 0){
		cout << "No" << endl;
		return;
	}
	if(odd == n and ~k&1){
		cout << "No" << endl;
		return;
	}
	if(even == n){
		cout << "No" << endl;
		return;
	}
	for(int i = 1; i <= k; i++){
		if(i&1){
			if(odd >= i && even >= k-i){
				cout << "Yes" << endl;
				return;
			}
		}
	}
	cout << "No" << endl;
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
