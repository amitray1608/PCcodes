import java.util.ArrayList;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

public class List {
	static Scanner sc = new Scanner(System.in);
	public static void main(String [] args) {
		ArrayList<String> alist = new ArrayList<String>();
		String element;
		while(true){
      int n = getOption();
      sc.nextLine();
			switch(n){
				case 1:
					System.out.println("Enter the item to be inserted:");
					element = sc.nextLine();
					alist.add(element);
          break;
				case 2:
					System.out.println("Enter the item to search : ");
					element = sc.nextLine();
					boolean ans = alist.contains(element);
					if (ans == true)
            			System.out.println("Item found in the list.");
        			else
            			System.out.println("Item not found in the list.");
          break;
				case 3:
					System.out.println("Enter the item to delete : ");
					element = sc.nextLine();
					alist.remove(element);
          break;
				case 4:
        	System.out.println("The Items in the list are :");  
					for(String str : alist)  
        				System.out.println(str);  
          break;
				case 5:
          System.out.println("Thank You");
					break;
			}
		}
	}

  static int getOption() {
    System.out.println("Enter your choice : ");
		System.out.println("1. Insert");
		System.out.println("2. Search");
		System.out.println("3. Delete");
		System.out.println("4. Display");
		System.out.println("5. Exit");
		String t = sc.next();
    int n = Integer.parseInt(t);
    return n;
  }
}
