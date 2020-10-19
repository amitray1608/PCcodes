#include <bits/stdc++.h>
#define pb push_back
#define s(a, x, y) sort(a.begin()+x, a.begin()+y);
#define mp make_pair
#define F first
#define S second
#define ll long long
using namespace std;
ll t, n, m, a, b, mod;
ll gcd(ll x, ll y){
	for(int i=min(x, y); i>=1; i--){
		if(x%i==0&&y%i==0) return i;
	}
}
bool x[52][52];
int main() {
	cin>>t;
	for(int w=0; w<t; w++){
		cin>>n>>m>>a>>b;
		if(n*a==m*b){
			cout<<"YES"<<endl;
		} 
		else{
			cout<<"NO"<<endl;
			continue;
		}
		mod=m/gcd(m, a);
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(j%mod==i%mod) x[i][j]=0;
				else{
					x[i][j]=1;
				}
				cout<<x[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}
