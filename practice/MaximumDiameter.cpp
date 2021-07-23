
#include <bits/stdc++.h>

using namespace std;

int f, len;
vector<vector<int>> adj;

void dfs(int s, int p, int d, int maxi) {
    d++;
    for (auto i : adj[s]) {
        if (i != p) {
            if (d >= maxi) {
                maxi = d;
                f = i;
                len = maxi;
            }
            dfs(i, s, d, maxi);
        }
    }
}

int main(){
    int n;
    cin >> n;
    adj.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }   
    vector<vector<int>> d(n);
    dfs(0, 0, 0, 0);
    int fir = f;
    dfs(fir, 0, 0, 0);
    int sec = f;
    // cout << fir << ' ' << sec << '\n';
    vector<int> dist(n, 0);
    function<void(int, int)> get = [&](int s, int p) {
        dist[s] = 1;
        int maxi = 0;
        for (int i : adj[s]) {
            if (i != p) {
                get(i, s);
                d[s].push_back(dist[i]);
                maxi = max(maxi, dist[i]);
            }
        }
        dist[s] += maxi; 
    };
    // cout << len << '\n';
    get(sec, sec);
    int maxi = 0;
    for (int i = 0; i < n; i++) {
        sort(d[i].rbegin(), d[i].rend());
        // for (int j : d[i]) cout << j << ' ';
        // cout << '\n';
        if (d[i].size() >= 2) {
            maxi = max(maxi, d[i][1]);
        }
    }
    cout << len + maxi;
   return 0;
}
