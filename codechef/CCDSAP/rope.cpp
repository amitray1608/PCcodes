//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
vector<pair<int, int>>adj;
bool vis[1002][1002];
int X, Y, count1 = 0, n, m;
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
char a[1001][1001];
void dfs(int i, int j, int c){
	if(c > count1)
		count1 = c, X = i, Y = j;
	vis[i][j] = true;
	for(int ii = 0; ii < 4; ii++){
		int nx = i+dx[ii];
		int ny = j+dy[ii];
		if(nx < 0 || ny < 0 || nx >= n || ny >= m || a[nx][ny] == '#' || vis[nx][ny] ) continue;
			dfs(nx, ny, c+1);
	}
	vis[i][j] = 0;
}
void solve(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			cin >> a[i][j];
	}
	X = -1, Y = -1;
	memset(vis, 0, sizeof vis);
	bool flag = false;
	count1 = INT_MIN;

	//for(int i = 0; i < n; i++)
		//cout << a[i] << endl;
	 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == '.'){
				dfs(i, j, 0);
				flag = true;
				break;
			}
			if(flag)
				break;
		}
	}
	cout << "Before:" << endl;
	cout << count1 << " " << X << " " << Y << endl;
	count1 = INT_MIN;
	memset(vis, 0, sizeof vis);
	dfs(X, Y, 0);
	cout << "After" << endl;
	cout << count1 << " " << X << " " << Y << endl;
	cout << "Maximum rope length is " << count1 << ".\n";

}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1;
		cin >> t;
		while(t--){
			solve();
		}
	return 0;
}	
