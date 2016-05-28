import java.io.*;
import java.util.StringTokenizer;

/**
 * Created by Илнар on 15.05.2015.
 */
class RMQD {
    class Node {
        private int l, r;
        private long value, set, add;
        public Node(int l, int r, long value) {
            this.l = l;
            this.r = r;
            this.value = value;
            this.set = 651518161811L;
            this.add = 651518161811L;
        }
        public Node(int l, int r) {
            this.l = l;
            this.r = r;
            this.set = 651518161811L;
            this.add = 651518161811L;
        }
        public void set(long x) {
            this.set = x;
            this.value = x;
            this.add = 651518161811L;
        }
        public void add(long x) {
            if (set != 651518161811L) {
                set += x;
            } else if (add != 651518161811L) {
                add += x;
            } else {
                add = x;
            }
            value += x;
        }
        public Node() {}

        public String toString() {
            return l + " " + r + " " + value + " type: " + add + " x: " + set;
        }
    }
    private Node[] arr;
    private long NEUTRAL = Long.MAX_VALUE;

    private void push(int v) {
        if (arr[v].set != 651518161811L) {
            if (v * 2 + 1 < arr.length && arr[v * 2 + 1] != null) {
                arr[v * 2].set(arr[v].set);
                arr[v * 2 + 1].set(arr[v].set);
            }
            arr[v].set = 651518161811L;
        }
        if (arr[v].add != 651518161811L) {
            if (v * 2 + 1 < arr.length && arr[v * 2 + 1] != null) {
                arr[v * 2].add(arr[v].add);
                arr[v * 2 + 1].add(arr[v].add);
            }
            arr[v].add = 651518161811L;
        }
    }

    private void build (long[] a, int v, int l, int r) {
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

    private void update(int v) {
        arr[v].value = Math.min(arr[v * 2].value, arr[v * 2 + 1].value);
    }

    public RMQD(long[] a) {
        arr = new Node[a.length * 4];
        build(a, 1, 0, a.length);
    }

    private void add(int v, int l, int r, long x) {
        if (r <= arr[v].l || arr[v].r <= l) {
            return;
        }
        if (l <= arr[v].l && arr[v].r <= r) {
            arr[v].add(x);
            push(v);
            return;
        }
        push(v);
        add(v * 2, l, r, x);
        add(v * 2 + 1, l, r, x);
        update(v);
    }

    private void set(int v, int l, int r, long x) {
        if (r <= arr[v].l || arr[v].r <= l) {
            return;
        }
        push(v);
        if (l <= arr[v].l && arr[v].r <= r) {
            arr[v].set(x);
            push(v);
            return;
        }
        set(v * 2, l, r, x);
        set(v * 2 + 1, l, r, x);
        update(v);
    }

    private long get(int v, int l, int r) {
        push(v);
        if (r <= arr[v].l || arr[v].r <= l) {
            return NEUTRAL;
        }
        if (l <= arr[v].l && arr[v].r <= r) {
            return arr[v].value;
        }
        update(v);
        return Math.min(get(v * 2, l, r), get(v * 2 + 1, l, r));
    }

    public long min(int l, int r) {
        return get(1, l, r);
    }

    public void add(int l, int r, long x) {
        add(1, l, r, x);
    }

    public void set(int l, int r, long x) {
        set(1, l, r, x);
    }

    public String toString() {
        String res = "";
        for (int i = 0; i < arr.length; i++) {
            res = res + "{" + i + "} -> {" + arr[i] + "}\n";
        }
        return res;
    }
}

class Silly {
    private long[] arr;
    public Silly(long[] arr) {
        this.arr = arr;
    }

    public void set(int l, int r, long x) {
        for (int i = l; i < r; i++) {
            arr[i] = x;
        }
    }

    public void add(int l, int r, long x) {
        for (int i = l; i < r; i++) {
            arr[i] += x;
        }
    }

    public long min(int l, int r) {
        long mn = Long.MAX_VALUE;
        for (int i = l; i < r; i++) {
            mn = Math.min(mn, arr[i]);
        }
        return mn;
    }
}

public class TaskD {
    boolean eof;
    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    public static void main(String[] args) throws IOException {
        new TaskD().run();
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
        String name = "rmq2.";
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
        long a[] = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextLong();
        }
        RMQD tree = new RMQD(a);
        //Silly silly = new Silly(a);
        int q, w;
        long r;
        for (String s = nextToken(); !eof && !s.equals("end"); s = nextToken()) {
            q = nextInt();
            w = nextInt();
            switch (s) {
                case "min":
                    out.println(tree.min(q - 1, w));
                    break;
                case "set":
                    r = nextLong();
                    tree.set(q - 1, w, r);
                    break;
                case "add":
                    r = nextLong();
                    tree.add(q - 1, w, r);
            }
            //out.println(tree);
        }
//        Random rand = new Random(System.currentTimeMillis());
//        String ans = "";
//        for (int i = 0; i < 100000; i++) {
////            if (i % 5 == 0) {
////                silly = new Silly(a);
////                tree = new RMQD(a);
////                ans = "";
////            }
//            q = Math.abs(rand.nextInt()) % n + 1;
//            w = Math.abs(rand.nextInt()) % n + 1;
//            if (w < q) {
//                int t = w;
//                w = q;
//                q = t;
//            }
//            switch (rand.nextInt() % 3) {
//                case 0:
//                    ans += "min " + q + " " + w + "\n";
//                    long ans1 = silly.min(q - 1, w);
//                    long ans2 = tree.min(q - 1, w);
//                    out.println("Siily: " + ans1 + " Tree: " + ans2);
//                    if (ans1 != ans2) {
//                        out.println("Ooopps\n" + ans);
//                        return;
//                    }
//                    break;
//                case 1:
//                    r = rand.nextLong() % 25;
//                    ans += "set " + q + " " + w + " " + r + "\n";
//                    tree.set(q - 1, w, r);
//                    silly.set(q - 1, w, r);
//                    break;
//                case 2:
//                    r = rand.nextLong() % 25;
//                    ans += "add " + q + " " + w + " " + r + "\n";
//                    tree.add(q - 1, w, r);
//                    silly.add(q - 1, w, r);
//            }
//            //out.println(tree);
//        }
    }
}

