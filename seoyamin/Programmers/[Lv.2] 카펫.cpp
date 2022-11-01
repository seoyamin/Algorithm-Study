#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    /*  조건 2가지
		(1)   w * l = r + b
		(2)   2*w + 2*l - 4 = r  
	*/

	for (int i = 3; i <= (brown + yellow) / 3; i++) {           //  조건(1) 의해서 범위 설정
		for (int j = 3; j <= (brown + yellow) / 3; j++) {
			if (i * j == brown + yellow && 2*i + 2*j - 4 == brown) {
                answer.push_back(max(i, j));
                answer.push_back(min(i, j));
                return answer;
			}
		}
	}
}