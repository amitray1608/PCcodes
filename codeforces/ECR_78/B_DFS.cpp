#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const int siz = 1e5 + 5;
vector< vector<ll> > visited;
vector< vector<ll> > matrix;
ll n;
ll X[] = {1, 2, -1, 2, -2, 1, -2, -1};
ll Y[] = {2, 1, 2, -1, 1, -2, -1, -2};
bool check(ll a, ll b){
		return(a>=0 && a<n && b<n && b >= 0 && visited[a][b] == false);
}

void dfs(int x, int y, int color){
	
	visited[x][y] = true;
	matrix[x][y] = color;
	
	for(int i = 0; i<8; i++)
	{
		ll dx = x + X[i], dy = y + Y[i];
		if(check(dx, dy))
			dfs(dx, dy, color^1);
	}
	
}

void solve()
{
	cin >> n;
	visited.resize(n, vector<ll>(n));
	matrix.resize(n, vector<ll>(n));
	//memset(visited, false, sizeof visited);
	dfs(0, 0, 0);
	
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<n; j++)
			(matrix[i][j]) ? cout << "W" : cout << "B";
			
		cout << endl;
	}
}
 
int main()
{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		ll t = 1;
	//	cin >> t;
		while(t--)
		{
			solve();
		}
	return 0;
}
