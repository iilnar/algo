import java.io.*;
import java.util.StringTokenizer;

class TreeE {
    class Node {
        private int l, r;
        private int value;
        public Node(int l, int r, int value) {
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
    private int NEUTRAL = -1;

    private void update(int v) {
        if (arr[v * 2].value != -1) {
            arr[v].value = arr[v * 2].value;
        } else {
            arr[v].value = arr[v * 2 + 1].value;
        }
    }

    private void build (int v, int l, int r) {
        arr[v] = new Node(l, r);
        if (r - l == 1) {
            arr[v].value = l;
            return;
        }
        int m = (l + r) / 2;
        build(2 * v, l, m);
        build(2 * v + 1, m, r);
        update(v);
    }

    public TreeE(int n) {
        arr = new Node[n * 4];
        build(1, 0, n);
    }

    private void set(int v, int pos, int x) {
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

    private int get(int v, int l, int r) {
        if (r <= arr[v].l || arr[v].r <= l) {
            return NEUTRAL;
        }
        if (l <= arr[v].l && arr[v].r <= r) {
            return arr[v].value;
        }
        int res = get(v * 2, l, r);
        if (res == -1) {
            res = get(v * 2 + 1, l, r);
        }
        return res;
    }

    public int min(int l, int r) {
        int res = get(1, l, r);
        if (res == -1) {
            res = get(1, 0, l);
        }
        return res;
    }

    public void set(int pos, int x) {
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

public class TaskE {
    boolean eof;
    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    public static void main(String[] args) throws IOException {
        new TaskE().run();
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
        String name = "parking.";
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
        int m = nextInt();
        TreeE tree = new TreeE(n);
        int k;
        for (int i = 0; i < m; i++) {
            switch (nextToken()) {
                case "enter":
                    k = tree.min(nextInt() - 1, n);
                    out.println(k + 1);
                    tree.set(k, -1);
                    break;
                case "exit":
                    k = nextInt();
                    tree.set(k - 1, k - 1);
                    break;
            }
        }
    }
}
