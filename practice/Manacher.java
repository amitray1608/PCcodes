
import java.util.*;

public class Manacher {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String s = sc.nextLine();
    int n = s.length();
    int fre[] = new int[26];
    for (int i = 0; i < n; i++) {
      int ind = s.charAt(i) - 'a';
      fre[ind]++;
    }
    int count = 0;
    for (int i = 0; i < 26; i++) {
      if (fre[i] > 0) count++;
    }
    if (count == 1) {
      System.out.println(s);
      return;
    }
    //using Manacher algorithm source : https://cp-algorithms.com/string/manacher.html
    int dp1[] = new int[n];
    int l = 0, r = -1;
    for (int i = 0; i < n; i++) {
      int k = (i > r) ? 1 : Math.min(dp1[l + r - i], r - i + 1);
      while (0 <= i - k && i + k < n && s.charAt(i - k) == s.charAt(i + k)) {
        k++;         
      }
      dp1[i] = k--;
      if (i + k > r) {
        l = i - k;
        r = i + k;
      }
    }
    int dp2[] = new int[n];
    l = 0;
    r = -1;
    for (int i = 0; i < n; i++) {
      int k = (i > r) ? 0 : Math.min(dp2[l + r - i + 1], r - i + 1);
      while (0 <= i - k - 1 && i + k < n && s.charAt(i - k - 1) == s.charAt(i + k)) {
        k++;         
      }
      dp2[i] = k--;
      if (i + k > r) {
        l = i - k - 1;
        r = i + k;
      }
    }
    int maxi = 0, pos = 0;
    for (int i = 0; i < n; i++) {
//      System.out.print(dp1[i] + " ");
      if (dp1[i] > maxi) {
        maxi = dp1[i];
        pos = i;
      }
    }
    for (int i = 0; i < n; i++) {
//      System.out.print(dp2[i] + " ");
      if (dp2[i] > maxi) {
        maxi = dp2[i];
        pos = i;
      }
    }
    for (int i = pos - maxi; i < pos + maxi; i++) {
      System.out.print(s.charAt(i));
    }
    System.out.println();
    sc.close();
  }
}
