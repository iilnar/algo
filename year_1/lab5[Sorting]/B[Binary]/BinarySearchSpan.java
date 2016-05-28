import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * Created by Илнар on 23.02.2015.
 */


public class BinarySearchSpan {
    boolean eof;
    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    public static void main(String[] args) throws IOException {
        new BinarySearchSpan().run();
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
        String name = "binsearch.";
        try {
            File f = new File(name + "in");
            if (f.exists() && f.canRead()) {
                input = new FileInputStream(f);
                output = new PrintStream(name + "out");
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
        int a[] = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }
        int m = nextInt();
        for (int i = 0; i < m; i++) {
            int x = nextInt();
            int l = binarySearchIterative(a, x, -1, n, 'l');
            int r = binarySearchIterative(a, x, -1, n, 'r');
            if (l == n || r == -1 || a[l] != x) l = -2;
            if (r == n || r == -1 || a[r] != x) r = -2;
            out.println((l + 1) + " " + (r + 1));
        }
        out.println("");
        
    }

    static boolean compare(int[] a, int x, int i, char type) {
           return (type == 'l') ? a[i] < x : a[i] <= x;
       }

    static int binarySearchIterative(int[] a, int x, int l, int r, char type) {
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (compare(a, x, m, type)) {
                l = m;
            } else {
                r = m;
            }
        }
        return (type == 'l') ? r : l;
    }

}
