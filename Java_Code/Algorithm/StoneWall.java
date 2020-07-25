import java.util.Stack;
class Solution {
	public int solution(int[] H) {
		int result = 0;
		Stack<Integer> s = new Stack<Integer>();
		s.push(H[0]);
		for(int i = 1; i < H.length; ++i) {
			while(!s.empty()) {
				if(s.peek() > H[i]) {
					++result;
					s.pop();
				} else if(s.peek() < H[i]) {
					s.push(H[i]);
					break;
				} else break;
			}
			if(s.empty()) s.push(H[i]);
		}
		return result + s.size();
	}
}

public class StoneWall {

	public static void main(String[] args) {
		Solution s = new Solution();
		int[] h = {8, 8, 5, 7, 9, 8, 7, 4, 8};
		System.out.println(s.solution(h));
	}

}
