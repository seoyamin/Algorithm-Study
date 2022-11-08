#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    vector<int> v;

    for(int i=0; i<dungeons.size(); i++)
        v.push_back(i);

    int answer = 0;

    do{
        int Health = k; // ex.80
        int cnt = 0;
        // ex. [[80,20],[50,40],[30,10]]
        for(int i=0; i<v.size(); i++){
            int minHealth = dungeons[v[i]][0]; // 최소 피로도
            int usedHealth = dungeons[v[i]][1]; // 소모 피로도

            if (minHealth > Health) 
                continue;

            Health -= usedHealth; // Health : 80->60->20 
            cnt++;
        }
        answer = max(answer, cnt);
    } while (next_permutation(v.begin(), v.end()));
    /*
     * 1 2 3 
     * 1 3 2
     * 2 1 3
     * 2 3 1
     * 3 1 2
     * 3 2 1
     * */

    return answer;
}
