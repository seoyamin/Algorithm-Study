#include <string>
#include <vector>

using namespace std;

int ks;   // key.size()
int ls;   // lock.size()
int bs;   // board.size()


// key 90도 회전 함수
vector<vector<int>> rotate(vector<vector<int>> key) {
    vector<vector<int>> temp(ks, vector<int>(ks));

    for(int i = 0; i < ks; i++) {
        for(int j = 0; j < ks; j++) {
            temp[i][j] = key[ks - 1 - j][i];
        }
    }

    return temp;
}

// 열리는지 여부 판단하는 함수
bool isOpened(int x, int y, vector<vector<int>> key, vector<vector<int>> board) {
    
    // board에 key 더해보기
    for(int i = x; i < x + ks; i++) {
        for(int j = y; j < y + ks; j++) {
            board[i][j] += key[i-x][j-y];
        }
    }

    // opened 여부 판단
    for(int i = ks - 1; i <= bs - ks; i++) {
        for(int j = ks - 1; j <= bs - ks; j++) {
            if(board[i][j] != 1) 
                return false;
        }
    }

    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    
    ks = (int) key.size();
    ls = (int) lock.size();
    bs = ls + (ks-1) * 2;     // lock 뒤에 깔아두는 background
    
    vector<vector<int>> board(bs, vector<int>(bs));
    
    // board 위에 lock 올리기
    for(int i = ks - 1; i <= bs - ks; i++) {
        for(int j = ks - 1; j<= bs - ks; j++) {
            board[i][j] = lock[i-ks+1][j-ks+1];
        }
    }
    
    // x, y 1칸씩 움직이며 풀리는지 체크
    for(int r = 0; r < 4; r++) {
        for(int i = 0; i <= bs - ks; i++) {
            for(int j = 0; j <= bs - ks; j++) {
                if(isOpened(i, j, key, board)) {
                    return true;
                }
            }
        }

        key = rotate(key);
    }
    
    return answer;
}