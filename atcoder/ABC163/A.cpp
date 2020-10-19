#include<bits/stdc++.h>
using namespace std;
int main(){
    int q;
    cin >> q;
    queue<pair<int, int>>s1, s2, s3, s4;
    queue<int> frnt;
    bool f1 = 0, f2 = 0, f3 = 0, f4 = 0;
    while(q--){
        char c;
        cin >> c;
        if(c == 'E'){
            int x, y;
            cin >> x >> y;
            if(x == 1){
                if(!f1)
                    frnt.push(x), f1 = 1;
                s1.push(make_pair(x, y));
            }else if(x == 2){
                if(!f2)
                    frnt.push(x), f2 = 1;
                s2.push(make_pair(x, y));
            }else if(x == 3){
                if(!f3)
                    frnt.push(x), f3 = 1;
                s3.push(make_pair(x, y));
            }else{
                if(!f4)
                    frnt.push(x), f4 = 1;
                s4.push(make_pair(x, y));
            }
        }else{
            pair<int, int>ans;
            int l = frnt.front();
            if(l == 1){
                ans = s1.front();
                s1.pop();
                if(s1.empty())
                    f1 = 0, frnt.pop();
            }else if(l == 2){
                ans = s2.front();
                s2.pop();
                if(s2.empty())
                    f2 = 0, frnt.pop();
            }else if(l == 3){
                ans = s3.front();
                s3.pop();
                if(s3.empty())
                    f3 = 0, frnt.pop();
            }else{
                ans = s4.front();
                s4.pop();
                if(s4.empty())
                    f4 = 0, frnt.pop();
            }
            cout << ans.first << " " << ans.second << endl;
        }
    }
    return 0;
}
