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
	char a[9][9];
	int n = 9;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> a[i][j];
			
		a[0][8] = a[0][7];
		a[1][5] = a[1][4];
		a[2][2] = a[2][1];
		a[3][7] = a[3][6];
		a[4][4] = a[4][3];
		a[5][1] = a[5][0];
		a[6][6] = a[6][7];
		a[7][3] = a[7][4];
		a[8][0] = a[8][1];

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			cout <<  a[i][j];
		cout << endl;
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
