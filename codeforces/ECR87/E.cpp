#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Max = 1e5+1;

int rec(int n, int sum){
	if(n == -1)
		return 0;
	ll sumx = sum*10 + a[i];
	sumx = max(rec(n-1, sum), rec(n-1, sumx));
	return sumx;
}

void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int &i : a) cin >> i;
	sort(a, a+n);
	rec(n-1, 0);
	
}

int main(){
	int t = 1;
	cin >> t;
	for(int i = 1; i <= t; i++){
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}	
	
