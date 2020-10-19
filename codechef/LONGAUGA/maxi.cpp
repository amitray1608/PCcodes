#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
ll MOD = 1e9+7;

ll solve(){
        cout << fixed << setprecision(15);
        ll n, i;
            cin >> n;
        dd k[n], c[n], x[n];
        for(i = 0; i<n; i++) 
            cin >> k[i];

        for( i=0; i<n; i++)
            cin >> c[i];

        dd sum = 0, below = 0, ans = 0, up = 0;
        for( i=0; i<n; i++){
                sum += c[i] * k[i];
            below += ((dd)1.0)/k[i];
        }
        if(sum < 0)           
            return 0;

         up = sum / below;
        
        for(i=0; i<n; i++) 
                x[i] = up / (k[i] * k[i]);
        
        for(i=0; i<n; i++) 
                ans += sqrt(x[i]);
        
        for(i=0; i<n; i++) 
                x[i] -= c[i];

        cout << ans << " ";
        for(i=0; i<n; i++) 
            cout << x[i] << " ";
        cout << endl;

        return 1;
}

int main(){
		ll t;
		cin >> t;
		while(t--)
		{
            //memset(DP, 0, sizeof(DP));
			ll it = solve();
            if(it == 0) 
            { 
               cout << -1 << endl;
                continue;
            }
		}
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
ll MOD = 1e9+7;

ll solve(){
        cout << fixed << setprecision(15);
        ll n, i;
            cin >> n;
        dd k[n], c[n], x[n];
        for(i = 0; i<n; i++) 
            cin >> k[i];

        for( i=0; i<n; i++)
            cin >> c[i];

        dd sum = 0, below = 0, ans = 0, up = 0;
        for( i=0; i<n; i++){
                sum += c[i] * k[i];
            below += ((dd)1.0)/k[i];
        }
        if(sum < 0)           
            return 0;

         up = sum / below;
        
        for(i=0; i<n; i++) 
                x[i] = up / (k[i] * k[i]), ans += sqrt(x[i]);
        
        for(i=0; i<n; i++) 
                x[i] -= c[i];

        cout << ans << " ";
        for(i=0; i<n; i++) 
            cout << x[i] << " ";
        cout << endl;

        return 1;
}

int main(){
		ll t;
		cin >> t;
		while(t--)
		{
            //memset(DP, 0, sizeof(DP));
			ll it = solve();
            if(it == 0) 
            { 
               cout << -1 << endl;
                continue;
            }
		}
	return 0;
}

