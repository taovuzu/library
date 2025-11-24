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

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  string name;
  int n;
  cin >> name >> n;
  cin.ignore();

  map< string, int> mp;
  for (int i = 0; i < n; i++) {
    string s, s1 = "", s2 = "", s3 = "", s4 = "";
    getline(cin, s);  
    
    int j = 0;  
    
    while (j < s.size() && s[j] != ' ') {
      s1 += s[j++];
    }
    j++;  // Move past space
    while (j < s.size() && s[j] != ' ') {
      s2 += s[j++];
    }
    j++;
    while (j < s.size() && s[j] != ' ') {
      s3 += s[j++];
    }
    j++;
    while (j < s.size() && s[j] != ' ') {  // Read the rest of the string
      s4 += s[j++];
    }
    s4.pop_back();
    s4.pop_back();
    s3.pop_back();
    s3.pop_back();
    if (s2 == "posted") {
      if (s1 == name) {
        mp[ s4] += 15;
      }
      else if(s4==name){
        mp[s1]+=15;
      }
      else {
        mp[s1]+=0;
        mp[s4]+=0;
      }
    } else if (s2 == "commented") {
      if (s1 == name) {
        mp[ s4] += 10;
      }
      else if(s4==name){
        mp[s1]+=10;
      }
      else {
        mp[s1]+=0;
        mp[s4]+=0;
      }
    } else {
      if (s1 == name) {
        mp[ s3] += 5;
      }
      else if(s3==name){
        mp[s1]+=5;
      }
      else {
        mp[s1]+=0;
        mp[s3]+=0;
      }
    }
  }

  vector<pair<int, string>> a;

  for (auto it : mp) {
    string s = it.first;
    int points = it.second;
    a.push_back({points, s});
  }

  sort(a.begin(), a.end(), [&](pair<int, string> &p1, pair<int, string> &p2) {
    if (p1.first != p2.first) {
      return p1.first > p2.first;
    }
    return p1.second < p2.second;
  });

  for (int i = 0; i < a.size(); i++) {
    cout << a[i].second << "\n";
  }

  return 0;
}
