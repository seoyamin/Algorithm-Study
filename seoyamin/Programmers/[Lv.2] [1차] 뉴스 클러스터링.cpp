#include <string>
#include <cctype> // tolower 함수
#include <map>
#include <cmath> // floor 함수
#include <iostream>

using namespace std;

string getValid(string s) {
    string result = "";
    
    for(auto i : s) {
        i = tolower(i);
        result += i;
    }
    
    return result;
}

int solution(string str1, string str2) {
    double answer = 0;
    int e1 = 0, e2 = 0;                        // str1, str2 다중집합의 총 원소 개수
    int num_intersection = 0, num_union = 0;   // 교집합, 합집합 원소 개수
    map<string, int> m1, m2;
    
    // 유효한 문자열로 변경
    str1 = getValid(str1);
    str2 = getValid(str2);
    
    
    // m1, m2 만들기
    string temp;
    for(int i=0 ; i<str1.size() - 1 ; i++) {
        temp = str1.substr(i, 2);
        
        
        if((temp[0] >= 'a' && temp[0] <= 'z') && (temp[1] >= 'a' && temp[1] <= 'z')) {
            e1++;
            if(m1.find(temp) == m1.end()) m1.insert({temp, 1});
            else m1[temp]++;
        }
    }
    
    for(int i=0 ; i<str2.size() - 1 ; i++) {
        temp = str2.substr(i, 2);
        
        if((temp[0] >= 'a' && temp[0] <= 'z') && (temp[1] >= 'a' && temp[1] <= 'z')) {
            e2++;
            if(m2.find(temp) == m2.end()) m2.insert({temp, 1});
            else m2[temp]++;
        }
    }
    
    num_union = e1 + e2;
    
    for(auto iter : m1) {
        if(m2.find(iter.first) != m2.end()) {
            int common = m1[iter.first] < m2[iter.first] ? m1[iter.first] : m2[iter.first];
            num_intersection += common;
            num_union -= common;
            
        } 
    }
    
    // inter, union 둘 다 0인 경우
    if(num_intersection == 0 && num_union == 0) return 65536;  
    
    answer = (double) num_intersection / (double) num_union * 65536;
    answer = floor(answer);
    
    return answer;
}