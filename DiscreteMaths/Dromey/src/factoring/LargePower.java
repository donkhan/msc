package factoring;
import java.util.*;

/**
 * Created by kkhan on 25/03/20.
 */
public class LargePower {

    public long power(int x,int n){
        if (n == 1){
            return x;
        }
        if(n % 2 == 0){
            long p = power(x,n/2);
            return p * p;
        }
        if(n % 2 == 1){
            long p = power(x,n/2);
            return p * p * x;
        }
        return 1;
    }

    public static void main(String args[]){
        System.out.println(new LargePower().power(3,5));
        System.out.println(new LargePower().power(4,15));
    }

}
