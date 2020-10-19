//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve() {
    int N, M, i, lim, j, v;
    queue< int > q, n;
    scanf( "%d%d", &N, &M );
    vector< int > graph[ N + 1 ];
    int in[ N + 1 ], P[ N + 1 ];
    for ( i = 0; i <= N; ++i ) {
        in[ i ] = 0;
        P[ i ] = 0;
    }
    for ( i = 1; i <= M; ++i ) {
        scanf( "%d", &lim );
        for ( j = 0; j < lim; ++j ) {
            scanf( "%d", &v );
            in[ v ] += 1;
            graph[ i ].push_back( v );
        }
    }
    int boss = -1;
    for ( i = 1; i <= N; ++i ) {
        if ( in[ i ] == 0 ) {
            q.push( i );
        }
    }
    int prevpop = 0;
    while ( !q.empty() ) {
        int p = q.front();
        q.pop();
        P[ p ] = prevpop;
        for ( i = 0; i < graph[ p ].size(); ++i ) {
            int k = graph[ p ][ i ];
            in[ k ] -= 1;
            if ( in[ k ] == 0 ) {
                q.push( k );
            }
        }
        prevpop = p;
    }
    for ( i = 1; i <= N; ++i ) {
        printf( "%d\n", P[ i ] );
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