
#include<bits/stdc++.h>

using namespace std;
int n;
vector<int> a;

void sortUsingTwoStacks() {
  stack<int> order, current;
  
  for (int i : a) current.push(i);
  
  while (!current.empty()) {
    int curr = current.top();
    current.pop();
    
    while (!order.empty() and order.top() > curr) {
      current.push(order.top());
      order.pop();
    }
    order.push(curr);
    
    while (!current.empty() and current.top() >= order.top()) {
      order.push(current.top());
      current.pop();
    }
  }
  
  while (!order.empty()) {
    current.push(order.top());
    order.pop();
  }
  
  for (int i = 0; i < n; i++) {
    a[i] = current.top();
    current.pop();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  
  cin >> n;
  a.resize(n);
  for (int &i : a) 
    cin >> i;
  sortUsingTwoStacks();
  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';

  return 0;
}
