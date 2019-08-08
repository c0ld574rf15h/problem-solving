#include <iostream>
#include <string>
using namespace std;

int disass(int num) {
  int ret = num;
  string s = to_string(num);
  for(int i=0;i<s.size();++i)
    ret += s[i]-'0';
  return ret;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  bool flag = false;
  for(int i=0;i<n;++i) {
    if(disass(i)==n) {
      flag = true;
      cout << i << '\n';
      break;
    }
  }
  if(!flag)
    cout << 0 << '\n';
  return 0;
}