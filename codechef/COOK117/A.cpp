//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
int raise(int x,  int y) { 
    if (y == 0) 
        return 1; 
    else if (y % 2 == 0) 
        return raise(x, y / 2) * raise(x, y / 2); 
    else
        return x * raise(x, y / 2) * raise(x, y / 2); 
} 
void solve(){
	int n;
	cin >> n;
	int x=0, k=0;
	for(int i=2; i <= 32; i++){
		int p = raise(2,i);
		p--;
		if(n % p == 0){
			k = i;
			x = n/p;
			break;
		}
	}
	cout << x << endl;
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
