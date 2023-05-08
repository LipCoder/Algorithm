import java.util.HashMap;
import java.util.Vector;

public class EquiLeader {
	public int solution(int[] A) {
		int result = 0;
		int leader = 0, leaderCount = 0;
		// ���� �� ī��Ʈ �� ����� ���� �ؽø� �����̳ʸ� �����Ѵ�.
		HashMap<Integer, Integer> hm = new HashMap<Integer, Integer>();
		// ī��Ʈ ���� ����Ѵ�
		for(int i = 0 ; i < A.length; ++i) {
			if(hm.containsKey(A[i])) {
				int count = hm.get(A[i]);
				hm.replace(A[i], count + 1);
			} else {
				hm.put(A[i], 1);
			}
			
			// ���� ���� ���� �� (Leader)�� ����Ѵ�.
			if(leaderCount < hm.get(A[i])) {
				leaderCount = hm.get(A[i]);
				leader = A[i];
			}
		}
		
		// Leader ���ڸ� �������� Leader ���ڰ� �� �ε������� 
		// �� �� ���� ���Դ��� ����� ���� �����̳ʸ� �����.
		Vector<Integer> record = new Vector<Integer>();
		int currentCount = 0;
		// �� �ε�����ġ���� Leader�� �󵵼��� ����Ѵ�.
		for(int i = 0 ; i < A.length; ++i) {
			if(A[i] == leader) {
				++currentCount;
			}
			record.add(currentCount);
		}
		
		for(int i = 0; i < A.length - 1; ++i) {
			int LeftCount = record.elementAt(i); // �ѷ� �ɰ����� ���� �κ� Leader �󵵼�
			int RightCount = record.lastElement() - LeftCount; // ������ �κ� Leader �󵵼�
			
			int limitEquiLeft = ((i + 1) / 2) + 1;
			int limitEquiRight = ((A.length - (i + 1)) / 2) + 1;
			// EquiLeader ������ ���ʰ� ������ �κ� ��� �����Ѵٸ� ������ ���� ��Ų��.
			if(LeftCount >= limitEquiLeft && RightCount >= limitEquiRight) {
				++result;
			}
 		}
		return result;
	}
}
