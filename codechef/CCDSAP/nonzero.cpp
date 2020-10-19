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
	int n;
	cin >> n;
	int a[n];
	int sum = 0, prod = 1, z = 0;
	for(int &i : a) {
		cin >> i;
		sum += i;
		prod *= i;
		if(i == 0) z++;
	}
	if(z == 0){
		if(sum == 0)
			cout << 1 << endl;
		else
			cout << z << endl;
	}else{
		if(sum == 0){
			cout << z << endl;
		}else{
			if(sum + z == 0){
				cout << z+1 << endl;
			}else
				cout << z << endl;
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
		cin >> t;
		while(t--){
			solve();
		}
	return 0;
}	
	
