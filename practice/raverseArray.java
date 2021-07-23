
public class raverseArray {
  public static void main(String []args) {
    int a[][] = new int[2][2];
    int i = 0, j = 0;
    for (String k : args) {
      a[i][j] = Integer.parseInt(k);
      j++;
      if (j == 2) {
        j = 0;
        i++;
      }
    }
    System.out.println("The matrix before reverse is : ");
    for (i = 0; i < 2; i++) {
      for (j = 0; j < 2; j++) {
        System.out.print(a[i][j] + " ");
      }
      System.out.println();
    }
    int tmp = a[0][0];
    a[0][0] = a[1][1];
    a[1][1] = tmp;
    tmp = a[0][1];
    a[0][1] = a[1][0];
    a[1][0] = tmp;
    
    System.out.println("The matrix after reverse is : ");
    for (i = 0; i < 2; i++) {
      for (j = 0; j < 2; j++) {
        System.out.print(a[i][j] +  " ");
      }
      System.out.println();
    }
  }
}
