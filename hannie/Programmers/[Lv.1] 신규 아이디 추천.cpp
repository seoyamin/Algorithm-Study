
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string new_id) {

    string answer="";

    if(new_id.empty())
        return "a";

    for(int i=0; i<new_id.size(); i++) {
        char c = new_id[i];
        // 1단계
        if (65 <= c && c <= 90)
            answer.push_back(c + 32);

        // 2단계
        if (c == '-' || c == '_' || c == '.' || isdigit(c) != 0 || ((97 <= c) && (c <= 122))) {
            // 3단계
            if (c == '.' && answer.back() == '.')
                continue;
            else answer.push_back(c);
        }
        // 4단계 - 시작에 마침표
        if(answer.front()=='.')
            answer.erase(0);
    }
    // 5단계
    if(answer.empty())
        answer.push_back('a');

    // 6단계
    if(answer.size()>15){
        do{
            answer.pop_back();
        }while(answer.size()>15);
    }
    // 4단계 - 끝에 마침표
    if(answer.back()=='.')
        answer.pop_back();

    // 7단계
    if(answer.size()<=2){
        char ch = answer.back();
        do{
            answer.push_back(ch);
        }while(answer.size()<3);
    }


    return answer;
}
