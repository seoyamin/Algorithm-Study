#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
  
    vector<int> answer;
    
    for(vector<int> v:commands){
      // array에서 v[0]번째부터 v[1]번째까지 slice 해주기
        vector<int> tmp = vector<int>(array.begin()+v[0]-1, array.begin()+v[1]);
      // 정렬
        sort(tmp.begin(), tmp.end());
      // v[2] 번째에 있는 값 
        answer.push_back(tmp[v[2]-1]);
    }
    return answer;
}
