//Amit Kumar
//18BCS2059
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        if(n == 0)
            return  str2;
        if(n < m)
            return gcdOfStrings(str2, str1);
        if(str1.substr(0, m) != str2)
            return "";
        return
            gcdOfStrings(str1.substr(m, n), str2);
    }
};