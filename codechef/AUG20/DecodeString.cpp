#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> times;
        stack<string> str;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            char c = s[i];
            if(c >= '1' and c <= '9')
                times.push(c-'0');
            string r = "";
            while(s[i] != ']') {
                if(s[i] == '[') {i++; continue;}
                r += s[i];
                i++;
            }
            if(s[i] == ']') {
                int x = times.top();
                times.pop();
                string t = "";
                for(int j = 0; j < x; j++) {
                    t += r;
                }
                t = str.top() += t;
                str.pop();
                str.push(t);
            } else
                str.push(r);
        }
        return str.top();
    }
};