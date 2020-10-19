//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

vector<vector<int> >adj;
vector<int> tin, tout, sum;
vector<bool> vis;
int timer, times;

void dfs(int s) {
  vis[s] = true;
  tin[s] = timer++;
  for(auto i : adj[s]) {
    if(!vis[i]) {
      dfs(i);
      sum[s] += sum[i];
    }
  }
  tout[s] = ++timer;
}

void solve() {
  int n;
  cin >> n;
  adj = vector<vector<int> > (n);
  vis = vector<bool>(n);
  tin = vector<int>(n, 0);
  tout = vector<int>(n, 0);
  sum = vector<int> (n, 0);
  timer = 0, times = 0;
  for(int i = 0; i < n; i++)
    cin >> sum[i];
  for(int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
  }
  dfs(0);
  int q;
  cin >> q;

  cout << "Timer in:" << endl;
  for(auto i : tin)
    cout << i << ' ';
  cout << endl;  
  cout << "Timer out:" << endl;
  for(auto i : tout)
    cout << i << ' ';
  cout << endl;

  while(q--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    if(tin[u] < tin[v] and tout[v] < tout[u])
      cout << sum[u] << endl;
    else if(tin[u] > tin[v] and tout[v] > tout[u])
      cout << sum[v] << endl;
    // if(sum[0]-sum[u] == sum[0]-sum[v]-(sum[u]-sum[v]))
    //   cout << sum[u] << endl;
    // else if(sum[0]-sum[v] == sum[0]-sum[u]-(sum[v]-sum[u]))
    //   cout << sum[v] << endl;
    else
      cout << sum[v]+sum[u] << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  // cin >> t;
  for(int tt = 1; tt <= t; tt++) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  

/*
9
1 2 3 4 5 6 7 8 9
1 2
1 3
3 6
3 7
2 4
2 5
5 8
5 9
4
2 5
1 7
3 5
3 2
*/

Name: Amit Kumar

UID: 18BCS2059

Subject/Subject-code: AIML LAB/CSP-303



Aim of the experiment:

 Write a program in R to print “Hello, World”. Use single line comment.

Solution:

#This is the example of single line comment.

print("Hello, World")



Learning outcomes of the experiment:

Learnt how to use single line comment and print "Hello, World".

Name: Amit Kumar

UID: 18BCS2059

Subject/Subject-code: AIML LAB/CSP-303



Aim of the experiment:

Write a program in R to print all of your personal details.Use multi line comments.

Solution:

if(false) {

This is the example of multi line comment.

we used if statement to make if a multi line comment.

}

print("Name : Amit Kumar")

print("UID : 18BCS2059")

print("Course : CSE")

print("Section : 18K2G3")



Learning outcomes of the experiment:

Learnt how to do multi line comment and print the my details.