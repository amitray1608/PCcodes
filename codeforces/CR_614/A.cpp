//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
void solve(){
	int n, q;
	cin >> n >> q;
	int a[2][n+1];
	memset(a, 0, sizeof a);
	bool flag = true;
	pair<int, int>p;
    priority_queue <pair<int, int>, vector<int>, greater<int> > pq; 
	pq.push(make_pair(n, 2));
	while(q--){
		int x, y;
		cin >> x >> y;
		a[x][y] ^= 1;
		if(a[x][y] == 1){
			if(x == 1){
				if(a[x+1][y] == 1 || a[x+1][y+1] == 1 || a[x+1][y+1] == 1)
					pq.push(make_pair(y, x));
					
			}else{
				if(a[x-1][y] == 1 || a[x-1][y-1] == 1 || a[x-1][y+1] == 1)
					pq.push(make_pair(y, x));
			}
		}	
		p = pq.top();
		if(p.second == 2 && p.first == n)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
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
