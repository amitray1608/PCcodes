#include <bits/stdc++.h> 
using namespace std; 
//https://www.geeksforgeeks.org/xor-of-elements-in-a-given-range-with-updates-using-fenwick-tree/
int getXOR(int BITree[], int index) { 
    int ans = 0; 
    index += 1; 
  
    while (index > 0) { 

        ans ^= BITree[index]; 
        index -= index & (-index); 
    } 
    return ans; 
} 

void updateBIT(int BITree[], int n, 
               int index, int val) 
{ 
    index = index + 1; 

    while (index <= n) { 
        BITree[index] ^= val; 
        index += index & (-index); 
    } 
} 
  

int* constructBITree(int arr[], int n) 
{ 
 
    int* BITree = new int[n + 1]; 
    for (int i = 1; i <= n; i++) 
        BITree[i] = 0; 
  

    for (int i = 0; i < n; i++) 
        updateBIT(BITree, n, i, arr[i]); 
  
    return BITree; 
} 
  
int rangeXor(int BITree[], int l, int r) 
{ 
    return getXOR(BITree, r) 
           ^ getXOR(BITree, l - 1); 
} 
  
int main() 
{ 
    int n, qq;
    cin >> n >> qq;
    int A[n]; 
    for(int i = 0; i < n; i++)
      cin >> A[i];
    vector<vector<int>> q(qq, vector<int>(3));
    for(int i = 0; i < qq; i++)
      cin >> q[i][0] >> q[i][1] >> q[i][2]; 
    int* BITree = constructBITree(A, n); 
  
    for (int i = 0; i < qq; i++) { 
        int id = q[i][0]; 
  
        if (id == 2) { 
            int L = q[i][1]; 
            int R = q[i][2];
            L--, R--;
            cout << rangeXor(BITree, L, R) << "\n"; 
        } 
        else { 
            int idx = q[i][1];
            idx--;
            int val = q[i][2]; 
            A[idx] ^= val; 
            updateBIT(BITree, n, idx, val); 
        } 
    } 
  
    return 0; 
} 
