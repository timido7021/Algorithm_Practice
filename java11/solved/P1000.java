import java.util.*;
import java.io.*;

public class P1000 { // boj.kr/1000
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));


        List<Integer> arr = new ArrayList<>();
        Collections.sort(arr);
        PriorityQueue<Integer> PQ;

        int a, b;
        StringTokenizer st = new StringTokenizer(br.readLine());
        a = Integer.parseInt(st.nextToken());
        b = Integer.parseInt(st.nextToken());
        bw.write(String.format("%d", a + b));
        bw.flush();
    }
}
