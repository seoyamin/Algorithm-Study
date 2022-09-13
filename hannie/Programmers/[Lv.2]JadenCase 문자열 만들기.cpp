#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;


string JadenCase(string word){
    // 첫문자
    if('Z'<word[0])
        word[0] = toupper(word[0]);
    // 나머지 소문자로 바꿔주기
    for(int i=1; i<word.size(); i++){
        if(word[i]<'a'|| isdigit(word[i]))
            word[i] = tolower(word[i]);
    }
    return word;
}

string solution(string s) {
    string answer = "";
    string word="";

    for(int i=0; i<s.size(); i++){
        if(s[i]==' '){
            word = JadenCase(word);
            answer+=word;
            answer+=s[i];
            word = "";
        }
        else{
            word+=s[i];
        }
        if(i==s.size()-1){
            word = JadenCase(word);
            answer+=word;
        }
    }
    return answer;
}
