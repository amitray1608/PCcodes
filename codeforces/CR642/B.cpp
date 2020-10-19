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
	int a[n], b[n];
	for(int &i : a) cin >> i;
		for(int &i : b) cin >> i;
	sort(a, a+n);
	sort(b, b+n);
	ll ans = 0, j = n-1, count = 0;
	for(int i = n-1; i >=0 ;){
		if(b[j] > a[i] && k > 0){
			ans += b[j--];
			k--;
			count++;
		}else{
			ans+=a[i--];
			count++;
		}
		if(count == n)
			break;
		
	}
	cout << ans << endl;
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
	
