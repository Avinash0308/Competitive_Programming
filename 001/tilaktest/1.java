import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }

        solve(arr, n);
        scanner.close(); // Close the scanner after use
    }

    public static void solve(int[] arr, int n) {
        int i = 0;
        while (i < n - 1 && arr[i] < arr[i + 1]) {
            i++;
        }

        if (i == n - 1) {
            System.out.println("YES");
            System.out.println(n + " " + n);
            return;
        }

        int pnt = i + 1;
        while (i < n - 1 && arr[i] > arr[i + 1]) {
            i++;
        }

        if (pnt == 1 || arr[pnt - 2] < arr[i]) {
            if (i == n - 1 || arr[pnt-1] < arr[i + 1]) {
                System.out.println("YES");
                System.out.println(pnt + " " + (i + 1));
            } else {
                System.out.println("NO");
            }
        } else {
            System.out.println("NO");
        }
    }
}
