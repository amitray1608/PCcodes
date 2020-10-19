//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;	
int dp[20005][20005];

int min(int x, int y, int z) 
{ 
	return min(min(x, y), z); 
} 

void solve(){
	string a, b;
	cin >> a >> b;
	int n = (int)a.size();
	int m = (int)b.size();
	
	//for(int i = 1; i<=n; i++) dp[i][0] = i;
	//for(int i = 1; i<=m; i++) dp[0][i] = i;
	for (int i=0; i<=m; i++) 
	{ 
		for (int j=0; j<=n; j++) 
		{ 
			// If first string is empty, only option is to 
			// insert all characters of second string 
			if (i==0) 
				dp[i][j] = j; // Min. operations = j 

			// If second string is empty, only option is to 
			// remove all characters of second string 
			else if (j==0) 
				dp[i][j] = i; // Min. operations = i 

			// If last characters are same, ignore last char 
			// and recur for remaining string 
			else if (a[i-1] == b[j-1]) 
				dp[i][j] = dp[i-1][j-1]; 

			// If the last character is different, consider all 
			// possibilities and find the minimum 
			else
				dp[i][j] = 1 + min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]); // Replace 
		} 
	} 
	cout << dp[m][n] << endl;
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
