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
	int one = 0, two = 0, three = 0;
	set<char>ss;
	int mini = INT_MAX;
	for(int i = 0; s[i]; i++){
		ss.insert(s[i]);
		if(s[i] == '1')
			one = i;
		if(s[i] == '2')
			two = i;
		if(s[i] == '3')
			three = i;
		if(ss.size() == 3){
			mini = min(mini, (max({one, two, three}) - min({one, two, three})) + 1);
		}
	}
	if(mini == INT_MAX)
		mini = 0;
		
	cout << mini << endl;
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
