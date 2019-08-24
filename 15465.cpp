#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<int, int> pii;

struct info {
  int day, milk;
  string name;
};

vector<info> vec;
int n, cnt = 0;
string best="";
map<string, int> m;

bool cmp(info a, info b) {
  return a.day < b.day;
}

bool change(int num) {
  for(auto it=m.begin();it!=m.end();++it)
    if(num < it->second) return false;
  return true;
}

bool other(int num) {
  for(auto it=m.begin();it!=m.end();++it)
    if(num == it->second && it->first != best)
      return true;
  return false;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for(int i=0;i<n;++i) {
    int day, milk; string name;
    cin >> day >> name >> milk;
    vec.push_back({day, milk, name});
    m[name]=0;
  }
  sort(vec.begin(), vec.end(), cmp);
  for(int i=0;i<vec.size();++i) {
    m[vec[i].name] += vec[i].milk;
    if((change(m[vec[i].name]) && best!=vec[i].name) || (change(m[vec[i].name]) && best==vec[i].name && other(m[vec[i].name]))) {
      best = vec[i].name;
      cnt++;
    }
  }
  cout << cnt << '\n';
  return 0;
}