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
	int n, q;
	cin >> n >> q;
	  map<pair<int, int>, int> check;	
	int flag = 0;
	 while(q--){
          int x, y, row;
			cin >> x >> y;
	 	 if(check[{x,y}] == 0){
				 if(x == 1)
					row =2;
				 else
					row=1;
				 if(check[{row,y}] == 1) flag++;
				 if(check[{row,y-1}] == 1) flag++;
				 if(check[{row,y+1}] == 1)flag++;
				 if(flag > 0)
					cout << "NO" << endl;
				 else
					cout << "YES" << endl;
				 check[{x,y}] = 1;
	 	 	} else {
				 if(x == 1)
					row=2;
				 else
					row=1;
				 if(check[{row,y}] == 1 && flag > 0) flag--;
				 if(check[{row,y-1}] == 1 && flag > 0) flag--;
				 if(check[{row,y+1}] == 1 && flag > 0) flag--;	 	 	 	
				 if(flag == 0)
					cout << "YES" << endl;
					
				 else
					cout << "NO" << endl;
				 check[{x,y}] = 0;
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


