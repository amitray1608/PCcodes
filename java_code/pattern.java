import java.util.*;

public class pattern {

  public static void main(String[] args) {
    int n = 5, curr = 1;
    for(int i = 0; i < n; i++) {
      for(int j = n - i - 1; j >= 0; j--) {
        System.out.print(curr);
      }
      System.out.println();
      curr += 2;
    }
  }
}
