#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef pair<int, int> pii;

struct st {
  string ramp;
  int low, high;
};

vector<st> vec;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  for(int i=0;i<n;++i) {
    st tmp; cin >> tmp.ramp >> tmp.low >> tmp.high;
    vec.push_back(tmp);
  }
  pii ans = make_pair(0, 1000);
  for(int i=n-1;i>=0;--i) {
    st cur = vec[i];
    if(cur.ramp == "off") {
      ans.first += cur.low;
      ans.second += cur.high;
    } else if(cur.ramp == "on") {
      ans.first -= cur.high;
      ans.second -= cur.low;
    } else {
      ans.first = max(ans.first, cur.low);
      ans.second = min(ans.second, cur.high);
    }
  }
  cout << max(0, ans.first) << ' ' << ans.second << '\n';

  ans = make_pair(0, 1000);
  for(int i=0;i<n;++i) {
    st cur = vec[i];
    if(cur.ramp == "on") {
      ans.first += cur.low;
      ans.second += cur.high;
    } else if(cur.ramp == "off") {
      ans.first -= cur.high;
      ans.second -= cur.low;
    } else {
      ans.first = max(ans.first, cur.low);
      ans.second = min(ans.second, cur.high);
    }
  }
  cout << max(0, ans.first) << ' ' << ans.second << '\n';
  return 0;
}