//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
const int N = 20;
const int inf = 1e9+5;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int n, m;
string b[N];
int bfs(int i, int j){
	queue<pair<int, int >>q;
	q.push(make_pair(i, j));
	int dist[N][N];
	memset(dist, inf, sizeof dist);
	dist[i][j] = 0;
	int maxi = 0;
	while(!q.empty()){
		auto t = q.front();
		q.pop();
		maxi = max(maxi, dist[t.first][t.second]);
		for(int ii = 0; ii < 4; ii++){
			int x = t.first + dx[ii], y = t.second + dy[ii];
			if(x < 0 || x >= n || y < 0 || y >= m || b[x][y] == '#')
				continue;
			if(dist[x][y] <= dist[t.first][t.second]+1) continue;
			dist[x][y] = dist[t.first][t.second]+1;
			q.emplace(x, y);
		}
	}
	
	return maxi;
}



void solve(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
			b[i].clear();
			cin >> b[i]; 
	}

	int maxi = 0;
	for(int i = 0;  i < n; i++){
		for(int j = 0; j < m; j++){
			if(b[i][j] == '.')
			maxi = max(maxi, bfs(i, j));
		}
		
	}
	cout << maxi << endl;
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1;
		//cin >> t;
		while(t--){
			solve();
		}
	return 0;
}
	
