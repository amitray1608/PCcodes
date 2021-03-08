
#include <bits/stdc++.h>

using namespace std;

template<class T, class U> T cast(U x) { 
  T result;
  ostringstream out; out << x;
  istringstream in(out.str()); in >> result; 
  return result; 
}

void stackPrint(vector<string> operation) {
  
  stack<int> st;
  map<int, int> mp;

  for (auto i : operation) {
    stringstream fin(i);
    string tp;
    fin >> tp;
    if (tp == "push") {
      int x;
      fin >> x;
    } else if (tp == "pop") {
      
    } else {

    }
  }

  mp.erase(7);
}

template<class T> 
vector<T> split(string s, string separator = " ") {
  vector<T> result;
  for(int i = 0, n = (int)s.length(); i < n; ++i) {
    string a;
    while(i < n and separator.find(s[i]) == string::npos) 
      a += s[i++]; 
    if(!a.empty()) result.emplace_back(cast<T>(a));
  }
  return result;
}

void solve() {
  string s = "amt:pulkit:raju";
  vector<string> res = split<string>(s, ":");
  for (auto i : res) {
    cout << i << ' ';
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  //cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


