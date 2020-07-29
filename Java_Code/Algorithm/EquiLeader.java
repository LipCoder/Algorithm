import java.util.HashMap;
import java.util.Vector;

public class EquiLeader {
	public int solution(int[] A) {
		int result = 0;
		int leader = 0, leaderCount = 0;
		// 숫자 빈도 카운트 값 기록을 위해 해시맵 컨테이너를 선언한다.
		HashMap<Integer, Integer> hm = new HashMap<Integer, Integer>();
		// 카운트 값을 기록한다
		for(int i = 0 ; i < A.length; ++i) {
			if(hm.containsKey(A[i])) {
				int count = hm.get(A[i]);
				hm.replace(A[i], count + 1);
			} else {
				hm.put(A[i], 1);
			}
			
			// 가장 많이 나온 수 (Leader)를 기록한다.
			if(leaderCount < hm.get(A[i])) {
				leaderCount = hm.get(A[i]);
				leader = A[i];
			}
		}
		
		// Leader 숫자를 구했으니 Leader 숫자가 각 인덱스에서 
		// 몇 개 정도 나왔는지 기록할 벡터 컨테이너를 만든다.
		Vector<Integer> record = new Vector<Integer>();
		int currentCount = 0;
		// 각 인덱스위치에서 Leader의 빈도수를 기록한다.
		for(int i = 0 ; i < A.length; ++i) {
			if(A[i] == leader) {
				++currentCount;
			}
			record.add(currentCount);
		}
		
		for(int i = 0; i < A.length - 1; ++i) {
			int LeftCount = record.elementAt(i); // 둘로 쪼갰을때 왼쪽 부분 Leader 빈도수
			int RightCount = record.lastElement() - LeftCount; // 오른쪽 부분 Leader 빈도수
			
			int limitEquiLeft = ((i + 1) / 2) + 1;
			int limitEquiRight = ((A.length - (i + 1)) / 2) + 1;
			// EquiLeader 조건을 왼쪽과 오른쪽 부분 모두 만족한다면 갯수를 증가 시킨다.
			if(LeftCount >= limitEquiLeft && RightCount >= limitEquiRight) {
				++result;
			}
 		}
		return result;
	}
}
