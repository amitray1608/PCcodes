import java.util.*;

class maxOfAMatrix {
  public static void main(String [] args){
    int a[][] = new int[3][3];
    int k = 0;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        a[i][j] = Integer.parseInt(args[k++]);
      }
    }
    int maxi = 0;
    System.out.println("The given matrix is :");
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        maxi = Math.max(maxi, a[i][j]);
        System.out.print(a[i][j] + " ");
      }
      System.out.println();
    }
    System.out.println("The biggest number in the given array is : " + maxi); 
  }
}
