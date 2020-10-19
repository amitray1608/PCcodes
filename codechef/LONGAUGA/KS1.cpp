/*RAY header for competition*/
#include <bits/stdc++.h> 
using namespace std;
typedef long long int ll;

void sub(ll a[], ll n)
{
		ll i, j, k, l;
		for(i = 0; i<n; i++)
		{
			for(j = i; j<n; j++)
			{
				for(k = i; k<=j; k++)
					cout << a[k] <<  " ";
			cout << endl;
		}
			//cout << endl;
		}
}


void solve(){
		ll n;
		cin >> n;
		ll arr[n];
		for(ll i = 0; i<n; i++)
			cin >> arr[i];

        ll  count=0, temp;
		for(ll i = 0; i<n-1; i++)
		{
			temp = arr[i];
			for(ll it = i+1; it<n; it++)
			{
				temp ^= arr[it];
				if(temp==0)
			    {		
			        count += (it-i);
			    }
			    cout << " ( " << temp << " count = " << count << " ) ";
			}
			cout << endl;
		}
		cout << count << endl;

    
}


int main() {
ios::sync_with_stdio(false); 
#ifdef RAY
  freopen("input.txt" , "r" , stdin);
#endif
ll t;
cin >> t;
while(t--){
    //ll n;
		//cin >> n;
//	ll a[n];
	//for(int i = 0; i<n; i++)
		//cin >> a[i];
		solve();
		//ll ans = 
		//sub(a, n);
		//cout << ans << endl;
}
#ifdef RAY
  cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
#endif
}

