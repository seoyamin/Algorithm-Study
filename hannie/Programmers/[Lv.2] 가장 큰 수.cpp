
// [6, 10, 2]	"6210"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//string solution2(vector<int> numbers) {
//    string answer = "";
//    long long ans = 0;
//    // 순열
//    sort(numbers.begin(), numbers.end());
//    do{
//        string str="";
//        for(auto i=numbers.begin(); i!=numbers.end(); i++){
//            str += to_string((long long)(*i));
//        }if(stoll(str) > ans)
//            ans = stoll(str);
//    } while (next_permutation(numbers.begin(), numbers.end()));
//
//    answer = to_string(ans);
//    return answer;
//}

bool cmp(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;

    for (int num : numbers)
        v.push_back(to_string(num));

    sort(v.begin(), v.end(), cmp); // vector 정렬
    
    if (v.at(0) == "0") // 처음 숫자가 0
        return "0";

    for (auto num : v)
        answer += num;
    return answer;
}
