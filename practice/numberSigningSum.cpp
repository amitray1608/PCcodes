#include<bits/stdc++.h>
using namespace std;
int numberSigningSum(int n) {
    string s = to_string(n);
    int sz = s.size();

    int arr[sz+1];
    int N = n;
    int i = sz;
    
    while(N > 0){
        int rem = N % 10;
        arr[i] = rem;
        N = N /10;
        i--;
    }
    cout << arr[0] << endl;
    int ans = arr[0];
    for (i = 1; i <= sz; ++i){
        if((i ^ 1) != i + 1)
            ans += arr[i];
        else
            ans -= arr[i];
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    cout << numberSigningSum(n);
}
