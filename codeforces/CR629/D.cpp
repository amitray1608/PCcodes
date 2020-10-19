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
    string s = "";
    for(int  i = 0; i < n-2; i++){
		s += 'a';
	}
	s+="bb";
	//cout << s << endl;
	vector<string>ss;
	do{
		ss.push_back(s);
	}while(next_permutation(s.begin(), s.end()));
	sort(ss.begin(), ss.end());
	for(string c : ss)
		cout << c << endl;
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
