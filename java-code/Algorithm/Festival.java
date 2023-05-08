import java.util.Scanner;

public class Festival {
	public static Scanner scan = new Scanner(System.in);
	
	public static void main(String[] args) throws Exception {
		int testCase;
		testCase = scan.nextInt();
		double[] Result = new double[testCase];
		
		for(int k = 0; k < testCase; ++k) {
			int days, teams;
			days = scan.nextInt();
			teams = scan.nextInt();
			
			int[] Arr = new int[days];
			for(int i = 0; i < days; ++i) {
				Arr[i] = scan.nextInt();
			}
			
			int count = days;
			double min = Double.MAX_VALUE;
		
			while (count >= teams) {
				
				double tmp = 0.0;
				for (int i = 0; i < days - count; ++i) {
					for (int j = i; j < i + count; ++j) {
						tmp += Arr[j];
					}
					
					double avg = tmp / count;
					if(avg < min) {
						min = avg;
					}
				}
				--count;
			}
			Result[k] = min;
		}
		
		for(int k = 0; k < testCase; ++k) {
			System.out.println(Result[k]);
		}
	}
}
