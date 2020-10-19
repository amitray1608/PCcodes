//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
vector<int> pre ;
ll power(ll a, ll n) {
	ll p = 1;
	while (n > 0){
		if(n%2) p = p * a;
		
		 n >>= 1, a *= a;
	} 
return p;
}

bool calc(int k, int n, int p)
{
    int m = n-k*p ;
    if(!m) 
		return 0;
    int dem = k ;
    while(m > 0 && dem--){
        int tmp = upper_bound(pre.begin(),pre.end(),m) - pre.begin()-1 ;
        m = m - pre[tmp]  ;
    }
    if(dem >= 0 && !m)
        return 1 ;
    return 0 ;
}

void solve(){
    int n,p ;
    cin >> n >> p ;
    for(int i = 0; i<31; i++){
        int x = power(2, i) ;
        pre.push_back(x) ;
    }
    for(int i = 0; i<31; i++)
        if(calc(i, n, p))
        {
            cout << i ;
            return;
        }
    cout << -1 ;
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
