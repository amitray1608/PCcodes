
#include<iostream>

using namespace std;

//Array implementation of stack.
struct Stack { 
  int top = -1;
  int siz = 100;
  int s[101];
  
  Stack() {
    top = -1;
  };

  void push(int i) {
    if(top == siz - 1) {
      cout << "Stack Overflow." << '\n';
    };
    s[++top] = i;
  }
  
  bool pop() {
    if(empty()) return false;
    s[top--] = 0;
    return true;
  }
  
  int onTop() {
    if(empty()) return -1;
    return s[top];
  }
  
  bool empty() {
    return top == -1;
  }
  
  int size() {
    return top + 1;
  }
};

//recursive function to put the element at the right positon.
void sortInsert(Stack &st, int i) {
  if (st.empty() or i > st.onTop()) {
    st.push(i);
    return;
  }
  int x = st.onTop();
  st.pop();
  sortInsert(st, i);
  st.push(x);
}


//Sorting recursive funciton
void sortUsingRecursion (Stack &st) {
  if (!st.empty()) {
    int x = st.onTop();
    st.pop();
    sortUsingRecursion(st);
    sortInsert(st, x);
  }
}

//function to print the stack.
void printStack(Stack &x) {
  if (x.empty()) return;
  int tp = x.onTop();
  x.pop();
  printStack(x);
  cout << tp << ' ';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  
  cout << "Enter the number of elements:" << endl;
  int n;
  cin >> n;
  Stack st, stt;
  
  cout << "Enter the elements of the stack:" << endl;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    st.push(x); 
    stt.push(x);
  }

  cout << "\nBefore Sorting : " << '\n';
  printStack(stt);
  cout << "\n\n";
  
  sortUsingRecursion(st);
  
  cout << "After Sorting : " << '\n';
  printStack(st);
  cout << "\n\n";
  
  return 0;
}

