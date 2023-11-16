import java.util.*;

public class DataStructure {
    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<>();
//        stack.push(2);
//        stack.peek();
//        stack.pop();
        Queue<Integer> queue = new LinkedList<>();
//        queue.add(3);
//        queue.remove();
//        queue.poll();

        TreeMap<String, Integer> map = new TreeMap<>();
//        map.containsKey("key");

        TreeSet<Integer> set = new TreeSet<>();
//        set.add(4);
//        set.remove(0);
//        set.contains(3);
//        set.remove(3);

        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
//        pq.add(3);
//        pq.peek();
//        pq.remove();

        List<Integer> a = Arrays.asList(7, 3, 2, 9, 1);
        a.sort(Collections.reverseOrder());
    }
}
