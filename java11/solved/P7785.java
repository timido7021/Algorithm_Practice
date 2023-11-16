import java.util.*;
import java.io.*;

public class P7785 {
    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

//        HashMap<String, Integer> map = new HashMap<>();
        TreeSet<String> treeSet = new TreeSet<>();

        int n = Integer.parseInt(br.readLine());

        for (int i = 0; i < n; i++) {
            String[] in = br.readLine().split(" ");
            if (in[1].equals("enter")) {
                treeSet.add(in[0]);
            } else {
                treeSet.remove(in[0]);
            }
        }

        Stack<String> stack = new Stack<>();
        for (String s : treeSet) {
            stack.add(s);
//            bw.write(s + "\n");
        }

        while (!stack.empty()) {
            bw.write(stack.pop() + "\n");
        }

        Queue<Integer> Q;

        bw.flush();
    }
}
