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
		int n;
		cin>>n;
		int a[n];
		int count=0;
		int sount=0;
		for(int i=0;i<n;i++){
			cin >> a[i];
			if(~a[i]&1)
				count=1;
			else{
				sount=1;
			}
		}
		if(count==1&&sount==1){
			cout<<"YES"<<endl;
		}
		else{
			if(count==0){
				if(n%2==1)
				cout<<"YES"<<endl;
				else{
					cout<<"NO"<<endl;
				}
 
			}
			else
			cout<<"NO"<<endl;
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
