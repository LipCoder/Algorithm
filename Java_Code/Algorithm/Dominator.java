import java.util.HashMap;
import java.util.Map;
import java.util.Vector;
class Solution_Dominator {
	public int solution(int[] A) {
		int result = -1;
		// �ؽ� ���̺� ����
		HashMap<Integer, Vector<Integer>> hm = new HashMap<Integer, Vector<Integer>>();
		// ��ȸ���� Key, Value ���� ä���.
		for(int i = 0; i < A.length; ++i) {
			if(hm.containsKey(A[i])) {
				// �̹� Key�� �����ϴ� ��� Value���� Vector�� �޾ƿ�
				// �ش� �ε��� ���� �߰��ϰ� �ؽ��� Value���� �����Ѵ�.
				Vector<Integer> v = hm.get(A[i]);
				v.add(i);
				hm.replace(A[i], v);
			} else {
				// �ؽ� ���̺� �������� �ʴ� Key�� ��� Vector�� ���� �Ҵ�޾�
				// �ش� �ε��� ���� Vector�� �߰��Ͽ� �ؽÿ� �־��ش�.
				Vector<Integer> v = new Vector<Integer>();
				v.add(i);
				hm.put(A[i], v);
			}
		}
		
		// �ؽÿ� �� ���� �� Dominator���ǿ� �����ϴ� Key���� ã�´�.
		for(Map.Entry<Integer, Vector<Integer>> elem : hm.entrySet()) {
			if(elem.getValue().size() >= (A.length / 2) + 1) {
				// �����ϴ� ��� Dominator�� ������ �ϴ� �ε��� ��ġ�� ù��° ��ġ�� �������� �Ѵ�.
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
