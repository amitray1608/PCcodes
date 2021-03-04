
#include<bits/stdc++.h>
using namespace std;
#define int long long

int d, I, s, v, f;

map<string, vector<int>> tm;
vector<vector<string>> cars;

signed main() {
    freopen("f.txt", "r", stdin);
    freopen("F.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> d >> I >> s >> v >> f;
    vector<vector<string>> a(I);
    for (int i = 0; i < s; i++) {
        int x, y, l;
        string name;
        cin >> x >> y >> name >> l;
        a[y].push_back(name);
    }
    cars.resize(v);
    map<string, int> mp;
    for (int i = 0; i < v; i++) {
        int len;
        cin >> len;
        cars[i].assign(len, "");
        for (auto &j: cars[i]) cin >> j, mp[j]++;
    }
    map<string, int> res;
    vector<pair<int, int>> sol;
    for (int i = 0; i < I; i++) {
        vector<pair<int, string>> freq;
        for (auto &j: a[i]) if (mp[j]) freq.push_back({mp[j], j});
        int sz = freq.size();
        if (!sz) continue;
        sol.push_back({i, freq.size()});
        sort(begin(freq), end(freq));
        reverse(begin(freq), end(freq));
        int sum = d;
        for (int j = 0; j < sz; j++) 
            res[freq[j].second] = (rand() % 2) + (j & 1 ? 1 : 0);
    }

    cout << sol.size() << "\n";
    for (auto &i: sol) {
        cout << i.first << "\n";
        cout << i.second << "\n";
        vector<pair<string, pair<int, int>>> vc;
        for (auto &j: a[i.first]) if (mp[j])
            vc.push_back({j, {res[j], mp[j]}});
        sort(begin(vc), end(vc), [&](pair<string, pair<int, int>> x, pair<string, pair<int, int>> y) {
            return x.second.second > y.second.second;
        });
        for (auto &j: vc) cout << j.first << " " << j.second.first << "\n";
    }
    return 0;
}
