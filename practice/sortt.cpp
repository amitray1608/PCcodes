//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;
 
//solution:
#define int int64_t
 
struct trie {
  constexpr static int sigma = 2, offset = '0';
  trie* key[sigma], *parent;
  int end, p;
  trie() = default;
  trie(trie* parent): parent(parent) {
    for(auto& i: key) i = nullptr;
    end = p = 0;
  }
  void insert(string s) {
    int n = s.length();
    trie* nav = this;
    for(int i = 0; i < n; ++i) {
      if(!(nav -> key[s[i] - offset])) {
        nav -> key[s[i] - offset] = new trie(nav);
      }
      nav = nav -> key[s[i] - offset], (nav -> p)++;
    }
    (nav -> end)++;
  }
  int search(string s) {
    int n = s.length();
    trie* nav = this;
    for(int i = 0; i < n; ++i) {
      if(!(nav -> key[s[i] - offset])) return 0;
      nav = nav -> key[s[i] - offset];
    }
    return nav -> p;
  }
  bool isleaf() {
    for(int i = 0; i < sigma; ++i) if(this -> key[i]) return false;
    return true;
  }
  int query(string b, string c) {
    int n = 32, count = 0, zero = true;
    trie* nav = this;
    for(int i = 0; i < n; ++i) {
      if(zero) {
        if(b[i] == '0') {
          nav = nav -> key[c[i] - '0'];
        } else {
          zero = false;
          count += (nav -> key[(c[i] - '0')]) -> p;
          nav = nav -> key[(c[i] - '0') ^ 1];
        }
      } else {
        if(b[i] == '0') {
          nav = nav -> key[c[i] - '0'];
        } else {
          count += nav -> key[(c[i] - '0')] -> p;
          nav = nav -> key[(c[i] - '0') ^ 1];
        }
      }

      
    }
    cout << "OK " << "" << '\n';
      return 0;
    return count;
  }
};
 
void hike() {
  int n, k; cin >> n >> k;
  vector<int> a(n);
  for(int& i: a) cin >> i;
  trie* root = new trie(nullptr);
  root -> insert(bitset<32>(0).to_string());
  for(int i = 0; i < n; ++i) {
    root -> insert(bitset<32>(a[i]).to_string());
  }
  auto valid = [&](int m) {
    int count = 0;
    for(int i = 0; i < n; ++i) {
      count += root -> query(bitset<32>(m).to_string(), bitset<32>(a[i]).to_string());
    }  
    return k <= count;
  };

  
  int lo = 0, hi = 1e10;
  while(hi - lo > 1) {
    int mid = lo + hi >> 1;
    if(valid(mid)) hi = mid;
    else lo = mid;
  }
  cout << hi << "\n";
}
 
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1; cin >> t;
  while(t--) hike();
  return 0;
} //farewell, until we meet again..
