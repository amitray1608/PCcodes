#include<bits/stdc++.h>
using namespace std;

class Node {
public:
  int val;
  vector<Node*> child;
  Node() {}
  Node(int val) {
    val = _val;
  }
  Node(int _val, vector<Node*> _child) {
    val = _val;
    child = _child;
  }

};

double ans = INT_MIN;
Node *res;

pair<double, double> dfs(Node *node) {
  if(!node)
    return {0, 0};
  double currVal = node->val;
  double count = 1;
  for(auto &i : node->child) {
    pair<double, double>tmp = dfs(i);
    count += tmp.second;
    currVal += tmp.first;
  }
  double avg = currVal/count;
  if(count > 1 and avg > ans) {
    ans = avg;
    res = node;
  }
  return {currVal, count};
} 

int main() {

}