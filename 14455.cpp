#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct cow {
  string name;
  int milk;
};

int N, flag = 0;
vector<cow> vec;
map<string, int> m;

void prep_cows(void) {
  m["Bessie"] = 0;
  m["Elsie"] = 0;
  m["Daisy"] = 0;
  m["Gertie"] = 0;
  m["Annabelle"] = 0;
  m["Maggie"] = 0;
  m["Henrietta"] = 0;
}

bool _cmp(const cow &a, const cow &b) {
  return a.milk < b.milk;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  prep_cows();
  cin >> N;
  for(int i=0;i<N;++i) {
    string name; int milk;
    cin >> name >> milk;
    m[name] += milk;
  }
  for(auto it = m.begin();it!=m.end();++it) {
    cow c = { it->first, it->second };
    vec.push_back(c);
  }
  sort(vec.begin(), vec.end(), _cmp);
  for(int i=0;i<vec.size();++i) {
    if(vec[i].milk == vec[0].milk) continue;
    else {
      if(vec[i].milk != vec[i+1].milk) cout << vec[i].name << '\n';
      else cout << "Tie" << '\n';
      flag = 1;
      break;
    }
  }
  if(flag == 0) cout << "Tie" << '\n';
  return 0;
}
