#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    /*sort할 경우, 같은 접두어일 경우엔 긴 게 나중에 들어감. 다른 접두어일 경우에는 숫자가 작은 것부터 들어감.
    vector<string> v = {"21", "123", "2156"};
    sort(v.begin(), v.end());
    cout << v[0] << endl;
    cout << v[1] << endl;
    */
    for (int i = 0; i < phone_book.size() - 1; i++) {
        if (phone_book[i + 1].substr(0, phone_book[i].size()) == phone_book[i]) {
            return false;
        }
    }
    
    return true;
}
