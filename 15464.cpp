#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> vec, num;
vector<int> rvs, tmp;

void shuffle(void) {
  for(int i=1;i<=n;++i)
    tmp[rvs[i]] = vec[i];
  for(int i=1;i<=n;++i)
    vec[i] = tmp[i];
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n; vec.resize(n+1); num.resize(n+1);
  rvs.resize(n+1); tmp.resize(n+1);
  for(int i=1;i<=n;++i) cin >> vec[i];
  for(int i=1;i<=n;++i) cin >> num[i];
  for(int i=1;i<=n;++i) rvs[vec[i]] = i;
  for(int i=1;i<=n;++i) vec[i] = i;
  for(int i=0;i<3;++i) shuffle();
  for(int i=1;i<=n;++i) cout << num[vec[i]] << '\n';
  return 0;
}