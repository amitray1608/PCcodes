//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
const int INF = 1000000; 
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
void solve(){
        int n;
        string s;
        cin >> n >> s;
        int prev[26], ans = 0;
        memset(prev, -1, sizeof(prev));
        for(int i = 0; i < s.length(); i++) {
            if (prev[s[i] - 'a'] != -1) {
                int cur = n - i + prev[s[i] - 'a'];
                if (cur > ans) ans = cur;
            }
            prev[s[i] - 'a'] = i;
        }
        cout << ans << endl;
}

int main(){
	#ifndef RAY
	//	freopen("input.txt", "r", stdin);
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
	
