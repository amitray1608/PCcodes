#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector <int> check ;
bool vis[1000000] ;
vector <int> G[1000000] ;
int beg[1000000] , end[1000000] ;
void DFS(int s){
  
  vis[s] = true ;
  beg[s] = (int)check.size() ;
  check.push_back(s) ;
  for(int i =0 ;i < G[s].size() ;i++)
    if(vis[G[s][i]] == false)
      DFS(G[s][i]) ;
    end[s] = (int)check.size() ;
}
  

void solve(){
	//cout << fixed << setprecision(6);
  int n , q ;
  cin >> n >> q ;
    memset(vis, fasle, sizeof vis);
  for(int i = 1 ; i < n ;i++){
    
    int u , v ;
    cin >> u >> v ;
    G[u].push_back(v) ;
    G[v].push_back(u) ;
  }
  DFS(1) ;
  int calc[(int)check.size() + 10] ;
  for(int i =0 ; i < (int)check.size() + 10 ;i++)
    calc[i] =0 ;
  while(q--) {
    
    int p , x ;
    cin >> p >> x ;
    calc[beg[p]]+=x ;
    calc[end[p]]-=x;
  }

  for(int i=1 ; i < check.size() ;i++)
    calc[i] = calc[i - 1] + calc[i] ;

  for(int i = 1 ; i <= n ;i++)
    cout << calc[beg[i]] <<" ";


}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
	//cin >> t;
	while(t--)
	{
		solve();
	}
		return 0;
}
