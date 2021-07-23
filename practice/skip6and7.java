import java.util.*;

public class skip6and7 {
  public static void main(String [] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int a[] = new int[n];
    for (int i = 0; i < n; i++) {
      a[i] = sc.nextInt();
    }
    boolean prev = false;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == 6) {
        prev = true;
        continue;
      }
      if (prev == true && a[i] == 7) {
        prev = false;
        continue;
      }
      System.out.println(a[i]);
      if (prev == true) continue;
      sum += a[i];
    }
    System.out.println(sum);
  }
}
