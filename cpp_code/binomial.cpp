//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

int C(int n, int k){
	int ans = 1;
	
	for(int i = n-k+1; i <= n; i++) ans *= i;
	
	for(int i = 2; i<=k; i++) ans /= i;
	
	
return ans;
}

int better_C(int n, int k){
	
	double res = 1;
	
	for(int i = 1; i<=k; i++)
		res = res * (n-k+i) / i;
		
	return (int) (res + 0.01);
}
int c[100][100];
void pascal_triangle(int N){

		c[0][0] = 1;
	
	for(int n =1; n <= N; n++){
		c[n][0] = c[n][n] = 1;
		for(int k = 1; k<n; k++)
			c[n][k] = c[n-1][k-1] + c[n-1][k];
	}
	
	for(int i = 0; i<=N; i++){
		for(int j = 0; j <= i; j++)
			cout << c[i][j] << " ";
			
		cout << endl;
	}
}

void solve(){
	int n, k;
	cin >> n >> k;
	int ans = better_C(n, k);
	cout << ans << endl;
	
	pascal_triangle(7);
}

int main(){
	#ifndef RAY
		freopen("input.txt", "r", stdin);
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
