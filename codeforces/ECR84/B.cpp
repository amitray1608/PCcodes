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
		int n, k;
        cin >> n;
        vector<int> a[n+1];
		ll taken[n+1], check[n+1];
        for(int i=0;i<=n;i++){
            taken[i]=0;
            check[i]=0;
        }
        for(int i=0;i<n;i++){
            a[i].clear();
            cin >> k;
            for(int j=0;j<k;j++){
                ll x;
                cin >> x;
                a[i].push_back(x);
            }
        }
        for(int i=0; i<n; i++){
            bool flag = false;
            for(auto it : a[i]){
                if(taken[it]) 
                    continue;
                taken[it] = 1;
                flag = true;
                break;
            }
            if(flag){
                check[i] = 1;
            }
        }
        ll X = -1, Y = -1;
        for(int i=0; i<n; i++){
            if(check[i] == 0)
                Y = i;
        }
        for(int i=1; i <= n; i++){
            if(taken[i] == 0){
                X = i;
            }
        }
        if(X != -1 && Y != -1){
            cout << "IMPROVE" << endl;
            cout << Y+1 << " " << X << endl;
        }else{
            cout << "OPTIMAL" << endl;
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
