import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'receivedText' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts STRING S as parameter.
     */

    public static String receivedText(String S) {
    // WRITE DOWN YOUR CODE HERE
        StringBuilder myString = new StringBuilder();
        
        int j = 0;
        boolean numLock = true;
        for(int i = 0; i < S.length(); i++) {
            if(S.charAt(i) == '<') {
                j = 0;
            }
            else if(S.charAt(i) == '>') {
                j = myString.length();
            }
            else if(S.charAt(i) == '*') {
                j = j - 1;
                myString.deleteCharAt(j);
            }
            else if(S.charAt(i) == '#') {
                numLock = !numLock;
            }
            else {
                if(Character.isDigit(S.charAt(i))) {
                    if(numLock) {
                        myString.insert(j, S.charAt(i));
                        j++;
                    }
                    
                }
                else {
                    myString.insert(j, S.charAt(i));
                    j++;
                }  
            }     
        }
        
        
        return myString.toString();
    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String S = bufferedReader.readLine();

        String result = Result.receivedText(S);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
