//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 5000000;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
int g[1000][1000];
int bfs(int s, int n){
	queue<int>q;
	q.push(s);
	bool vis[n+1];
	memset(vis, false, sizeof vis);
	vis[s] = 1;
	int dist[n+1];
	memset(dist, 0, sizeof dist);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int i = 1; i <= n; i++) {
			if(vis[i] == 0 && g[x][i] != 0){
				dist[i] = dist[x]+g[x][i];
				vis[i] = 1;
			}
		}

	}
	return *max_element(dist, dist+n);
}

void solve(){
	int n;
	cin >> n;
	memset(g, 0, sizeof g);
		//memset(vis, 0, sizeof vis);
	for(int i = 0; i < n-1; i++){
		int u, v, w;
		cin >> u >> v >> w;
		g[u][v] = w;
		g[v][u] = w;
	}
	int s = bfs(1, n);
	cout << bfs(s, n) << endl;
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
#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>
#include<cctype>
#include<cmath>
#include<cstring>
#include<queue>
#include<cstdio>
#include<sstream>
using namespace std;
#define pb push_back
#define pi 3.141592653589793238462643383
 
int dist[50001];
int visited[50001];
int n;
struct node
{
    int i,d;
};
typedef struct node node;
vector<node> v[50001];
int bfs(int start){
    queue<int> q;
    q.push(start);
    int i,j;
    for(i=0;i<=n;i++){
        visited[i]=0;
        dist[i]=0;
    }
    visited[start]=1;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(i=0;i<v[temp].size();i++){
            if(visited[v[temp][i].i]==0){
                visited[v[temp][i].i]=1;
                dist[v[temp][i].i]+=dist[temp]+v[temp][i].d;
                q.push(v[temp][i].i);
            }
        }
    }
    return int(max_element(dist+1,dist+n+1)-dist);
}
int main()
{
 int i,j,t,u1,v1,d;
 node temp;
 scanf("%d",&t);
 while(t>0){
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            v[i].clear();
        for(i=1;i<=n-1;i++){
                scanf("%d%d%d",&u1,&v1,&d);
                temp.i =  v1;
                temp.d = d;
                v[u1].pb(temp);
                temp.i = u1;
                v[v1].pb(temp);
        }
        int start = bfs(1);
        int ans = bfs(start);
        printf("%d\n",dist[ans]);
        t--;
    }
     
         
         
}
