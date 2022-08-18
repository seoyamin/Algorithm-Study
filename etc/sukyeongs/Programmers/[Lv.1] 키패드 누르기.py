# 67256 - Lv.1 키패드 누르기

def solution(numbers, hand):
    # 각 번호를 Key로 하고, Value로 좌표값을 담고 있는 딕셔너리 생성
    coordinate = {0: [3,1], 1: [0,0], 2: [0,1],
                  3: [0,2], 4: [1,0], 5: [1,1],
                  6: [1,2], 7: [2,0], 8: [2,1],
                  9: [2,2]}
    
    answer = ''
    
    # 왼손을 사용하는 번호 set
    left_list = {1, 4, 7}
    # 오른손을 사용하는 번호 set
    right_list = {3, 6, 9}
    
    # 현재 왼손의 위치 (*)
    now_l = [3,0]
    # 현재 오른손의 위치 (#)
    now_r = [3,2]
    
    for n in numbers:
        nk = coordinate[n]
        
        if n in left_list:
            answer += 'L'
            now_l = coordinate[n]

        elif n in right_list:
            answer += 'R'
            now_r = coordinate[n]
        
        # n이 2, 5, 8, 0 중 하나인 경우
        else:
            # abs() : 절댓값 계산 함수
            left_d = abs(now_l[0]-nk[0])+abs(now_l[1]-nk[1])
            right_d = abs(now_r[0]-nk[0])+abs(now_r[1]-nk[1])
            
            if left_d > right_d:
                answer += 'R'
                now_r = coordinate[n]

            elif left_d < right_d:
                answer += 'L'
                now_l = coordinate[n]

            else:
                if hand == "left":
                    answer += 'L'
                    now_l = coordinate[n]
                else:
                    answer += 'R'
                    now_r = coordinate[n]
            
    return answer
