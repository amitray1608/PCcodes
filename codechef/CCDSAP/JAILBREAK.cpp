//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

vector<vector<pair<int, int>>>dist;
string v;
int n, m;

void solve(){
  cin >> n >> m;
  v.resize(n);
  pair<int, int>f[2], k = 0;
  for(int i = 0; i < n; i++){
    cin >> v[i];
    for(int j = 0; j < m; j++)
        if(v[i][j] == '$')
          f[k++] = {i, j};
  } 
  
  dist.resize(n, vector<pair<int,int>>(m, {INT_MAX, 0}));
  // for(int i = 0; i < n; i++)
  //   for(int j = 0; j < m; j++)
  //     dist[i][j] = INT_MAX;
  
  deque<pair<int, int>>q;
  q.

}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << tt << ": ";
    solve()
  }
  return 0;
}  