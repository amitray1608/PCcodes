//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
string ar[55];
int n, m;
bool vis[55][55];

void solve(){
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(ar[i][j] == 'B') {
				//cout << "####" <<  i << ' ' << j << '\n';
				for(int k = 0; k < 4; k++) {
					int x = i + dx[k], y = j + dy[k];
					if(x < 0 || x >= n || y < 0 || y >= m) continue;
					if(ar[x][y] == 'G') {
						cout << "No\n";
						return;
					}
					else if(ar[x][y] == '.') ar[x][y] = '#';
				}
			}
		}
		//cerr << ar[i] << '\n';
	}
	bool ok = true;
	queue<pair<int, int>> q;
	q.push({n - 1, m - 1});
	vis[n - 1][m - 1] = true;
	memset(vis, false, sizeof vis);
	while(!q.empty()) {
		auto t = q.front();
		q.pop();
		int x = t.first, y = t.second;
		if(ar[x][y] == 'B' || ar[x][y] == '#') continue;
		if(ar[x][y] == 'G') ar[x][y] = '.';
		for(int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];
			if(nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny]) continue;
			if(ar[nx][ny] == '#' || ar[nx][ny] == 'B') {
				continue;
			}
			vis[nx][ny] = true;
			q.push({nx, ny});
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			ok &= (ar[i][j] != 'G');
		}
	}
	cout << (ok ? "Yes" : "No") << '\n';
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1, tt = 0;
		cin >> t;
		while(t--){
			//tt++;
			//cout << "Case #" << t << ": ";
			solve();
		}
	return 0;
}
