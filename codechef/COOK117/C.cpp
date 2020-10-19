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
	ll n;
	cin >> n;
	ll a[n];
	for(ll &i : a) cin >> i;
	ll ans = 0, curr = 0, status = 1, ans1 = 0;
	//pos
	ll counta = 0, countb = 0;
	for(int i = 0; i < n; i++){
		if(status && a[i] < 0) continue;
		if(!status && a[i] > 0) continue;
		if(!status){
			curr = INT_MIN;
			while(i < n && a[i] < 0){
				curr = max(curr, a[i]);
				i++;
			}
			i--;
		status ^= 1;	
		}else{
			curr = 0;
			while(i < n && a[i] > 0){
				curr = max(curr, a[i]);
				i++;
			}
			i--;
		status ^= 1;
		}
		//cout << curr << " ";
		ans += curr;
		counta++;
	}
	//cout << endl;
	//neg
	status = 0;
	for(int i = 0; i < n; i++){
		if(status && a[i] < 0) continue;
		if(!status && a[i] > 0) continue;
		if(!status){
			curr = INT_MIN;
			while(i < n && a[i] < 0){
				curr = max(curr, a[i]);
				i++;
			}
			i--;
			status ^= 1;
		}else{
			curr = 0;
			while(i < n && a[i] > 0){
				curr = max(curr, a[i]);
				i++;
			}
			i--;
				status ^= 1;

		}
		ans1 += curr;
		//cout << curr << " ";
		countb++;
	}
	//cout << endl;
	//deb(ans);
	//deb(ans1);
	if(counta == countb)
		cout << max(ans, ans1) << endl;
	else if(counta > countb)
		cout << ans << endl;
	else
		cout << ans1 << endl;
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
