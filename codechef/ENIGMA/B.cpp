//“Make it work, make it right	, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
vector<ll> fact;
void factor(int n){
	for (int i=1; i <= sqrt(n); i++) { 
        if (n%i == 0) { 
            if (n/i == i) 
                fact.push_back(i);
            else 
                fact.push_back(i), fact.push_back(n/i);
        } 
    } 
}
void solve(){
	ll n,k;
	cin >> n >> k;
	ll sum = k * (k+1);
    sum /= 2;  
    ll dist = n/sum, rem = 1;
	if(sum > n)
	  cout << -1 << endl;
	else{
         cout << n / sum << endl;
	}
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
	
