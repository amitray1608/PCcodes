
public class isIndian {
  public static void main(String[] args) throws InvalidCountryException {
    String username = args[0];
    String country = args[1];
    country.toLowerCase();
    if (!country.equals("india")) {
      throw new InvalidCountryException();
    }
    System.out.println("User registration done successfully.");
  }
}

class InvalidCountryException extends Exception {
  public InvalidCountryException() {
    super();
    System.out.println("User Outside India cannot be registered.");
  }
}
