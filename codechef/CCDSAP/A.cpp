#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int tt = 1; tt <=t; tt++){
       cout << "Case #" << tt << ": ";
        int n, m;
        cin >> n >> m;
        int a[n];
        for(int &i : a) cin >> i;
        sort(a, a+n);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(a[i] > m) break;
            else{
                m -= a[i];
                ans++;
            }
        }
        cout << ans << endl;
    }
}
