
class MaxProfit {
	public int solution(int[] A) {
		int min = (A.length > 0) ? A[0] : 0;
		int result = 0;
		for(int num : A) {
			if(num <= min) {
				min = num;
			}
			if(result < num - min) {
				result = num - min;
			}
		}
		return result;
	}
}
