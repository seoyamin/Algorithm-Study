#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(string s) {
    int answer=s.size();

    for(int i=1;i<=s.size()/2;i++){ // 1/2씩 나눠가기
        string convert,temp;

        int cnt=1;
        temp=s.substr(0,i); // i까지 문자열 자르기

        for(int j=i;j<s.size();j+=i){
            if(temp==s.substr(j,i)) cnt++;
            else{
                if(cnt>1) convert+=to_string(cnt);
                convert+=temp;
                temp=s.substr(j,i);
                cnt=1;
            }
        }

        if(cnt>1) convert+=to_string(cnt);

        convert += temp;
        if(answer > convert.size()) 
            answer = convert.size(); 
    }
    return answer;
}
