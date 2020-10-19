public class Solution2 {
    public static int[] solution(l, int t) {
        // Your code here
        int ll = -1, r = -1;
        for(int i = 0; i < l.length; i++){
				int sum = 0;
				for(int j = i; j < l.length; j++){
					sum += l[j];
					if(sum == t){
						ll = i; r = j;
						break;
					}
				}
				if(ll != -1 && r != -1)
					break;
		  }
		  int []a = {ll, r};
		//System.out.println(ll);
		//System.out.println(r);
		  return a;
    }
    public static void main(String []args){
		 int []a = {1, 2, 3, 4};
		 int t = 15;
		int [] x = solution(a, t);
	 }
}
//https://foobar.withgoogle.com/?eid=etarJ
