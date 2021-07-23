import java.util.*;

class MyUnit {
  public boolean palindromeCheck(String s) {
    int n = s.length();
    for (int i = 0; i < n; i++) {
      if (s.charAt(i) != s.charAt(n - i - 1)) 
        return false;
    }
    return true;
  }
}

public class Junit {
  public static void main(String [] args) {
    Scanner sc = new Scanner(System.in);
    String  s = sc.next();
    MyUnit obj = new MyUnit();
    boolean res = obj.palindromeCheck(s);
    System.out.println((res == true ? "Palindrome" : "Not Palindrome"));
  }
}
