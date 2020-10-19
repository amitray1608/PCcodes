#include<bits/stdc++.h>
using namespace std;
const int N = 26;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>	
using namespace __gnu_pbds;
template<typename T, class cmp = std::less<T>>
using Tree = tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
struct TrieNode{
	struct TrieNode * child[N];
	bool End;
};

struct TrieNode *getNode(){
	struct TrieNode *node = new TrieNode;
	node->End = false;
	for(int i = 0; i < N; i++)
		node->child[i] = NULL;
		
	return node;
}

void insert(struct TrieNode * root, string key){
	struct TrieNode *node = getNode();
	for(int i = 0; i < (int)key.length(); i++){
		int ind = key[i]-'a';
		if(!node->child[ind])
			node->child[ind] = getNode();
			
		node = node->child[ind];
	}
		node->End = true;
}

bool search(struct TrieNode *root, string key){
	struct TrieNode * node = root;
	for(int i = 0; i < (int)key.length(); i++){
		int ind = key[i]-'a';
		if(!node->child[ind])
			return false;
			
		node = node->child[ind];
	}
	return 	(node != NULL && node ->End);
}

int main(){
    string keys[] = {"the", "a", "there", 
                    "answer", "any", "by", 
                     "bye", "their" }; 
    int n = sizeof(keys)/sizeof(keys[0]); 
  
    struct TrieNode *root = getNode(); 
  
    // Construct trie 
    for (int i = 0; i < n; i++) 
        insert(root, keys[i]); 
  
    // Search for different keys 
    search(root, "the")? cout << "Yes\n" : 
                         cout << "No\n"; 
    search(root, "these")? cout << "Yes\n" : 
                           cout << "No\n"; 

	return 0; 
}


