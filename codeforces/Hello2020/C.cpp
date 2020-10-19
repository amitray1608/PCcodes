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
    cin>>n;
    vector< pair<int,int> > a;
    int freq[n]={0};
    for(int i = 0; i < n; i++){
        int l;
        cin >> l;
        int maxi=-1;
        int mini= 1000000001;
        for(int j = 0; j < l; j++){
            int tmp;
            cin >> tmp;
            if(tmp > mini){
                freq[i	] = 1;
            }
            maxi = max(maxi, tmp);
            mini = min(mini, tmp);
            
        }

        a.push_back(make_pair(mini,maxi));
    }
    int ans=0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i].first<a[j].first || a[i].first<a[j].second || a[i].second<a[j].first || a[i].second<a[j].second || freq[i]==1 || freq[j]==1){
                ans++;
            }
        }
    }
    cout << ans << endl;
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
	
