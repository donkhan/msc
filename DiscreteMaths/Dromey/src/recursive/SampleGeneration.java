package recursive;
/**
 * Created by kkhan on 25/03/20.
 */

public class SampleGeneration {

    private void sg_crude(int n,int r){
        for(int i = 1;i<=r;i++){
            for(int j = 1;j<=r;j++){
                for(int k = 1;k<=r;k++){
                    System.out.println(i + "," + j + "," + k);
                }
            }
        }
    }

    private void print_array(Object[] array,int r){
        String output = "";
        for(int i=0;i<r;i++) {
            output = output + array[i] + ",";
        }
        System.out.println(output.substring(0,output.length()-1));
    }

    private void sample_generation(int n,int r,int k,Object[] array,Object objects[]){
        if (r == k){
            print_array(array,r);
            return;
        }
        for(int i = 0;i<r;i++){
            array[k] = objects[i];
            sample_generation(n,r,k+1,array,objects);
        }
    }


    public static void main(String args[]){
        //new SampleGeneration().sg_crude(5,3);
        new SampleGeneration().sample_generation(5,3,0,new Object[3],new Object[]{"A","B","C"});
    }


}
