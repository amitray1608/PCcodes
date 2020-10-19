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
	string s, p, t;
	cin >> s >> t >> p;
	int freq_p[26] ={0};
	for(char c : p) freq_p[c - 'a']++;
	string ss = "";
	int k = 0;

	for(int i = 0; i < (int)t.size(); i++){
		if(s[k] == t[i]) ss += s[k], k++;
		else if(freq_p[t[i] - 'a'] > 0) freq_p[t[i] - 'a']--, ss += t[i];
	}
	if(k < (int)s.size()){
		for(; k < (int)s.size(); k++) ss += s[k];
	}
	if(ss == t) cout << "yes\n";
	else cout << "no\n";
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
