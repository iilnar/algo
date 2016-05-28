import java.io.*;
import java.util.StringTokenizer;

/**
 * Created by Илнар on 15.05.2015.
 */

class Matrix {
    int a, b, c, d;

    public Matrix (int a, int b, int c, int d) {
        this.a = a;
        this.b = b;
        this.c = c;
        this.d = d;
    }

    public Matrix multiply (Matrix m, int r) {
        return new Matrix((a * m.a + b * m.c) % r, (a * m.b + b * m.d) % r, (c * m.a + d * m.c) % r, (c * m.b + d * m.d) % r);
    }

    public String toString() {
        return a + " " + b + "\n" + c + " " + d + "\n";
    }
}

class Tree {
    class Node {
        private int l, r;
        private Matrix value;
        public Node(int l, int r, Matrix value) {
            this.l = l;
            this.r = r;
            this.value = value;
        }
        public Node(int l, int r) {
            this.l = l;
            this.r = r;
        }

        public String toString() {
            return l + " " + r + " " + value;
        }
    }
    private Node[] arr;
    private Matrix NEUTRAL = new Matrix(1, 0, 0, 1);
    private int r;

    private void update(int v) {
        arr[v].value = arr[v * 2].value.multiply(arr[v * 2 + 1].value, r);
    }

    private void build (Matrix[] a, int v, int l, int r) {
        arr[v] = new Node(l, r);
        if (r - l == 1) {
            arr[v].value = a[l];
            return;
        }
        int m = (l + r) / 2;
        build(a, 2 * v, l, m);
        build(a, 2 * v + 1, m, r);
        update(v);
    }

    public Tree(Matrix[] a, int r) {
        arr = new Node[a.length * 4];
        this.r = r;
        build(a, 1, 0, a.length);
    }


    private Matrix get(int v, int l, int r) {
        if (r <= arr[v].l || arr[v].r <= l) {
            return NEUTRAL;
        }
        if (l <= arr[v].l && arr[v].r <= r) {
            return arr[v].value;
        }
        return get(v * 2, l, r).multiply(get(v * 2 + 1, l, r), this.r);
    }

    public Matrix calc(int l, int r) {
        return get(1, l, r);
    }


    public String toString() {
        String res = "";
        for (int i = 0; i < arr.length; i++) {
            res = res + "{" + i + "} -> {" + arr[i] + "}\n";
        }
        return res;
    }
}

public class TaskC {
    boolean eof;
    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    public static void main(String[] args) throws IOException {
        new TaskC().run();
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
        String name = "crypto.";
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
        int r = nextInt();
        int n = nextInt();
        int m = nextInt();
        Matrix[] a = new Matrix[n];
        for (int i = 0; i < n; i++) {
            a[i] = new Matrix(nextInt(), nextInt(), nextInt(), nextInt());
        }
        Tree tree = new Tree(a, r);
        for (int i = 0; i < m; i++) {
            out.println(tree.calc(nextInt() - 1, nextInt()));
        }
    }
}
