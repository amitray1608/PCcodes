import java.util.*;
import java.util.ArrayList;

class ItemType {
  private String name;
  private double deposit;
  private double costPerDay;
  
  ItemType (String n, double d, double c) {
    this.name = n;
    this.deposit = d;
    this.costPerDay = c;
  }
  
  String getname() {
    return this.name;
  }

  double getd() {
    return this.deposit;
  }
}

public class ArrayListObjectMain {
  public static void main(String [] args) {
    Scanner sc = new Scanner(System.in);
    ArrayList<ItemType> arr = new ArrayList<ItemType>();
    String s = sc.nextLine();
    int n = Integer.parseInt(s);
    for (int i = 0; i < n; i++) {
      String name = sc.nextLine();
      s = sc.nextLine();
      double dd = Double.parseDouble(s);
      s = sc.nextLine();
      double cc = Double.parseDouble(s);
      ItemType it = new ItemType(name, dd, cc);
      arr.add(it);
    }
    for (ItemType e : arr) {
      System.out.println(e.getname() + " " + e.getd());
    }
    sc.close();
  }
}
