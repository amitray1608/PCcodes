#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const int siz = 1e5 + 5;
vector <ll> edges[siz];
vector <ll> in_degree(siz);
int dist[siz];
bool vis[siz];
void solve();


void solve()
{

	ll n, m, count = 0, final_count = 0;
	cin >> n >> m;
    ll n_half = n/2, c_factor = 0, maxi = (n*(n-1))/2 + n;
		if(n==1 && m==0)  cout << "0\n";
		
        else if((n==1 && m==1) || (n==2 && m==1))	cout << "1\n";
		
        else if(n==2 && (m==2 || m==3)) 	cout << "2\n";
		
        else  if(m >= (n-1) && m <= maxi)
		{
			
            if(m <= (n+1))  c_factor = 2;

			else if(m <= (n*2))   c_factor = 3;
			
			else
			{
				if(~ n & 1)
				{
					final_count = 3;
					
                    m = m-(n*2);
					
                    final_count = final_count + m / n_half;
					
                    if(m % n_half > 0)
					    final_count++;

                    c_factor = min(final_count, n) ;
				}
				else
				{
					 
                    final_count = 3;
					
                    m = m - (n * 2);
					
                     count = 0;
					
                    while(m > 0)
					{
					
                    	final_count++;
					
                    	count++;
					
                    	m = m - (n_half);
					
                    	if(~count & 1)
							m--;
					}
                    
                    c_factor = final_count;
				}
			}

            cout << c_factor << endl;
		}
		else
			cout << "-1" << endl;
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
	
