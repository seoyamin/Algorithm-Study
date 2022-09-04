#include <string>
#include <vector>
#include <sstream>
#include <cctype>

using namespace std;

string toJaden(const string& s) {
    vector<string> words;
    vector<int> blanks;
    
    // 공백의 인덱스 저장
    for(int i=0 ; i<s.size() ; i++) 
        if(s[i] == ' ') blanks.push_back(i);
    
    
    
    // 공백 기준으로 단어 자르기 -> words 벡터에 저장
    stringstream ss(s);
    ss.str(s);
    
    string word;
    while(ss >> word) {
        words.push_back(word);
    }
    
    
    // JadenCase로 바꾸기
    for(int i=0 ; i<words.size() ; i++) {
        
        // 시작 문자가 알파벳인 경우
        if(words[i][0] < '0' || words[i][0] > '9') {
            words[i][0] = toupper(words[i][0]);  // 첫 문자 대문자로
        }
        
        // 나머지 문자 다 소문자로
        for(int j=1 ; j<words[i].size() ; j++) {
            words[i][j] = tolower(words[i][j]);
        }
    }
    
    
    // 다시 하나의 문자열로 합치기
    string result = words[0];
    for(int i=1 ; i<words.size() ; i++)   result += words[i];
    for(int i=0 ; i<blanks.size() ; i++)  result.insert(blanks[i], " ");

    
    return result;
}



string solution(string s) {
    string answer = toJaden(s);
    return answer;
}