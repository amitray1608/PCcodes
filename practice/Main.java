
import java.util.*;

public class pro2 {
    public static void main(String[] args) throws NumberFormatException {
        int num;
        try {
            for(int i = 0; i < 5; ++i){

            }
            int sum = 0;
            int avg = 0; 
            System.out.println ("Result = " + sum);
            System.out.println ("Result = " + avg);
        }
        catch(ArithmeticException e) {
            System.out.println ("Can't divide a number by 0");
        }
        int num = Integer.parseInt(args[]);
        if (num < 0)
            throw new NumberFormatException();
        System.out.println(num);
    }
}
class NumberFormatException extends Exception {
    public NumberFormatException() {
        super();
        System.out.println("Invalid Input");
    }
}
