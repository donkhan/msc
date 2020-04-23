package factoring;
import java.util.*;

/**
 * Created by kkhan on 25/03/20.
 */
public class LargePower3 {

    public int power(int x,int n){
        if (n == 1){
            return x;
        }
        if(n % 3 == 2){
            int p = power(x,n/3);
            return p * p * p;
        }
        if(n % 3 == 1){
            int p = power(x,n/3);
            return p * p * x;
        }
        return 1;
    }

    public static void main(String args[]){
        System.out.println(new LargePower().power(3,5));
        System.out.println(new LargePower().power(4,15));
    }

}
