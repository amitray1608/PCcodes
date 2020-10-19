vector<int> ar[10001];
vector<bool> vis(10001);
const int mod = 1e9+7;
int binpow(int a, int b, int m = mod) {
    a %= m;
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int ans;
void dfs(int node, int level,int p){
    int cnt = 0; 
    for(auto i:ar[node]){
            if(level==p)
              dfs(i,level+1,p);
    }
}
int Solution::solve(vector<vector<int> > &A, int B) {
    for(auto i:A){
        ar[i[0]].push_back(i[1]);
        ar[i[1]].push_back(i[0]);
    }
    dfs(1,0,B-1);
    for(auto &i:ar) i.clear();
    memset(&vis,false,sizeof vis);
    return binpow(2,ans);
}
