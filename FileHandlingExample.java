
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class FileHandlingExample {

    public static void main(String[] args) {
        String fileName = "sample.txt"; // File name

        try {
            // --- Writing to the file ---
            FileWriter writer = new FileWriter(fileName);
            writer.write("Hello! This is a sample text file.\n");
            writer.write("File handling in Java is simple and powerful.\n");
            writer.close();
            System.out.println("Content written to " + fileName);

            // --- Reading from the file ---
            FileReader reader = new FileReader(fileName);
            int character;

            System.out.println("\nContents of the file:");
            while ((character = reader.read()) != -1) {
                System.out.print((char) character);
            }
            reader.close();
        } catch (IOException e) {
            System.out.println("An error occurred while handling the file.");
            e.printStackTrace();
        }
    }
}
