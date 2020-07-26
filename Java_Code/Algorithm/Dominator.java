import java.util.HashMap;
import java.util.Map;
import java.util.Vector;
class Solution_Dominator {
	public int solution(int[] A) {
		int result = -1;
		HashMap<Integer, Vector<Integer>> hm = new HashMap<Integer, Vector<Integer>>();
		for(int i = 0; i < A.length; ++i) {
			if(hm.containsKey(A[i])) {
				Vector<Integer> v = hm.get(A[i]);
				v.add(i);
				hm.replace(A[i], v);
			} else {
				Vector<Integer> v = new Vector<Integer>();
				v.add(i);
				hm.put(A[i], v);
			}
		}
		
		for(Map.Entry<Integer, Vector<Integer>> elem : hm.entrySet()) {
			if(elem.getValue().size() >= (A.length / 2) + (A.length % 2)) {
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
