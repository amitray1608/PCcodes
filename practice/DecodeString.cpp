#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string res = "";
        stack<string> st;
        string curr = "";
        int i = 0;
        int n = s.size();
        for (;i < n; i++) {
            char c = s[i];
            if (c == '[') continue;
            if (c >= '0' and c <= '9') {
                string times = to_string(c);
                while(i < n and s[i] != '[') {
                    times += to_string(s[i]);
                    i++;
                } i--;
                st.push(times);
            } else if (c >= 'a' and c <= 'z') {
                curr += c;
            } else {
                while (!st.empty()) {
                    string tp = st.top();
                    if (tp[0] >= '0' and tp[0] <= '9') {
                        int x = stoi(tp);
                        while (x--) curr += curr;
                    } else {
                        curr += tp;
                    }
                }
                st.push(curr);
                curr = "";
            }
        }
        return st.top();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    Solution st;
    cout << st.decodeString(s) << '\n';
}