
#include <bits/stdc++.h>
using namespace std;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int, int > ii;
#define ll long long
#define MOD 1000000007
#define dd double
#define f0(i, n) for(int i = 0; i < n; i++)
#define fab(i,a,b) for(int i=a;i<b;i++)
#define f1(i,b) for(int i=1;i<=b;i++)
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define F first
#define S second
#define all(c) c.begin(), c.end()
#define allr(c) c.rbegin(), c.rend()





int main() {


  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif


//ios_base& scientific (ios_base& str);
  int t;
  cin >> t;

  while (t--) {

    int n, k;
    cin >> n >> k;

    vector<int>v(n);

    vector<int>w(k);

    f0(i, n) {
      cin >> v[i];
    }

    f0(i, k) {
      cin >> w[i];
    }

    sort(allr(v));
    for(int i : v)
      cout << i << ' ';
    cout << endl;
    ll ans = 0;

    sort(all(w));
/*
    int mn[k];
    for (int i = 0; i < k; i++) {
      mn[i] = INT_MAX;
    }

    int mx[k];

    for (int i = 0; i < k; i++) {
      mx[i] = INT_MIN;
    }


    int cnt = k;
    int j = 0;

    for (int i = 0; i < n; i++) {

      int x = w[j];

      for (int p = 0; p < x; p++) {

        mn[j] = min(mn[j], v[i + p * cnt]);
        mx[j] = max(mx[j], v[i + p * cnt]);

      }
      cnt--;
      j++;
    }

    for (int i = 0; i < k; i++) {

      // cout << mn[i] << " " << mx[i] << endl;

      ans += (mn[i] + mx[i]);
    }



    cout << ans << endl;
*/

  }




  return 0;
}