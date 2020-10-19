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
	int n, m, t = 0;
    cin >> n >> m;
    while((1ll << t) * n < m ) t++;
	int h = (1ll << t) * n - m;
    int kv = h / (1ll << t);
    h %= (1ll << t);
    while(h > 0)
		kv += h%2, h /= 2;
    cout << kv+t;
   
   	int a,b;
	cin >> b >> a;
	int ans = 0;
	while( a != b)
	{
		if( a < b )
		{
			++a;
			++ans;
			continue;
		}
		if( a % 2) a++; else a/=2;
		++ans;
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
		//cin >> t;
		while(t--){
			solve();
		}
	return 0;
}
