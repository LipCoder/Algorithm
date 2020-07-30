import java.lang;

class MaxDoubleSliceSum {
	static final int ALWAYS_SAME = 0;

	public int solution(int[] A) {
		if (A == null || A.length == 3) {
			return 0;
		}
		
		BidirectionSum[] bidirectionSums = new BidirectionSum[A.length];
		for(int i = 0; i < bidirectionSums.length; ++i){
		    bidirectionSums[i] = new BidirectionSum();
		}
		
		int max_forward_ending_here = A[1];
		bidirectionSums[1].max_forward_ending_here = max_forward_ending_here;
		
		int max_reverse_ending_here = A[A.length - 2];
		bidirectionSums[A.length - 2].max_reverse_ending_here = max_reverse_ending_here;
		
		for(int i = 2; i < A.length - 1; ++i) {
			max_forward_ending_here = 
					Math.max(A[i], max_forward_ending_here + A[i]);
			bidirectionSums[i].max_forward_ending_here = max_forward_ending_here;
			
			int reverse_index = A.length - i - 1;
			max_reverse_ending_here = 
					Math.max(A[reverse_index], max_reverse_ending_here + A[reverse_index]);
			bidirectionSums[reverse_index].max_reverse_ending_here = max_reverse_ending_here;
		}
		
		int max = 0;
		for(int i = 0; i < bidirectionSums.length - 2; ++i) {
			int sum = Math.max(0, bidirectionSums[i].max_forward_ending_here) 
					+ Math.max(0, bidirectionSums[i + 2].max_reverse_ending_here);
			max = Math.max(max, sum);
		}
		return max;
	}
}

class BidirectionSum {
	int max_forward_ending_here = 0;
	int max_reverse_ending_here = 0;
}
