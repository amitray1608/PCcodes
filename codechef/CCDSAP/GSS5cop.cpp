#include<bits/stdc++.h>
using namespace std;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __AnAkLuSmOs freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define i_64 long long

struct node {
    i_64 pref, suf, total, mx;
    node() {
        pref = suf = total = mx = 0;
    }
    void join(node a, node b) {
        pref = max(a.pref, a.total + b.pref);
        suf = max(b.suf, a.suf + b.total);
        total = a.total + b.total;
        mx = max(pref, max(suf, max(a.suf + b.pref, max(total, max(a.mx, b.mx))))); 
    }
}tr[50001];

void build(i_64 p, i_64 s, i_64 e, i_64 a[]) {
    if (s > e) {
        return;
    }
    if (s == e) {
        tr[p].pref = tr[p].suf = tr[p].total = tr[p].mx = a[s];
        //cout << a[s] << "\n";
        return;
    }
    i_64 m = (s + e) >> 1;
    build(p << 1, s, m, a);
    build((p << 1) | 1, m + 1, e, a);
    tr[p].join(tr[p << 1], tr[(p << 1) | 1]);
}

node query(i_64 p, i_64 s, i_64 e, i_64 l, i_64 u) {
    node res;
    if (l > u or l > e or s > u) {
        return res;
    }
    if (l <= s and u >= e) {
        return tr[p];
    }
    i_64 m = (s + e) >> 1;
    if (u <= m) {
        return query(p << 1, s, m, l, u);
    }
    if (l > m) {
        return query((p << 1) | 1, m + 1, e, l, u);
    }
    res.join(query(p << 1, s, m, l, u), query((p << 1) | 1, m + 1, e, l, u));
    return res;
}
void solve() {
    i_64 n, q;
    cin >> n;
    i_64 a[n];
    for (i_64 &i: a) cin >> i;
    build(1, 0, n - 1, a);
    cin >> q;
    while (q--) {
        i_64 x1, y1, x2, y2, res;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;
        x2--;
        y1--;
        y2--;
        if (x2 > y1) {
            node r1 = query(1, 0, n - 1, x1, y1);
            node r2 = query(1, 0, n - 1, x2, y2);
            node r3 = query(1, 0, n - 1, y1 + 1, x2 - 1);
            res = r1.suf + r3.total + r2.pref;
        }
        else {
            node r1 = query(1, 0, n - 1, x1, x2 - 1);
            node r2 = query(1, 0, n - 1, y1 + 1, y2);
            node r3 = query(1, 0, n - 1, x2, y1);
            res = max(r1.suf + r3.pref, max(r1.suf + r3.total + r2.pref, max(r2.pref + r3.suf, r3.mx)));
        }
        cout << res << "\n";
    }
}

int main() {
    // auto start=chrono::steady_clock::now();
    #ifndef ONLINE_JUDGE 
        //__AnAkLuSmOs
    #endif

    __AcHiLlEs
    
    i_64 t(1);
    cin >> t;
    while (t--) {
        solve();
    }
    // auto end = chrono::steady_clock::now();
    // double elapsed = double (chrono::duration_cast < chrono::nanoseconds> (end-start).count());
    // cout << endl << "Terminated\n"<< elapsed/1e9;
    return 0;
}
