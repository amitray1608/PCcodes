#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
    int main() {
      // #ifndef ONLINE_JUDGE
      //     freopen("input.txt", "r", stdin);
      //     freopen("output.txt", "w", stdout);
      // #endif
      int n, k, temp;
      cin >> n >> k;
      priority_queue<int, vector<int>, greater<int>> Q;
      for (int i = 0; i < n; i++) {
        cin >> temp;
        Q.push(temp);
      }

      int cnt = 0;
      while (true) {
        if ((temp = Q.top()) < k) {
          Q.pop();         
          if (Q.empty())
            { 
            cout << -1;
            break;
          }
          int temp2 = 2 * Q.top();
          Q.pop();       
          Q.push(temp + temp2); 
          cnt++;       
        } 
        else
        {
          cout << cnt; 
          break;
        }
      }

      return 0;
}
