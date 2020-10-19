#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const int siz = 1e6 + 5;
#define deb(x) cout << #x << " = " << x << endl;
int seive[10000];
void prime();
bool three_fact(int n);
void solve()
{
	int n;
	cin >> n;
	int i = 1, count = 0; 
	while(i>0)
	{
		if(three_fact(i) == true)
			count++;
		
		if(count == n)
		{	cout << i << endl;
			break;
		}
		
		i++;
	}
}

bool three_fact(int n)
{
	int count = 0;
		for(int i = 2; i<=n/2; i++)
		{
			if(seive[i] && n%i==0)
				count++;
		}
		if(count >= 3)
			return true;
		else
			return false;
}

void prime()
{
	memset(seive, 1, sizeof seive);
		for(int i = 2; i*i <= 10000; i++)
		{
				if(seive[i])
				{
					for(int j = i*i; j<=10000; j += i)
						seive[j] = 0;
				}
		}
}

int main()
{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		ll t = 1;
		cin >> t;
		prime();
		while(t--)
		{
			solve();
		}
	return 0;
}
	
