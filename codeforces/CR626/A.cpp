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
	int count = 0, flag = 0;
	vector<int>v;
	for(int &i : a) cin >> i;
	for(int i = 0; i < n; i++){
		count += a[i];
		if(~a[i]&1){
			flag = 1;
			v.clear();
			v.push_back(i+1);
			break;
		}
		v.push_back(i+1);
		if(~count&1)
			{
				flag = 1;
				break;
			}
	}
	if(flag){
	cout << v.size() << endl;
	for(int i : v)
		cout << i << " ";
	cout << endl;
	}else
		cout << "-1" << endl;
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
	
