#include<bits/stdc++.h>
using namespace std;
int main(){
		int t;
		cin >> t;
		while(t--){
			int n;
			cin >> n;
			int z = 0, tt = 0;
			for(int i = 0; i < n; i++){
				int x;
				cin >> x;
				if(x == 0) z++;
				if(x == 2) tt++;
			}
			long ans = 0;
			ans = (z*(z-1))/2 + (tt*(tt-1))/2;
			cout << ans << endl;
		}
	return 0;
}
