#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int parent[100];

// 비용 기준 오름차순 정렬
bool cmp(vector<int> &v1, vector<int> &v2) {
    return v1[2] < v2[2];
}

// 최상위 부모 노드 구하기
int getParent(int n) {
    if(parent[n] == n) return n;
    return getParent(parent[n]);
}

using namespace std;

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    int count = 0;
    
    // 부모 노드를 자기 자신으로 초기화
    for(int i=0 ; i<n ; i++) {
        parent[i] = i;
    }
    
    sort(costs.begin(), costs.end(), cmp);
    
    for(int i=0 ; i<costs.size() ; i++) {
        int node1 = getParent(costs[i][0]);
        int node2 = getParent(costs[i][1]);
        
        // 사이클 안생기는 경우
        if(node1 != node2) {
            answer += costs[i][2];
            parent[node2] = node1;
        }
    }    
    
    return answer;
}