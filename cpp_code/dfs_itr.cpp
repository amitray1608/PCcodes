#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int n, m;
	cin >> n >> m;
	int G[n+1][n+1] ={0};
	while(m--){
		int a, b;
		cin >> a >> b;
		G[a][b] = 1;
		G[b][a] = 1;
	}
	
	//~ for(int i = 1; i<=n; i++){
		//~ for(int j = 1; j <= n; j++){
			//~ cout << G[i][j] << " ";	
		//~ }
		//~ cout << endl;
	//~ }
	
	cout << "BFS traversal:\n";
	int vis[n] = {0};
	int Q[n] = {0};
	int f = 0, r = -1;
	vis[1] = 1;
	Q[++r] = 1; // starting vertex
	while(f <= r){
		int x = Q[f++];
		cout << x << " ";
		for(int i = 1; i<=n; i++){
			if(G[x][i] == 1 && vis[i] == 0){
				Q[++r] = i, vis[i] = 1;
			}
		}
	}
	cout << endl;
	cout << "DFS traversal:\n";
	int st[n] = {0};
	int visi[n] = {0};
	int top = -1;
	st[++top] = 1;
	visi[1] = 1;
	while(top > -1){
		int x = st[top--];
		cout << x << " ";
		for(int i = 1; i <= n; i++){
			if(G[x][i] == 1 && visi[i] == 0)
				st[++top] = i, visi[i] = 1;
		}
	}
		return 0;
}
