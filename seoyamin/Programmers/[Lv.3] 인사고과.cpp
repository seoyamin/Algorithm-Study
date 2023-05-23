#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct person {
    int a, b, idx;
};

// person을 근무 태도 점수 (a) 큰 순서로 정렬
bool cmp(person p1, person p2) {
    return p1.a > p2.a;
}

// 인센티브 받을 수 있는 사원의 점수 총합을 내림차순 정렬
bool cmp2(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first) return b.second < a.second;
    return a.first > b.first;
}

int solution(vector<vector<int>> scores) {
    int answer = 0;
    vector<person> v;               // person 저장 
    vector<pair<int,int>> ans;      // 인센티브 받을 수 있는 사원의 점수 총합, 인덱스 저장
    
    
    // person 만들어서 v 채우기
    for(int i=0 ; i<scores.size() ; i++) {
        v.push_back({scores[i][0], scores[i][1], i});
    }
        
    // person들을 a가 큰 순서로 내림차순 정렬
    sort(v.begin(), v.end(), cmp);
    
    // ans 채우기
    for(int i=0; i<v.size(); i++) {
        bool flag = true;   // 인센티브 받을 수 있는지 여부
        person p1 = v[i];
        
        // p1보다 a가 큰 사원만 탐색
        for(int j=0; j<i; j++) {
            person p2 = v[j];   
            if(p2.a > p1.a && p2.b > p1.b) {    // p2가 b도 더 큰 경우 -> p1은 인센티브 X
                flag = false;
                break;
            }
        }
        
        if(!flag) continue;
        
        ans.push_back({p1.a + p1.b, p1.idx});   // flag = true로 버틴 경우
    }
    
    sort(ans.begin(), ans.end(), cmp2);     // 총 점수 합 (a+b) 높은 순으로 정렬
    
    
    
    int rank = 1;    // 완호 석차
    
    for(int i=0; i<ans.size(); i++) {
        int a = ans[i].first;   // 비교하는 사원 점수 (높은순)
        int cnt = 0;            // 완호보다 높은 점수 사원 수
        while(i<ans.size() && a==ans[i].first) {    // 높은 점수 ~> 완호 점수
            if(ans[i].second == 0) {
                answer = rank++;
                break;
            }
            i++;
            cnt++;
        }
        rank += cnt;    // 완호 등수
        i--;
        
        if(answer != 0) break;  
    }
    
    return answer == 0 ? -1 : answer;
}