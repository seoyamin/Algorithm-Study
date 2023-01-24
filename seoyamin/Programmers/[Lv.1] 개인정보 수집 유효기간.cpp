#include <string>
#include <vector>
#include <map>

using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

// string (2022.05.19) -> Date
Date strToDate(string s) {
    Date d = { stoi(s.substr(0, 4)), stoi(s.substr(5, 2)), stoi(s.substr(8)) };
    return d;
}


// DueDate : 유효기간 지난 바로 다음날
// today >= DueDate 이면 유효기간 지난 것
Date getDueDate(Date d, int term) {
    Date dueDate = d;
    int totalMonth = d.month + term;
    
    if(d.month + term > 12) {
        dueDate.year += (totalMonth/12);
        dueDate.month = (totalMonth%12);
    }
    
    else dueDate.month += term;
    
    return dueDate;
}


// (Date) a >= b ? 여부 확인
bool compare(Date a, Date b) {
    if(a.year > b.year) return true;
    if(a.year < b.year) return false;
    
    if(a.month > b.month) return true;
    if(a.month < b.month) return false;
    
    if(a.day >= b.day) return true;
    
    return false;    
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    map<char, int> m_terms;
    vector<int> answer;
    
    // m_terms 채우기
    for(auto t : terms) {
        m_terms.insert( {t[0], stoi(t.substr(2))} );
    }
    
    // today
    Date t = strToDate(today);
    
    for(int i=0 ; i<privacies.size() ; i++) {
        Date p = strToDate(privacies[i].substr(0, 10));
        int term_type = m_terms[privacies[i].back()];      //  A-Z
        
        Date dueDate = getDueDate(p, term_type);
        
        if(compare(t, dueDate)) answer.push_back(i+1);
    }
    
    
    return answer;
}