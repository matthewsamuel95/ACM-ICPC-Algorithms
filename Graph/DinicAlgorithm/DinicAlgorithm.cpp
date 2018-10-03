#include <bits/stdc++.h>
 
using namespace std;
 
#define N 40
#define M 35
 
vector < int > graph[M];
bool visited[N];
int matchs[N];
int n, m;
 
bool match_vertex(int u) {
    for (int v : graph[u])
        if (!visited[v]) {
            visited[v] = true;
            if (matchs[v] < 0 || match_vertex(matchs[v])) {
                matchs[v] = u;
                return true;
            }
        }
    return false;
}
 
int max_match() {
    memset(matchs, -1, sizeof(matchs));
    int result = 0;
    for (int u = 0; u < m; u++) {
        memset(visited, 0, sizeof(visited));
        if (match_vertex(u)) result++;
    }
    return result;
}
 
 
int main() {
    int t;
    map < string, int > ind = {{"XXL", 0}, {"XL", 1}, {"L", 2}, {"M", 3}, {"S", 4}, {"XS", 5}};
    scanf("%d", &t);
    for (int tc = 0; tc < t; tc++) {
        for (int i = 0; i < M; i++)
            graph[i].clear();
 
        scanf("%d %d", &n, &m);
        string x, y;
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            for (int j = 0; j < n/6; j++) {
                graph[i].push_back(ind[x] + j*6);
                graph[i].push_back(ind[y] + j*6);
            }
        }
 
        if (max_match() == m) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
