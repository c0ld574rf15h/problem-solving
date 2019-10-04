#include <iostream>
using namespace std;

int a[101], ans = 0;
bool fire[2222222];

int main(void) {
  int n, c; cin >> n >> c;
  for(int i=0;i<n;++i) cin >> a[i];
  for(int i=0;i<n;++i)
    for(int j=a[i];j<=c;j+=a[i])
      fire[j] = true;
  for(int i=0;i<=c;++i) ans += fire[i] ? 1 : 0;
  cout << ans << '\n';
}