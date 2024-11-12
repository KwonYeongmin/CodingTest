## 문제
https://www.acmicpc.net/problem/1260
## 풀이
```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, V;
vector<int> graph[10002];
bool visited[10002];

void dfs(int start) 
{
    visited[start] = true;
    cout << start << ' ';

    for (int i = 0; i < graph[start].size(); ++i) 
    {
        int x = graph[start][i];
        if (false == visited[x]) 
        {
            dfs(x);
        }
    }
}

void bfs(int start) 
{
    fill_n(visited, N + 1, false);

    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) 
    {
        int x = q.front();
        q.pop();

        cout << x << ' ';

        for (int i = 0; i < graph[x].size(); ++i) 
        {
            int y = graph[x][i];
            if (false == visited[y]) 
            {
                q.push(y);
                visited[y] = true;
            }
        }
    }
}

int main() 
{
    cin >> N >> M >> V;

    for (int i = 0; i < M; ++i) 
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문
    for (int i = 1; i <= N; ++i)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    // 첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력
    dfs(V);
    cout << '\n';

    bfs(V);

    return 0;
}
```
