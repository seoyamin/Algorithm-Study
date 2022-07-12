# 42586 - Lv.2 기능개발

def solution(progresses, speeds):
    answer = []
    # 작업 일수
    day = 0
    # 하루에 배포할 기능 개수
    count = 0
    
    # 현재 남아있는 기능이 없을 때까지 반복
    while len(progresses) > 0:
        # progresses, speeds를 queue로 생각
        if (progresses[0] + day * speeds[0]) >= 100:
            # 우선순위가 가장 높은 작업과 속도 pop
            progresses.pop(0)
            speeds.pop(0)
            count += 1
        else:
            # 현재 우선순위가 높은 작업이 100%가 아닌데, count가 0보다 큰 경우 => 전에 완료된 기능이 있으니 배포
            if count > 0 :
                answer.append(count)
                count = 0
            day += 1
    
    answer.append(count)
    return answer
