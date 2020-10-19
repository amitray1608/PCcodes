//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
#define span(a) begin(a), end(a)
mt19937 mersenne{ static_cast<mt19937::result_type>(time(nullptr)) };

auto encode(vector<vector<int>>& adj, vector<int>& d, int n) {
    priority_queue<int, vector<int>, greater<int>> leaves;
    for(int i = 1; i <= n; ++i) {
        if(adj[i].size() == 1) leaves.push(i);
    }
    vector<int> code(n - 2);
    vector<bool> killed(n + 1);
    for(int i = 0; i < n - 2; ++i) {
        int leaf = leaves.top(), v;
        leaves.pop();
        killed[leaf] = true;
        for(auto& u: adj[leaf]) if(!killed[u]) v = u;
        code[i] = v;
        if(--d[v] == 1) leaves.push(v);
    }
    return move(code);
}

auto decode(vector<int>& code, int n) {
    vector<int> d(n + 1, 1);
    for(int& i: code) d[i]++;
    priority_queue<int, vector<int>, greater<int>> leaves;
    for(int i = 1; i <= n; ++i) if(d[i] == 1) leaves.push(i);
    vector<pair<int, int>> edges;
    for(int& v: code) {
        int leaf = leaves.top();
        leaves.pop();
        edges.emplace_back(leaf, v);
        if(--d[v] == 1) leaves.push(v);
    }
    edges.emplace_back(leaves.top(), n);
    return move(edges);
}
void dfs(vector<vector<int>>& adj, vector<bool>& vis, int u) {
    vis[u] = true;
    for(auto& v: adj[u]) if(!vis[v]) dfs(adj, vis, v);
}

auto treetest(vector<pair<int, int>>& edges, int n) {
    int m = 0;
    vector<bool> vis(n + 1);
    vector<vector<int>> adj(n + 1);
    for(auto& [x, y]: edges) {
        adj[x].push_back(y);
        adj[y].push_back(x);
        m++;
    }
    assert(m == n - 1);
    dfs(adj, vis, 1);
    for(int i = 1; i <= n; ++i) assert(vis[i]);
    //return move(adj);
}

void hike() {
    uniform_int_distribution<> coin{0, 1};
    //uniform_int_distribution<> N{2, 20000};
    //uniform_int_distribution<> Q{1, 100'000};
    uniform_int_distribution<> A{1, 50};
    int n = 20000, q = 20000;
    cout << 1 << "\n";
    cout << n << ' ' << q << "\n";
    vector<int> code(n - 2);
    uniform_int_distribution<> I{1, n};
    for(int i = 0; i < n - 2; ++i) {
        code[i] = I(mersenne);
    }
    auto edges = decode(code, n);
    treetest(edges, n);
    shuffle(span(edges), mersenne);
    for(auto& [x, y]: edges) {
        if(coin(mersenne) == 1) swap(x, y);
        cout << x << ' ' << y << "\n";
    }
    for(int i = 1; i <= q; ++i) cout << I(mersenne) << "\n";
    //cout << "\n";
    // while(q--) {
    //     int t = coin(mersenne) + 1;
    //     cout << t << ' ';
    //     if(t == 1) {
    //         cout << I(mersenne) << ' ' << A(mersenne) << "\n";
    //     } else {
    //         cout << I(mersenne) << "\n";
    //     }
    // }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t = 1; //cin >> t;
    while(t--) hike();
    return 0;
} //farewell, until we meet again..
