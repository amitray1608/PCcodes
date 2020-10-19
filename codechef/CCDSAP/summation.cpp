#include<bits/stdc++.h>
using namespace std;
int main(){
	int t, tt = 0;
	cin >> t;
	while(t--){
		tt++;
		int n;
		cin >> n;
		int a[n];
		long long ans = 0;
		for(int &i : a) cin >> i, ans += (i*(n+1));
		cout << "Case " << tt << ": " << ans << endl; 
	}
	return 0;
}
