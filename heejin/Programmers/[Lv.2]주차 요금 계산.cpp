
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>

using namespace std;

int time_diff(string in, string out) { //각 입 출차 시간을 통해서 이용시간 계산하는 함수
    /* ex - (IN) 11:30 (OUT) 14:50 */
    int h1 = stoi(in.substr(0, 2)); //11
    int m1 = stoi(in.substr(3, 2)); //30
    int h2 = stoi(out.substr(0, 2)); //14
    int m2 = stoi(out.substr(3, 2)); //50

    int diff = (h2-h1)*60 + (m2-m1); //전체 시간

    return diff;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer; //답 벡터
    map<string, vector<string>> m; //차번호로 입차/출차 시간 벡터 찾음

    stringstream ss; //공백으로 문자를 파싱해주는 라이브러리
    for(auto record: records) { //배열속 객체 하나하나 탐색
        ss.str(record); //문장 하나를 파싱해줄 문자열에 추가
        string time, number, status; ss >> time >> number >> status; //파싱해줌

        m[number].push_back(time); //차번호로 찾을 수 있는 벡터에 시간 넣어줌
        ss.clear(); //다음 문장을 위해 지워줌
    }

    for(auto it: m) { //한 차당 요금 계산
        if(it.second.size() & 1) //만약 시간 벡터의 사이즈가 1이면
            it.second.push_back("23:59"); //출차시간이 입력되지 않은 것이므로 따로 넣어줌

        vector<string> info = it.second; //입차/출차 시간 벡터 정보 넘겨줌
        int total = 0;
        for(int i=0; i<info.size()-1; i+=2) { //각 입 출차 시간을 통해서 이용시간 계산하는 함수 호출
            total += time_diff(info[i], info[i+1]); //이용 시간 받음
        }

        int price = fees[1]; //기본 요금은 무조건 들어감
        if(total > fees[0]) { //만약 이용시간이 기본 시간을 넘겼을 경우에
            price += ceil((total-fees[0]) / (double)fees[2]) * fees[3]; //넘긴 만큼 단위 시간당 단위 요금 더해줌
        }

        answer.push_back(price);
    }

    return answer;
}