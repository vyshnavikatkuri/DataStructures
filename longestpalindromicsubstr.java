import java.util.*;

public class longestpalindromicsubstr {

    // Helper function to expand around center and return the longest palindrome
    public static String isPalindrome(int left, int right, String s) {
        while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
            left--;
            right++;
        }
        // left + 1 and right are now the valid palindrome boundaries
        return s.substring(left + 1, right);
    }

    // Main function to find longest palindromic substring
    public static String longestPalindrome(String s) {
        String longest = "";
        for (int i = 0; i < s.length(); i++) {
            // Check for odd-length palindromes
            String odd = isPalindrome(i, i, s);
            if (odd.length() > longest.length()) {
                longest = odd;
            }

            // Check for even-length palindromes
            String even = isPalindrome(i, i + 1, s);
            if (even.length() > longest.length()) {
                longest = even;
            }
        }
        return longest;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the string: ");
        String input = sc.nextLine();

        String result = longestPalindrome(input);
        System.out.println("Longest Palindromic Substring: " + result);
        sc.close();
    }
}
