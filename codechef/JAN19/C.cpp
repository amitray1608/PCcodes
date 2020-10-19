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
	int n;
	cin >> n;
	if(n == 1) cout << "Hooray\n1" << endl;
	else if(n&1) cout << "Boo\n";
	else{
		int a[n+1][n+1] = {0};
		bool st[n*2][n+1], vis[n+1][n+1];
		memset(st, 0, sizeof st);
		memset(vis, 0, sizeof vis);
		cout << "Hooray\n";		
		// first row and column and diagonal;
		for(int i = 1; i <=n; i++) 
			a[1][i] = i, a[i][i] = 1, st[1][i] = 1, st[i][1] = 1, st[i][i] = 1, vis[i][1] = 1;
		
		for(int i = 2; i <=n; i++) 
			a[i][1] = i+(n-1), st[i+(n-1)][1] = 1, st[i+(n-1)][i] = 1;
				
		// initialising rows ans columns
		for(int i = 2; i <= n; i++){
			for(int j = i+1; j <= n-i+1; j++){
				int x = a[i][j] = a[i-1][j+1];
				st[x][i] = st[x][j] = vis[x][i] = 1;
				int y = a[j][i] = a[j+1][i-1];
				st[y][i] = st[y][j] = 1;
			}
		}
				//for(int i = 1; i <= (2*n)-1; i++){
			//for(int j = 1; j <= n; j++)
				//cout << st[i][j] << " ";
			//cout << endl;
		//}
		//filling the right ends
		for(int i = 2; i <= n; i++){
			for(int j = i; j <= n; j++){
				if(a[i][j]!= 0) continue;
			//cout << i << " " << j << endl;
				for(int k = 2; k <= n; k++){
					if((st[k][j] == 0 && st[k][i] == 0)){
						a[i][j] = k;
						if(i != j){
							a[j][i] = k+(n-1);
						}
						st[k+n-1][i] = st[k+n-1][j] = 1;
						st[k][j] = st[k][i] = 1;
						break;
					}
				}
				
			}
		}
		
		
				//bool array print
		//for(int i = 1; i <= (2*n)-1; i++){
			//for(int j = 1; j <= n; j++)
				//cout << st[i][j] << " ";
			//cout << endl;
		//}

		//final array print
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++)
				cout << setw(2) << a[i][j] << " ";
			cout << endl;
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
	
