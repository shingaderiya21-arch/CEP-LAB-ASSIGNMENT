
import java.util.*;

class simple 

    calculator {
    public static void main(String[] args) {
        int num1, num2, ans;
        char operator;

        Scanner scn = new Scanner(System.in); // built-in class

        System.out.println("Enter num1");
        num1 = scn.nextInt();

        System.out.println("Enter num2");
        num2 = scn.nextInt();

        System.out.println("Enter your choice:(+ ,-,*,/,% )");
        operator = scn.next().charAt(0);

        switch (operator) {
            case '+':
                ans = num1 + num2;
                System.out.println("\n add = " + ans);
                break;

            case '-':
                ans = num1 - num2;
                System.out.println("\n sub = " + ans);
                break;

            case '*':
                ans = num1 * num2;
                System.out.println("\n mul = " + ans);
                break;

            case '/':
                if (num2 != 0) {
                    ans = num1 / num2;
                    System.out.println("\n div = " + ans);
                } else {
                    System.out.println("\n Cannot divide by zero!");
                }
                break;

            case '%':
                if (num2 != 0) {
                    ans = num1 % num2;
                    System.out.println("\n mod = " + ans);
                } else {
                    System.out.println("\n Cannot perform modulus by zero!");
                }
                break;

            default:
                System.out.println("\n Invalid operator!");
                break;
        }
    }
}
