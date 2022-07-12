# 42587 - Lv.2 프린터

# queue를 생성하기 위한 deque
from collections import deque

def solution(priorities, location):
    answer = 0
    
    # enumerate -> 인덱스와 요소 같이 저장
    d = deque([(v,i) for i,v in enumerate(priorities)])

    while True:
        item = d.popleft()
        # any -> 하나라도 있으면 True
        if any(item[0] < q[0] for q in d):
            d.append(item)
        else:
            answer += 1
            if item[1] == location:
                return answer
