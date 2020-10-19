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
    int deg[n+1] = {0};
    int edge[n-1][2];
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
        edge[i][0]=u;
        edge[i][1]=v;
    }
    int pos = 0;
    for (int i = 1; i <= n; i++){
        if (deg[i] >= 3){
            pos = i;
            break;
        }
    }
    if (pos == 0){
        for(int i = 0; i < n-1; i ++)
         cout << i << endl;
    }else{
        int mini=0, maxi=3;
        for(int i = 0; i < n-1; i ++){
            if ((edge[i][0] == pos || edge[i][1] == pos) && mini<3){
                cout << mini << endl;
                mini++;
            }
            else{
                cout << maxi << endl;
                maxi++;
            }
        }
    }
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
