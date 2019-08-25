#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n;
double mini=INT_MAX, sum = 0, maxi = 0;
vector<double> vec, _min, _sum, _score;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n; vec.resize(n+1); _min.resize(n+1); _sum.resize(n+1);
  for(int i=1;i<=n;++i) cin >> vec[i];
  for(int i=n;i>=1;--i) {
    _min[i] = mini = min(mini, vec[i]);
    _sum[i] = sum += vec[i];
  }
  _score.resize(n+1, 0);
  for(int i=1;i<=n-1;++i) {
    _score[i] = (_sum[i]-_min[i])/(n-i);
    maxi = max(maxi, _score[i]);
  }
  for(int i=2;i<=n-1;++i)
    if(_score[i] == maxi)
      cout << i-1 << '\n';
  return 0;
}