import java.io.*;
import java.util.StringTokenizer;

public class MergeSort {
    boolean eof;
    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    public static void main(String[] args) throws IOException {
        new MergeSort().run();
    }

    public String nextToken() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (Exception e) {
                eof = true;
                return "-1";
            }
        }
        return st.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(nextToken());
    }

    public long nextLong() {
        return Long.parseLong(nextToken());
    }

    double nextDouble() {
        return Double.parseDouble(nextToken());
    }

    String nextLine() throws IOException {
        return br.readLine();
    }

    void run() throws IOException {
        InputStream input = System.in;
        PrintStream output = System.out;
        String name = "sort";
        try {
            File f = new File(name + ".in");
            if (f.exists() && f.canRead()) {
                input = new FileInputStream(f);
                output = new PrintStream(name + ".out");
            }
        } catch (Throwable e) {
        }
        br = new BufferedReader(new InputStreamReader(input));
        out = new PrintWriter(output);
        solve();
        br.close();
        out.close();
    }

    void mergeSort (int[] a, int l, int r) {
        if (r - l <= 8) {
            for (; l < r; l++) {
                for (int j = l + 1; j < r; j++) {
                    if (a[l] > a[j]) {
                        int temp = a[l];
                        a[l] = a[j];
                        a[j] = temp;
                    }
                }
            }
            return;
        }
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m, r);
        int[] b = new int[r - l];
        int p = 0, i = l, j = m;
        while (i < m && j < r) {
            if (a[i] < a[j]) {
                b[p++] = a[i++];
            } else {
                b[p++] = a[j++];
            }
        }
        while (i < m) {
            b[p++] = a[i++];
        }
        while (j < r) {
            b[p++] = a[j++];
        }
        for (i = l; i < r; i++) {
            a[i] = b[i - l];
        }
    }

    void solve() {
        int n = nextInt();
        int a[] = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }
        mergeSort(a, 0, n);
        for (int i = 0; i < n; i++) {
            out.print(a[i] + " ");
        }
        out.println("");

    }
}
