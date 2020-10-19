#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//vector<vector<int>>adj;
//vector<int>dis;
vector<bool>vis;
int inf = 1e9;
#define deb(x) cout << #x << " " << x << endl;
const int N = 10878;
int adj[N][N];
int d, s;
void djikstra(int n, int src) {
  vector<int> dis(n, inf);
  vector<bool> mark(n, false);
  vector<int> p(n, -1);
  dis[src] = 0;
	//for(int i = 0; i < n; i++){
		//for(int j = 0; j < n; j++)
			//cout << adj[i][j] << ' ';
		//cout << endl;
	//}
	
  for (int i = 0; i < n; ++i) {
    int ms = inf, k = -1;
    for (int j = 0; j < n; ++j) {
      if (!mark[j] && (dis[j] < ms || k == -1)) {
        ms = dis[j], k = j;
      }
    }    
    if(dis[k] == inf)
        break;
    //deb(k);
    mark[k] = true;
    for (int j = 0; j < n; ++j) {
		//if (!mark[j]){ 
			if(dis[k]+adj[k][j] < dis[j])
				p[j] = k;
			dis[j] = std::min(dis[j], dis[k] + adj[k][j]);
		//}
    }
  }
	cout << dis[d] << endl;
	//restore path
	vector<int>path;
	for(int i = d; i != src; i = p[i])
		path.push_back(i);
	path.push_back(src);
	reverse(path.begin(), path.end());
	
	for(int i : path)
		cout << i << " ";
		
	cout << endl;
}

void solve(){
	int n;
	cin >> n;
	//adj.resize(n, vector<int>(n));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> adj[i][j];
			 if(adj[i][j] == 0) adj[i][j] = inf;
		}
	}
	cin >> s >> d;
	djikstra(n, s);
}
int main(){

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
/*
5 7
1 2 5
1 4 4
1 3 3
2 3 1
2 5 1
4 5 2
3 4 2
1
*/
