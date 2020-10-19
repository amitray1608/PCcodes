#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b); 
} 
  
// Returns LCM of array elements 
ll findlcm(int arr[], int n) 
{ 
    // Initialize result 
    ll ans = arr[0]; 
  
    // ans contains LCM of arr[0], ..arr[i] 
    // after i'th iteration, 
    for (int i = 1; i < n; i++) 
        ans = (((arr[i] * ans)) / 
                (gcd(arr[i], ans))); 
  
  return ans;
}


void solve(){
	int n;
	cin >> n;
	int a[n];
	cout << fixed << setprecision(6);
	for(int i = 0; i<n; i++)
	cin >> a[i];
	
	ll lcm = findlcm(a, n);
	double ans = 0;
	for(int i = 0; i<n; i++)
	{
		ans += (double)lcm/(a[i]*1.0);
	}
	ans = (double)lcm/ans;
	cout << ans << endl;

}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
	//cin >> t;
	while(t--)
	{
		solve();
	}
		return 0;
}
