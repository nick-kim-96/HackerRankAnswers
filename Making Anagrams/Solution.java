import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the makeAnagram function below.
    static int makeAnagram(String a, String b) {
        int[] myArray = new int[300];

        for(int i = 0; i < a.length(); i++)
        {
            int number = Character.getNumericValue(a.charAt(i));
            myArray[number] = myArray[number] + 1;
        }
        for(int i = 0; i < b.length(); i++)
        {
            int number = Character.getNumericValue(b.charAt(i));
            myArray[number] = myArray[number] - 1;
        }
        for(int i = 0; i < myArray.length; i++)
        {
            myArray[i] = Math.abs(myArray[i]);
        }
        int count = 0;
        for(int i = 0; i < myArray.length; i++)
        {
            count += myArray[i];
        }
        return count;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String a = scanner.nextLine();

        String b = scanner.nextLine();

        int res = makeAnagram(a, b);

        bufferedWriter.write(String.valueOf(res));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
