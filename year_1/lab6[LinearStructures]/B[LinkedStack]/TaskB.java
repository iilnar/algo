import java.io.*;
import java.util.StringTokenizer;

/**
 * Created by Илнар on 31.03.2015.
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
        String name = "stack2.";
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
        LinkedStack stack = new LinkedStack();
        for (int i = 0; i < n; i++) {
            String c = nextToken();
            if (c.equals("+")) {
                stack.push(nextInt());
            } else {
                out.println(stack.pop());
            }
        }
     
    }
}

class LinkedStack {
    private class Node {
        Node prev;
        Object value;

        public Node(Node prev, Object value) {
            this.prev = prev;
            this.value = value;
        }

        public Node() {}
    }
    private int size;
    private Node head;

    public void push(Object o) {
        head = new Node(head, o);
        size++;
    }

    public Object top() {
        assert size != 0;
        return head.value;
    }

    public Object pop() {
        Object ret = top();
        head = head.prev;
        size--;
        return ret;
    }

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public void clear() {
        head = null;
        size = 0;
    }

    public LinkedStack makeCopy() {
        LinkedStack copy = new LinkedStack();
        copy.head = head;
        copy.size = size;
        return copy;
    }

}