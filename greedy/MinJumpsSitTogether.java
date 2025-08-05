import java.util.*;
package greedy;
public class MinJumpsSitTogether {
    public int jumps(String A){
        int MOD=10000003;
        List<Integer>pos=new ArrayList<>();
        for(int i=0;i<A.length();i++){
            if(A.charAt(i)=='x'){
                pos.add(i);
            }
        }
        if(pos.size()==0||pos.size()==A.length()) return 0;
        int medianidx=pos.size()/2;
        int medianpos=pos.get(medianidx);
        long jumps=0;
        for(int i=0;i<pos.size();i++){
            int target=medianpos-(medianidx-i);
            jumps=(jumps+Math.abs(pos.get(i)-target))%MOD;
        }
        return (int)jumps;

    }
}
