import java.util.*;

public class TreeMap {
  public static void main(String []args) {
    Scanner sc = new Scanner(System.in);
    Map<Character, Integer> mp;
    mp = new java.util.TreeMap<Character, Integer>();
    int count = 0, total = 0;
    while (true) {
      System.out.println("Enter a card:");
      Character tp = sc.next().charAt(0);
      int num = sc.nextInt();
      total++;
      if (mp.containsKey(tp) == true) {
        continue;
      } else {
        count++;
        mp.put(tp, num);
      }
      if (count == 4) break;
    }
    System.out.println("Four symbols gathered in " + total + " cards.");
    for (Map.Entry<Character, Integer> e : mp.entrySet())
            System.out.println(e.getKey() + " " + e.getValue());  
  }
}
