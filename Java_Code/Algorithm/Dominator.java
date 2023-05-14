import java.util.HashMap;
import java.util.Map;
import java.util.Vector;
class Solution_Dominator {
	public int solution(int[] A) {
		int result = -1;
		// 해시 테이블 생성
		HashMap<Integer, Vector<Integer>> hm = new HashMap<Integer, Vector<Integer>>();
		// 순회돌며 Key, Value 값을 채운다.
		for(int i = 0; i < A.length; ++i) {
			if(hm.containsKey(A[i])) {
				// 이미 Key가 존재하는 경우 Value값인 Vector를 받아와
				// 해당 인덱스 값을 추가하고 해시의 Value값을 갱신한다.
				Vector<Integer> v = hm.get(A[i]);
				v.add(i);
				hm.replace(A[i], v);
			} else {
				// 해시 테이블에 존재하지 않는 Key의 경우 Vector를 새로 할당받아
				// 해당 인덱스 값을 Vector에 추가하여 해시에 넣어준다.
				Vector<Integer> v = new Vector<Integer>();
				v.add(i);
				hm.put(A[i], v);
			}
		}
		
		// 해시에 들어간 값들 중 Dominator조건에 만족하는 Key값을 찾는다.
		for(Map.Entry<Integer, Vector<Integer>> elem : hm.entrySet()) {
			if(elem.getValue().size() >= (A.length / 2) + 1) {
				// 존재하는 경우 Dominator를 값으로 하는 인덱스 위치중 첫번째 위치를 정답으로 한다.
				result = elem.getValue().get(0);
			}
		}
		return result;
	}
}

public class Dominator {

	public static void main(String[] args) {
		Solution_Dominator test = new Solution_Dominator();
		int[] arr = {3, 4, 3, 2, 3, -1, 3, 3};
		System.out.println(test.solution(arr));
	}

}
