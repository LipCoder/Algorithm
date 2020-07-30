
class Info{
	int sum_from_front = 0;
	int sum_from_back = 0;
}

class MaxDoubleSliceSum {
	public int solution(int[] A) {
		if (A == null || A.length == 3) {
			return 0;
		}
		
		Info[] infos = new Info[A.length];
		for(int i = 0; i < infos.length; ++i) {
			infos[i] = new Info();
		}
		
		infos[1].sum_from_front = A[1];
		infos[A.length - 2].sum_from_back = A[A.length - 2];
		for (int i = 2; i < infos.length - 2; ++i) {
			infos[i].sum_from_front = Math.max(A[i], 
					infos[i - 1].sum_from_front + A[i]);

			int backIndex = A.length - i - 1;
			infos[backIndex].sum_from_back = Math.max(A[backIndex], 
					infos[backIndex + 1].sum_from_back + A[backIndex]);
		}
		
		int maxSlice = 0;
		for(int i = 0 ; i < A.length - 2; ++i) {
			int partSumFromFront = Math.max(0,  infos[i].sum_from_front);
			int partSumFromBack = Math.max(0, infos[i + 2].sum_from_back);
			int sum = partSumFromFront + partSumFromBack;
			
			maxSlice = Math.max(maxSlice, sum);
		}
		return maxSlice;
	}
}
