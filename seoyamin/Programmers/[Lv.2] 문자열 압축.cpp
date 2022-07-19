#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = s.size();   // 일단 anwer에 s의 길이 넣고 시작    
    int target_size = 1;
    
    
    // s 길이의 절반 이하 길이까지만 압축 가능
    while(target_size <= s.size()/2) {       
        vector<pair<string, int>> v;         // <새끼 문자열, 새끼 문자열 포함된 개수> 저장하는 벡터 v
        string after;                        // 압축 완료 후 문자열
        
        
        // target_size 길이의 <item, s 안에 item 포함된 개수>
        for(int i=0 ; i<s.size(); i+=target_size) {
            string item = s.substr(i, target_size);     
            pair p = make_pair(item, 1);                
            
            
            // [case 1] item이 v 끝 원소와 동일한 경우
            if(!(v.empty()) && v.back().first == p.first)  v.back().second++;
            
            // [case 2] item이 v 끝 원소와 동일하지 않은 경우
            else  v.push_back(p);
            
        }
        

        // 최종 압축 후 문자열 만들기
        for(int j=0 ; j<v.size() ; j++) {
            
            if(v[j].second == 1) after += v[j].first;
            
            else {
                after += to_string(v[j].second);
                after += v[j].first;
            }
        }

        
        // min size를 answer로
        if(after.size() < answer) answer = after.size();
        target_size++;
    }

    
    return answer;
}