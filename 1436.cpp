#include <iostream>
#include <string>
using namespace std;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  int cur = 666, cnt = 1;
  while(true) {
    if(to_string(cur).find("666") != string::npos) {
      if(cnt==n) {
        cout << cur << '\n';
        break;
      } cnt++;
    }
    cur++;
  }
  return 0;
}