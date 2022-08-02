# 72411 - Lv.2 메뉴 리뉴얼

from itertools import combinations
from collections import Counter

def solution(orders, course):
    answer = []
    for c in course:
        # 가능한 조합을 모두 담기 위한 temp 리스트
        temp = []
        for order in orders:
            # combinations(리스트, 원소 개수) : 해당 리스트와 원소개수로 만들 수 있는 조합을 만들어주는 함수
            # ex. combinations([1, 2, 3], 2) => (1, 2), (1, 3), (2, 3)
            combination = combinations(sorted(order), c)
            temp += combination
        counter = Counter(temp)
        
        if len(counter) > 0 and max(counter.values()) > 1:
            answer += [''.join(f) for f in counter if counter[f] == max(counter.values())]
    
    return sorted(answer)
