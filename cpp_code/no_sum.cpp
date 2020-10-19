#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const ll siz = 1e5 + 5;
#define deb(x) cout << #x << " = " << x << endl;
bool prime[100];
void seive()
{
	for(int i = 2; i<100; i++)
	{
		if(prime[i])
		{
			for(int j = i*2; j < 100; j += i)
			{
				prime[j] = false;
			}
		}
	}
}

int fact_sum(int n)
{
	ll count = 0, total = 1, sum = 0, finals = 1;
		for(int i = 2; i<=n; i++)
		{
			if(prime[i])
			{
				sum = 0;
				count = 0;
				if(n%i == 0)
				{
					while(n%i == 0)
					{
						n /= i;
						count++;
					}
					//deb(count);
					for(int ii = 0; ii<= count; ii++)
					sum += pow(i, ii);
				
				//deb(sum);
				finals *= sum;
				total = total * (++count); 
				}
			}
		}
		cout << "finals = " << finals << endl;
		return total;
}

void solve()
{
	int n;
	cin >> n;
	int total = fact_sum(n);
	cout << total << endl;
}

int main()
{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		ll t = 1;
		//cin >> t;
		memset(prime, 1, sizeof (prime));
		seive();
		while(t--)
		{
			solve();
		}
	return 0;
}
	
