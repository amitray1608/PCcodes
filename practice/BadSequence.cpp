#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  stack<char> st;
  for(int i = 0; i < n; i++) {
    if(st.empty() or s[i] == '(')
      st.push(s[i]);
    else if(st.top() == '(' and s[i] == ')')
      st.pop();
    else 
      st.push(s[i]);
  }
  int o = 0, c = 0;
  while(!st.empty()) {
    char x = st.top();
    st.pop();
    x == ')' ? c++ : o++;
  }
  if(o != c or o > 1 or c > 1)
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
}

int main(){
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
