//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
vector<string> digits = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
void solve(){
	int n, k;
	cin >> n >> k;
	vector<string>s(n);
	vector<vector<int>>dist(n, vector <int>(10));
	for(int i = 0; i < n; i++){
		cin >> s[i];
		for(int d = 0; d < 10; d++){
			for(int j = 0; j < 7; j++){
				char x = s[i][j];
				char y = digits[d][j];
				if(x == '1' and y == '0'){
					dist[i][d] = -1;
					break;
				}
				if(x == '0' and y == '1')
					++dist[i][d];
			}
		}
	}
	vector<vector<int>>dp(n+1, vector<int>(k+1));
	dp[n][0] = 1;
	for(int i = n; i > 0; i--){
		for(int j = 0; j <= k; j++){
			if(dp[i][j]){
				for(int d = 0; d < 10; d++){
					if(dist[i-1][d] != -1 and j+dist[i-1][d] <= k){
						dp[i-1][j+dist[i-1][d]] = 1;
					}
				}
			}
		}
	}
	if(dp[0][k] == 0){
		cout << -1 << endl;
		return;
	}
	for(int i = 0; i < n; i++){
		int now = -1;
		for(int d = 9; d >= 0; d--){
			if(dist[i][d] != -1 and k >= dist[i][d] and dp[i+1][k-dist[i][d]]){
				now = d;
				k -= dist[i][d];
				break;
			}
		}
		assert(now != -1);
			cout << now;
	}
	cout << endl;
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
