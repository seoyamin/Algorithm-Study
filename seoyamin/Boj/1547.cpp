#include <iostream>
#include <map>

using namespace std;

// 두 컵의 위치 바꾸기
void change(map<int, int> &cups, int cup1, int cup2) {
    int temp = cups[cup1];      // cup1의 현재 위치
    cups[cup1] = cups[cup2];
    cups[cup2] = temp;
}

int main() {
    int M;
    cin >> M;

    map<int, int> cups;             // <컵 번호, 컵 위치>
    for(int i=1 ; i<=3 ; i++) {
        cups.insert({i, i});
    }

    int cup1, cup2;
    for(int i=0 ; i<M ; i++) {
        cin >> cup1 >> cup2;
        change(cups, cup1, cup2);
    }

    for(auto iter = cups.begin() ; iter != cups.end() ; iter++) {
        if(iter->second == 1) {     // 공의 위치 = 위치 1
            cout << iter-> first;
            break;
        }
    }

    return 0;
}
