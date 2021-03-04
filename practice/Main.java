import java.util.*;

public class Main {
  public static void main(String [] args) {
    Parent obj = new subclass1();
    obj.message();
    Parent obj1 = new subclass2();
    obj1.message();
  }
}

abstract class Parent {
  abstract void message();
}

class subclass1 extends Parent {
  void message() {
    System.out.println("This is first subclass");
  }
}
class subclass2 extends Parent {
  void message() {
    System.out.println("This is second subclass");
  }
}

