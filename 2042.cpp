#include <iostream>
using namespace std;
typedef long long ll;

int N, M, K;
ll a[1111111],pos[1111111], seg[2222222];

ll make_segtree(int left, int right, int idx) {
  if(left == right) {
    pos[left] = idx;
    return seg[idx] = a[left];
  }
  int mid = (left + right) >> 1;
  seg[idx] += make_segtree(left, mid, idx*2);
  seg[idx] += make_segtree(mid+1, right, idx*2+1);
  return seg[idx];
}

ll sum(int start, int end, int left=0, int right=N-1, int idx=1) {
  if(start>right || end<left) return 0;
  if(start<=left && right<=end) return seg[idx];
  int mid = (left + right) >> 1;
  return sum(start, end, left, mid, idx*2) + sum(start, end, mid+1, right, idx*2+1);
}

void update(int pos, int val) {
  seg[pos] = val;
  while(pos > 1) {
    pos >>= 1;
    seg[pos] = seg[pos*2] + seg[pos*2+1];
  }
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M >> K;
  for(int i=0;i<N;++i) cin >> a[i];
  make_segtree(0, N-1, 1);

  for(int i=0;i<M+K;++i) {
    int cmd, x, y; cin >> cmd >> x >> y;
    if(cmd == 1) update(pos[x-1], y);
    else if(cmd == 2) cout << sum(x-1, y-1) << '\n';
  }
  return 0;
}