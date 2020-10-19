#include<bits/stdc++.h>
using namespace std;
int main(){
		int t;
		cin >> t;
		while(t--){
			int n;
			cin >> n;
			int a[9];
			memset(a, 0, sizeof a);
			int sum = 0;
			for(int i = 0; i < n; i++){
				int x=0, y=0;
				cin >> x >> y;
				if(x < 9)
				a[x] = max(a[x], y);
			}
			//~ accumulate(a, a+9, sum);
			for(int i = 1; i<9; i++)
			sum+=a[i];
			cout << sum << endl;
		}
	return 0;
}
//~ 2
//~ 5
//~ 2 45
//~ 9 100
//~ 8 0
//~ 2 15
//~ 8 90
//~ 1
//~ 11 1
