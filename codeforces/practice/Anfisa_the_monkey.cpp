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
	int k, a, b;
	string s;
    cin >> k >> a >> b >> s;
    int len = (int)s.length();
    if (k * a > len || k * b < len) {
        cout << "No solution" << endl;
        return;
    }
    int rem = len - k * a;
    int pos = 0;
    for(int i = 0; i < k; i++) {
        int cur = min(b, a + rem);
        rem -= cur - a;
        cout << s.substr(pos, cur) << endl;
        pos += cur;
    }
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
