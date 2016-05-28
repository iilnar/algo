import java.io.*;
import java.util.StringTokenizer;

/**
 * Created by Ilnar on 09.05.2015.
 */
public class MergeSortIterative {
    boolean eof;
    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    public static void main(String[] args) throws IOException {
        new MergeSortIterative().run();
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
        String name = "";
        try {
            File f = new File(name + "input.txt");
            if (f.exists() && f.canRead()) {
                input = new FileInputStream(f);
                output = new PrintStream(name + "output.txt");
            }
        } catch (Throwable e) {
        }
        br = new BufferedReader(new InputStreamReader(input));
        out = new PrintWriter(output);
        solve();
        br.close();
        out.close();
    }
    void solve() {
        int n = nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }
        mergeSort(a);
        for (int i = 0; i < n; i++) {
            out.print(a[i] + " ");
        }
    }

    void mergeSort(int[] a) {
        for (int i = 1; i < a.length; i *= 2 ) {
            for (int j = 0; j + i < a.length; j += 2 * i) {
                merge(a, j, j + i, Math.min(a.length, j + 2 * i));
            }
        }
    }

    void merge(int[] a, int l, int m, int r) {
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
}