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
		int count = 0, a[3];
		cin >> a[0] >> a[1] >> a[2];
		if(a[0]!=0){ 
				count++; 
				a[0]-- ;
		}
		if(a[1]!=0){ 
				count++; 
				a[1]-- ;
		}
		if(a[2]!=0){ 
			count++; 
			a[2]-- ;
		}
		sort(a, a+3);
		if(a[1]!= 0 && a[2]!=0){
			count+=1; 
			a[1]--;
			a[2]--;
		}
		if(a[2] != 0 && a[0] != 0){
			count+=1; 
			a[2]--;
			a[0]--;
		}
		if(a[1] != 0 && a[0] != 0){
			count+=1;
			a[1]--; 
			a[0]--;
		}
		if(a[0] > 0 && a[1] > 0 && a[2] > 0)
			count++;
		cout << count << endl;
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
