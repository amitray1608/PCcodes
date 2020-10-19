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
  vector<int>a(n);
  for(int &i : a) cin >> i;
  int ans = 0;
  auto get = [&](int p) {
    int res = 0;
    for(int i = 1; i < n; i++) {
      res += (a[i] - a[i-1] - 1) / p;
    }
    return (bool) (res <= k);
  };
  int l = 1, r = a.back(), res = 1.01e9;
  while( l <= r ) {
    int m = (l + r) >> 1;
    if(get(m))
      res = m, r = m - 1;
    else
      l = m + 1; 
  }
  cout << res << endl;
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1, tt = 0;
		cin >> t;
		while(t--){
			tt++;
			cout << "Case #" << tt << ": ";
			solve();
		}
	return 0;
}
