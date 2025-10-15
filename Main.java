// Define an interface named Playable

interface Playable {

    void play(); // Method to be implemented by classes
}

// Class Cricket implementing Playable interface
class Cricket implements Playable {

    public void play() {
        System.out.println("Playing Cricket!");
    }
}

// Class Football implementing Playable interface
class Football implements Playable {

    public void play() {
        System.out.println("Playing Football!");
    }
}

// Main class to test the program
public class Main {

    public static void main(String[] args) {
        // Create objects of Cricket and Football
        Playable game1 = new Cricket();
        Playable game2 = new Football();

        // Call the play() method
        game1.play();
        game2.play();
    }
}
