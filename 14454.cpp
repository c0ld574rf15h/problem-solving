#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

string s; ll idx, cur;

ll go(ll idx) {
  if(cur == s.size()) return idx;
  cur >>= 1;
  if(idx < cur) return go(idx);
  else {
    if(idx==cur) return go(idx-1); 
    else return go(idx-cur-1);
  }
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> s >> idx;
  cur = s.size();
  while(cur < idx) cur <<= 1;
  cout << s[go(idx-1)] << '\n';
  return 0;
}