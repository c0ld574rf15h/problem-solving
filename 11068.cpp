#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool isValid(int b, int n) {
  vector<int> vec;
  while(n > 0) {
    vec.push_back(n%b);
    n /= b;
  }
  int vec_sz = vec.size();
  for(int i=0;i<(vec_sz>>1);++i)
    if(vec[i] != vec[vec_sz-1-i])
      return false;
  return true;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc; cin >> tc;
  while(tc--) {
    bool flag = false;
    int n; cin >> n;
    for(int i=2;i<=64;++i) {
      if(isValid(i, n)) {
        cout << 1 << '\n'; flag  = true;
        break;
      }
    }
    if(!flag) cout << 0 << '\n';
  }
  return 0;
}