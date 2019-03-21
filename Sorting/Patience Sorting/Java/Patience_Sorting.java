import java.util.*;
 
public class PatienceSort {
    public static <E extends Comparable<? super E>> void sort (E[] n) {
        List<Pile<E>> piles = new ArrayList<Pile<E>>();
        // sort into piles
        for (E x : n) {
            Pile<E> newPile = new Pile<E>();
            newPile.push(x);
            int i = Collections.binarySearch(piles, newPile);
            if (i < 0) i = ~i;
            if (i != piles.size())
                piles.get(i).push(x);
            else
                piles.add(newPile);
        }
 
        // priority queue allows us to retrieve least pile efficiently
        PriorityQueue<Pile<E>> heap = new PriorityQueue<Pile<E>>(piles);
        for (int c = 0; c < n.length; c++) {
            Pile<E> smallPile = heap.poll();
            n[c] = smallPile.pop();
            if (!smallPile.isEmpty())
                heap.offer(smallPile);
        }
        assert(heap.isEmpty());
    }
 
    private static class Pile<E extends Comparable<? super E>> extends Stack<E> implements Comparable<Pile<E>> {
        public int compareTo(Pile<E> y) { return peek().compareTo(y.peek()); }
    }
 
    public static void main(String[] args) {
	Integer[] a = {4, 65, 2, -31, 0, 99, 83, 782, 1};
	sort(a);
	System.out.println(Arrays.toString(a));
    }
}