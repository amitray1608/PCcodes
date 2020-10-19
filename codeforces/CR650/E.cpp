#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
const int N = 100005;
int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;cin>>t;while(t--)
    {
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        string s;
        cin >> n >> k >> s;
        //n = s.length();
        j = 0;
        int a[n] = {0};
        /*for(i=0;i<n;i++){
            a[i] = (s[i] - '0');
            cout << a[i];
        }*/
        for (i = 0; i < n; i++) {
            sum += (s[i] - '0') ;
            //cout << s[i]-'0';
            if((s[i] - '0') == 1){
                //cout <<i<<"*";
                m = i-j-1;
                if(m >= 2*k){
                    ans += m/(2*k);
                }
                j = i;
            }
        }
        if(sum == 0){
            i=0;
            while(i<n){
                ans++;
                i += (k);
            }
            if(n%2 == 0 && k%2 == 0 && n > 2){
                ans--;
            }
            cout << ans<<endl;
        }else if(sum == 1){
            j = 0;
            i = 0;
            while((s[i] - '0') != 1){
                i++;
            }
            ans = (i-j-1)/(2*k);
            ans += (n-i+1)/(2*k);
            cout << ans<<endl;
        }else{
            cout << ans <<endl;
        }
    }
}