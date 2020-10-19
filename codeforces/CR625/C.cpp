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
	int n;
	cin >> n;
	string s;
	cin >> s;
	for(int c = 'z'; c > 'a'; c--){
		bool flag = 0;
		for(int i = 0;  i< (int)s.size(); i++){
			if(s[i] == c){
				if((i && s[i-1] == c-1 ) || (i + 1 < (int)s.size() && s[i+1] == c-1)){
					flag = 1;
					s.erase(s.begin()+i);
					break;
				}
			}
		}
		if(flag)
			c++;
	}
	cout << n-(int)s.size() << endl;
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
