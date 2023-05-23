#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 현재 곡괭이와 캐야할 광물 -> 피로도 계산 함수
int getTiredSum(int p, int d, int i, int s) {
    int sum = 0;
    
    switch(p) {
        case 0:
            sum = d + i + s;
            break;
            
        case 1:
            sum = 5 * d + i + s;
            break;
            
        case 2:
            sum = 25 * d + 5 * i + s;
            break;
    }
    
    return sum;
}


int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    
    // 5개씩 묶은 묶음의 개수
    int count = (minerals.size() % 5 == 0) ? minerals.size() / 5 : minerals.size() / 5 + 1;     
    
    // 5개씩 묶음이 요구하는 피로도 합 (다이아 : 철 : 돌 = 1000 : 100 : 1)
    vector<int> tired;  
    
    int sum = 0;
    for(int i=0 ; i<minerals.size() ; i++) {
        if(minerals[i] == "diamond") sum += 1000;
        else if(minerals[i] == "iron") sum += 100;
        else sum += 1;
        
        // 이번 묶음의 마지막 원소이면 sum을 tired에 저장
        if(i % 5 == 4 || i == minerals.size()-1) {  
            tired.push_back(sum);
            sum = 0;
        } 
    }
    
    int requiredPicks = tired.size();       // 광물을 모두 캐기 위해 필요한 곡괭이 수
    int currentPicks = 0;                   // 현재 보유한 곡괭이 수
    for(auto p : picks) currentPicks += p;
    
    
    // 곡괭이 부족한 경우 : tired에서 현재 곡괭이 개수만큼만 남기고 버림
    if(requiredPicks > currentPicks) {
        tired.erase(tired.begin() + currentPicks, tired.begin() + tired.size());
    }
    
    // 피로도 높은 순으로 곡괭이 배정
    sort(tired.begin(), tired.end(), greater<>());
    
    for(int i=0 ; i<tired.size() ; i++) {
        int dia = tired[i] / 1000;              // 다이아몬드 개수
        int iron = (tired[i] % 1000) / 100;     // 철 개수
        int stone = tired[i] % 100;             // 돌 개수
        
        
        if(picks[0] > 0) {
            answer += getTiredSum(0, dia, iron, stone);
            picks[0]--;
            continue;
        }
        
        else if(picks[1] > 0) {
            answer += getTiredSum(1, dia, iron, stone);
            picks[1]--;
            continue;
        }
        
        else {
            answer += getTiredSum(2, dia, iron, stone);
            picks[2]--;
            continue;
        }
    }
    
    
    return answer;
}