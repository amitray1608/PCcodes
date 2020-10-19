#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const int siz = 1e6 + 5;
#define deb(x) cout << #x << "x = " << x << endl;

void solve()
{
	    ll n;
        cin >> n;
        string A, B;
        cin >> A >> B;
        A = " " + A;
        B = " " + B;
        bool check[200001][10];
        check[0][0] = 1, check[0][1] = check[n][0] = check[n][1] = 0;
       
       for (int i = 1; i <= n; i++){
            
            check[i][0] = check[i][1] = 0;
            
            if (check[i-1][0] && A[i] - '0' <= 2) 
                check[i][0] = 1;

            if (check[i-1][1] && B[i] - '0' >  2 && A[i] - '0' > 2) 
                check[i][0] = 1;

            if (check[i-1][0] && A[i] - '0' >  2 && B[i] - '0' > 2) 
                check[i][1] = 1;
                
            if (check[i-1][1] && B[i] - '0' <= 2) 
                check[i][1] = 1;
                
            if (check[i][0] + check[i][1] == 0) 
                break;
        }

        (check[n][1] == 1) ? cout << "YES" : cout << "NO"; 
        cout << endl;
}

int main()
{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		ll t = 1;
		cin >> t;
		while(t--)
		{
			solve();
		}
	return 0;
}
	
