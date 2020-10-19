/*RAY header for competition*/
#include <bits/stdc++.h> 
using namespace std;
typedef long long int ll;
int main() {
ios::sync_with_stdio(false); 
#ifdef RAY
  freopen("input.txt" , "r" , stdin);
#endif
ll t;
cin >> t;
while(t--){
        ll n;
        cin >> n;
        ll a[n];
        for(int i = 0; i<n; i++)
            cin >> a[i];
        set <ll> check;
        
        for(int i = 0; i<n; i++)
        check.insert(a[i]);
        ll w =0, x=0, y=0, z=0;
        if(check.size() == 1)
            w = a[0]*2;
        
            ll maxi = *max_element(a, a+n), mini = *min_element(a, a+n);
            ll gcd1 = 0, gcd2 = 0;
            for(auto it = check.begin(); it!=check.end(); it++)
            {
                if(*it != maxi)
                gcd1 = __gcd(gcd1, *it);
                
                if(*it != mini)
                gcd2 = __gcd(gcd2, *it);
            }
            x = max(gcd1+maxi, gcd2 + mini);
            
            
            ll prev = 0;
            vector <ll> v1, v2;
            for(auto it = check.begin(); it!=check.end(); it++)
            {
                if(__gcd(prev, *it) == mini)
                    prev = __gcd(prev, *it), v1.push_back(*it);
                else
                    v2.push_back(*it);
            }
            ll bb=0, cc=0;
            for(auto it = v1.begin(); it != v1.end(); it++)
            {
                bb = __gcd(bb, *it); 
            }
            for(auto it = v2.begin(); it != v2.end(); it++)
            {
                cc = __gcd(cc, *it); 
            }
             y = cc+bb;
             
             prev = INT_MAX;
             ll pp = 0;
             for(auto it = check.begin(); it != check.end(); it++)
            {
                if(__gcd(*it, mini)<prev)
                {
                    prev = __gcd(*it, mini);
                    pp = *it;
                }
            }
            prev= 0;
             for(auto it = check.begin(); it != check.end(); it++)
            {
                 if(*it != pp)
                {
                    prev = __gcd(*it, prev);
                }
            }
            z = pp+prev;
            cout << max(w, max(x, max(y, z))) << endl;

}
    return 0;
}

