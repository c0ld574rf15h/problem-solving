#include <iostream>
#include <string>
using namespace std;

const int fail = 9;
int dfa[10][2] = {
  {5, 1}, {2, fail}, {3, fail}, {3, 4}, {5, 7},
  {fail, 6}, {5, 1}, {8, 7}, {3, 6}, {fail, fail}
};

bool app(string s) {
  int slen = s.size(), cur = 0;
  for(int i=0;i<slen;++i)
    cur = dfa[cur][s[i]-'0'];
  return cur==4 || cur==6 || cur==7;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc; cin >> tc;
  while(tc--) {
    string s; cin >> s;
    cout << (app(s) ? "YES" : "NO") << '\n';
  }
  return 0;
}