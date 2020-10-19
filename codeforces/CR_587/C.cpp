#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const int siz = 1e5 + 5;
#define deb(x) cout << #x << "x = " << x << endl;

void solve()
{
    int n;
    cin >> n;
    int arr[n], cop[n];
    for(int i = 0; i<n; i++){
        cin >> arr[i]; 
        cop[i]=arr[i];
    }
    int maxi = *max_element(arr,arr+n);
    
    for(int i = 0; i<n; i++){
        cop[i] = maxi-cop[i];
    }
    int i,sol;
    for(i = 0; i<n; i++){
        if(cop[i] != 0){
            sol = cop[i];
            break;
        }
    }
    for(i  = 0; i<n; i++){
        if(cop[i]!=0){
            sol= __gcd(sol,cop[i]);
        }
    }
    ll talvr=0;
    for(int i = 0; i<n; i++){
        talvr += (cop[i]/sol);
    }
    cout << talvr << " " << sol << endl;
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
	
