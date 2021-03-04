import java.util.*;
public class Lec {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
       HashSet<Integer> hs = new HashSet<Integer>();
        int a[] = new int[n];
        for (int i = 0; i < n; i++) {
        	a[i] = in.nextInt();
          hs.add(a[i]);
        }
//        Arrays.sort(a); 
//        int maxi = 0, second = 0;
//        for (int i = 0; i < n; i++) {
//        	if (a[i] > maxi) {
//        		second = maxi;
//        		maxi = a[i];
//        	} else if (a[i] > second) {
//            second = a[i];
//          }
//        }
        int i = n - 2, res = 0;
        while (i >= 0) {
          if (a[i] != a[i + 1]) {
            res = a[i]; 
            break;
          }
          i--;
        }
        
        System.out.println("The Second largest number is : " + res);
    }
}
