#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<ll>> G(1000);
bool vis[1000];
ll level[1000];
vector< pair <ll, ll> > v[1000];
ll n, m;
ll dist[1000];
void printSolution() 
{ 
   printf("Vertex   Distance from Source\n"); 
   for (ll i = 0; i < n; i++) 
      cout <<  i << " " <<  dist[i] << endl; 
} 
   

void dijkstra(ll src)
{
	memset(vis, false, sizeof vis);
	dist[src] = 0;
	multiset< pair <ll, ll > >s;
	s.insert({0, 1});

	while(!s.empty())
	{

		pair <ll, ll > p = *s.begin();
		s.erase(s.begin());
		
		ll x = p.second; ll wei = p.first;
		if(vis[x]) continue;

		vis[x] = true;
	
		for(ll i = 0; i< v[x].size(); i++)
		{

			ll e = v[x][i].first;
			ll w  = v[x][i].second;
			if(dist[x] + w <  dist[e])
			{
				dist[e] = dist[x] + w;
				s.insert(dist[e], e);
			}

		}

	}
	printSolution();
}


int main(){
	memset(vis, 0, sizeof vis);
	cin >> n >> m;
	for(ll i = 0; i<m; i++)	
	{
		int u, vv, x;
		cin >> u >> vv >> x;
		v[u].push_back({vv,x });
	//	G[v].push_back(u);
	}

	dijkstra(1);
	//cout << endl << level[n-1] << endl;
return 0;
}
