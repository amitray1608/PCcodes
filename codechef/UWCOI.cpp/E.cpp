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
	int h, w, q;
	cin >> h >> w >> q;
	int a[h][w];
	bool flag = 1;
	int  prev = 0;
	int cc = 0;
	for(int i = 0; i < h ; i++){
		for(int j = 0; j < w; j++){
			cin >> a[i][j];
			if(prev != a[i][j] && cc > 0) flag = false;
			prev = a[i][j];
			cc++;
		}
	}

	while(q--){
		int x, y, p;
		cin >> x >> y >> p;
		x--, y--;
		if(flag){
			if(p > a[x][y])
				cout << h*w << endl;
			else
				cout << 0 << endl;
		}else{
			int count = 0, xx, yy;
			xx = y;
			yy = y+1;	
			while(xx >= 0){
				if(a[0][xx] <= p)
					count++;
				else
					break;
				xx--;
			}
			
			while(yy < w){
				if(a[x][yy] <= p)
					count++;
					else
						break;
				yy++;
			}
			cout << count << endl;
		}
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
