# 64065 - Lv.2 튜플

from collections import Counter

def solution(s):
    new_s = s.replace('{', '').replace('}', '')  # '{', '}' 제거
    s_list = list(map(int, new_s.split(',')))  # ','로 구분한 요소들을 int로 변환
    
    # Counter() : 리스트의 원소 개수를 딕셔너리 형태로 반환하는 함수
    # Counter(s_list) = {2 : 4, 1 : 3, 3: 2, 4: 1}
    return sorted(Counter(s_list), key=lambda x:Counter(s_list)[x], reverse=True)
