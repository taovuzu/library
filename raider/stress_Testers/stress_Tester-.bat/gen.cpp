#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int a, int b) {
    return a + rng() % (b - a + 1);
}

string get_random_string(int n){
    string charset="abcde";
    string rand_str = "";
    for(int i=0;i<n;i++){
        rand_str+=charset[rnd(0,4)];  
    }
    return rand_str;
}


vector<int> get_random_permutation(int n) {
    vector<int> perm(n);
    iota(perm.begin(), perm.end(), 1); // Fill with 1, 2, ..., n
    shuffle(perm.begin(), perm.end(), rng); // Randomize the order
    return perm;
}

// Function to generate a random adjacency matrix for a graph based on a permutation
vector<string> get_random_adjacency_matrix(int n) {
    // Generate a random permutation of size n
    vector<int> perm = get_random_permutation(n);

    // Create an adjacency matrix based on the permutation
    vector<string> matrix(n, string(n, '0')); // Initialize with '0'

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // If perm[i] < perm[j], add an edge
            if (perm[i] < perm[j]) {
                matrix[perm[i]-1][perm[j]-1] = '1';
                matrix[perm[j]-1][perm[i]-1] = '1';
            } 
        }
    }

    return matrix;
}


int main() {
    // cout<<1<<"\n";
    int n= rnd(3,15);
    cout<<n<<" "<<rnd(0,5)<<"\n";
    for (int i = 0; i < n; i++) {
        int l=rnd(1,4);
        int r=rnd(l+1,10);
        int c=rnd(1,15);
        cout<<l<<" "<<r<<" "<<c<<"\n";
    }

    return 0;
}












// #ifndef ONLINE_JUDGE
// #define debarr(a,n)cerr<<#a<<":";for(lli i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<endl;
// #define debmat(mat,row,col)cerr<<#mat<<":\n";for(lli i=0;i<row;i++){for(lli j=0;j<col;j++)cerr<<mat[i][j]<<" ";cerr<<endl;}
// #define pr(...)dbs(#__VA_ARGS__,__VA_ARGS__)
// template<class S,class T>ostream &operator<<(ostream &os,const pair<S,T> &p){return os<<"("<<p.first<<","<<p.second<<")";}
// template<class T>ostream &operator<<(ostream &os,const vector<T> &p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
// template<class T>ostream &operator<<(ostream &os,const set<T>&p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
// template<class T>ostream &operator<<(ostream &os,const multiset<T>&p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
// template<class S,class T>ostream &operator<<(ostream &os,const map<S,T>&p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
// template<class T>void dbs(string str,T t){cerr<<str<<":"<<t<<"\n";}
// template<class T,class...S>void dbs(string str,T t,S... s){lli idx=str.find(',');cerr<<str.substr(0,idx)<<":"<<t<<",";dbs(str.substr(idx+1),s...);}
// #else
// #define pr(...){}
// #define debarr(a,n){}
// #define debmat(mat,row,col){}
// #endif


 
// //----------------//
// #ifndef ONLINE_JUDGE
// #define debarr(a,n)cerr<<#a<<":";for(lli i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<endl;
// #define debmat(mat,row,col)cerr<<#mat<<":\n";for(lli i=0;i<row;i++){for(lli j=0;j<col;j++)cerr<<mat[i][j]<<" ";cerr<<endl;}
// #define pr(...)dbs(#__VA_ARGS__,__VA_ARGS__)
// template<class S,class T>ostream &operator<<(ostream &os,const pair<S,T> &p){return os<<"("<<p.first<<","<<p.second<<")";}
// template<class T>ostream &operator<<(ostream &os,const vector<T> &p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
// template<class T>ostream &operator<<(ostream &os,const set<T>&p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
// template<class T>ostream &operator<<(ostream &os,const multiset<T>&p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
// template<class T> ostream &operator<<(ostream &os,const unordered_set<T>&p){os << "[";for(const auto& elem : p) {os << elem << " ";}return os << "]";}
// template<class T> ostream &operator<<(ostream &os,const unordered_multiset<T>&p){os << "[";for(const auto& elem : p) {os << elem << " ";}return os << "]";}
// template<class S,class T>ostream &operator<<(ostream &os,const map<S,T>&p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
// template<class S,class T> ostream &operator<<(ostream &os,const multimap<S,T>&p){os << "[";for(const auto& kv : p) {os << "(" << kv.first << "," << kv.second << ") ";}return os << "]";}
// template<class S, class T> ostream &operator<<(ostream &os, const unordered_map<S, T>& p) { os << "["; for (const auto &kv : p) { os << "(" << kv.first << "," << kv.second << ") "; } return os << "]"; }
// template<class S, class T> ostream &operator<<(ostream &os, const unordered_multimap<S, T>& p) { os << "["; for (const auto &kv : p) { os << "(" << kv.first << "," << kv.second << ") "; } return os << "]"; }
// template<class T> ostream &operator<<(ostream &os, queue<T> p) {os << "[";while (!p.empty()) {os << p.front() << " ";p.pop();}return os << "]";}
// template<class T> ostream &operator<<(ostream &os, priority_queue<T> p) {os << "[";while (!p.empty()) {os << p.top() << " ";p.pop();}return os << "]";}
// template<class T> ostream &operator<<(ostream &os, const deque<T> &p) {os << "[";for (const auto &it : p) os << it << " ";return os << "]";}
// template<class T> ostream &operator<<(ostream &os, const list<T> &p) {os << "[";for (const auto &it : p) os << it << " ";return os << "]";}
// template<class T> ostream &operator<<(ostream &os, stack<T> p) {stack<T> temp = p;os << "[";while (!temp.empty()) {os << temp.top() << " ";temp.pop();}return os << "]";}
// template<class T>void dbs(string str,T t){cerr<<str<<":"<<t<<"\n";}
// template<class T,class...S>void dbs(string str,T t,S... s){lli idx=str.find(',');cerr<<str.substr(0,idx)<<":"<<t<<",";dbs(str.substr(idx+1),s...);}
// #else
// #define pr(...){}
// #define debarr(a,n){}
// #define debmat(mat,row,col){}
// #endif
// //----------------//





// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// // This function generates a random number between `a` and `b` (inclusive)
// int rnd(int a, int b) {
//     // `rng()` generates a random number and `% (b - a + 1)` limits it to the range
//     // Adding `a` shifts the random number to the range [a, b].
//     return a + rng() % (b - a + 1);
// }

// string get_random_string(int n){
//     string charset="ab";
//     string rand_str = "";
//     for(int i=0;i<n;i++){
//         rand_str+=charset[rnd(0,1)];
//     }
//     return rand_str;
// }