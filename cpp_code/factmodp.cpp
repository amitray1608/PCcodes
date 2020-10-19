#include<bits/stdc++.h>
using namespace std;
const int mod = 5;
int fac(int n){
	int ans = 1;
	for(int i = 1; i <= n; i++)
		ans = (ans*i)%mod;
	return ans%mod;
}
int fact(int n){
		int ans = 1;
		while(n > 1){
			ans = (ans * ((n/mod)%2 ? mod-1 : 1))%mod;
			for(int i = 2; i <= n%mod; i++)
				ans = (ans*i)%mod;
			n /= mod;
		}
	return ans%mod;
}
int main(){
	int n;
	cin >> n;
	cout << fac(n) << endl;
	cout << fact(n) << endl;
}
