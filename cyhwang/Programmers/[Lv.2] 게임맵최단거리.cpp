#include <vector>
#include <queue>

using namespace std;

int BFS(vector<vector<int>> maps);

class Point {
public:
    int x;
    int y;
    Point (int yy, int xx) {
        x = xx;
        y = yy;
    }
};

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    answer = BFS(maps);
    return answer;
}

int BFS(vector<vector<int>> maps)
{
    int n = maps.size();
    int m = maps[0].size();
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    vector<vector<bool>> visited (n, vector<bool>(m, false));
    vector<vector<int>> dist (n, vector<int> (m));
    
    queue<Point> q;
    q.push(Point(0,0));
    visited[0][0] = true;
    dist[0][0] = 1;
    
    
    while (!q.empty()) {
        Point cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_x = cur.x + dx[i];
            int next_y = cur.y + dy[i];
            
            if (next_x < 0 || next_y < 0 || next_x >= m || next_y >= n)
                continue;
            if (maps[next_y][next_x] == 0)
                continue;
            if (visited[next_y][next_x])
                continue;
            
            q.push(Point(next_y, next_x));
            visited[next_y][next_x] = true;
            dist[next_y][next_x] = dist[cur.y][cur.x] + 1;
        }
    }
    if (!visited[n - 1][m - 1])
        return -1;
    else
        return dist[n - 1][m - 1];
}
