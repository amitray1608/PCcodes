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
    string s;
    cin >> s;
    bool flag = 0;
    int left=1, right=n;
    map< pair<int,int> ,int> check;
    int U=0, L=0, dist = INT_MAX;
    pair<int,int> at = make_pair(0ll,0ll);
    check[at] = 1;
    for(int i=0; i<n; i++){
         if(s[i]=='U')
            U++;
        if(s[i]=='D')
            U--;
        if(s[i]=='L')
            L++;
        if(s[i]=='R')
            L--;
        pair<int,int> curr = make_pair(U, L);
        if(check[curr] == 0){
            check[curr] = i+2;
        }
        else{
            int tmp = i + 1 - check[curr];
            if(tmp < dist){
                flag = 1;
                left = check[curr];
                right = i+1;
                dist = tmp;
                check[curr] = tmp;
            }
            check[curr] = i+2;
        }
    }
    if(flag)
        cout << left << " " << right << endl;
    else{
        cout << "-1" << endl;
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
