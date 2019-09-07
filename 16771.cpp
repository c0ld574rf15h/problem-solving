#include <iostream>
#include <set>
#include <vector>
using namespace std;

set<int> s;
multiset<int> barn[2];

void dfs(int day, int cur) {
  if(day>5) {
    s.insert(cur);
    return;
  }
  int src = day&1 ? 1 : 0;
  vector<int> vec;
  for(auto it=barn[src].begin();it!=barn[src].end();++it)
    vec.push_back(*it);
  for(int i=0;i<vec.size();++i) {
    barn[src].erase(barn[src].find(vec[i]));
    barn[1-src].insert(vec[i]);
    if(src==0)
      dfs(day+1, cur-vec[i]);
    else
      dfs(day+1, cur+vec[i]);
    barn[1-src].erase(barn[1-src].find(vec[i]));
    barn[src].insert(vec[i]);
  }
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  for(int i=0;i<2;++i) {
    for(int j=0;j<10;++j) {
      int x; cin >> x;
      barn[i].insert(x);
    }
  }
  dfs(2, 1000);
  cout << s.size() << '\n';
  return 0;
}