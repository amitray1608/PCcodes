#include <bits/stdc++.h>
using namespace std;

int dist[2001][2001];

int main() {
	int n,x,y;
	map<int,int> mp;
	
	cin>>n>>x>>y;
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			dist[i][j] = dist[j][i] = abs(j-i);
		}
	}
	
	for(int i=1;i<=x;i++){
		for(int j=y;j<=n;j++){
			dist[i][j] = dist[j][i] = abs(j-i-y+x+1);
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int d = dist[i][j];
			if(mp.find(d)==mp.end()) mp[d] = 1;
			else mp[d]+=1;
		}
	}
	
	for(int i=1;i<n;i++){
		if(mp.find(i)==mp.end()) cout<<0<<endl;
		else cout<<mp[i]<<endl;
	}
	
	return 0;
	
}
