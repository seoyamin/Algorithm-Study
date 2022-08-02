
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, int> m;

bool cmp(const pair<string, int> &a, const pair<string, int> &b) {
    return a.second > b.second; // true or false
}


void Combination(string order, int count) {

    vector<int> selected;
    for (int i=0; i<order.size()-count; i++) { selected.push_back(0); }
    for (int i=0; i<count; i++) { selected.push_back(1); }

    do {
        string key = "";
        for (int i=0; i<selected.size(); i++) {
            if (selected[i]) { key += order[i]; }
        }

        // abcde 순서대로 알파벳 정렬
        sort(key.begin(), key.end());
        m[key]++;

    } while (next_permutation(selected.begin(), selected.end()));
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (int i=0; i<orders.size(); i++) {
        for (int j=0; j<course.size(); j++) {
            if (orders[i].size() >= course[j]) {
                Combination(orders[i], course[j]);
            }
        }
    }

    // 주문된 횟수가 많은 순으로 단품메뉴 조합 정렬
    vector<pair<string, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);

    for (int i=0; i<course.size(); i++) {
        int maxCount = 2;
        for (auto iter=v.begin(); iter!=v.end(); iter++) {
            if (iter->first.size() == course[i] && iter->second >= maxCount) {
                maxCount = iter->second;
                answer.push_back(iter->first);
            }
        }
    }

    // cf) 정답은 각 코스요리 메뉴의 구성을 문자열 형식으로 배열에 담아 사전 순으로 오름차순 정렬
    sort(answer.begin(), answer.end());

    return answer;
}
