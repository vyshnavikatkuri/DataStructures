class Solution {
    public String reverseWords(String s) {
        StringBuilder str=new StringBuilder(s);
        str.reverse();
        int n=str.length();
        StringBuilder ans=new StringBuilder("");
        for(int i=0;i<str.length();i++){
            StringBuilder word=new StringBuilder("");
            while(i<n && str.charAt(i)!=' '){
                word.append(str.charAt(i));
                i++;
            }
            word.reverse();
            if(word.length()>0){
                ans.append(' ').append(word);
            }
        }
        return ans.substring(1);
    }
}