#include<bits/stdc++.h>
using namespace std;
#define int long long


struct edge {
  int t, st, ed, curr;
  edge(int t, int st, int ed) { 
    t = t; 
    st = st;
    ed = ed; 
  }
};

struct Intersect {
  int sno;
  map<string, int> status;
  int now;
  set<string> towards;
};

struct  car{
  int n;
  vector<string> whichpath; 
};

int d, I, s, v, f;
map<string, vector<int>> tm;
vector<vector<string>> cars;

signed main() {
    freopen("a.txt", "r", stdin);
    freopen("A.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> d >> I >> s >> v >> f;
    vector<Intersect> intr(I);
    map<string, edge> mp_edge;
    vector<car> C(v);
    map<string, int> sf;
    for (int i = 0; i < s; i++) {
      int x, y, l;
      string name;
      cin >> x >> y >> name >> l;
      mp_edge[name].st = x;
      mp_edge[name].ed = y;
      mp_edge[name].t = l;
      intr[mp_edge[name].st].towards.insert(name);
      intr[mp_edge[name].ed].sno = mp_edge[name].ed;
    }
    
    for (int i = 0; i < v; i++) {
      int n;
      cin >> n;
      C[i].n = n;
      int total = 0;
      for (int k = 0; k < n; k++) {
        string ss;
        cin >> ss;
        C[i].whichpath.push_back(ss);
        total += mp_edge[ss].t;
      }
      if (total < d) {
        for (int k = 0; k < C[i].n; k++) {
          sf[C[i].whichpath[k]]++;
        }
      }
    }

    for (int i = 0; i < I; i++) {
      cout << i << "\n";
      cout << intr[i].towards.size() << '\n';
      int sum = 0;
      for (auto x : intr[i].towards) {
        sum += sf[x];
      }
      for (auto x : intr[i].towards) {
        if (sum) {
          int calc = (sf[x] / sum) * 5LL << '\n';
          cout << x << ' ' << calc << '\n';
        } else {
          cout << x << ' ' << 1 << endl;
        }
      }
    }
    return 0;
}
