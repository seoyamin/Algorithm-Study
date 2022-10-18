#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end()); // 오름차순

    unordered_set<string> hash_map;
    hash_map.insert(phone_book[0]); 
    for(int i = 1; i < phone_book.size(); ++i){
        // 1. 접두어가 있는지 확인
        string str = "";
        for(int j = 0; j < phone_book[i].length(); ++j){
            str += phone_book[i][j]; // "abc" 라면 차례대로 "a", "ab", "abc"
            if (hash_map.find(str) != hash_map.end()) 
                return false;
        }
        // 해시맵에 저장
        hash_map.insert(phone_book[i]);
    }

    return true;
}

