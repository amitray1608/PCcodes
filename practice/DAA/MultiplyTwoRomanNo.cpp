//Amit Kumar
//18BCS2059
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

int romanToInt(string s) {
  unordered_map<char, int>c;
  c['I'] = 1;
  c['V'] = 5;
  c['X'] = 10;
  c['L'] = 50;
  c['C'] = 100;
  c['D'] = 500;
  c['M'] = 1000;
  reverse(s.begin(), s.end());
  int n = (int)s.size(), res = 0, p = 0; 
  for (int i = 0; i < n ; i++) { 
    int x = c[s[i]]; 
    if (x >= p) 
     res += x; 
    else
     res -= x; 
    p = x; 
  }
 return res; 
}


int main() {
 string s, t;
 cin >> s >> t;
 int a = romanToInt(s);
 int b = romanToInt(t);
 cout << b*a << endl;
 return 0;
}