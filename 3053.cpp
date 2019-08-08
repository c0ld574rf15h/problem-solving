#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  double r; cin >> r;
  cout << fixed;
  cout << setprecision(9) << r * r * M_PI << '\n';
  cout << setprecision(9) << r * r * 2 << '\n';
  return 0;
}