#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    int m1, m2, element;
    
    for(int i=left ; i<=right ; i++) {
        m1 = i / n;  // row 좌표
        m2 = i % n;  // col 좌표
        
        element = (m1 > m2) ? m1+1 : m2+1;
        answer.push_back(element);
    }
    
    return answer;
}