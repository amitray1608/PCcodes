import java.util.*;
import java.util.Collections;

public class ArrayListEg {
  public static void main(String[] args) {
    
    //Declaration
    ArrayList<Integer> a = new ArrayList<Integer>();
    

    //add method
    for (int i = 0; i < 10; i++) {
      a.add(i + 1);
    }
    
    //print method
    for (int i : a) {
      System.out.print(i + " ");
    }
    System.out.println();
    
    //size method
    System.out.println("Size of the list : " + a.size());
    
    //remove method
    a.remove(4);
    for (int i : a) {
      System.out.print(i + " ");
    }
    System.out.println();

    //set method
    a.set(4, 99);
    for (int i : a) {
      System.out.print(i + " ");
    }
    System.out.println();
    
    //search method
    boolean ok = (a.contains(99));
    if (ok == true)
      System.out.println("Yes it contains the value 99");
    else
      System.out.println("NO it does not contain");
  
    a.add(43);
    a.add(354);
    a.add(76);
    
    //sort method
    Collections.sort(a);
    
    for (int i : a) {
      System.out.print(i + " ");
    }
    System.out.println();
  
    int ind = a.indexOf(99);

    System.out.println(ind);

    List<Integer> ls = a.subList(1, 5);

    for (int i : ls) {
      System.out.print(i + " ");
    }
    System.out.println();  
  }
}
