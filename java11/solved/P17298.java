import java.io.*;
import java.util.*;


class Pair implements Comparable<Pair> {
    public int a, b;

    Pair(int a, int b) {
        this.a = a;
        this.b = b;
    }

    public int getA() {
        return a;
    }

    public int getB() {
        return b;
    }

    @Override
    public int compareTo(Pair o) {
        if (this.a == o.getA()) {
            return this.b - o.getB();
        }
        return this.a - o.getA();
    }
}

public class P17298 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        List<Integer> arr = new ArrayList<>(Collections.nCopies(n, 0));

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr.set(i, Integer.parseInt(st.nextToken()));
        }
        List<Integer> answer = new ArrayList<>(Collections.nCopies(n, -1));
        // Stack<Pair> stack = new Deque<>();
        // java에서는 Stack, Queue 보다는 Deque를 쓰자.
        // Vector클래스를 상속했기 때문에 많이 느리다.


//        Deque<Pair> stack = new ArrayDeque<>();
        Deque<Pair> stack = new LinkedList<>();
        // 오큰수: 스택에서 더 큰 수가 나올 때까지 pop.
        // 해당 인덱스에 맞는 답 저장.
        for (int i = 0; i < n; i++) {
            while (!stack.isEmpty() && stack.peekFirst().getB() < arr.get(i)) {
                answer.set(stack.peekFirst().getA(), arr.get(i));
                // stack.top();
                stack.pollFirst();
                // stack.pop();
            }
//            stack.push(new Pair(i, arr.get(i)));
            stack.addFirst(new Pair(i, arr.get(i)));
        }
        StringBuilder sb = new StringBuilder();
        for (int elem : answer) {
            sb.append(elem);
            sb.append(" ");
        }
        bw.write(sb.toString());
//            bw.write(String.format("%d ", elem));

        bw.flush();
    }
}
