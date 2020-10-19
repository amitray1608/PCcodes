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
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	if(n*a != m*b){
		cout << "NO" << endl;
		return;
	}
   vector<vector<int>>v(n, vector<int>(m, 0));
   int s = 0;
   for(s = 1; s < m; s++)
      if(s*n % m == 0)
         break;
   cout << "YES" << endl;
    for (int i = 0, dx = 0; i < n; i++, dx += s) {
      for (int j = 0; j < a; j++) {
        v[i][(j + dx) % m] = 1;
      }
    }
   for(auto i : v){
      for(auto ii : i)
         cout << ii;
      cout << endl;
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
