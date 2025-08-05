int minFlipsMonoIncr(string s) {
    int n = s.size();
    int ones = 0;   // count of 1's seen so far
    int flips = 0;  // min flips needed

    for (char c : s) {
        if (c == '1') {
            ones++;  // 1 is fine, might keep it
        } else {
            // c == '0': we can flip this 0 to 1, OR flip earlier 1s to 0s
            flips++;         // flip this 0 to 1
            flips = min(flips, ones);  // choose min: flip this or flip previous 1s
        }
    }
    return flips;
}
