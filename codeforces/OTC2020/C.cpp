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
	int n, m;
	cin >> n >> m;
	int a[n];
	for(int &i : a) cin >> i;
	//int fre[m];
    //memset(fre, 0, sizeof fre);
	//for(int i = 0; i < n; i++)
	  	//fre[a[i]%m]++;
	  //bool flag = false;
	//for(int i=0; i < m; i++){
        //if(fre[i] >= 2){
             //flag = true;
             //break;
         //}
    //}
	   if(m < n)
	    cout << 0 << endl;
	   else {
	    	ll ans=1;
	    	for(int i=0; i<n; i++){
	    	 	for(int j = i+1; j<n; j++)
	    	 	  ans = (ans*abs(a[i]-a[j]))%m;
	    	 }
	    	cout << ans << endl; 
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
