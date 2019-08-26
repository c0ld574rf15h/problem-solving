#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct st {
  int day, id, delta;
};
int ans = 0;
vector<st> vec;
map<int, int, greater<int>> cnt;
map<int, int> cow_mlk;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, g; cin >> n >> g; vec.resize(n);
  for(int i=0;i<n;++i) cin >> vec[i].day >> vec[i].id >> vec[i].delta;
  sort(vec.begin(), vec.end(), [](const st &a, const st &b) { return a.day < b.day; });
  cnt[0] = n+1;
  for(int i=0;i<n;++i) {
    int cur_mlk = cow_mlk[vec[i].id];
    bool was_top = cur_mlk == cnt.begin()->first;
    int bef_cnt = cnt[cur_mlk];
    cnt[cur_mlk]==1 ? cnt.erase(cur_mlk) : cnt[cur_mlk] -= 1;
    cur_mlk += vec[i].delta; cow_mlk[vec[i].id] += vec[i].delta;
    cnt[cur_mlk] ? cnt[cur_mlk] += 1 : cnt[cur_mlk] = 1;
    int cur_cnt = cnt[cur_mlk];
    bool is_top = cur_mlk == cnt.begin()->first;
    if(was_top) {
      if(!is_top || bef_cnt != 1 || cur_cnt != 1) ans++;
    } else if(is_top) ans++;
  }
  cout << ans << '\n';
  return 0;
}