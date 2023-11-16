import java.util.*;
import java.io.*;

public class P10818 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        List<Integer> arr = new ArrayList<>(Collections.nCopies(N, 0)); // vector<int>(N, 0);

        int arrMax = (int) 1e9;
        int arrMin = (int) -1e9;
        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < arr.size(); i++){
            arr.set(i, Integer.parseInt(st.nextToken()));
        }

//        for (int elem : arr) {
//            elem = Integer.parseInt(st.nextToken());
//        }

//        for (int elem : arr) {
//            // Math.max, Math.min
//            arrMax = Integer.max(elem, arrMax);
//            arrMin = Integer.min(elem, arrMin);
//        }
//        bw.write(String.format("%d %d", arrMax, arrMin));

        bw.write(String.format("%d %d", Collections.min(arr), Collections.max(arr)));
        bw.flush();
    }
}
