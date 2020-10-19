//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
bool comp(pair<int, int> fst, pair<int, int> sec){
    double d1 = sqrt(fst.first*fst.first + fst.second*fst.second);
    double d2 = sqrt(sec.first*sec.first + sec.second*sec.second);
    if(d1>d2)
        return true;
    return false;
}
void solve(){
	    int n;
		cin >> n;
		vector< pair <int,int> > v(n);
		for(int i=0;i<n;i++){
			cin >> v[i].first >> v[i].second;
		}
        int tmp, tmps, fst, sec, X=0, Y=0,  flg = 1;
		sort(v.begin(), v.end());
		tmp=v[0].second;
		for (int i = 1; i < n; i++) { 
        	tmps = v[i].second;
        	if(tmps < tmp){
        		flg=0;
        		break;
        	}
        	else{
        		tmp = tmps;
        	} 
    	}
    	if(!flg){
    		cout << "NO" << endl;
    	}
    	else{
    		cout << "YES" << endl;
    		for(int i=0; i<n; i++){
    			fst = v[i].first;
    			sec = v[i].second;
    			while(fst > X)	cout << "R", X++;
    			while(sec > Y) cout << "U", Y++;
    		}
    		cout << endl;
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
	
