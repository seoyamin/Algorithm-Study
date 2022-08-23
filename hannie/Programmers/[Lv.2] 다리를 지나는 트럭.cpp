
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> q;

    int cnt=0; // 총 하중
    int iter=0; // 인덱스

    while(1){
        // 트럭 전부 지나감
        if(iter==truck_weights.size()){
            answer+=bridge_length;
            break;
        }
        answer++; // 시간 증가
        int truck = truck_weights[iter]; // 현재 트럭

        if(cnt+truck <= weight){
            cnt += truck;
            iter++;
            q.push(truck);
        }else
            q.push(0);

//        cout << q.front() << ' ';
//        cout << q.back() << ' ';
//        cout << endl;

        if(q.size() == bridge_length){
            cnt -= q.front();
            q.pop();
        }
    }

    return answer;
}
