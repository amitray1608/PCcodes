import java.util.Scanner;

public class colorCode {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the color code.");
        char color = sc.nextLine().charAt(0);
        switch (color) {
            case 'R':
                System.out.println("R is the color code of Red");
                break;
            case 'B':
                System.out.println("B is the color code of Blue");
                break;
            case 'G':
                System.out.println("G is the color code of Green");
                break;
            case 'O':
                System.out.println("O is the color code of Orange");
                break;
            case 'Y':
                System.out.println("Y is the color code of Yellow");
                break;
            case 'W':
                System.out.println("W is the color code of White");
                break;
            default:
                System.out.println("Invalid Code.");
        }
        sc.close();
    }

}


