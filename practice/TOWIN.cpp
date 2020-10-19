#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve(){
  int n;
  cin >> n;
  int even = 0, odd = 0;
  int a[n];
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a+n);
  int turn = 1;
  for(int i = n-1; i >= 0; i--) {
    if(i == n-2) {
      odd += a[i];
      if(i-1 >= 0)
        odd += a[--i];
      turn = 1;
    } else if(i == n-1) {
      even += a[i];
    } else {
      if(turn)
        even += a[i], turn = 0;
      else
        odd += a[i], turn = 1;
    }
  }
  if(odd > even)
    cout << "second" << endl;
  else if(odd < even)
    cout << "first" << endl;
  else
    cout << "draw" << endl;
}

int main(){
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
