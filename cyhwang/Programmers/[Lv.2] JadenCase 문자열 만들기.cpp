#include <string>
#include <vector>

using namespace std;

string change_size (string s);

string solution(string s) {
    string answer = "";
    
    answer = change_size(s);
    
    return answer;
}

string change_size (string s) {
    /*첫 단어의 첫 문자가 소문자일 경우 대문자로 바꾸기*/
    if (s[0] >= 97 && s[0] <= 122)
        s[0] -= 32;
    
    
    int start = 0;
    for (int end = 1; end < s.size() + 1; end++) {
        if (s[end] == ' ') {
            /*공백이 있을 경우 그 다음 문자가 소문자일 경우 대문자로 바꿈*/
            if (s[end + 1] >=97 && s[end + 1] <= 122)
                s[end + 1] -= 32;
            /*공백 이전에 있던 단어에서 첫 문자를 제외한 문자들이 모두 소문자인지 확인. 대문자일 경우 소문자로 바꿈.*/
            for (int i = start + 1; i < end; i++) {
                if (s[i] >= 65 && s[i] <= 90)
                    s[i] += 32;
            }
            /*다음 단어의 시작 index 업데이트*/
            start = end + 1;
        }
        /*마지막 단어에 대해서, 첫 문자렐 제외한 문자들이 모두 소문자인지 확인.*/
        if (s[end] == '\0') {
            for (int i = start + 1; i < end; i++) {
                if (s[i] >= 65 && s[i] <= 90)
                    s[i] += 32;
            }
        }
    }
    
    return s;
}
