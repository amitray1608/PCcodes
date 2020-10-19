//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(tmp) cout << #tmp << " = " << tmp << endl;
void solve(){
		int n,m;
    cin >> n >> m;
	char ss[20][20];
	char tt[20][20];
	for(int i=0; i<n; i++)
		cin >> ss[i];

	for(int i=0;i<m;i++) 
		cin >> tt[i];

	int qu;
    cin >> qu;
	while(qu--) {
		int tmp;
        cin >> tmp;
		int ff=(tmp-1) % n;
		int st=(tmp-1) % m;
		cout << ss[ff] << tt[st] << endl;
	}
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
	
