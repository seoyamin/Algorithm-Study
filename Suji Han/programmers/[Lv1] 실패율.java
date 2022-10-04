import java.util.*;


public class Solution {
	public int[] solution(int N, int[] stages) {    
		int[] answer = new int[N];
		int[] step = new int[N]; //stage clear or stay user number array
		int[] stay = new int[N]; //users stay stage
		float[] ratio = new float[N];

		//step 배열에 해당 stag를 클리어했거나 머물고있는 유저들의 수 구하기 
		for(int i=0; i<stages.length; i++) {
			int count = 0;
			for(int j=0; j<stages[i]; j++) {
				step[j]++;
				count++;
			}
			stay[count-1]++;
		}

		//실패율 구하기
		for(int i=0; i<N; i++) {
			ratio[i] = step[i]/stay[i]; 
		}

		int temp = 0;
		answer[0] = 0;
		//sort
		for(int i=0; i<N; i++) {
			for(int j=0; j<N-1; j++) {
			
			}
		}

		return answer;
	}
}
