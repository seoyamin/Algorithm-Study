#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    vector<vector<bool>> visited (m, vector<bool>(n, false));
    
    vector<int> answer(2);
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (picture[i][j] == 0 || visited[i][j] == true)
                continue;

            int dm[4] = {0, 0, 1, -1};
            int dn[4] = {1, -1, 0, 0};
            int area = 1;
            number_of_area++;

            queue<pair<int, int>> q;
            q.push({i,j});
            visited[i][j] = true;


            while (!q.empty()) {
                pair<int, int> cur = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int next_m = cur.first + dm[k];
                    int next_n = cur.second + dn[k];

                    if (next_n < 0 || next_m < 0 || next_n >= n || next_m >= m)
                        continue;
                    if (visited[next_m][next_n])
                        continue;
                    if (picture[next_m][next_n] != picture[cur.first][cur.second])
                        continue;

                    q.push({next_m, next_n});
                    visited[next_m][next_n] = true;
                    
                    area++;
                }
            }
            if (area > max_size_of_one_area)
                max_size_of_one_area = area;
        }
    }
    
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
