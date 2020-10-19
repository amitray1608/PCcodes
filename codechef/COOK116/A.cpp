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
	int x = 0, y = 0;
	for(int i = 0; i< n;){
		if(s[i] == 'L')
			x--;
		else if(s[i] == 'R')
			x++;
		else if(s[i] == 'U')
			y++;
		else if(s[i] == 'D')
			y--;
		
		if((s[i] == 'L' || s[i] == 'R')) {
			while((s[i] == 'L' || s[i] == 'R')&&  i < n) i++;
		}else if((s[i] == 'D' || s[i] == 'U')){
			while((s[i] == 'U' || s[i] == 'D')&& i < n) i++;
		}else i++;
	}
	cout << x << " " << y << endl;
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
