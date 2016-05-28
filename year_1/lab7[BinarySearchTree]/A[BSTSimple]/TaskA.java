import java.io.*;
import java.util.StringTokenizer;

/**
 * Created by Илнар on 12.04.2015.
 */
public class TaskA {
    final int bad = 1_000_000_001;
    boolean eof;
    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    public static void main(String[] args) throws IOException {
        new TaskA().run();
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
        String name = "bstsimple.";
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
        BST tree = new BST();
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
                    out.println(tree.exist(k));
                    break;
                case "next":
                    k = tree.next(k);
                    out.println((k != bad) ? k : "none");
                    break;
                case "prev":
                    k = tree.prev(k);
                    out.println((k != -bad) ? k : "none");
                    break;
            }
        }
    }
}
class BST {
    final int bad = 1_000_000_001;

    private class Node {
        private Node left, right, parent;
        private int value;

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

    public boolean exist(int value) {
        return (exist(head, value) != null);
    }

    private int min(Node node) {
        return (node.left == null) ? node.value : min(node.left);
    }

    public int min () {
        return min(head);
    }

    private int max(Node node) {
        return (node.right == null) ? node.value : max(node.right);
    }

    public int max() {
        return max(head);
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

    public void delete(int key) {
        delete(head, key);
    }
}
