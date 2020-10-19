#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve(){
	int n;
  cin >> n;
  int sum = 0;
  vector<int> a(n);
  for(int &i : a) cin >> i, sum += i;
  bool flag = true;
  if(sum & 1) {
    cout << n-1 << endl;
    for(int &i : a) {
      if(flag and i) {
        flag = false;
        continue;
      }
      cout << i << ' ';
    }
    cout << endl;
  } else {
    cout << n << endl;
    for(int &i : a)
      cout << i  << ' ';
    cout << endl;
  } 
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
