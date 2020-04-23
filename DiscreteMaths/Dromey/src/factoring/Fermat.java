package factoring;

// Checking for Primality
/**
 * Created by kkhan on 28/03/20.
 */
public class Fermat {


    public static void main(String args[]){
        LargePower lp = new LargePower();
        int n = 13;
        boolean flag = true;
        for(int i = 2;i<n;i++){
            long v = lp.power(i,n-1);
            long mod = v % n;
            System.out.println(i + " " + v + " " + mod);
            if(mod != 1){
                flag = false;
                break;
            }
        }
        if(flag){
            System.out.println("Prime Number...");
        }else{
            System.out.println("Not Prime Number ....");
        }
    }
}
