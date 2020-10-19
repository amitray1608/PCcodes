#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef double dd;
const int MOD = 1e9 + 7;

struct DSU {
  vector<int> data;
  DSU(int n) {data.assign(n, -1);}
  bool unionSet(int x, int y) {
    x = root(x); y = root(y);
    if(x != y) {
      if (data[y] < data[x]) std::swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool findSet(int x, int y) {return root(x) == root(y);}
  int root(int x) {return data[x] < 0 ? x : data[x] = root(data[x]);}
  int size(int x) {return -data[root(x)]; }
};


void solve(){
  ll n, m, x;
  cin >> n >> m >> x;
  vector<ll>a(n), b(m);
  for(ll &i : a) cin >> i;
  for(ll &i : b) cin >> i;
  ll ans = 0, sum = 0, i = 0, j = 0;
  while(i < n and sum + a[i] <= x) {
    sum = sum + a[i];
    ans++;
    i++;
  }
  while(j < m and i >= 0) {
    sum = sum + b[j];
    j++;
    if(sum > x) {
      i--;
      if(i >= 0)
        sum = sum - a[i];
    } else
      ans++;  
  }
  cout << ans << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1, tt = 0;
  cin >> t;
  while(t--){
  //cout << "Case #" << ++t << ": ";
    solve();
  }
  return 0;
}

