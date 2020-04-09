import java.util.HashSet;
import java.util.Iterator;
import java.util.HashMap;

class LRU{
    static int pageFaults(int pages[], int n, int capacity){
        HashSet<Integer> s = new HashSet<>(capacity);
        HashMap<Integer, Integer> indexes = new HashMap<>();
        int page_faults = 0;
        for (int i=0; i<n; i++){
            if (s.size() < capacity){
                if (!s.contains(pages[i])){
                    s.add(pages[i]);
                    page_faults++;
                }
                indexes.put(pages[i], i);
            }
            else{
                if (!s.contains(pages[i])){
                    int lru = Integer.MAX_VALUE, val=Integer.MIN_VALUE;
                    Iterator<Integer> itr = s.iterator();
                    while (itr.hasNext()) {
                        int temp = itr.next();
                        if (indexes.get(temp) < lru){
                            lru = indexes.get(temp);
                            val = temp;
                        }
                    }
                    s.remove(val);
                    indexes.remove(val);
                    s.add(pages[i]);
                    page_faults++;
                }
                indexes.put(pages[i], i);
            }
        }
        return page_faults;
    }

    public static void main(String args[]){
        int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2,1,2,0,1,7,0,1};
        //System.out.println(pageFaults(pages, pages.length, 3));
        pages = new int[]{ 1,2,3,4,2,1,5,6,2,1,2,3,7,6,3,2,1,2,3,6};
        //System.out.println(pageFaults(pages, pages.length, 3));
        System.out.println(pageFaults(pages, pages.length, 4));

    }
}