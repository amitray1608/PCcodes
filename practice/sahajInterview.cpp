// 1 -> 2 -> 3 -> 4 -> 5

struct Node {
  int data;
  Node *next;
}

void findSecondLast(Node *root, int pos) {
  Node *copy = root;
  if (copy == NULL) return;
  int size = 0;
  while (copy -> next != NULL) {
    copy = copy -> next;
    size++;
  }
  int count = size - pos;
  copy = root;
  while (count--) {
    copy = copy -> next;
  }
  cout << copy -> data;
}

1 -> 2 -> 3 -> 4 -> 5 -> 3


void isLoop(Node *root) {
  Node *copy = root;
  map<Node *, bool> mp;
  while (copy != NULL) {
    if (mp[copy] == true) return true;
    mp[copy] = true;
    copy = copy -> next;
  }
  return false;
}


int main() {

  int n;
  cin >> n;
  int a[14] = {0};
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[x]++;
  }
  for (int i = 1; i <= 13; i++) {
    while (a[i]--) cout << i << ' ';
  }
}


CityTheatre

Id | city | TheatreName | ShowRunning | startDate | EndDate
No  text 

1 chd abc fdjdk
2 chd dc  fdfd
3 bng xy  abc
4 delhi xx bd


CityTheatre = {
city : ,
theatre[]: {
  {
id : 
  }
},

Theatre = {
  
}



