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
	int v[n+1];
	int freq[n+1] = {0};
	queue<int>s;
	
	for(int i = 1; i <= n; i++){
		cin >> v[i];
			freq[v[i]] = 1;
	}
	for(int i = n; i >= 1; i--){
		if(freq[i] == 0){
			s.push(i);
		}
	}
	for(int i = 1; i <= n; i++){
		if(v[i] == 0){
			int x = s.front();
			s.pop();
			if(x == i) { s.push(x); v[i] = s.front(); s.pop();}
			else v[i] = x;
		}
	}
	for(int i = 1; i <= n; i++)
	cout << v[i] << " ";
	cout << endl;
	//cout << endl;
	//for(int i : v) cout << i << ' ';
	//cout << endl;
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
