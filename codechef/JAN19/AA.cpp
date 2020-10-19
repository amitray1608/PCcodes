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
	int s;
	cin >> s;
	int a, b, c;
	cin >> a >> b >> c;
	int sum = a+b+c;
	if(s >= sum) cout << 1 << endl;
	else if(s == 1) cout << sum << endl;
	else{
		int countA = 0, countB = 0;
		if(s >= a){
			if(s >= a+b)
				countA =  2;
			else 
				countA = 3;
		}
		if(s >= c){
			if(s >= b+c)
				countB = 2;
			else 
				countB = 3;
		}
		cout << min (countA, countB) << endl;
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
