public class printNum {

	public static void main(String[] args) {
		int n = Integer.parseInt(args[0]);
		System.out.println("Given Number: " + n);		
		System.out.println("Binary equivalent: " + Integer.toBinaryString(n));
		System.out.println("Octal equivalent: " + Integer.toOctalString(n));
		System.out.println("Hexadecimal equivalent: " + Integer.toHexString(n));
	}
}
