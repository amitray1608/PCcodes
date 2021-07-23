
public class maxOfMatrix {
  public static void main(String []args) {
    int a[][] = new int[3][3];
    int i = 0, j = 0;
    int maxi = 0;
    if (args.length != 9) {
      System.out.println("Please enter 9 integer numbers."); 
      return;
    }
    for (String k : args) {
      a[i][j] = Integer.parseInt(k);
      maxi = Math.max(maxi, a[i][j]);
      j++;
      if (j == 3) {
        j = 0;
        i++;
      }
    }
    
    System.out.println("The given matrix is : ");
    for (i = 0; i < 3; i++) {
      for (j = 0; j < 3; j++) {
        System.out.print(a[i][j] + " ");
      }
      System.out.println();
    }

    System.out.println("The biggest number in the given array is : " + maxi);
  }
}
