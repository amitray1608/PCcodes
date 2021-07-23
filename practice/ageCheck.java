
import java.util.*;

public class ageCheck {
  public static void main(String [] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter your name.");
    String name = sc.next();
    System.out.println("Enter your age.");
    int age = sc.nextInt();
    if (age >= 18 && age < 60) {
      System.out.println("You are eligible.");
      System.out.println("Name : " + name);
      System.out.println("Age : " + age);
    } else {
      System.out.println("You have to leave immediately. You are not eligible.");
    }
  }
}
