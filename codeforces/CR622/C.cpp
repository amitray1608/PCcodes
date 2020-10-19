//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
//long long int n,x,y,maxi,mini;
void solve(){
        int n, x, y;
        cin >> n >> x >> y;
        if(x > y)
			swap(x, y);
		int maxi = 0, mini = 0; 
        if ((x-1) >= (n-y)){
            maxi = n;
        } else {
            maxi = x + y - 1;
        }
        if ((x-1) <= (n-y-1)){
            mini = 1;
        } else {
            mini = x + y + 1 - n;
        }
        cout << mini << " " << maxi;
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
