package DP.Dp on Strings;

public class printlcs {
    
}
class Solution {
    public static String longestCommonSubsequence(String text1, String text2) {
        int m = text1.length();
        int n = text2.length();

        // Create DP table
        int[][] dp = new int[m + 1][n + 1];

        // Fill the table - LCS length
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1.charAt(i - 1) == text2.charAt(j - 1)) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Reconstruct the LCS string
        StringBuilder lcs = new StringBuilder();
        int i = m, j = n;
        while (i > 0 && j > 0) {
            if (text1.charAt(i - 1) == text2.charAt(j - 1)) {
                lcs.append(text1.charAt(i - 1));
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }

        return lcs.reverse().toString(); // Reverse the LCS to correct order
    }

    public static void main(String[] args) {
        String s1 = "abcde";
        String s2 = "ace";
        System.out.println("Longest Common Subsequence: " + longestCommonSubsequence(s1, s2));
    }
}

