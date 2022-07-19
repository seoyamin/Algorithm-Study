# 42888 - Lv.2 오픈채팅방

def solution(record):
    answer = []    # 채팅방 메시지 결과를 담을 리스트
    id_dic = {}    # id - nickname 값을 저장할 딕셔너리
    
    # record에서 명령어가 Enter, Change인 경우에 id_dic 업데이트
    for r in record:
        # Leave는 "Leave [유저아이디]" 의 형태로 길이가 2, 나머지는 3
        if len(r.split()) == 2:
            continue
            
        else:
            command, uid, nickname = r.split()
            id_dic[uid] = nickname
    
    # 채팅방 메시지 출력
    for r in record:
        # 명령어가 Leave인 경우
        if len(r.split()) == 2:
            command, uid = r.split()
            answer.append(id_dic[uid]+"님이 나갔습니다.")
        
        else:
            command, uid, nickname = r.split()
            if command == 'Enter':
                answer.append(id_dic[uid]+"님이 들어왔습니다.")
            
            # Change의 경우, 메시지 출력 X
            else:
                continue
    
    return answer
