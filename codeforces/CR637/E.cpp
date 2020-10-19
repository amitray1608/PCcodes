#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<string>ss;
    for(int i = 0; i < n; i++){
        ss.push_back(s.substr(i, n));
    }
    sort(ss.begin(), ss.end());
    for(auto i : ss)
    cout << i << endl;
    return 0;
}
