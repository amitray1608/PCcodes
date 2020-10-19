//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
bool solve(){
int nbElem;
    cin >> nbElem;
 
    int extSize = nbElem+2;
    vector<int> orig(extSize), target(extSize);
    vector<int> diff(extSize, 0);
 
    for (int iElem = 1; iElem <= nbElem; ++iElem) {
        cin >> orig[iElem];
    }
 
    for (int iElem = 1; iElem <= nbElem; ++iElem) {
        cin >> target[iElem];
        diff[iElem] = target[iElem] - orig[iElem];
    }
 
    int cntModif = 0;
    for (int iElem = 0; iElem < extSize-1; ++iElem) {
        if (diff[iElem] < 0) {
            return false;
        }
        if (diff[iElem] != diff[iElem+1]) {
            ++cntModif;
        }
    }
 
    return (cntModif <= 2);
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
		bool flag = 	solve();
		if(flag) cout << "YES\n";
		else cout << "NO\n";
		}
	return 0;
}
