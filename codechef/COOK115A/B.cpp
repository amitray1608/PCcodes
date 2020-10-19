//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
  
ll maxSubArraySum(ll a[], ll size) { 
    ll max_so_far = INT_MIN, max_ending_here = 0; 
  
    for (int i = 0; i < size; i++) 
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
	int n;
	cin >> n;
	ll a[n], sum = 0, pref[n] = {0}, j = 0, x = INT_MIN, p = 0;
	for(ll &i : a){
		cin >> i;
		sum += i;
		p += i;
		if(x < p)
		pref[j++] = p, x = p;
		if(p < 0)
			p = 0;
	}
	for(int i = 0; i < n; i++)
		cout << pref[i] << " ";
	cout << endl;
	
	ll maxi = maxSubArraySum(a, n);
	if(sum == maxi){
		for(int i = 0; i < n; i++)
			cout << sum << " ";
		cout << endl;
	}else{
		cout << maxi << " "
		for(int i = 0; i < n-1; i++){
			
		}
		cout << endl;
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
