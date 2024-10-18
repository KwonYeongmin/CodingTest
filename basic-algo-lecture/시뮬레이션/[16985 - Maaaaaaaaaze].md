
- 임의로 바뀌는 미로 갱신
- 모든 경우의 수에서 계산하여 최솟 값 갱신
```cpp
#include <iostream>
#include <algorithm> 
#include <queue> 

using namespace std;

int maze_original[5][5][5];
const int N = 5;

// 임의로 바뀌는 배열
int maze[5][5][5];


struct Node 
{
    int x, y, z;
    Node(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {  }
};

int dx[6] = { 1,0,0,0,0,-1 };
int dy[6] = { 0,1,-1,0,0,0 };
int dz[6] = { 0,0,0,1,-1,0 };

void Rotate(int h) 
{
    int temp[5][5];

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            temp[j][N - 1 - i] = maze[h][i][j];
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            maze[h][i][j] = temp[i][j];
        }
    }
    
}

int simulation()
{
    int dist[5][5][5] = {0, };

    // 탈출 불가능 하다면
    if (maze[0][0][0] == 0 || maze[4][4][4] == 0)
    {
        return 9999;
    }

    queue<Node> q;
    q.push(Node(0, 0, 0));
    dist[0][0][0] = 1;

    while (!q.empty()) 
    {
        int x = q.front().x;
        int y = q.front().y;
        int z = q.front().z;
        q.pop();
        
        for (int dir = 0; dir < 6; ++dir) 
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nz = z + dz[dir];
            
            // 범위 판정
            if (nx < 0 || ny < 0 || nz < 0 || nx >= N || ny >= N || nz >= N) 
            {
                continue;
            }

            // 이미 방문한 곳이거나 들어갈 수 없는 곳이면
            if(dist[nx][ny][nz] !=0 || maze[nx][ny][nz] == 0)
            {
                continue;
            }

            // 탈출 조건이라면
            if (nx == N-1 && ny == N-1 && nz == N-1) 
            {
                return dist[x][y][z];
            }

            dist[nx][ny][nz] = dist[x][y][z] + 1;
            q.push(Node(nx,ny,nz));
        }
    }
    return 9999;
}

int main()
{
    for (int h = 0; h < N; ++h) 
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                cin >> maze_original[h][i][j];
            }
        }
    }
    
    int order[5] = {0,1,2,3,4};
    int res = 9999;
    do {

        for (int temp = 0; temp < 1024; ++temp)
        {
            int brute = temp;

            for (int h = 0; h < N; ++h)
            {
                // 미로 입력하기
                for (int i = 0; i < N; ++i)
                {
                    for (int j = 0; j < N; ++j)
                    {
                        maze[h][i][j] = maze_original[order[h]][i][j];
                    }
                }

                int dir = brute % 4;
                brute /= 4;

                if (dir == 1)
                {
                    Rotate(h);
                }
                else if (dir == 2)
                {
                    Rotate(h);
                    Rotate(h);
                }
                else if (dir == 3)
                {
                    Rotate(h);
                    Rotate(h);
                    Rotate(h);
                }
            }
            res = min(res, simulation());
        }
    } while (next_permutation(order,order+5));

        cout << res;
    return 0;
}
```
