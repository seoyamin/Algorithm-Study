#include <string>
#include <vector>
#include <iostream>

using namespace std;

int snail[1001][1001] = { 0 };
int r = 1, c = 1;
string curr_move = "di";

// type 방법으로 이동한 후, 그 자리에 num 저장
void move(int type, int num) {
    switch(type) {
        case 0:
            curr_move = "dw";
            snail[r+1][c] = num;
            r++;
            break;
        
        case 1:
            curr_move = "ri";
            snail[r][c+1] = num;
            c++;
            break;
        
        case 2:
            curr_move = "di";
            snail[r-1][c-1] = num;
            r--; 
            c--;
            break;
    }
}


void putSnail(int n, int num) {
    if(curr_move == "dw") {
        if(r+1 <= n && snail[r+1][c] == 0) move(0, num);
        else if(r+1 > n || snail[r+1][c] > 0) move(1, num);
        return;
    }
    
    else if(curr_move == "ri") {
        if(c+1 <= n && snail[r][c+1] == 0) move(1, num);
        else if(c+1 > n || snail[r][c+1] > 0) move(2, num);
        return;
    }
    
    else {  // curr_move == "di"
        if(r-1 > 0 && c-1 > 0 && snail[r-1][c-1] == 0) move(2, num);
        else move(0, num);
        return;
    }
}


vector<int> solution(int n) {
    int count = 0;
    vector<int> answer;
    
    // 1 + 2 + 3 + ... + n = count 구하기
    for(int i=1 ; i<=n ; i++) {
        count += i;
    }
    
    snail[1][1] = 1;  // 1은 넣고 시작
    
    for(int i=2 ; i<=count ; i++) {
        putSnail(n, i);
    }
    
    // snail -> answer
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=n ; j++) {
            if(snail[i][j] > 0) answer.push_back(snail[i][j]);
        }
    }
    
    
    return answer;
}