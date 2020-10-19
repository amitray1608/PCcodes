//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
ll maxSubArraySum(ll a[], ll pos, ll size) 
{ 
    ll max_so_far = INT_MIN, max_ending_here = 0; 
  
    for (ll i = pos; i < size; i++) 
    { 
        max_ending_here = max_ending_here + a[i]; 
        if (max_so_far < max_ending_here) 
            max_so_far = max_ending_here; 
  
        if (max_ending_here < 0) 
            max_ending_here = 0; 
    } 
    return max_so_far; 
} 
void solve(){
	ll n;
	cin >> n;
	ll a[n];
	ll sum = 0;
	for(ll &i : a) cin >> i, sum += i;
	ll suma = maxSubArraySum(a, 0, n-1);
	ll sumb = maxSubArraySum(a, 1, n);
	//deb(sum);
	//deb(suma);
	//deb(sumb);
	if(sum > suma && sum > sumb)
		cout << "YES\n";
	else
		cout << "NO\n";
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
