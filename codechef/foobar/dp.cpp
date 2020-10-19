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
	cin >> n;
	int a[n], sum = 0;
	for(int &i : a) cin >> i, sum += i;
	sort(a, a+n);
	if(sum % 3 == 1){
		int i = 0;
		for(i = 0; i < n; i++){
			if(a[i] % 3 == 1){
				a[i] = -1;
				break;
			}
		}
		if(i == n){
			int count = 0;
			for(i = 0; i < n; i++){
				if(a[i]% 3 == 2)
					a[i] = -1, count++;
				if(count == 2)
					break;
			}
		}
	}else if(sum % 3 == 2){
		int i = 0;
		for(i = 0; i < n; i++){
			if(a[i] % 3 == 2){
				a[i] = -1;
				break;
			}
		}
		if(i == n){
			int count = 0;
			for( i = 0; i < n; i++){
				if(a[i]% 3 == 1)
					a[i] = -1, count++;
				if(count == 2)
					break;
			}
		}
	}
	for(int i = n-1; i >= 0; i--){
		if(a[i] == -1)
			continue;
		cout << a[i];
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
