#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const ll siz = 1e6 + 5;
#define deb(times) cout << #times << " = " << times << endl;

int main(){
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;
//	vector< vector< int > > v(n, vector<int>(m));
	int v[n][m];
	int row[n], col[m];
	for(int i = 0; i<n; i++){
		row[i] = i+1;
		for(int j = 0; j<m; j++)	
		cin >> v[i][j], col[j] = j+1;
	}
	
	while(k--){
		int tmp;
		char x;
		cin >> x;
		int l, r;
		cin >> l >> r;
	//	l--, r--;
		if(x == 'c'){
			 tmp = col[l-1];
			col[l-1] = col[r-1];
			col[r-1] = tmp;
		}
		else if(x == 'r'){
			tmp = row[r-1];
			 row[r-1] = row[l-1];
			 row[l-1] = tmp;
		}
		else{
			int x = row[l-1]-1, y = col[r-1]-1;
			cout << v[x][y] << '\n';
		}
	}
	return 0;
}
	
