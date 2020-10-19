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
	ll count = 0, one = 0, pos = 0;
    int n = s.length();
    for(int i = 0; i < n; i++){
        if(s[i]=='1'){
			one++;
            pos = i;
            break;
		}
    }
    int x = pos;
  	for(int i = pos+1; i < n; i++){
		if(s[i] == '1')
		one++, pos = i;

	}

	if(pos == x or one == 0)
	cout << 0 << endl;
	else{
		count = (pos - x)+1 - one;
    cout << count << endl;
	
	}
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
