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
	int a, b;
	cin >> a >> b;
	int q;
	cin >> q;
//((xmoda)modb)≠((xmodb)moda)
	while(q--){
		int x, y;
		cin >> x >> y;
		int count = 0;
		for(int i = x; i <= y; i++){
			int moda = (i%a)%b;
			int modb = (i%b)%a;
			if(moda != modb)
				count++;
		}
		cout << count << " ";
	}
	cout << endl;
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
