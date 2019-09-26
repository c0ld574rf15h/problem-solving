#include <iostream>
#include <set>
using namespace std;

int N, T, cow[10001];

bool isValid(int k) {
  if(k>=N) return true;
  multiset<int> ms; int idx = 0;
  for(;idx<k;++idx) ms.insert(cow[idx]);
  for(int t=1;t<=T;++t) {
    ms.erase(t);
    if(idx<N)
      for(int i=0;i<k-ms.size();++i)
        ms.insert(cow[idx++]+t);
  }
  return ms.empty();
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> T;
  for(int i=0;i<N;++i) cin >> cow[i];
  int left = 1, right = 10000;
  while(left < right) {
    int mid = (left + right) >> 1;
    if(isValid(mid)) right = mid;
    else left = mid + 1;
  }
  cout << left << '\n';
  return 0;
}