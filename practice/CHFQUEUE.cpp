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
  int a[n];
  for(int &i : a) cin >> i;
  stack<pair<int, int>> st;
  ll ans = 1;
  for(int i = 0; i < n; i++) {  
    if(st.size() == 0)
      st.push({a[i], i});
    else if(a[i] < st.top().first) {
      while(st.top().first > a[i]) {
        ans = (ans * (i - st.top().second + 1))%MOD;
        st.pop();
        if(st.size() == 0)
          break;
      }
      st.push({a[i], i});
    } else
      st.push({a[i], i}); 
  }
  cout << ans << endl;
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
			//tt++;
			//cout << "Case #" << t << ": ";
			solve();
		}
	return 0;
}

/*
1
9 6
5 4 1 3 2 3 4 6 1
*/