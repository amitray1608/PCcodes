import java.util.*;
public class sumPrime {
    public static void main(String args[]) {
      //Seive 
      int maxsz = 107;
      boolean P[] = new boolean[maxsz + 1];
      for (int i = 0; i < maxsz; i++) {
        P[i] = true;
      }
      P[0] = P[1] = false;
      for (int i = 2; i * i <= maxsz; i++) {
          if (P[i] == true) {
              for (int j = i * i; j <= maxsz; j += i)
                  P[j] = false;
          }
      }
       
      Scanner in = new Scanner(System.in);
      int n = in.nextInt();
      int sum = 0, count = 0, i = 2;
      while(i < maxsz) {
        if (P[i] == true) {
          sum += i;
          count++;
        }
        if (count == n) break;
        i++;
      }
        System.out.println("The Sum of first n primes is: " + sum);
    }
}
