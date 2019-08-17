#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans;
vector<int> vec, l_ind, r_ind;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n; vec.resize(n);
  l_ind.resize(n, 0); r_ind.resize(n, 0);
  for(int i=0;i<n;++i) cin >> vec[i];
  sort(vec.begin(), vec.end());
  for(int i=1;i<n-1;++i) {
    if(vec[i]-vec[i-1]<=vec[i+1]-vec[i]) r_ind[i-1]++;
    else l_ind[i+1]++;
  }
  l_ind[1]++; r_ind[n-2]++;
  for(int i=0;i<n;++i) ans += (!l_ind[i] && !r_ind[i]) ? 1 : 0;
  for(int i=0;i<n-1;++i) ans += (r_ind[i] && !l_ind[i] && !r_ind[i+1] && l_ind[i+1]) ? 1 : 0;
  cout << ans << '\n';
  return 0;
}