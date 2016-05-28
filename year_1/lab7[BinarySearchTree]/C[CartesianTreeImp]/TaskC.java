import java.io.*;
import java.util.Random;
import java.util.StringTokenizer;

/**
 * Created by Илнар on 26.04.2015.
 */

class Treap {
    static Random rand = new Random();

    class Node {
        int x, y, size;
        Node left, right;

        public Node() {}

        public Node(int x) {
            this.x = x;
            this.y = rand.nextInt();
            this.size = 1;
        }

        public void recalc() {
            this.size = sizeOf(left) + sizeOf(right) + 1;
        }
    }

    class Pair {
        Node left, right;

        public Pair() {}

        public Pair(Node left, Node right) {
            this.left = left;
            this.right = right;
        }
    }

    private Node root = null;

    private int sizeOf (Node node) {
        return node == null ? 0 : node.size;
    }

    private Pair split (Node node, int x) {
        if (node == null) {
            return new Pair(null, null);
        }
        if (x <= sizeOf(node.left)) {
            Pair spli = split(node.left, x);
            node.left = spli.right;
            node.recalc();
            spli.right = node;
            return spli;
        } else {
            Pair spli = split(node.right, x - sizeOf(node.left) - 1);
            node.right = spli.left;
            node.recalc();
            spli.left = node;
            return spli;
        }
    }

    private Node merge (Node left, Node right) {
        if (left == null || right == null) {
            if (left == null) {
                return right;
            } else {
                return left;
            }
        } else {
            if (left.y > right.y) {
                left.right = merge(left.right, right);
                left.recalc();
                return left;
            } else {
                right.left = merge(left, right.left);
                right.recalc();
                return right;
            }
        }
    }

    public void delete (int x) {
        Pair spli = split(root, x);
        Pair ssli = split(spli.right, x + 1);
        root = merge(spli.left, ssli.right);
    }

    public void insert (int x) {
        Pair spli = split(root, x);
        root = merge(merge(spli.left, new Node(x)), spli.right);
    }

    public int size () {
        return sizeOf(root);
    }

    public boolean exists (int x) {
        try {
            return (next(x - 1) == x);
        } catch (NullPointerException e) {
            return false;
        }
    }

    public int next (int x) {
        Pair spli = split(root, x + 1);
        if (spli.right == null) {
            root = merge(spli.left, spli.right);
            throw new NullPointerException("There is no greater element in treap");
        } else {
            Node last = spli.right;
            while (last.left != null) {
                last = last.left;
            }
            root = merge(spli.left, spli.right);
            return last.x;
        }
    }

    public int prev (int x){
        Pair spli = split(root, x);
        if (spli.left == null) {
            root = merge(spli.left, spli.right);
            throw new NullPointerException("There is no lesser element in treap");
        } else {
            Node last = spli.left;
            while (last.right != null) {
                last = last.right;
            }
            root = merge(spli.left, spli.right);
            return last.x;
        }
    }

    public void moveToFront(int l, int r) {
        Pair spli = split(root, l - 1);
        Pair ssli = split(spli.right, r - l + 1);
        Node newNode = merge(ssli.left, spli.left);
        root = merge(newNode, ssli.right);
    }
    private String toString(Node node) {
        if (node == null) {
            return "";
        }
        return toString(node.left) + " " + node.x + " " + toString(node.right);
    }

    public String toString() {
        return toString(root);
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
        String name = "movetofront.";
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
        Treap tree = new Treap();
        int n = nextInt();
        int m = nextInt();
        for (int i = 1; i <= n; i++) {
            tree.insert(i);
        }
        for (int i = 1; i <= m; i++) {
            tree.moveToFront(nextInt(), nextInt());
        }
        out.println(tree);
    }
}

