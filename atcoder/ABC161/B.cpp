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
	int n, m;
	cin >> n >> m;
	double a[n], sum = 0;
	for(double &i : a) cin >> i, sum+=i;
	int count = 0;
	for(int i = 0; i < n; i++){
		if(a[i] >= (sum/(4.0*m)))count++;
	}
	if(count >= m)
		cout << "Yes";
	else
		cout << "No";
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
	
