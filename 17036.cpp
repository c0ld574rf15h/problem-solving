#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n; vector<int> vec;

int find_min(void) {
  if(vec[n-2]-vec[0]+1==n-1 && vec[n-1]-vec[n-2]>2) return 2;
  else if(vec[1]-vec[0]>2 && vec[n-1]-vec[1]+1==n-1) return 2;
  int mx_cows = 0, j = 0;
  for(int i=0;i<n;++i) {
    while(vec[j+1]-vec[i]+1<=n && j<n-1) j++;
    mx_cows = max(mx_cows, j-i+1);
  }
  return n-mx_cows;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for(int i=0;i<n;++i) {
    int x; cin >> x;
    vec.push_back(x);
  }
  sort(vec.begin(), vec.end());
  int mn = find_min(), mx = max(vec[n-2]-vec[0], vec[n-1]-vec[1])-(n-2);
  cout << mn << '\n' << mx << '\n';
  return 0;
}