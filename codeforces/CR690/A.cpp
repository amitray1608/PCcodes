#include<bits/stdc++.h>

using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int &i : a) cin >> i;
  vector<int> ans;
  int i = 0, j = n - 1, k = 1;
  while(i <= j) {
    if(k&1) ans.push_back(a[i++]);
    else ans.push_back(a[j--]);
    k++;
  }
  for(int &i : ans) cout << i << ' ';
  cout << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1, tt = 0;
  cin >> t;
  while(t--){
    //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite
