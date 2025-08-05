import java.util.*;

public class Solution {

    // Class to represent each Meeting with start and end times
    static class Meeting {
        int st, end;

        public Meeting(int s, int e) {
            st = s;
            end = e;
        }
    }

    // Function to find the maximum number of meetings
    public int maxMeetings(int[] start, int[] end) {
        int n = start.length;
        Meeting[] m = new Meeting[n];

        // Create array of Meeting objects
        for (int i = 0; i < n; i++) {
            m[i] = new Meeting(start[i], end[i]);
        }

        // Sort meetings by ascending order of end time
        Arrays.sort(m, (a, b) -> a.end - b.end);

        int cnt = 1;  // always select the first meeting
        int crend = m[0].end;

        // Select meetings that don't overlap
        for (int i = 1; i < n; i++) {
            if (m[i].st >=crend) {
                cnt++;
                crend = m[i].end;
            }
        }

        return cnt;
    }

    // Main method for testing
    public static void main(String[] args) {
        Solution sol = new Solution();

        // Test Case 1
        int[] start1 = {1, 3, 0, 5, 8, 5};
        int[] end1 = {2, 4, 6, 7, 9, 9};
        System.out.println("Max Meetings: " + sol.maxMeetings(start1, end1)); // Output: 4

        // Test Case 2
        int[] start2 = {10, 12, 20};
        int[] end2 = {20, 25, 30};
        System.out.println("Max Meetings: " + sol.maxMeetings(start2, end2)); // Output: 1

        // Test Case 3
        int[] start3 = {1, 2};
        int[] end3 = {100, 99};
        System.out.println("Max Meetings: " + sol.maxMeetings(start3, end3)); // Output: 1
    }
}
