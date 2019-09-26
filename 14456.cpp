#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

vector<pii> vec;

int go(int a, int b, int c) { // a : Rock, b : Scissors, c : Paper
  int ret = 0;
  for(int i=0;i<vec.size();++i) {
    if(vec[i].first==a && vec[i].second==b) ret++;
    else if(vec[i].first==b && vec[i].second==c) ret++;
    else if(vec[i].first==c && vec[i].second==a) ret++;
  }
  return ret;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, ans = 0; cin >> n; vec.resize(n);
  for(int i=0;i<n;++i) cin >> vec[i].first >> vec[i].second;
  for(int i=1;i<=3;++i) {
    for(int j=1;j<=3;++j) {
      if(j==i) continue;
      for(int k=1;k<=3;++k) {
        if(k==i || k==j) continue;
        ans = max(ans, go(i, j, k));
      }
    }
  }
  cout << ans << '\n';
  return 0;
}