#include<bits/stdc++.h>

using namespace std;

int main() {
  string a, b;
  cin >> a >> b;
  int A = 0, B = 0;
  for(char c : a) A += c - '0';
  for(char c : b) B += c - '0';
  cout << max(A, B);
  return 0;
}


