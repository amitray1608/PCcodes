//Amit Kumar
//18BCS2059
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> m;
        
        for (auto &i: words)  m[i]++;
        
        vector<pair<string, int>> v;
        
        auto cmp = [&](pair<string, int> a, pair<string, int> b) {
            return a.second == b.second ? a.first < b.first : a.second > b.second;
        };
        
        for (auto &i: m) v.push_back(i);
        sort(v.begin(), v.end(), cmp);
        
        vector<string> res;
        int i = 0;
        while (i < k) 
            res.push_back(v[i++].first);
        return res;
    }
};
