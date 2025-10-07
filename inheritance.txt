// Parent class
class Person {
    void displayInfo() {
        System.out.println("I am a person.");
    }
}

// Child class
class Student extends Person {
    void displayRole() {
        System.out.println("I am a student.");
    }
}

// Main class with main() method
public class Main {
    public static void main(String[] args) {
        Student s = new Student();

        // Using parent class method
        s.displayInfo();

        // Using child class method
        s.displayRole();
    }
}