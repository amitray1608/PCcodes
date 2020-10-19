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
	int l = 0, r = 0, d = 0, u = 0;
	int len = 0;
	for(char c : s){
			if(c == 'L') l++;
			if(c == 'R') r++;
			if(c == 'U') u++;
			if(c == 'D') d++;
	}
		int a = min(l, r), b = min(d, u);
	if(a == 0 && b == 0) cout << 0 << endl;
	else if(b == 0) cout << "2\nLR\n";
	else if(a == 0) cout << "2\nUD\n";
	else{
	len = (min(l, r) + min(u, d))*2;
	cout << len << endl;
	for(int i = 0; i < a; i++) cout << "L";
		for(int i = 0; i < b; i++) cout << "U";
			for(int i = 0; i < a; i++) cout << "R";
				for(int i = 0; i < b; i++) cout << "D";
	
	cout << endl;
	}
}

int main(){
	#ifndef RAY
	//	freopen("input.txt", "r", stdin);
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
	
