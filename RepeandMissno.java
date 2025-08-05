public int[] findDuplicateAndMissing(int[] nums) {
    int n = nums.length;
    long S = (long)n * (n + 1) / 2;
    long S2 = (long)n * (n + 1) * (2 * n + 1) / 6;
    
    long sum = 0, sumSq = 0;
    for (int num : nums) {
        sum += num;
        sumSq += (long)num * num;
    }
    
    long diff1 = sum - S;          // A - B
    long diff2 = sumSq - S2;       // A^2 - B^2 = (A - B)(A + B)
    
    long sumAB = diff2 / diff1;    // A + B
    
    long A = (diff1 + sumAB) / 2;
    long B = A - diff1;
    
    return new int[]{(int)A, (int)B};
}
