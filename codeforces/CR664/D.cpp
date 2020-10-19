//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a%2 + b%2 + c%2 + d%2 <= 1) {
        cout << "Yes" << endl;
        return;
    } 
    if(min(a, min(b, c)) >= 1) {
        a--, b--, c--;
        d += 3LL;
        if(a%2 + b%2 + c%2 + d%2 <= 1) {
            cout << "Yes" << endl;
            return;
        } 
    }
    cout << "No" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10);
    int t = 1;
    cin >> t;
    for(int tt = 1; tt <= t; tt++) {
        //cout << "Case #" << tt << ": ";
        solve();
    }
    return 0;
}    