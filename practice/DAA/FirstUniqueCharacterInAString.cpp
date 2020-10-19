//Amit Kumar
//18BCS2059
class Solution {
public:
    int firstUniqChar(string s) {
        int ans = s.size();
        map<char, pair<int, int>>vis;
        for(int i = s.size()-1; i >= 0; i--) {
            vis[s[i]].first++;
            vis[s[i]].second = i;
        }
        for(char &c : s) {
            if(vis[c].first == 1)
                return vis[c].second;
        }
        return -1;
    }
};