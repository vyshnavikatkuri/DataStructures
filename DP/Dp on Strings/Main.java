public class Main{
    public static int minInsertions(String s){
        StringBuffer str=new StringBuffer(s);
        str.reverse();
        int n=s.length();
        int [][]dp=new int[n+1][n+1];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s.charAt(i-1)==str.charAt(j-1)){
                    dp[i][j]=1+dp[i-1][j-1];
                }else {
                    dp[i][j]=Math.max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int palindrome_lcs=dp[n][n];
        return n-palindrome_lcs;
        
    }
    public static void main(String[] args) {
        String s="vyshnavi";
        int res=minInsertions(s);
        System.out.println(res);

    }
}
