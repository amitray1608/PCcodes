
import java.util.*;

class reverseANumber {
  public static void main(String [] args){
    Scanner in = new Scanner(System.in);
    String s = in.next();
    int n = s.length();
    int i = n - 1;
    while (i >= 0 && s.charAt(i) == '0') i--;
    for (; i >= 0; i--) {
      System.out.print(s.charAt(i));
    }
    System.out.println();
    in.close();
  }
}
