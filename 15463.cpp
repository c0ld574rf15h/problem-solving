#include <iostream>
#include <cstring>
using namespace std;

bool arr[2001][2001];

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  memset(arr, false, sizeof(arr));
  for(int i=0;i<2;++i) {
    int a, b, c, d; cin >> a >> b >> c >> d;
    a += 1000; b += 1000; c +=1000; d += 1000;
    for(int row=b;row<d;++row)
      for(int col=a;col<c;++col)
        arr[row][col]=true;
  }
  int a, b, c, d; cin >> a >> b >> c >> d;
  a += 1000; b += 1000; c +=1000; d += 1000;
  for(int row=b;row<d;++row)
    for(int col=a;col<c;++col)
      arr[row][col]=false;
  int ans = 0;
  for(int i=0;i<=2000;++i)
    for(int j=0;j<=2000;++j)
      ans += arr[i][j] ? 1 : 0;
  cout << ans << '\n';
  return 0;
}