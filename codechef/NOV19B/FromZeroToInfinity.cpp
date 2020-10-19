//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll siz = 1e6 + 5;
const ll MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
ll power (ll a, ll b) {
    ll ans = 1ll;
    while(b) {
        if(b&1) ans=(ans*a)%MOD;
        a=(a*a)%MOD;
        b >>= 1;
    }
    return ans;
    }
 long long int mod(int n){
    int cnt = 0;
    while(n!=0){
        cnt++;
        n = n/10;
    }
    return cnt;
}
long double powers(ll a, ll n) {
	long double deno = 1.0;
	while (n > 0){
		if(n%2) deno = deno * a;
		
		 n >>= 1, a *= a;
	} 
return deno;
}
bool isAlice(char s){
        if(s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u')
            return true;

        return false;
}
void solve(){
	    ll l;
        cin >> l;
        ll c_in_a[26] = {0}, freq_in_a[26] = {0};
        ll c_in_b[26] = {0}, freq_in_b[26]={0};
        ll alice_c = 0, bob_c = 0;
        vector<string>v;
        while(l--){
            string s;
            cin >> s;
            v.push_back(s);
            bool flag = true;
            ll v = -1, tmp[26] = {0};
            for(ll j = 0; j < (ll)s.length(); j++){
                if(isAlice(s[j])){
                    tmp[s[j]-'a']++;
                }
                else{
                    if(v == -1 )
                        v = j;
                    else{
                        if(j-v>2)
                            v = j;
                        else
                            flag = false;
                    }
                    tmp[s[j] - 'a']++;
                }
                
            }
            if(flag){
                for(ll j=0;j<26;j++){
                    c_in_a[j] += tmp[j];
                    if(tmp[j])
                        freq_in_a[j] += 1;
                }
                alice_c++;
            }else{
                for(ll j=0;j<26;j++){
                    c_in_b[j] += tmp[j];
                    if(tmp[j])
                        freq_in_b[j] += 1;
                }
                bob_c++;
            }
            
            
            
        }
        ll ac[26] = {0}, bc[26] = {0};
           for(int i=0; i<26; i++){
            for(int j=0; j<l; j++){
                int len = v[j].length();
                for(int k=0; k<len; k++){
                    if((int)(v[j]).at(k)-97 == i){
                        if(freq_in_a[j]) ac[i]++;
                        else bc[i]++;
                        break;
                    }
                }
            }
        }
       // long double countA = 1.000000000, countB=1.00000000;
		long double a=1,b=1,c=1,d=1,temp,num1,num2,result;
        long long int ap=0,bp=0,cp=0,dp=0,num1p,num2p,resultp;
        for(ll i=0; i<26; i++)
        {
            if(freq_in_a[i]){
				a = ac[i];
				ap += mod(a);
				temp = pow(10, mod(a));
				a = a/temp;
				c *= c_in_a[i];
				cp += mod(c);
				temp = pow(10, mod(c));
				c = c/temp;
            }
        }
        
        
        
        for(ll i=0; i<26; i++){
            if(freq_in_b[i] )
            {
				b *= ac[i];
				bp += mod(b);
				temp = pow(10, mod(b));
				b = b/temp;
				d *= c_in_b[i];
				dp += mod(d);
				temp = pow(10, mod(d));
				d = d /temp;
            }
        }
        num1 = a/b;
        num1p = ap-bp;
        temp = pow(c,alice_c);
        num2 = pow(d,bob_c);
        num2 = num2/temp;
        num2p = dp*bob_c - cp*alice_c;
        result = num1*num2;
        resultp = num1p + num2p;
        while(result<10000000){
            result*=10;
            resultp--;
        }
        if(resultp > 0) cout<<"Infinity";
        else if(resultp == 0){
            if(result > 10000000)
				cout<<"Infinity";
            else cout << result;
        }
        else if(resultp < 0 && resultp >= -14){
            result = result*pow(10,resultp);
            cout<<result;
        }
        else cout<<"0.0000000";
        cout<<endl;

}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		ll t = 1;
		cin >> t;
		cout << fixed << setprecision(12);
		while(t--){
			solve();
		}
	return 0;
}
