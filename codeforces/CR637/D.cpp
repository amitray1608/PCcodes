//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
string s[2005];
vector<int> digit;
int dp[2005][2005], n, k;
string seg[] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
bool rec(int pos, int x){
    if(pos == n)
		return x == 0;
    if(dp[pos][x] != -1)
		return (dp[pos][x]);
    for(int i = 9; i >= 0; i--){
        int count=0;
        for(int j = 0; j < 7; j++)
			if(s[pos][j] != seg[i][j])
				count++;
        if(x >= count) {
            if(rec(pos+1, x-count)){
				digit.push_back(i);
				return dp[pos][x] = 1;
			}
        }
    }
    return dp[pos][x] = 0;
}
void solve(){
	cin >> n >> k;
	memset(dp, -1, sizeof(dp));
	for(int i = 0; i < n; i++)
		cin >> s[i];
    bool is = rec(0, k);
	if(is){
		for(int i = n-1; i >= 0; i--)
			cout << digit[i];
		cout << endl;
	}
	else
		cout << -1 << endl;
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
	
