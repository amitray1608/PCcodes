//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

int p[MAXN];
int prime[MAXN][6];
int MAXK = 6;
void precompute()
{
  for(int i = 2; i < MAXN; i++) 
    if(p[i] == 0)
      for(int j=i; j < MAXN; j+=i)
        p[j]++;
  for(int i = 2; i < MAXN; i++)
    for(int j = 1; j < MAXK; j++)
      prime[i][j] = prime[i-1][j]+(p[i]==j?1:0);
}


void solve(){
  int a, b, k;
  cin >> a >> b >> k;
  cout << prime[b][k]-prime[a-1][k] << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  precompute();
  while(t--){
    //tt++;
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  