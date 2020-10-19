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
		int a,b,p,tmp;
		cin >> a >> b >> p;
		string s;
		cin >> s;
		char prev = 'C';
		bool flag = 0;
		for(int i = s.length()-2; i >= 0 && !flag; i--){
			if(s[i] != prev){
				prev = s[i];
				if(s[i] == 'A')
                     tmp = a;
                else 
                    tmp = b;
				p = p - tmp;
				if(p < 0){
					cout << i+2 << endl;
					return;
				}
			}
		}
		cout << 1 << endl;
	
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
