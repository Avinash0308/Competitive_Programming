import java.util.List;
import java.util.ArrayList;

public class Main {

    public static List<Integer> getMaxElementIndexes(List<Integer> a, List<Integer> rotate) {
        int n = a.size();
        int m = rotate.size();
        List<Integer> ans = new ArrayList<>(m);
        int maxy = -1;
        int ind = -1;

        for (int i = 0; i < n; i++) {
            if (maxy < a.get(i)) {
                maxy = a.get(i);
                ind = i;
            }
        }

        for (int i = 0; i < m; i++) {
            int r = rotate.get(i) % n;
            if (ind >= r) {
                ans.add(ind - r);
            } else {
                r -= ind;
                ans.add(n - r);
            }
        }

        return ans;
    }

    public static void main(String[] args) {
        List<Integer> a = List.of(1, 2, 3, 4, 5);
        List<Integer> rotate = List.of(1, 2, 3);

        List<Integer> result = getMaxElementIndexes(a, rotate);
        System.out.println(result);  // Output: [4, 3, 2]
    }
}
