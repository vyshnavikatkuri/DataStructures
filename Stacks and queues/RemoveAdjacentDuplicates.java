package Stacks and queues;
import java.util.*;

public class RemoveAdjacentDuplicates {

    public static String removeDuplicates(String s) {
        Stack<Character> stack = new Stack<>();

        for (char ch : s.toCharArray()) {
            if (!stack.isEmpty() && stack.peek() == ch) {
                stack.pop(); // remove the adjacent duplicate
            } else {
                stack.push(ch);
            }
        }

        // Build the result from the stack
        StringBuilder result = new StringBuilder();
        while(!stack.isEmpty()) {
            result.append(stack.pop());
        }

        return result.reverse().toString();
    }

    public static void main(String[] args) {
        String input = "abbaca";
        String result = removeDuplicates(input);
        System.out.println("Result: " + result);  // Output: "ca"
    }
}

