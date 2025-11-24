#include <bits/stdc++.h>
using namespace std;

bool check(string s0, string s1){
  if(s0[0] == s1[0]){
    return true;
  }
  if(s0[1] == s1[1]){
    return true;
  }
  
  return false;
}

int main() {
  
  while(true){
    vector<vector<string>> a(52);
    string s;
    
     for(int i = 0; i < 52; i++){
      cin >> s;
      if(s == "#") return 0;
      a[i].push_back(s);
    }

    int i = 1;
    while(i < a.size()){
      if (!a[i].empty() && i - 3 >= 0 && !a[i-3].empty() && check(a[i].back(), a[i - 3].back())){
        a[i - 3].push_back(a[i].back());
        a[i].pop_back();
        if(a[i].empty()){
          a.erase(a.begin() + i);
        }
        i = max(i - 3, 0); 
      }
      else if (!a[i].empty() && i - 1 >= 0 && !a[i-1].empty() && check(a[i].back(), a[i - 1].back())){
        a[i - 1].push_back(a[i].back());
        a[i].pop_back();
        if(a[i].empty()){
          a.erase(a.begin() + i);
        }
        i = max(i - 1, 0);
      }
      else{
        i++;
      }
    }
    
    if(a.size() > 1)  cout << a.size() << " piles remaining: ";
    else cout << a.size() << " pile remaining: ";
    for(int i = 0; i < a.size(); i++){
      cout << a[i].size() << " \n"[i == a.size() - 1];
    }
    
  }
  
  return 0;
}