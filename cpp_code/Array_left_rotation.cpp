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
            int n, d;
            cin >> n >> d;
            int a[n+1]={0};
            for(int i = 0; i<n; i++)
                cin >> a[i];

            int b[n+1]={0};
            for(int i = 0; i<n; i++)
            {
                int pos = (i+(n-d))%n;
                b[pos] = a[i];
                //cout << " POS = " << pos << " " << "b[i] = " << b[i] << endl;
            }

            for(int i = 0; i<n; i++)
                cout << b[i] << " ";
    return 0;
}
