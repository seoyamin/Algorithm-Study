#include <vector>
#include <queue>

using namespace std;

void myQueue(int num, queue<int> &q) {
    
    if(q.empty()) q.push(num);
    
    else {
        if(q.back() != num) q.push(num);
    }
    
}

vector<int> solution(vector<int> arr) {
    queue<int> q;
    
    for(int i=0 ; i<arr.size() ; i++) {
        myQueue(arr[i], q);
    }
    
    vector<int> answer;
    while(!q.empty()) {
        answer.push_back(q.front());
        q.pop();
    }

    return answer;
}