import java.io.*;
import java.util.*;

public class P1504 { // boj.kr/1504
    public static class Pair implements Comparable<Pair> {
        public int a, b;

        Pair(int a, int b) {
            this.a = a;
            this.b = b;
        }

        public int compareTo(Pair other) {
            if (this.a == other.a)
                return this.b - other.b;
            return this.a - other.a;
        }
    }
    public static void getDijk(int start, List<Pair>[] adj, List<Integer> dist) {
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        pq.add(new Pair(0, start));

        while (!pq.isEmpty()) {
            int currDist = pq.peek().a;
            int curr = pq.peek().b;

            pq.poll();

            if (currDist > dist.get(curr))
                continue;

            for (Pair p : adj[curr]) {
                int cost = p.a;
                int nxt = p.b;
                if (dist.get(nxt) > currDist + cost) {
                    dist.set(nxt, currDist + cost);
                    pq.add(new Pair(currDist + cost, nxt));
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        int n, e;
        String[] arr = br.readLine().split(" ");

        n = Integer.parseInt(arr[0]);
        e = Integer.parseInt(arr[1]);

//        @SuppressWarnings("unchecked")
        List<Pair>[] adj = new List[n];

        for (int i = 0; i < n; i++)
            adj[i] = new LinkedList<>();

//        int[][] adj = new int[801][801];

        for (int i = 0; i < e; i++) {
            int a, b, c;
            StringTokenizer st = new StringTokenizer(br.readLine());

            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());

            // "양방향 길이 존재하며"
            adj[a - 1].add(new Pair(c, b - 1));
            adj[b - 1].add(new Pair(c, a - 1));
        }

        arr = br.readLine().split(" ");
        int v1 = Integer.parseInt(arr[0]);
        int v2 = Integer.parseInt(arr[1]);

        // 특정 최단 경로
        // v1 -> v2 혹은 v2 -> v1 이므로
        // 1 -> v1 - v2 -> N
        // 1 -> v2 - v1 -> N
        // 두 경우에 대해 조사.

        // 모든 index에 -1 처리.

        List<Integer> dijk_from_0 = new ArrayList<>(Collections.nCopies(n, 1 << 27));
        dijk_from_0.set(0, 0);
        List<Integer> dijk_from_V1 = new ArrayList<>(Collections.nCopies(n, 1 << 27));
        dijk_from_V1.set(v1 - 1, 0);
        List<Integer> dijk_from_V2 = new ArrayList<>(Collections.nCopies(n, 1 << 27));
        dijk_from_V2.set(v2 - 1, 0);


        getDijk(0, adj, dijk_from_0);
        getDijk(v1 - 1, adj, dijk_from_V1);
        getDijk(v2 - 1, adj, dijk_from_V2);

        int answer = Integer.min(
                dijk_from_0.get(v1 - 1) + dijk_from_V1.get(v2 - 1) + dijk_from_V2.get(n - 1),
                dijk_from_0.get(v2 - 1) + dijk_from_V2.get(v1 - 1) + dijk_from_V1.get(n - 1)
        );

        if (answer > (1 << 26))
            answer = -1;

        sb.append(answer);
        bw.write(sb.toString());

        bw.flush();
    }
}
