#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  regex re("(100+1+|01)+");
  string s; cin >> s;
  cout << (regex_match(s, re) ? "SUBMARINE" : "NOISE") << '\n';
  return 0;
}