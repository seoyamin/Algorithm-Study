#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

int timeCalculate(string s1, string s2){
    // 11:50, 00:04 ==> 14분으로 환산 (00:00 처리=30번 테스트케이스)
    int min2 = stoi(s2.substr(0,2));
    int min1 = stoi(s1.substr(0,2));
    int sec2 = stoi(s2.substr(3,5));
    int sec1 = stoi(s1.substr(3,5));
    if(sec1>sec2){
        min2--;
        sec2+=60;
    }
    if(min1>min2)
        min2+=12;
    return (min2-min1)*60+(sec2-sec1);
}

string Convert(string s){
    // ABC#D -> ABcD 변환
    for(int i=0; i<s.size(); i++){
        if(s[i]=='#'){
            s[i-1]+=32;
            s.erase(s.begin()+i);
        }
    }
    return s;
}

bool isMatch(string info, string m){ 
    // 조건과 일치 여부
    for(int i=0; i<info.size(); i++){
        // 하나씩 뒤로 밀기: ABC, BCA, CAB
        info.push_back(info[0]);
        info.erase(info.begin());
        if(info.find(m)!=string::npos) // info 코드가 m 코드를 포함할 때
            return true;
    }
    return false;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)"; // 초기값(여기서 10점)
    int maxtime = 0;
    vector<string> v;

    // ',' 문자열 분리
    // "03:00,03:30,FOO,CC#B" => {"03:00","03:30","FOO","CC#B"}
    for(string m:musicinfos){
        istringstream ss(m);
        while(getline(ss,m,','))
            v.push_back(m);
    }

    for(int i=3; i<v.size(); i+=4){
        // ABC# => ABc 변환 (# 제거)
        v[i] = Convert(v[i]);
        m = Convert(m);

        int musictime = timeCalculate(v[i-3],v[i-2]); // 재생 시간

        // 재생 시간보다 info 코드가 길 때=>재생 시간까지 잘라주기
        if(v[i].size()>musictime)
            v[i] = v[i].substr(0,musictime);

        // 재생 시간보다 m 코드가 작을 때 & info 코드가 m 코드보다 짧을 때
        if(m.size()<=musictime && v[i].size()<m.size()){
            string s="";
            while(musictime>s.size()){
                s.append(v[i]); // m 코드 길이만큼 늘려줌.
                if(s.size()>=m.size())
                    break;
            }
            v[i] = s;
        } // ex. CC#B => CC#BCC#BCC#B

        // m 코드가 재생 시간 이내에 있고 & 조건과 일치하면 => answer
        if(m.size()<=musictime && isMatch(v[i],m)==1){
            if(maxtime<musictime){ // 개중 가장 긴 재생 시간(같을 경우 입력 순)
                answer = v[i-1];
                maxtime = musictime;
            }
        }
    }

    return answer;
}
