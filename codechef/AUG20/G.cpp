//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

int counttri(int a[], int b[], int c[], int n) 
{ 
  double slope[n]; 
  for (int i=0; i<n; i++) 
      slope[i] = (a[i]*1.0)/b[i]; 

  sort(slope, slope+n); 

  int count[n], k = 0; 
  int this_count = 1;   
  for (int i=1; i<n; i++) { 
      if (compareDoubles(slope[i], slope[i-1])) 
        this_count++;     
      else { 
        count[k++] = this_count; 
        this_count = 1; 
      } 
  } 
  count[k++] = this_count; 

  int sum1 = 0; 
  for (int i=0; i<k; i++) 
      sum1 += count[i]; 

  int sum2 = 0; 
  int temp[n]; 
  for (int i=0; i<k; i++) { 
    temp[i] = count[i]*(sum1-count[i]); 
    sum2 += temp[i]; 
  } 
  sum2 /= 2; 

  int sum3 = 0; 
  for (int i=0; i<k; i++) 
      sum3 += count[i]*(sum2-temp[i]); 
  sum3 /= 3; 

  return sum3; 
} 

void solve() {
  int n, c, k;
  cin >> n >> c >> k;
  vector<vector<ll>> a(n, vector<ll> (3));
  map<ll, ll>color;
  priority_queue<pair<ll, ll>, vector<pair<ll,ll>, cmp>q; 
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < 3; j++) {
      cin >> a[i][j];
    }
    color[a[i][2]-1]++;

  } 
  for(auto i : color)
    q.push({i.first, i.second});
  vector<ll>v(c);
  for(auto &i : v)
    cin >> i;
  while(k > 0 and !p.empty()) {
    ll col = p.top().firt, count = p.top().second;
    if(count >= 3) {
      if(k >= v[col]) {
        p.pop();
        count--;
        q.push({col, count});
        k -= v[col];
      } else {
        ans += comb()
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  cin >> t;
  for(int tt = 1; tt <= t; tt++) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  