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
	int a[n], b[n], counta = 0, countb = 0;
	for(int &i : a){
		cin >> i;
		if(i == 1)
			counta++;
	}
	for(int &i : b){
		cin >> i;
			if(i == 1)
			countb++;
	}
	int ans = 0, flag = 0;
	for(int c = 1; c <= 20000; c++){
		int x = 0, y = 0;
		 ans = c;
		for(int i = 0; i < n; i++){
			if(a[i] == 1 && b[i] == 0){
				x+=c;
			}else if(a[i] == 0 && b[i] == 1){
				y++;
			}else
				x++, y++;
		}
		if(x>y){
			flag = 1;
			break;
		}
	}
	if(flag)
	cout << ans;
	else
		cout <<-1;
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
