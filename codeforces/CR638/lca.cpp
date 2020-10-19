#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		int maxi = INT_MIN, mini = INT_MAX;
		for(int i = 0; i < n; i++){
			int x = i-1, y = i+1;
			int count = 1;
			while(x >= 0){
				if(a[x+1] - a[x] <= 2)
					count++;
				else
					break;
				x--;
			}
			while(y < n){
				if(a[y]-a[y-1] <= 2)
					count++;
				else
					break;
				y++;
			}
			mini = min(mini, count);
			maxi = max(maxi, count);
		}
		cout << mini << " " << maxi << endl;
	}
	return 0;
}
