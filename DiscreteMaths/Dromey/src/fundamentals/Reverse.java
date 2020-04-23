package fundamentals;

/**
 * Created by kkhan on 28/03/20.
 */
// Reverse the Digits

public class Reverse {
    public static void main(String args[]){
        int i = 12345;
        int j = 0;
        while(i > 0){
            j = j * 10 + i % 10;
            i = i / 10;
        }
        System.out.println(j);
    }
}
