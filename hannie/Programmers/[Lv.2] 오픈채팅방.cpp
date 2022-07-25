#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    
    vector<string> answer;
    vector<vector<string>> userIdAndAction;
    map<string, string> userMap;
    
    for (int i = 0; record.size() > i; i++)
    {
        stringstream ss(record[i]); // 유저아이디, 닉네임 저장
        string tmp;
        vector<string> log;
        
        while (ss>>tmp)
            log.push_back(tmp);

        if ("Change" != log[0])
        {
            vector<string> v;
            v.push_back(log[1]);
            if ("Enter" == log[0])
                v.push_back("들어왔습니다.");
            else
                v.push_back("나갔습니다.");

            userIdAndAction.push_back(v);
        }

        if ("Leave" != log[0])
            userMap[log[1]] = log[2];
    }

    for (int i = 0; userIdAndAction.size() > i; i++)
    {
        auto it = userMap.find(userIdAndAction[i][0]);
        string finalLog = it->second + "님이 " + userIdAndAction[i][1];
        answer.push_back(finalLog);
    }

    return answer;
}
