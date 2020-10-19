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

}
int main(){
	//#ifndef RAY
		//freopen("input.txt", "r", stdin);
	//#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		//int t = 1;
		//cin >> t;
		//while(t--){
			//solve();
		//}
	string s;
	cin >> s;
	int q, t, k;
	char c;
	cin >> q;
	int count = 0;
	while(q--){
		cin >> t;
		if(t == 1) count++;
		else{
			cin >> k >> c;
			if(~count&1){
				if(k == 1)
					s = c+s;
				else
					s = s+c;
			}else{
				if(k == 1)
					s = s+c;
				else
					s = c+s;
			}
		}
	}
	if(count&1){
		for(int i = s.size()-1; i >=0; i--)
			cout << s[i];
	}else
	cout << s;
	return 0;
}
