class Target{
    int answer = 0;

    public int solution(int[] numbers, int target) {
        dfs(numbers, 0, target, 0);

        return answer;
    }

    public void dfs(int[] numbers, int depth, int target, int sum){
        if(depth == numbers.length){ // 마지막 노드 까지 탐색한 경우
            if(target == sum) answer++;
        } else {
            dfs(numbers, depth + 1, target, sum + numbers[depth]); // 해당 노드의 값을 더한 후 넘어가기
            dfs(numbers, depth + 1, target, sum - numbers[depth]); // 해당 노드의 값을 뺀 후 넘어가기
        }
    }
}
