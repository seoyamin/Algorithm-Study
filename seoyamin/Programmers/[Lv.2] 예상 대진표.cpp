#include <iostream>

using namespace std;

int solution(int n, int a, int b) {
    int answer = 1;

    if(a > b) swap(a, b);   // a < b 순으로 정렬
    
    while(!(b-a == 1 && b%2 == 0)) {        
        answer++;
        
        if(a%2 == 1) a++;
        if(b%2 == 1) b++;
        
        b /= 2;
        a /= 2;
    }
    

    return answer;
}