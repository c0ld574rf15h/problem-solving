#include <iostream>
using namespace std;
typedef pair<int, int> pii;

pii a[3];

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  for(int i=0;i<3;++i) cin >> a[i].first >> a[i].second;
  for(int i=0;i<100;++i) {
    int src = i%3, dst = (i+1)%3;
    int vac = a[dst].first-a[dst].second;
    int rem = max(0, a[src].second-vac);
    a[dst].second += (a[src].second < vac ? a[src].second : vac);
    a[src].second = rem;
  }
  for(int i=0;i<3;++i) cout << a[i].second << '\n';
  return 0;
}