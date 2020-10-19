//#include <bits/stdc++.h>
//typedef long long ll;
//using namespace std;
//ll mod=1000000007;
//ll numberOfFactors(vector<int> &v) {
    //map<int, int> ctr;
    //for (int i = 0; i < v.size(); i++) {
        //int number = v[i];
        //for (int j = 2; j * j <= number; j++)
        //{
            //while (number % j == 0)
            //{
                //ctr[j]++;
                //number /= j;
            //}
        //}
        //if (number > 1) ctr[number]++;
    //}
    //ll ans = 1;
    //for (map<int, int>::iterator it = ctr.begin(); it != ctr.end(); it++) {
        //ans = ((ans % mod) * ((it->second + 1) % mod)) % mod;
        ans *= (it->second + 1);
    //}
    //return (ans );
//}

//int **table; 
//int height; 
//void initialize(int n) 
//{ 
	//height = (int)ceil(log2(n)); 
	//table = new int *[n + 1]; 
//} 
//void preprocessing(int n) 
//{ 
	//for (int i = 0; i < n + 1; i++) 
	//{ 
		//table[i] = new int[height + 1]; 
		//memset(table[i], -1, sizeof table[i]); 
	//} 
//} 
//void calculateSparse(int u, int v) 
//{ 
	//table[v][0] = u; 
	//for (int i = 1; i <= height; i++) 
	//{ 
		//table[v][i] = table[table[v][i - 1]][i - 1]; 

		//if (table[v][i] == -1) 
			//break; 
	//} 
//} 
//int kthancestor(int V, int k) 
//{ 
	//for (int i = 0; i <= height; i++) 
	//{ 
		//if (k & (1 << i)) 
		//{ 
			//V = table[V][i]; 
			//if (V == -1) 
				//break; 
		//} 
	//} 
	//return V; 
//} 
//int main() 
//{  
	//int t;
	//cin>>t;
	//while(t--)
	//{
		//int n;
		//cin>>n;
		//initialize(n);
		//int xx,yy;
		//for (int i = 0; i < n-1; ++i)
		//{
			//cin >> xx >> yy;
			//calculateSparse(xx,yy);

		//}
		//int arr[n];
		//for (int i = 0; i < n; ++i)
		//{
			//cin>>arr[i];
		//}
		//int q;
		//cin>>q;
		//int a,b;
		
		//while(q--)
		//{
			//std::vector<int> k,l;
			//cin>>a>>b;
			//if (a==b)
            //{
                //std::vector<int> k;
                //k.push_back(arr[a-1]);
                //cout<<numberOfFactors(k)%1000000007<<"\n";
            //}
            //else
            //{
            	//int tmp,flag=0,fv=0;
            	//for (int i = 0; i < n; ++i)
            	//{
            		//int tmp=kthancestor(a,i);
            		//if (tmp== -1)
            		//{
            			//flag=0;
            			//break;
            		//}
            		//else
            			//if (tmp==b)
            			//{
            				//flag=1;
            				//l.push_back(tmp);
            				//break;
            			//}
            			//else
            				//{
            					//l.push_back(tmp);
            					//fv=tmp;
            				//}

            	//}
            	//if (flag==0)
            	//{
            		//for (int i = 0; i < n; ++i)
            		//{
            			//tmp=kthancestor(b,i);
            			//if (tmp==fv)
            			//{
            				//flag=1;
            				
            				//break;
            			//}
            			//else
            				//{
            					//l.push_back(tmp);
            					
            				//}

            		//}
            	//}
            	//for (int i = 0; i < l.size(); ++i)
            	//{
            		//k.push_back(arr[l[i]-1]);
            	//}
            	//cout<<numberOfFactors(k)%1000000007<<"\n";
            //}


		//}
		
	//}
	//return 0; 
//}
//author: contrapasso;
#include<bits/stdc++.h>
using namespace std;

//seek and ye shall find;
mt19937 mersenne{ static_cast<mt19937::result_type>(time(nullptr)) };

void purgatorio() {
    auto start = chrono::system_clock::now();
    int n, m, k; scanf("%d %d %d", &n, &m, &k);
    int a[n][k];
    for(auto& i: a) for(auto& j: i) scanf("%d", &j);
    pair<vector<int>, int> solution = {{}, INT_MIN};
    uniform_int_distribution<> die{1, m};
    while(true) {
        vector<int> guess(n); //iske liye;
        for(int i = 0; i < n; ++i) guess[i] = die(mersenne);
        int score = INT_MAX; //sentinel;
        for(int j = 0; j < k; ++j) { //kaunse set mein evaluation ho raha hai;
            int local = 0;
            for(int i = 0; i < n; ++i) {
                if(a[i][j] == guess[i]) ++local;
            } //local score;
            score = min(score, local);
        }
        if(score > solution.second) solution = {guess, score};
        if(chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count() > 980) break;
    }
    for(auto& key: solution.first) printf("%d ", key);
    printf("\n");
}

int main() {
    int t; scanf("%d", &t);
    while(t--) purgatorio();
    return 0;
} //raise hellish blaze!
