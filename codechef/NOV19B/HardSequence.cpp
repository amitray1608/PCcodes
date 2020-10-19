//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
int vis[200] = {0};
int pre[200] = {0};
int seq[130] = {0};
void vanErk(){
	seq[1] = 0;
	vis[0] = 1;
	for(int i = 2; i<129; i++){
		int x = seq[i-1];
		if(pre[x] == 0) seq[i] = 0, pre[0] = vis[0], vis[0] = i;
		else seq[i] = vis[x] - pre[x], pre[seq[i]] = vis[seq[i]], vis[seq[i]] = i;
		
		//cout << seq[i] << " " << vis[i] << endl;
	}
}
void solve(){
	int n;
	cin >> n;
	int x = seq[n];
	int count = 0;
	for(int i =1; i<=n; i++){
		if(x == seq[i]) count++;
	}
	cout << count << endl;
	//for(int i : seq) cout << i << " ";
}
int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1;
		cin >> t;
		vanErk();
		while(t--){
			solve();
		}
	return 0;
}
