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
   ll n, k;
   cin >> n >> k;
   ll a[2*n], pref1[2*n] = {0}, pref2[2*n] = {0};
   for(ll i = 0; i < n; i++){
      cin >> a[i], a[i+n] = a[i];
   }
   pref1[0] = a[0], pref2[0] = (a[0]*(a[0]+1) / 2);
   for(ll i = 1; i < 2*n; i++){
      pref1[i] = pref1[i-1]+a[i];
      pref2[i] = pref2[i-1] + (a[i]*(a[i]+1) / 2);
   }
   //for(int i = 0; i < 2*n; i++)
      //cout << pref1[i] << " ";
   //cout << endl;
   //for(int i = 0; i < 2*n; i++)
      //cout << pref2[i] << " ";
   //cout << endl;
   ll ans = INT_MIN, l = 0, h = 2*n-1;
   for(ll i = 2*n-1; i >= n; i--){
      l = 0, h = i;
      ll pos = i;
      ll maxi = pref1[i];
      while(l <= h){
         ll mid = (l+h)/2;
         if(maxi - pref1[mid] < k)
            h = mid-1, pos = mid;
         else
            l = mid+1;
      }
      ll x = maxi - pref1[pos-1] - k;
      ll sum = pref2[i] - pref2[pos-1];
      sum -= (x*(x+1))/2;
      ans = max(ans, sum);
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
