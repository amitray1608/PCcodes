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
    int n, m;
    cin >> n >> m;
    ll a[m], total = 0;
	vector<ll> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
		b[i] = a[i];
        total += a[i];
    }
    if (total < n) {
        cout << -1 << endl;
        return;
    }
    ll dif = total - n;
    for (int i = 0; i < m; ++i) {
        ll left = min(dif, a[i] - 1);
        dif -= left;
        a[i] -= left;
    }
    int pos = 1;
    vector<ll> ans;
    for (int i = 0; i < m; i++) {
        if (pos > n - b[i] + 1) {
            cout << -1 << endl;
            return;
        }
        ans.push_back(pos);
        pos += a[i];
    }
    for (auto &c : ans)
        cout << c << " ";
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
	
