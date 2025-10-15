
import java.util.Scanner;

public class DivisionExample {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        try {
            // Taking input from user
            System.out.print("Enter the numerator: ");
            int numerator = sc.nextInt();

            System.out.print("Enter the denominator: ");
            int denominator = sc.nextInt();

            // Performing division
            int result = numerator / denominator;

            System.out.println("Result: " + result);
        } catch (ArithmeticException e) {
            // Handling division by zero
            System.out.println("Error: Cannot divide by zero!");
        } finally {
            // Closing the scanner
            sc.close();
        }
    }
}
