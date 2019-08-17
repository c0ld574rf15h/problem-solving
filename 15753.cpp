#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> vec;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  bool flag = false;
  cin >> n; vec.resize(n);
  for(int i=0;i<n;++i) cin >> vec[i];
  vec[0] = 0;
  for(int i=0;i<n;++i) {
    if(vec[i]!=-1) {
      int cur = vec[i];
      for(int j=i-1;cur>0;--j,--cur) {
        if(vec[j]!=-1 && vec[j]!=cur-1) flag=true;
        vec[j]=cur-1;
      }
    }
  }
  if(flag) cout << -1 << '\n';
  else {
    int ans = 0, max_ans;
    for(int i=0;i<vec.size();++i)
      if(vec[i]==0) ans++;
    max_ans = ans;
    for(int i=0;i<vec.size();++i)
      if(vec[i]==-1) max_ans++;
    cout << ans << ' ' << max_ans << '\n';
  }
  return 0;
}