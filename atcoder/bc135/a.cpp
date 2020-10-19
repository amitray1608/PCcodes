#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
		ll a, b;
		cin >> a >> b;
		ll ans = (a+b)/2;
		if((a+b)%2==1)
		cout << "IMPOSSIBLE";
	else
		cout << ans;
	
	return 0;
	}
