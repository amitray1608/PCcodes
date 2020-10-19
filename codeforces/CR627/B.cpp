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
	int n;
	cin >> n;
	int a[n+1];
	for(int i = 1; i <= n; i++) cin >> a[i];
	map<ll, ll> check;
    for (int i = 1; i <= n; i++){
        if (check[a[i]] != 0){
            if (i - check[a[i]] >= 2){ 
				cout << "YES" << endl;
					return ;
			}
			
        }else if(check[a[i]] == 0)
			check[a[i]] = i;
    }
    cout << "NO" << endl;
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
