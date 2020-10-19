#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
 
  int n, k;
  cin >> n >> k ;
  vector<int> a(n);
  int M = n/2;
  for(int i=0; i<n; ++i)
    cin >> a[i];
    sort(a.begin(), a.end());
    while(k > 0)
    {
        auto beg = M;
        while(beg!=n-1 && a[beg]==a[beg+1])
        {
            beg++;
        }
        if(k >= (beg-M+1))
        {
            for(int i=M;i<=beg;++i)
                a[i]++;
                
            k -= (beg-M+1);
        }
        else break;
    }
    ll ans = a[M];
   cout << ans;
}
 
int main()
{
	
	    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
		ll t =1;
		//	cin >> t;
		while(t--)
		{
			solve();
		}
		return 0;
}
 
