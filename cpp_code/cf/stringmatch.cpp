//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

vector<int> fun(string s){
	int n = s.length();
	vector<int>p(n);
	for(int i = 0; i < n; i++){
		for(int k = 0; k <= i; k++){
				cout << s.substr(0, k) << " " << s.substr(i-k+1, k) << endl;
			if(s.substr(0, k) == s.substr(i-k+1, k)){
				//deb(k);
				//cout << i-k+1 << " " << k << endl;
				p[i] = k;

			}
		}
	}
	return p;
}


vector<int> pre(string s){
	vector<int>pi(n);
	for(int i = 1; i < n; i++){
		int j = pi[i-1];
		while(j > 0 and s[i] != s[j])
			j = pi[j-1];
		if(s[j] == s[i])
			j++;
		pi[i] = j;
	}
	return p;
}




vector<int>kmp(string s){
	int n = s.length();
	vector<int>p(n, 0);
	for(int i = 1; i < n; i++){
		int j = p[i-1];
		while(j > 0 && s[i] != s[j])
			j = p[j-1];
		if(s[i] == s[j])
			j++;
		p[i] = j;
	}	
	return p;
}

void solve(){
	string s;
	cin >> s;
	vector<int>ans = kmp(s);
	for(auto &i : ans)
		cout << i << " ";
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
