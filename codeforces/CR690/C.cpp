#include<bits/stdc++.h>

using namespace std;
#define endl '\n'
#define deb(N) cout << #N << " = " << N << endl;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;

void solve() {
  int N;
  cin >> N;
  bool flag = false;
  if(N <= 9) {
    cout << N << endl;
    return;
  } else if(N > 45) {
    cout << -1 << endl;
    return;
  } else {
    vector<int> ans;
    int num = 0, d = 0, n = 9;
    while(N >= n and N > 0){
      num += (n * pow(10, d));
      N -= n;
      d++; n--;
    }
    if(N > 0){
        num += N * pow(10, d);
    }
    while(num) {
      ans.push_back(num%10);
      num /= 10;
    }
    sort(ans.begin(), ans.end());
    for(int i : ans) cout << i;
    cout << endl;
  }
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
