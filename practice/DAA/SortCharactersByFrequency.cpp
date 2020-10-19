//Amit Kumar
//18BCS2059
class Solution {
public:
    string frequencySort(string s) {
        map<char, int>c;
        priority_queue<pair<int, char>>q;
        
        for(char &i : s) c[i]++;
        
        for(auto &i : c) {
            q.push({i.second, i.first});
            
        }
        
        string ans = "";
        while(!q.empty()) {
            auto i = q.top();
            q.pop();
            int x = i.first;
            while(x--) ans += i.second;
        }
        return ans;
    }
};