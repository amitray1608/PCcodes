//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(xx) cout << #xx << " = " << xx << endl;
// BHAI LAUDA JAISA CONTEST HAI, LAUDA JAISA PROBLEM HAI
void solve(){
	int n;cin >> n;
	//int a[n][2];
	bool flag = true;
	//for(int i = 0; i < n; i++)
		//cin >> a[i][0] >> a[i][1];
	int xx, yy;
	cin >> xx >> yy;
	if(xx < yy){
		flag = false;
	}
	for(int i = 1; i < n; i++) {
	    	int x = xx;
            int y = yy;
		    cin >> xx >> yy;
			if((xx < x)||(yy < y) || xx < yy){
				flag = false;
			}
			if((yy-y) > (xx- x)){
				flag = false;
			}

	}
	if(flag)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	//cout << endl;
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
	
