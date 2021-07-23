import java.util.*;

public class hexToBinary {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int bit[] = hexToBinary("DFCDA");
		for (int i : bit) {
			System.out.print(i);
		}
	}

	static int [] hexToBinary(String hex) {
		String binary = "";
    HashMap<Character, String> mp = new HashMap<Character, String>();
    mp.put('0', "0000");
    mp.put('1', "0001");
    mp.put('2', "0010");
    mp.put('3', "0011");
    mp.put('4', "0100");
    mp.put('5', "0101");
    mp.put('6', "0110");
    mp.put('7', "0111");
    mp.put('8', "1000");
    mp.put('9', "1001");
    mp.put('A', "1010");
    mp.put('B', "1011");
    mp.put('C', "1100");
    mp.put('D', "1101");
    mp.put('E', "1110");
    mp.put('F', "1111");
   	
   	char ch;
   	for (int i = 0; i < hex.length(); i++) {
   		ch = hex.charAt(i);
   		if (mp.containsKey(ch)) {
   			binary += mp.get(ch);
   		} else {
   			binary = "Invalid";
   			break;
   		}
   	}
   	int n = binary.length();
   	int [] bit = new int[n];
   	for (int i = 0; i < binary.length(); i++) {
   		bit[i] = binary.charAt(i) - '0';
   	}
   	return bit;
	}

}