#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>G;
int main(){
    int n, q;
    cin >> n >> q;
    G.resize(n+1, vector<int>(n+1, 0));
    int dist[n+1][n+1], inf = 0x3f3f3f;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <=n; j++)
            G[i][j] = inf;
    }
    for(int i = 0; i < n-1; i++){
        int u, v, w;
        cin >> u >> v >> w;
        G[u][v] = w;
        G[v][u] = w;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <=n; j++)
            dist[i][j] = G[i][j];
    }
    // All pair shortest path. Floyd.
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                if(dist[j][i]+dist[i][k] < dist[j][k])
                    dist[j][k] = dist[j][i]+dist[i][k];
            }
        }
    }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <=n; j++)
                cout << dist[i][j] << " ";
            cout << endl;
        }
}
	
