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
        int n;
        cin >> n;
        string s;
        map <string, int> ma;

        for(int i = 0; i<n; i++){
            cin >> s;
            ma[s]++;
        }

        int q;
        cin >> q;
        while(q--)
        {
            cin >> s;
            cout << ma[s] << endl; 
        }
    return 0;
}
