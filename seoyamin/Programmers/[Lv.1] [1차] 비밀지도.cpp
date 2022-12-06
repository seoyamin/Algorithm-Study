#include <string>
#include <vector>

using namespace std;

string toBinary(int d, int n) {
    string result = "";
    
    // [case 1] d = 0 인 경우
    if(d < 1) {
        while(result.size() < n) {
            result = '0' + result;
        }
        return result;
    }
    
    // [case 2] d > 0 인 경우
    while(d > 1) {
        string temp = to_string(d % 2);
        result = temp + result;
        d /= 2;
    }
    result = '1' + result;
    
    while(result.size() < n) {
        result = '0' + result;
    }
    
    return result;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i=0 ; i<n ; i++) {        
        string b1 = toBinary(arr1[i], n);   // 이진수 string으로 변환한 값
        string b2 = toBinary(arr2[i], n);
        
        string temp = "";                   // 비밀지도 한 줄 해석 결과
        for(int j=0 ; j<n ; j++) {
            if(b1[j] == '0' && b2[j] == '0') temp += " ";
            else temp += "#";
        }
        
        answer.push_back(temp);
    }
    
    return answer;
}