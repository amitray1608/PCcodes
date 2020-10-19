//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll siz = 1e6 + 5;
const int sizz = 1e5+1;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
vector<int>parent;
struct Node{
	vector<int>v;
	int cost;
	vector<pair<int, int>>prime_fact;
};
// CREDIT - https://www.geeksforgeeks.org/prime-factorization-using-sieve-olog-n-multiple-queries/
#define MAXN   1000001 
int spf[MAXN]; 
void sieve() { 
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++)  
        spf[i] = i; 
    for (int i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<MAXN; i++) { 
        if (spf[i] == i) { 
            for (int j=i*i; j<MAXN; j+=i) 
                if (spf[j]==j)
                    spf[j] = i; 
        } 
    } 
} 
vector<pair<int, int>> getFactorization(int x) { 
	vector<pair<int, int>>ans;
    map<int, int>ret; 
    while (x != 1) { 
        ret[spf[x]] = (ret[spf[x]] +1); 
        x = x / spf[x]; 
    }
    for(auto i : ret)
		ans.push_back({i.first, i.second});
    return ans; 
}
//CREDIT - https://cp-algorithms.com/graph/lca.html

struct LCA {
    vector<int> height, euler, first, segtree;
    vector<bool> visited;
    int n;

    LCA(vector<vector<int>> &adj, int root = 0) {
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        visited.assign(n, false);
        dfs(adj, root);
        int m = euler.size();
        segtree.resize(m * 4);
        build(1, 0, m - 1);
    }

    void dfs(vector<vector<int>> &adj, int node, int h = 0) {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (auto to : adj[node]) {
            if (!visited[to]) {
                dfs(adj, to, h + 1);
                euler.push_back(node);
            }
        }
    }

    void build(int node, int v, int e) {
        if (v == e) {
            segtree[node] = euler[v];
        } else {
            int mid = (v + e) / 2;
            build(node << 1, v, mid);
            build(node << 1 | 1, mid + 1, e);
            int l = segtree[node << 1], r = segtree[node << 1 | 1];
            segtree[node] = (height[l] < height[r]) ? l : r;
        }
    }

    int query(int node, int v, int e, int L, int R) {
        if (v > R || e < L)
            return -1;
        if (v >= L && e <= R)
            return segtree[node];
        int mid = (v + e) >> 1;

        int left = query(node << 1, v, mid, L, R);
        int right = query(node << 1 | 1, mid + 1, e, L, R);
        if (left == -1) return right;
        if (right == -1) return left;
        return height[left] < height[right] ? left : right;
    }

    int lca(int u, int v) {
        int left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        return query(1, 0, euler.size() - 1, left, right);
    }
};


 
void bfs(int s, int n, vector<Node>&adj){
	bool vis[n];
	memset(vis, false, sizeof vis);
	queue<int>q;
	q.push(s);
	vis[s] = true;
	vector<pair<int, int>>pows[n];
	for(int i = 0; i < n; i++){
		pows[i] = adj[i].prime_fact;
	}
	while(!q.empty()){
		int x = q.front();
		q.pop();
		//if(x == d) break;
		vector<pair<int, int>>check = pows[x];
		for(auto &i: adj[x].v){
			if(!vis[i]){
				vector<pair<int, int>>xx = pows[i];
				parent[i] = x;
				//merge in sorted order
				int ii = 0, jj = 0;
				vector<pair<int, int>>insorted;
				while(ii < (int)xx.size() && jj < (int)check.size()){
					if(xx[ii].first == check[jj].first){
						insorted.push_back({xx[ii].first, (xx[ii].second+check[jj].second)});
						ii++, jj++;
					}else if(xx[ii].first < check[jj].first){
						insorted.push_back({xx[ii].first, (xx[ii].second)});
						ii++;
					}else{
						insorted.push_back({check[jj].first, (check[jj].second)});
						jj++;
					}
				}
				while(ii < (int)xx.size()){
						insorted.push_back({xx[ii].first, (xx[ii].second)});
						ii++;		
				}
				while(jj < (int)check.size()){
						insorted.push_back({check[jj].first, (check[jj].second)});
						jj++;		
				}
				vis[i] = true;
				q.push(i);
				adj[i].prime_fact = pows[i] = insorted;
				insorted.clear();
			}
		}
	}
	//for(int i = 0; i < n; i++){
		//for(auto &it : pows[i])
			//ans[i] = ((ans[i]%MOD)*((it.second)+1LL)%MOD)%MOD;
	//}
}

void debprint(int n, vector<Node>&adj){

	for(int i = 0; i < n; i++){
		cout << endl;
		cout << "Node : " << i << endl;
		cout << "cost = " << adj[i].cost << endl;
		cout << "Adjacent = ";
		for(int j : adj[i].v)
			cout << j <<  " ";
		cout << endl;
		cout << "Prime fact :" << endl;
		for(auto j : adj[i].prime_fact)
			cout << j.first << " " << j.second << " times." << endl;
		cout << endl << endl;
	}
}

