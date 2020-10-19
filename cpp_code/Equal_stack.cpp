//RAY
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1e9+7;
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
            int l, m, n;
            cin >> l >> m >> n;
            stack < int > s1, s2, s3;
            int sum1 = 0, sum2 = 0, sum3 = 0, a[l], b[m], c[n];

            for(int i = 0; i<l; i++)
                cin >> a[i],sum1+=a[i];
            
            for(int i = 0; i<m; i++)
                cin >> b[i], sum2+=b[i];
            
            for(int i = 0; i<n; i++)
                cin >> c[i], sum3 +=c[i];

            for(int i = l-1; i>=0; i--)
                s1.push(a[i]);

            for(int i = m-1; i>=0; i--)
                s2.push(b[i]);
            
            for(int i = n-1; i>=0; i--)
                s3.push(c[i]);

        while ( sum1 != sum2 || sum2 != sum3  ){
            if(sum1>=sum2 && sum1>=sum3){
                 sum1-=s1.top();
                 s1.pop();
            }
            else if(sum2>=sum1 && sum2>=sum3){
                sum2-=s2.top();
                s2.pop();
            }
            else{
                sum3-=s3.top();
                s3.pop();
            }
        }
        
        cout << sum1;
    return 0;
}
