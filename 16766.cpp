#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int n, m, c;
vector<int> vec;

bool isValid(int w) {
  int ride = 0, cow = 0;
  while(cow < n) {
    int passenger = 0;
    for(int i=cow;(i<cow+c) && (vec[i]-vec[cow]<=w) && (i<n);++i) passenger++;
    cow += passenger; ride += 1;
  }
  return ride <= m;
}

int prm_search(void) {
  ll left = 0, right = 1e9;
  while(left < right) {
    ll mid = (left+right)>>1;
    if(isValid(mid)) right=mid;
    else left=mid+1;
  }
  return left;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> c; vec.resize(n);
  for(int i=0;i<n;++i) cin >> vec[i];
  sort(vec.begin(), vec.end());
  cout << prm_search() << '\n';
  return 0;
}