#include <bits/stdc++.h>
using namespace std;

vector<int> vec(3);
int a, b, c, mx, mn;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> vec[0] >> vec[1] >> vec[2];
  sort(vec.begin(), vec.end());
  if(vec[0]+1==vec[1] && vec[1]+1==vec[2]) mn = 0;
  else if(vec[1]-vec[0]==2 || vec[2]-vec[1]==2) mn = 1;
  else mn = 2;
  cout << mn << '\n' << max(vec[2]-vec[1], vec[1]-vec[0])-1 << '\n';
  return 0;
}