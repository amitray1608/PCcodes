//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
vector<vector<int>>v, cost, vis;
int n;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
bool isvalid(int x, int y){
	if(x >= 0 and x < n and y >= 0 and y < n)
		return true;
	return false;
}

void bfs(int x, int y, int used, int mini, int dis){
	if(vis[x][y])
		return;
	vis[x][y] = 1;
	for(int i = 0; i < 4; i++){
		int xx = x + dx[i], yy = y+dy[i];
		//cout << xx << " " << yy << endl;
		if(isvalid(xx, yy)){
			cost[xx][yy] = min(cost[xx][yy], cost[x][y]+1);
			if(v[xx][yy] == 0)
				bfs(xx, yy, used);
			else if(used == 1)
				bfs(xx, yy, 0);
		}
	}
}

void solve(){
	cin >> n;
	v.resize(n, vector<int>(n));
	cost.resize(n, vector<int>(n));
	vis.resize(n, vector<int>(n, 0));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> v[i][j], cost[i][j] = INT_MAX;
	cost[0][0] = 1;
	bfs(0, 0, 1);
	cout << cost[n-1][n-1] << endl;
	
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
	
/*
4 4
0 1 1 0 
0 0 0 1 
1 1 0 0 
1 1 1 0 
6 6
0 0 0 0 0 0 
1 1 1 1 1 0 
0 0 0 0 0 0 
0 1 1 1 1 1 
0 1 1 1 1 1 
0 0 0 0 0 0
6 5
0 0 0 0 0 
1 1 1 1 0 
1 1 1 1 0 
0 1 1 0 0 
0 1 1 0 1
0 0 0 0 0 
*/
