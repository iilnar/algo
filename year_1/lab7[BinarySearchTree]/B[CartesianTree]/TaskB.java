import java.io.*;
import java.util.Random;
import java.util.StringTokenizer;

/**
 * Created by Илнар on 26.04.2015.
 */

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
        String name = "bst.";
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
        String st;
        int k;
        while (!eof) {
            st = nextToken();
            if (eof) {
                break;
            }
            k = nextInt();
            switch (st) {
                case "insert":
                    tree.insert(k);
                    break;
                case "delete":
                    tree.delete(k);
                    break;
                case "exists":
                    out.println(tree.exists(k));
                    break;
                case "next":
                    try {
                        out.println(tree.next(k));
                    } catch (NullPointerException e) {
                        out.println("none");
                    }
                    break;
                case "prev":
                    try {
                        out.println(tree.prev(k));
                    } catch (NullPointerException e) {
                        out.println("none");
                    }
            }
        }
    }
}



class Tree23 {
    final int bad = 1_000_000_001;

    private class Node {
        private Node left, right, parent, med;
        private int value;
        private boolean isLeaf;

        public Node(Node left, Node right, Node parent, int value) {
            this.left = left;
            this.right = right;
            this.value = value;
            this.parent = parent;
        }

        public Node() {}
    }

    private Node head;

    private void insert(Node node, int value) {
        if (node.value == value) {
            return;
        }
        if (value < node.value) {
            if (node.left != null) {
                insert(node.left, value);
            } else {
                node.left = new Node(null, null, node, value);
            }
        } else {
            if (node.right != null) {
                insert(node.right, value);
            } else {
                node.right = new Node(null, null, node, value);
            }
        }
    }

    public void insert(int value) {
        if (head == null) {
            head = new Node(null, null, null, value);
        } else {
            insert(head, value);
        }
    }

    private Node exist(Node node, int x) {
        if (node == null) {
            return null;
        }
        if (node.value == x) {
            return node;
        }
        if (node.value < x) {
            return exist(node.right, x);
        } else {
            return exist(node.left, x);
        }
    }
    private int next(Node node, int x) {
        if (node == null) {
            return bad;
        }
        if (node.value <= x) {
            return next(node.right, x);
        } else {
            return Math.min(node.value, next(node.left, x));
        }
    }

    public int next(int x) {
        return next(head, x);
    }

    private int prev(Node node, int x) {
        if (node == null) {
            return -bad;
        }
        if (node.value < x) {
            return Math.max(node.value, prev(node.right, x));
        } else {
            return prev(node.left, x);
        }
    }

    public int prev (int x) {
        return prev(head, x);
    }

    void replace(Node a, Node b) {
        if (a.parent == null) {
            head = b;
        } else if (a == a.parent.left) {
            a.parent.left = b;
        } else {
            a.parent.right = b;
        }
        if (b != null) {
            b.parent = a.parent;
        }
    }

    void delete(Node t, int key) {
        if (t == null) {
            return;
        }
        if (key < t.value) {
            delete(t.left, key);
        } else if (key > t.value) {
            delete(t.right, key);
        } else if (t.left != null && t.right != null) {
            Node m = t.right;
            while (m.left != null) {
                m = m.left;
            }
            t.value = m.value;
            t.value = m.value;
            replace(m, m.right);
        } else if (t.left != null) {
            replace(t, t.left);
        } else if (t.right != null) {
            replace(t, t.right);
        } else {
            replace(t, null);
        }
    }
} class Treap {
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

    private Node root = null;

    private int sizeOf (Node node) {
        return node == null ? 0 : node.size;
    }

    private Pair split (Node node, int x) {
        if (node == null) {
            return new Pair(null, null);
        }
        if (x <= node.x) {
            Pair spli = split(node.left, x);
            node.left = spli.right;
            node.recalc();
            spli.right = node;
            return spli;
        } else {
            Pair spli = split(node.right, x);
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
}