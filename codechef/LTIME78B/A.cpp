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
	int a[n];
	int flag = 0;
	for(int &i : a) cin >> i;
		
		string s = "";
		for(int i=0; i<n; i++) {
			flag = 0;
			int j = i;
			for(; j<n; j++) {
				if(a[j+1]-a[j] == 1) 
					flag++;
				else
				  break;
			}
			if(flag >= 2) {
				s = s + to_string(a[i]) + "..." + to_string(a[j]) + ",";
				i=j;
			}
			else 
				s = s + to_string(a[i]) + ",";
		}
		for(int i = 0; i < (int)s.length()-1; i++)
		cout << s[i];
		
		cout << endl;
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
