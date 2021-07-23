import java.util.Scanner;
 
public class LPS {
 
  private static int p1 = 29, p2 = 37, lt = 0;
  private static long pw1[];
  private static long pw2[];
 
  public static String reverseString(String str){  
    StringBuilder sb = new StringBuilder(str);  
    sb.reverse();  
    return sb.toString();  
  }  
 
  public static void precompute(int n) {
    pw1[0] = 1;
    pw2[0] = 1;
    for (int i = 1; i < n; i++) {
      pw1[i] = pw1[i - 1] * p1;
      pw2[i] = pw2[i - 1] * p2;
    }
  }
 
  public static int min(int a, int b) {
    return a < b ? a : b;
  }
 
  public static int getVal(char s) {
    return s - 'a';
  }
 
  public static boolean hashCheck(String s, String t, int n, int m, int k) {
    long []hs1 = new long[2];
    long []hs2 = new long[2];
    int len = n - k + 1;
    for (int i = 0; i < k; i++) {
      int val = getVal(s.charAt(i));
      hs1[0] = (hs1[0] * p1) + val;
      hs1[1] = (hs1[1] * p2) + val;
    }
    for (int i = m - 1, c = 0; i >= m - k; i--, c++) {
      int val = getVal(t.charAt(i));
      hs2[0] += (pw1[c] * val);
      hs2[1] += (pw2[c] * val);
    }
    if (hs1[0] == hs2[0] && hs1[1] == hs2[1]) {
      lt = 0;
      return true;
    }
    for (int i = k, j = m - k - 1, c = 1; i < n && j >= 0; i++, j--, c++) {
      int val = getVal(s.charAt(i - k));
      hs1[0] = hs1[0] - (pw1[k - 1] * val);
      hs1[1] = hs1[1] - (pw2[k - 1] * val);
      val = getVal(s.charAt(i));
      hs1[0] = (hs1[0] * p1) + val;
      hs1[1] = (hs1[1] * p2) + val;
      val = getVal(t.charAt(j + k));
      hs2[0] = hs2[0] - (val * pw1[c - 1]);
      hs2[1] = hs2[1] - (val * pw2[c - 1]);
      val = getVal(t.charAt(j));
      hs2[0] += (val * pw1[k - 1] * pw1[c]);
      hs2[1] += (val * pw2[k - 1] * pw2[c]);
      if ((hs1[0] * pw1[c]) == hs2[0] && (hs1[1] * pw2[c]) == hs2[1]) {
        lt = i - k + 1;
        return true;
      }
    }
    return false;
  }
 
  public static void main(String[] args) {
    double start = System.nanoTime();
    Scanner sc = new Scanner(System.in);
 
    String s = sc.next();
    int n = s.length();
    String t = reverseString(s);
    int m = n;
    int l = 0, r = (n / 2) + 1;
    pw1 = new long[n + 1];
    pw2 = new long[n + 1];
    precompute(n + 1);  
    int res = 1, res2 = 1;
 
    while (r - l > 1) {
      int mid = (l + r) / 2;
      if (hashCheck(s, t, n, m, mid * 2)) {
        l = mid; 
        res = mid * 2;
      }
      else r = mid;
    }
    l = 0;
    r = ((n - 1) / 2) + 1;
    while (r - l > 1) {
      int mid = (l + r) / 2;
      if (hashCheck(s, t, n, m, (mid * 2) + 1)) {
        l = mid; 
        res2 = (mid * 2) + 1;
      }
      else r = mid;
    }
    res = (res2 > res ? res2 : res);
    System.out.println(s.substring(lt, lt + res));
    double end = System.nanoTime();
    System.out.println("Execution time: " + ((end - start) / 1000000000) + " seconds");
  }
}
