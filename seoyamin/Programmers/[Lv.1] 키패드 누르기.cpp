#include <string>
#include <vector>

using namespace std;


// 키패드 값의 차이를 이용하여 거리값을 리턴하는 메소드
int distance(int diff) {
    switch(diff) {
        case 1: case 3:
            return 1;
            
        case 2: case 4: case 6:
            return 2;
            
        case 5: case 7: case 9:
            return 3;
            
        case 8: case 10:
            return 4;
    }
    return 0;
}


// 2,5,8,0 누를 차례인 경우, L/R 결과 char 리턴하는 메소드
char middle(int num, int left, int right, string hand) {
    
    // 모든 0은 11으로 취급
    if(num == 0) num = 11;
    if(left == 0) left = 11;
    if(right == 0) right = 11;
    
    // 이전 left/right와 지금 누르려는 숫자 num의 키패드 value 차이값 (양수)
    int diffLeft = (num-left) > 0 ? (num-left) : (left-num);
    int diffRight = (num-right) > 0 ? (num-right) : (right-num);
    
    
    // 키패드 value 차이값에 따른 거리를 diffLeft/diffRight에 저장
    diffLeft = distance(diffLeft);
    diffRight = distance(diffRight);
    
    
    // 거리 이용하여 최종 L/R을 리턴
    if(diffLeft < diffRight) {
        return 'L';
    }
    
    else if(diffRight < diffLeft) {
        return 'R';
    }
    
    else { // diffLeft = diffRight
        if(hand=="left") return 'L';
        else return 'R';
    }  
    
}


string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left = 10;    // *은 위치상 10으로 취급
    int right = 12;   // #은 위치상 12로 취급
    
    
    for(int i=0 ; i<numbers.size() ; i++) {
        switch(numbers[i]) {
            case 1: case 4: case 7:
                answer += 'L';
                left = numbers[i];
                break;
                
            case 3: case 6: case 9:
                answer += 'R';
                right = numbers[i];
                break;
            
            default:
                char c = middle(numbers[i], left, right, hand);
                answer += c;
                switch(c) {
                    case 'L':
                        left = numbers[i];
                        break;
                    case 'R' :
                        right = numbers[i];
                        break;
                }
        }
    }
    
    return answer;
}