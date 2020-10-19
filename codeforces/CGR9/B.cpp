//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
// int n, m;


void solve(){
  int n, m;
  cin >> n >> m;
  ll a[n][m];
  bool flag = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> a[i][j];
      int count = 0;
      if(i > 0 and i < n-1 and j > 0 and j < m-1)
        count = 4;
      else if((i == 0 and j == 0) or(j == m-1 and i == n-1))
        count = 2;
      else if((i == 0 and j == m-1) or (j == 0 and i == n-1))
        count = 2;
      else if(i == 0 or j == 0 or j == m-1 or i == n-1)
        count = 3;
      if(count < a[i][j])
        flag = true;
    }
  }
  if(flag){
    cout << "NO" << endl;
    return;
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(i == 0 and j == 0)
        a[i][j] = 2;
      else if(i == n-1 and j == m-1)
        a[i][j] = 2;
      else if(i == 0 and j == m-1)
        a[i][j] = 2;
      else if(i == n-1 and j == 0)
        a[i][j] = 2;
      else if(i == 0 or j == 0 or i == n-1 or j == m-1)
        a[i][j] = 3;
      else
        a[i][j] = 4;
    }
  }
  cout << "YES" << endl;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++)
      cout << a[i][j] << ' ';
    cout << endl;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  