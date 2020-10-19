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
  vector<pair<ll, ll>>a(n);
  for(pair<ll, ll> &i : a)
    cin >> i.first >> i.second;
  int count = 0;
  stack<ll>st;
  for(int i = 0; i < n; i++) {
    while(!st.empty() and st.top() >= a[i].second) {
      count++;
      st.pop();
    }
    st.push(a[i].second);
  }
  if(!st.empty())count++;
  cout << count << endl;
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1, tt = 0;
		//cin >> t;
		while(t--){
			//tt++;
			//cout << "Case #" << t << ": ";
			solve();
		}
	return 0;
}
