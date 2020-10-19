#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const ll siz = 1e6 + 5;
#define deb(x) cout << #x << "x = " << x << endl;

void solve()
{
	cin.ignore();
		string S;
          cin >> S;
          int N = S.size();
		int c, i;
            c=0;
                for(i=0; i<N; i++)
                    c+=S[i]=='B';
                    
			char x = (N/2<=c && c<=N-2)? 'Y' : 'N';
            cout << x;
            cout  << endl;
}

int main()
{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		ll t = 1;
		cin >> t;
		for(int j = 0; j<t; j++)
		{
			solve();
		}
	return 0;
}
	
