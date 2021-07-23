
import java.util.*;

class ignore6and7 {
  public static void main(String [] args){
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    int a[] = new int[n];
    for (int i = 0; i < n; i++) {
      a[i] = in.nextInt();
    }
    int sum = 0, curr = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] != 6)
        sum += a[i];
      else {
        curr = 0;
        while (i < n) {
          curr += a[i];
          if (a[i] == 7) break;
          i++;
        }
        if (i == n) sum += curr;
      }
    }
    System.out.println(sum);
    in.close();
  }
}
