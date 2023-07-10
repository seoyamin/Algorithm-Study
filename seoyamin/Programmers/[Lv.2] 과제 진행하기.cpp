#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>

using namespace std;

stack<pair<string, int>> st_wait;

bool compare(vector<string> &v1, vector<string> &v2) {
    return v1[1] < v2[1];
}


int startNew(string start, string end, string name, string playtime) {
    int startTime = stoi(start.substr(0, 2)) * 60 + stoi(start.substr(3, 2));
    int endTime = stoi(end.substr(0, 2)) * 60 + stoi(end.substr(3, 2));
    int givenTime = endTime - startTime;
    int remainTime = givenTime - stoi(playtime);
    
    return remainTime;
}


void startOld(int remainTime, vector<string> &answer) {    
    if(st_wait.empty()) return;
    
    pair<string, int> current = st_wait.top();
    st_wait.pop();

    // (1) 주어진 시간 내에 현재 과제 다 못 끝낸 경우
    if(current.second > remainTime) {
        current.second -= remainTime;
        st_wait.push(current);
        return;
    }

    // (2) 주어진 시간 내에 현재 과제 다 끝내고 시간이 남은 경우 => 다른 멈춰둔 과제 이어서 진행
    else if(current.second < remainTime) {
        answer.push_back(current.first);
        startOld(remainTime - current.second, answer);
    }

    // (3) 딱 맞게 주어진 시간 내에 현재 과제 다 끝낸 경우
    else {
        answer.push_back(current.first);
        return;
    }
}


vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    sort(plans.begin(), plans.end(), compare);
    
    for(int i=0 ; i<plans.size()-1 ; i++) {
        int remainTime = startNew(plans[i][1], plans[i+1][1], plans[i][0], plans[i][2]);
        cout << remainTime << endl;
        
        // (1) 주어진 시간 내에 현재 과제 다 못 끝낸 경우
        if(remainTime < 0) {
            st_wait.push(make_pair(plans[i][0], remainTime * (-1)));
            continue;
        }

        // (2) 주어진 시간 내에 현재 과제 다 끝내고 시간이 남은 경우 => 멈춰둔 과제 이어서 진행
        else if(remainTime > 0) {
            answer.push_back(plans[i][0]);
            startOld(remainTime, answer);
            continue;
        }

        // (3) 딱 맞게 주어진 시간 내에 현재 과제 다 끝낸 경우
        else {
            answer.push_back(plans[i][0]);
            continue;
        }
    }
    
    // 가장 마지막 plan은 endTime 계산 필요 없음
    answer.push_back(plans.back()[0]);
    
    // 멈춰둔 과제들 전부 수행
    while(!st_wait.empty()) {
        answer.push_back(st_wait.top().first);
        st_wait.pop();
    }
    
    
    return answer;
}