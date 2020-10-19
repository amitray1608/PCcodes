import java.util.*;
public class Braille {
    public static String solution(String s) {
    	// Your code here
    	String[] alpha = {"100000",
			 "110000",
			  "100100",
			  "100110",
			  "100010",
				"110100",
				"110110",
				"110010",
				"010100",
				"010110",
				"101000",
				"111000",
				"101100",
				"101110",
				"101010",
				"111100",
				"111110",
				"111010",
				"011100",
				"011110",
				"101001",
				"111001",
				"010111",
				"101101",
				"101111",
				"101011",
				};
    	String space = "000000";
    	String up = "000001";
		String ans = "";
		//System.out.println(s.length());
		for(int i = 0; i < s.length(); i++){
			char c = s.charAt(i);
			//System.out.println(c);
			if(c == ' '){
				ans = ans+space;
			}
			int pos = (int)(c - 'a');
			if(c >= 'a' && c <= 'z')
				ans = ans+alpha[pos];
			else if(c >= 'A' && c <= 'Z'){
				pos = (int)(c - 'A');
				ans = ans+up+alpha[pos];
			}
		}
		return ans;
    }
    //public static void main(String []args){
		//Scanner in = new Scanner(System.in);
		//String s = in.nextLine();
		//System.out.println(solution("The quick brown fox jumps over the lazy dog"));
	//}
}
