#include<bits/stdc++.h>
using namespace std;

class narytree{
	public:
	string data;
	bool islock;
	int childlocked;
	int uidowner;
	narytree* parent;
	vector<narytree*> children;
  unordered_map<int,int> uiddec;
	unordered_set<narytree*> lockedchildref;
  mutex m;
	narytree(string d){
		data=d;
		islock=false;
		childlocked=0;
		parent=NULL;
		uidowner=-1;
	}
	narytree(narytree* p,string d){
		data=d;
		islock=false;
		childlocked=0;
		parent=p;
		uidowner=-1;
	}
};
bool update_parents(narytree* node,int uid){
  if(node==NULL){
    return true;
  }
  if(node->islock){
    return false;
  }
  if(!node->m.try_lock()){
    return false;
  }
  node->childlocked++;
  node->m.unlock();
  bool ret=update_parents(node->parent,uid);
  if(!ret){
    node->childlocked--;
  }else{
    node->lockedchildref.insert(node);
	  node->uiddec[uid]++;
  }
  return ret;
}

bool lock(narytree* node,int uid,bool is_called_from_upgrade){
  unique_lock<mutex> locker(node->m);
	if(node->islock==true){
		return false;
	}
  if(node->childlocked>0 and !is_called_from_upgrade){
   return false;
  }
  node->islock=true;
  node->uidowner=uid;
  locker.unlock();
	if(update_parents(node->parent,uid)){
		return true;
  }else{
    locker.lock();
    node->islock=false;
    node->uidowner=-1;
    return false;
  }
}

bool unlock(narytree* node, int uid){
  unique_lock<mutex> locker(node->m);
	if(node->islock == false or node->uidowner!=uid){
		return false;
	}
	narytree* T = node->parent;
	node->islock=false;
  locker.unlock();
  node->uidowner=-1;
	while(T != NULL){
    T->lockedchildref.erase(node);
		T->uiddec[uid]--;
    if(T->uiddec[uid]==0){
      T->uiddec.erase(uid);
    }
		T->childlocked--;
		T=T->parent;
	}
	return true;
}
bool upgradelock(narytree* node, int uid){
  unique_lock<mutex> locker(node->m);
	if(node->islock == true){
		return false;
	}
	if(node->uiddec.size()!=1){
		return false;
	}
	if(node->uiddec.count(uid)){
		return false;
	}
  if(lock(node,uid,true)){
    return false;
  }
	auto tempdata=node->lockedchildref;
  locker.unlock();
	for(auto i:tempdata){
		unlock(i,uid);
	}
	return true;
}
int main(){
	int m,n,q;
	cin>>n>>m>>q;
	vector<string> s;
	for(int i=0;i<n;i++){
		string x;
		cin>>x;
		s.push_back(x);
	}
	int parent=-1;
	unordered_map<string,narytree*> ma;
	vector<narytree*> noder;
	narytree* root = new narytree(s[0]);
	ma[s[0]]=root;
	noder.push_back(root);
	int c=0;
	for(int ii=0;ii<n-1;ii++){
		int i=ii+1;
		c=(ii%m);
		if(c==0){
			parent+=1;
		}
		narytree* node = new narytree(noder[parent],s[i]);
		noder[parent]->children.push_back(node);
		ma[s[i]]=node;
		noder.push_back(node);
	}
	for(int i=0;i<q;i++){
		int type,uid;
		string name;
		cin>>type>>name>>uid;
		if(type==1){
			if(lock(ma[name],uid,false)==true){
				cout<<"true"<<endl;
			}else{
				cout<<"false"<<endl;
			}
		}else if(type==2){
			if(unlock(ma[name],uid)==true){
				cout<<"true"<<endl;
			}else{
				cout<<"false"<<endl;
			}
		}else if(type==3){
			if(upgradelock(ma[name],uid)==true){
				cout<<"true"<<endl;
			}else{
				cout<<"false"<<endl;
			}
		}
	}
	return 0;
}


