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
    string s = string(n, 'a');
    //int first = (3 + sqrt(8*k - 7) ) / 2 , last;
    //int x = (int)floor((-1 + sqrt(1 + 8 * k - 8)) / 2); 
    //int base = (x * (x + 1)) / 2 + 1; 
	for(ll i=0; i < n; i++) s[i]='a';
	s[n-2] = s[n-1] = 'b';
	ll first = 0, last = 0;
	while(first + 1 + last < k){
		first = first + 1 + last;
		last++;
	}
	ll x = n-2;
	while(last--){
		s[x] = 'a';
		x--;
	}	
	s[x] = 'b';
	ll q = k-(first+1);
	swap(s[n-1], s[n-1-q]);
	for(ll i = 0; i < n; i++)cout << s[i];
    cout << endl;
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
