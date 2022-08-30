#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<int> course_valid;
    map<string, int> m;
    map<string, int>::iterator iter;
    vector<string> answer;
    
    
    // 유효한 course 거르기 (course보다 긴 order가 1개 이상이어야 주문수 최소 2번 가능)
    for(int i=0 ; i<course.size() ; i++) {
        for(int j=0 ; j<orders.size() ; j++) {
            if(course[i] < orders[j].length()) {
                course_valid.push_back(course[i]);
                break;
            }
        }
    }
    
    
    
    for(int p=0 ; p<orders.size() ; p++) {
        string order = orders[p];
        sort(order.begin(), order.end());
        
        // order로 가능한 조합 구해서 map m에 추가하기
        for(int q=1 ; q<=order.size() ; q++) {
            
            // course_valid 길이의 조합만 따짐
            for(int n=0 ; n<course_valid.size() ; n++) {  
                if(course_valid[n] == q) {
                    vector<bool> v(order.size()-q, false);
                    v.insert(v.end(), q, true);       

                    do {
                        string temp = "";
                        for(int r=0 ; r<order.size() ; r++) {
                            if(v[r] == true) temp += order[r];
                        }
                        if(m.find(temp) == m.end()) m.insert(make_pair(temp, 1));
                        else m[temp]++;
                    }
                    while(next_permutation(v.begin(), v.end()));
                }
            }
            
        }
    }
    
    
    // 각 course_valid 길이별로 m에서 가장 많이 등장한 원소 구해서 answer에 push_back
    for(int a=0 ; a<course_valid.size() ; a++) {
        vector<string> max;         // 각 course_valid 길이별로 m에서 가장 많이 등장한 원소 배열
        int maxNum = 0;             // 각 course_valid 길이별로 m에서 가장 많이 등장한 원소의 등장 횟수
        
        for(iter = m.begin() ; iter != m.end() ; iter++) {
            if(iter->first.size() == course_valid[a] && iter->second > maxNum) {
                max.clear();
                max.push_back(iter->first);
                maxNum = iter->second;
            } 
            
            else if(iter->first.size() == course_valid[a] && iter->second == maxNum) {
                max.push_back(iter->first);
            }
        }
        
        for(int b=0 ; b<max.size(); b++) {
            answer.push_back(max[b]);
        }
        
        max.clear();
        maxNum = 0;
    }
    
    
    sort(answer.begin(), answer.end());
    return answer;
}