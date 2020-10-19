//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

const int N = 201;
vector<bool> prime;
vector<int> semi;
map<int, int>sum;
void seive() {
  prime.resize(N, true);
  prime[1] = false;
  for(int i = 2; i*i < N; i++) {
    if(prime[i]) {
      for(int j = i*i; j < N; j += i)
        prime[j] = false;
    }
  }
  for(int i = 2; i < N; i++) {
    if(!prime[i]) continue;
    for(int j = i+1; j < N; j++) {
      if(prime[j])
        semi.push_back(i*j);
    }
  }
  for(int i : semi) {
    for(int j : semi) {
      sum[i+j] = 1;
    }
  }
}

void solve() {
  int n;
  cin >> n;
  cout << (sum[n] ? "YES" : "NO") << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  cin >> t;
  seive();
  for(int tt = 1; tt <= t; tt++) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  