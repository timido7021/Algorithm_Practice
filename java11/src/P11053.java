import java.io.*;
import java.util.*;

public class P11053 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());


        List<Integer> LIS = new ArrayList<>();
//        int[] LIS = new int[0];
        List<Integer> arr = new ArrayList<>(Collections.nCopies(n, 0));
        String[] in = br.readLine().split(" ");

        for (int i = 0; i < n; i++) {
            arr.set(i, Integer.parseInt(in[i]));
        }
//        LIS.add(arr.get(0));
        for (int i = 0; i < n; i++) {
            int elem = arr.get(i);
            int index = Collections.binarySearch(LIS, elem);
            // LIS에 존재하지 않는 elem일 때는
            // 넣어도 기존의 정렬됨을 유지할 수 있는 -(insertion point) - 1을 반환
            // 1, 2, 4 <- 3 >> insertion_point:2, returns: -3
            if (index < 0) {
                index = -(index + 1);
            }
            if (index == LIS.size()) {
                LIS.add(elem);
            } else {
                LIS.set(index, elem);
            }
        }

        System.out.println(LIS.size());
    }
}
