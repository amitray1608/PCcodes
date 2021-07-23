
import java.util.*;

class seachANumber {
  public static void main(String [] args){
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    int a[] = new int[n];
    for (int i = 0; i < n; i++) {
      a[i] = in.nextInt();
    }
    int x = in.nextInt();
    int pos = -1;
    for (int i = 0; i < n; i++) {
      if (a[i] == x) {
        pos = i + 1;
        break;
      }
    }
    System.out.println(pos);
    in.close();
  }
}
