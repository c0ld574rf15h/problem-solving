#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <climits>
using namespace std;

struct st {
  int day, milk;
  string name;
};
int n, state = 0, ans = 0;
map<string, int> m;
vector<st> vec;

bool _cmp(st a, st b) {
  return a.day < b.day;
}

int func(int x) {
  int maxi = INT_MIN, ret = 0;
  m[vec[x].name] += vec[x].milk;
  for(auto it=m.begin();it!=m.end();++it) maxi = max(maxi, it->second);
  if(maxi==m["Bessie"]) ret += 1;
  if(maxi==m["Elsie"]) ret+=2;
  if(maxi==m["Mildred"]) ret += 4;
  return ret;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  m["Bessie"] = m["Elsie"] = m["Mildred"] = 0;
  cin >> n; vec.resize(n);
  for(int i=0;i<n;++i) cin >> vec[i].day >> vec[i].name >> vec[i].milk;
  sort(vec.begin(), vec.end(), _cmp);
  for(int i=0;i<n;++i) {
    int _new = func(i);
    if(state!=_new) {
      ans++; state = _new;
    }
  }
  cout << ans << '\n';
  return 0;
}