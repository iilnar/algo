import java.io.*;
import java.util.StringTokenizer;



public class TaskF {
    boolean eof;
    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    public static void main(String[] args) throws IOException {
        new TaskF().run();
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
        String name = "postfix";
        try {
            File f = new File(name + ".in");
            if (f.exists() && f.canRead()) {
                input = new FileInputStream(f);
                output = new PrintStream(name + ".out");
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
        LinkedStack stack = new LinkedStack();
        while (!eof) {
            String s = nextToken();
            if (eof) break;
            if (s.equals("+")) {
                stack.push(stack.pop() + stack.pop());    
            } else if (s.equals("-")) {
                stack.push(-stack.pop() + stack.pop());
            } else if (s.equals("*")) {
                stack.push(stack.pop() * stack.pop());
            } else {
                stack.push(Integer.parseInt(s));
            }
        }     
        out.println(stack.top());
    }
}

class LinkedStack {
    private class Node {
        Node prev;
        int value;

        public Node(Node prev, int value) {
            this.prev = prev;
            this.value = value;
        }

        public Node() {}
    }
    private int size;
    private Node head;

    public void push(int o) {
        head = new Node(head, o);
        size++;
    }

    public int top() {
        assert size != 0;
        return head.value;
    }

    public int pop() {
        int ret = top();
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
}