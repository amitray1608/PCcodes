//“Make it work, make it right, make it fast.” – kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
void solve(){
        int n, k;
        cin >> n >> k;
        string ss[n];
        int len[n] = {0}, vis[n]={0};
		for(int j=0;j<n;j++)
			cin >> ss[j];
        int st,ed, curr;
		//bfs for length;
        queue<int> Q ;
		Q.push(0);
		vis[0]=1;
		while(!Q.empty()){
			curr = Q.front();
			Q.pop();
            int x = (curr-k), y = (curr+k);
			st = x > 0 ? x : 0;
			ed = y < n ? y : n-1;
			for(int i = st; i <= ed; i++){
				if(ss[curr][i] == '1'){
					if(vis[i] == 0){
						Q.push(i);
						vis[i] = 1;
					}
					if(len[i]==0 || len[i] > len[curr]+1)
						len[i] = len[curr] + 1;
				}
			}
 
		}
		if(len[n-1] > 0)
			cout << len[n-1]-1 << endl;
		else
			cout << -1 << endl;
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
