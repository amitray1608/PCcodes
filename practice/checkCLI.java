
public class checkCLI {
  public static void main(String [] args) {
    if (args.length == 0) {
      System.out.println("No Values");
    } else { 
      for (int i = 0; i < args.length; i++) {
        System.out.print(args[i] + (i == args.length - 1 ? "\n" : ", "));
      }
    }
  }
}
