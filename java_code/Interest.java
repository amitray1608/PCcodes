import java.util.*;

class Interest {

  public static void main(String[] args) {

    String gender = args[0];
    int age = Integer.parseInt(args[1]);
    
    while(!isValid(gender, age)) {
      System.out.println("Wrong Input! Input Again:");
    }
    if(gender.equals("Female")) {
    	double ins = (age >= 1 && age <= 58 ? 8.2 : 7.6);
      System.out.println("Interest : " + ins);
    } else {
    	double ins = (age >= 1 && age <= 60 ? 9.2 : 8.3);
      System.out.println("Interest : " + ins);
    }
  }
  
  static Boolean isValid(String gen, int age) {
    return ((gen.equals("Male") || gen.equals("Female")) && (age >= 1 && age <= 120));
  }
}
