//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 5e5 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve(){
	int n;
	cin >> n ;
    pair<int, int>p[siz];
    bool vis[siz];
    int l, cnt;
    vector<int>v;
    int a[siz];
    ll ans = 0;
    for (int j = 1; j<=n; j++)
    {
        cin >> l ;
        int mini = 100000000;
        int maxi = -1;
        bool flag, bol ;
        flag = bol = 0;

        for (int i = 1 ; i<=l; i++){
            cin >> a[i];
            mini = min(a[i], mini);
            maxi = max(a[i], maxi);
        }
        for (int i = 1; i <= l; i++){
            if (a[i] == mini)
                flag = 1;
            else if (flag)
                bol = 1;
        }
        if (bol)
            vis[j] = 1, cnt++;
        else
            v.push_back(maxi);
        
        if (mini != maxi)
            ans++;
        p[j] = {mini, maxi};
    }
    sort(v.begin() , v.end());
    for (int i = 1; i<=n; i++)
    {
        if (vis[i]){
            ans += n-1;
            continue ;
        }
        ans += cnt ;
        int u = upper_bound(v.begin() , v.end() , p[i].first) - v.begin();
        u = v.size() - u;
        ans += u ;
        ans -= (p[i].second > p[i].first);
    }
    cout << ans << endl;
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
	
