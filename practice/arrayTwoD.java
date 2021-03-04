import java.util.*;

public class arrayTwoD {

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int a[][] = new int[3][3];
    int n = 3;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        a[i][j] = in.nextInt();
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        System.out.print(a[i][j] + (j == n - 1 ? "\n" : " "));
      }
    }
    in.close();
  }
}

