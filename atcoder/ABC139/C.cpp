 #include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
void solve()
{
	int n;
	cin >> n;
	vector <ll> h(n);
	for( ll &x :h)
		cin >> x;
		ll pos = 0, count = 0, prev=0;
	for(ll i = n-1; i >=0; i--)
	{
		if(h[i] <= h[i-1])
		{
			count++;
		}
		else
		{
			if(prev < count)
			prev = count;
			
			count = 0;
		}
	}
	
				if(prev < count)
			prev = count;
	
	cout << prev; 
}

int main()
{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		ll t = 1;
	//	cin >> t
		while(t--)
		{
			solve();
		}
	return 0;
}
