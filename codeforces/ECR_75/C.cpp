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
	string s;
	cin >> s;
	string ev, od;
	
	for(char c : s) ((c - '0') & 1) ? od += c : ev += c;
	
	reverse(ev.begin(), ev.end());
	reverse(od.begin(), od.end());
	string ans;
	while(!ev.empty() || !od.empty()){
		if(od.empty() || (!ev.empty() && od.back() > ev.back())) {
			ans += ev.back();
			ev.pop_back();
		} else {
			
			ans += od.back();
			od.pop_back();
		}
	}
	cout << ans << endl;
}

int main(){
	#ifdef RAY
		freopen("input.txt", "r", stdin);
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
