//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
int n, x[200005], p, bit[200005];
  
void update(int x, int d){
    while (x <= n){
        bit[x] += d;
        x += x & (-x);
    }
}
int query(int x){
    int ret = 0;
    for (int i = 17; i >= 0; i--){
        if (ret+(1<<i) <= n && bit[ret+(1<<i)] < x){
            ret += (1<<i);
            x -= bit[ret];
        }
    }
    return ret+1;
}
void solve(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> x[i];
        update(i, 1);
    }
    for (int i = 1; i <= n; i++){
        cin >> p;
        int ret = query(p);
        cout << x[ret] << " ";
        update(ret, -1);
    }
    cout << "\n";
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1, tt = 0;
//		cin >> t;
		while(t--){
			//tt++;
			//cout << "Case #" << t << ": ";
			solve();
		}
	return 0;
}
