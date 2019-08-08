#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int virus = 0;
bool visited[101];
vector<int> v[101];

void dfs(int s) {
    visited[s] = true;
    virus += 1;
    for(int i=0;i<v[s].size();i++)
        if(!visited[v[s][i]])
            dfs(v[s][i]);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(visited, false, sizeof(visited));
    int n, m; cin >> n >> m;
    for(int i=0;i<m;i++) {
        int x, y; cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1);
    cout << virus-1 << '\n';
    return 0;
}