void solve(){
	int n;
	cin >> n;
	vector<Node>adj(n);
	parent.resize(n, -1);
	vector<vector<int>>forlca(n);
	for(ll i = 0; i < n-1; i++){
		ll U, V;
		cin >> U >> V;
		U--, V--;
		adj[U].v.push_back(V);
		adj[V].v.push_back(U);
		forlca[U].push_back(V);
		forlca[V].push_back(U);
	}
	LCA l(forlca, 0);
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		adj[i].cost = x;
		adj[i].prime_fact = getFactorization(x);
	}
	
	//for(ll i = 1; i <= n; i++){
	bfs(0, n, adj);
		//for(int it = 1; it <= n; it++)
			//all[i][it] = tmp[it];
	//}
		//debprint(n, adj);
	//for(ll i = 0; i < n; i++){
		//for(ll j = 0; j < 10; j++)
			//cout << all[i][j] << " ";
		//cout << endl;
	//}
	vector<pair<int, int>>check[n];
	for(int i = 0; i < n; i++)
			check[i] = adj[i].prime_fact;
	
	//cout << endl;
	//for(int i = 0;i < n; i++)
		//cout << i << " parent " << parent[i] << endl;
	int q;
	cin >> q;
	while(q--){
		int u, v;
		cin >> u >> v;
		u--, v--;
		//cout << "OK" << endl;
		//return;
		int mid = l.lca(u, v);
		//cout << mid << endl;
		vector<pair<int, int>>x = check[u], y = check[v], z = check[mid], w;
        ll ans = 1;
		int xx = 0, yy = 0, zz = 0, ww = 0; 
		while(xx < (int)x.size() && zz <(int) z.size()){
			if(x[xx].first == z[zz].first){
				x[xx].second = x[xx].second - z[zz].second;
				zz++;
			}
			xx++;
		}xx = 0, yy = 0, zz = 0, ww = 0; 
		while(yy < (int)y.size() && zz < (int)z.size()){
			if(y[yy].first == z[zz].first){
				y[yy].second = y[yy].second - z[zz].second;
				zz++;
			}
			yy++;
		}xx = 0, yy = 0, zz = 0, ww = 0;
		if(parent[mid] != -1){ 
			w = check[parent[mid]];
			while(ww < (int)w.size() && zz < (int)z.size()){
				if(w[ww].first == z[zz].first){
					z[zz].second = z[zz].second - w[ww].second;
					ww++;
				}
				zz++;
			}
		}
		xx = 0, yy = 0, zz = 0, ww = 0; 
		while(xx < (int)x.size() && zz < (int)z.size()){
			if(x[xx].first == z[zz].first){
				x[xx].second = x[xx].second + z[zz].second;
				zz++;
			}
			xx++;
		}xx = 0, yy = 0, zz = 0, ww = 0;
		vector<int>raise;
		while(xx < (int)x.size() && yy < (int)y.size()){
			if(x[xx].first == y[yy].first){
				raise.push_back(x[xx].second + y[yy].second);
				xx++, yy++;
			}else if(x[xx].first < y[yy].first){
				raise.push_back(x[xx].second );
				xx++;
			}	
			else
				raise.push_back(y[yy].second), yy++;
		}
		while(xx < (int)x.size()){
			raise.push_back(x[xx].second);
			xx++;
		}
		while(yy < (int)y.size()){
			raise.push_back(y[yy].second);
			yy++;
		}
		for(auto &i : raise)
			ans = (ans*(i+1)%MOD)%MOD;

        cout << ans << endl;
	}
}

int main(){
	#ifndef RAY
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1;
		cin >> t;
		sieve();
		//for(int i = 1; i < sizz; i++)
			//cout << fact1[i] << " ";
		while(t--){
			solve();
		}
	return 0;
}


/*
86016
107520
614400
81920
69206016
169869312
4608
10752
1152
55296


86016
107520
614400
81920
69206016
169869312
4608
10752
1152
55296
*/

/*
1
100
33 34
33 72
33 90
34 52
52 21
34 64
52 91
52 28
34 40
33 60
34 3
90 23
52 19
34 18
34 49
19 96
49 68
64 97
91 89
96 6
33 48
40 35
48 78
35 30
90 13
91 24
21 98
13 37
64 87
48 46
97 14
49 32
40 45
96 79
13 80
28 10
40 93
79 31
40 7
21 36
10 51
35 61
89 25
72 74
97 100
97 71
10 95
90 53
49 88
14 76
78 82
76 38
100 9
31 81
14 47
79 73
48 11
73 57
31 39
95 69
14 65
10 62
9 67
62 86
49 20
45 63
65 83
31 66
91 17
93 22
31 16
3 50
45 8
87 5
22 77
3 27
46 43
66 15
74 42
76 58
96 29
100 75
29 94
20 44
15 54
18 70
79 99
38 59
24 56
27 2
52 84
62 41
6 4
2 92
42 85
15 1
42 55
82 12
63 26
196717 464231 535259 335978 793469 291008 557166 555281 493933 185616 163231 896028 229400 27291 282213 852733 263433 901895 171734 12868 354178 941661 993930 500573 340613 202887 360669 132506 417279 101403 260108 870383 93462 248990 299172 4658 136431 911511 505081 98445 794728 294769 124690 80203 642140 33205 942958 346736 985491 413036 914019 78588 622011 618363 693924 979369 392136 72686 957763 611072 260885 62976 621535 111248 190996 522951 477726 65615 690284 214545 133881 656803 957922 377997 747690 72501 389822 919156 181755 224014 857628 154968 706510 905286 835509 314744 376604 935450 302916 890309 362182 520839 444979 948455 363167 80966 608406 239846 685863 225680
10
25 34
98 79
42 20
10 6
37 25
7 54
36 84
36 96
40 27
40 36
*/
