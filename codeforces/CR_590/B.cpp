#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef double dd;
const ll INF = 1e18L + 5;
const ll siz = 1e6 + 5;
#define deb(x) cout << #x << "x = " << x << endl;

void solve()
{
    ll n, k;
    cin >> n >> k; 
  //  set <ll> check;
   // queue <ll> topp;
    ll a[n];
    for(ll &i : a)
        cin >> i;
    
    deque <ll> solution;
    map<ll, bool> check;
     ll tmp;
    for(ll i=0;i<n;i++)
    {
        if((ll)solution.size()<k && check.find(a[i])==check.end())
        {
            solution.push_front(a[i]);
            check[a[i]]=true;
        }
        else if((ll)solution.size()>k && check.find(a[i])==check.end())
        {
            tmp = solution.back();
            solution.pop_back();
            check[tmp]=false;
            solution.push_front(a[i]);
            check[a[i]]=true;
        }
    }
    deque <ll> :: iterator itr;
    cout << solution.size() << endl;
    for(itr = solution.begin(); itr!=solution.end(); itr++)
        cout << *itr<< " ";
}

int main()
{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		ll t = 1;
		//cin >> t;
		while(t--)
		{
			solve();
		}
	return 0;
}
	
