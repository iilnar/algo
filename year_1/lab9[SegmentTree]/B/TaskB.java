import java.io.*;
import java.util.StringTokenizer;

/**
 * Created by Илнар on 15.05.2015.
 */
class RMQ {
    class Node {
        private int l, r;
        private long value;
        public Node(int l, int r, long value) {
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
    private long NEUTRAL = 0;

    private void update(int v) {
        arr[v].value = arr[v * 2].value + arr[v * 2 + 1].value;
    }

    private void build (int[] a, int v, int l, int r) {
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

    public RMQ(int[] a) {
        arr = new Node[a.length * 4];
        build(a, 1, 0, a.length);
    }

    private void set(int v, int pos, long x) {
        if (arr[v].l > pos || arr[v].r <= pos) {
            return;
        }
        if (arr[v].r - arr[v].l == 1 && arr[v].l == pos) {
            arr[v].value = x;
            return;
        }
        set(v * 2, pos, x);
        set(v * 2 + 1, pos, x);
        update(v);
    }

    private long get(int v, int l, int r) {
        if (r <= arr[v].l || arr[v].r <= l) {
            return NEUTRAL;
        }
        if (l <= arr[v].l && arr[v].r <= r) {
            return arr[v].value;
        }
        return get(v * 2, l, r) + get(v * 2 + 1, l, r);
    }

    public long min(int l, int r) {
        return get(1, l, r);
    }

    public void set(int pos, long x) {
        set(1, pos, x);
    }

    public String toString() {
        String res = "";
        for (int i = 0; i < arr.length; i++) {
            res = res + "{" + i + "} -> {" + arr[i] + "}\n";
        }
        return res;
    }
}

public class TaskB {
    boolean eof;
    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    public static void main(String[] args) throws IOException {
        new TaskB().run();
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
        String name = "rsq.";
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
        RMQ tree = new RMQ(a);
        for (String s = nextToken(); !eof; s = nextToken()) {
            switch (s) {
                case "sum":
                    out.println(tree.min(nextInt() - 1, nextInt()));
                    break;
                case "set":
                    tree.set(nextInt() - 1, nextLong());
            }
//            out.println(tree);
        }
    }
}
