#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll sum(vector<int> &a) {
  ll ret = 0;
  for(int i=0;i<a.size();++i)
    ret += a[i];
  return ret;
}