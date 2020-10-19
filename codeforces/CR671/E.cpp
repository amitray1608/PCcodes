#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef double dd;
const int MOD = 1e9 + 7;

void solve(){
  int n; cin >> n;
  vector<int>fact;
  for(int i = 2; i*i <= n; i++) {
    if(n%i != 0) continue;
    fact.push_back(i);
    if(n/i != i)
      fact.push_back(n/i);
  }
  fact.push_back(n);
  vector<int>ord;
  for(int i = 0; i < (int)fact.size(); i++) {
    if(fact[i] == -1) continue;
    ord.push_back(fact[i]);
    for(int j = i+1; j < (int)fact.size(); j++) {
      if(fact[j] != -1) {
        if(__gcd(fact[i], fact[j]) > 1)
            ord.push_back(fact[j]), fact[j] = -1;
      }
    }
  }
  int count = 0;
  for(int i = 0; i < (int)ord.size()-1; i++) {
    if(__gcd(ord[i], ord[i+1]) == 1) count++;
  }
  for(int i : ord)
    cout << i << ' ';
  cout << endl;
  cout << count << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1, tt = 0;
  cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
