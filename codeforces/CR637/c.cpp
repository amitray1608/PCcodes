//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(maxi) cout << #maxi << " = " << maxi << endl;

void solve(){
	int n;
	cin >> n;
	int x;
	int pos[n+1], a[n];
	for(int i = 0; i < n; i++) {
        cin >> x;
        pos[x] = i+1;
        a[i] = x;
    }
	int flag = 0, last = n;
	for(int i = 1; i < n; i++){
		if(pos[i] != last){
			if(pos[i+1] != pos[i]+1) {
                flag = 1;
                break;
            } 
		}
		if(pos[i] == last)
             last--;
	}
	flag = 0;
	int i = 0 ;
	while (i < n-1){
		if ( a[i+1] < a[i] )
			i++ ;
		else if(a[i+1] == a[i]+1)
			i++ ;
		else
			break ;
	}
	flag = (i == n-1);
	if(flag) 
        cout << "Yes\n";
	else
        cout << "No\n";
	
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
	
