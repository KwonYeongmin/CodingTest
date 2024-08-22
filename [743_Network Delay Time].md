## 정리
- 최소 신장 트리를 사용하는 것 같은데, 최소 신장 트리에 대해서 정리해야 할 것 같다.
-  DFS, BFS, 최소 신장 트리, 이렇게 세 가지로 구현해보면 좋을 것 같다.

## 이슈
- 테스트 케이스 하나에서 실패한다..

## 코드
### DFS
```cpp
class Solution 
{
private:
    vector<bool> visited;
    vector<vector<int>> graph;
    vector<vector<int>> weights;
    int maxDelay;
    int currentDelay;
public:
    void dfs(int currentNode, int currentDelay)
    {
        visited[currentNode] = true;
        maxDelay = max(maxDelay, currentDelay);

        for (size_t i = 0; i < graph[currentNode].size(); ++i)
        {
            int x = graph[currentNode][i];
            int weight = weights[currentNode][i];

            if (false == visited[x])
            {
                dfs(x, currentDelay + weight);
            }
        }
    }

/*
노드의 개수 n, 시작 노드 k
*/
int networkDelayTime(vector<vector<int>>& times, int n, int k)
{
    // 방문 확인 초기화
    visited = vector<bool>(n + 1, false);
    graph = vector<vector<int>>(101, vector<int>(101, 0));
    weights = vector<vector<int>>(101, vector<int>(101, 0));
    
    // 변수 초기화
    maxDelay = 0;
    currentDelay = 0;

    // 그래프 만들기
    for (int i = 0; i < times.size(); ++i)
    {
        int u = times[i][0];
        int v = times[i][1];
        int w = times[i][2];
        graph[u].push_back(v);
        weights[u].push_back(w);
    }

    // 시작 노드 k에서 DFS를 시작
    dfs(k, 0);

    // 모든 노드를 방문할 수 있는지 확인
    for (int i = 1; i <= n; ++i)
    {
        // 방문하지 못하는 노드가 있다면 -1 반환
        if (false == visited[i])
        {
            return -1;
        }
    }

    return maxDelay;
}
};
```
