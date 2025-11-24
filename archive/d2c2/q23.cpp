#include <bits/stdc++.h>

using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
#include "pr.h"
#else
#define pr(...) {}
#define debarr(a, n) {}
#define debmat(mat, row, col) {}
#endif

struct state {
  int a, b;
  vector<string> steps;
};

void solve(int ca, int cb, int n){
  queue<state> q;
  map<pair<int, int>, bool> visited;
  q.push({0, 0, {}});
  
  while(!q.empty()){
    state curr = q.front();
    q.pop();
    int a = curr.a , b = curr.b;
    if(b == n){
      for(auto &s : curr.steps){
        cout << s << "\n";
      }
      cout << "success" << "\n";
      return ;
    }

    if(visited[{a,b}]) continue;
    visited[{a,b}] = true;

    vector<state>  next = {
      {ca, b, curr.steps},
      {a, cb, curr.steps},
      {0, b, curr.steps},
      {a, 0, curr.steps},
      {a - min(cb - b, a), b + min(cb - b, a), curr.steps},
      {a + min(b, ca - a), b - min(b, ca - a), curr.steps}
    };

    vector<string> actions = {
      "fill A", "fill B", "empty A", "empty B",
      "pour A B", "pour B A"
    };

    for(int i = 0 ; i < 6; i++){
      if(!visited[{next[i].a, next[i].b}]){
        next[i].steps.push_back(actions[i]);
        q.push(next[i]);
      }
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int a, b, c;
  while(cin >> a >> b >> c){
   solve(a, b, c);
  }

  return 0;
}
