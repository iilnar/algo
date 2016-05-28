import java.io.*;
import java.util.StringTokenizer;

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
        String name = "brackets";
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
        abc:
        while (!eof) {
            String s = nextToken();
            LinkedStack stack = new LinkedStack();
            if (eof) break;
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == '(' || s.charAt(i) == '[') {
                    stack.push(s.charAt(i));
                }
                if (s.charAt(i) == ')') {
                    if (!stack.isEmpty() && stack.top() == '(') {
                        stack.pop();
                    } else {
                        out.println("NO");
                        continue abc;
                    }

                }
                if (s.charAt(i) == ']') {
                    if (!stack.isEmpty() && stack.top() == '[') {
                        stack.pop();
                    } else {
                        out.println("NO");
                        continue abc;
                    }

                }
              }
            if (stack.isEmpty()) {
                out.println("YES");
            } else {
                out.println("NO");
            }
        }     
    }
}

class LinkedStack {
    private class Node {
        Node prev;
        char value;

        public Node(Node prev, char value) {
            this.prev = prev;
            this.value = value;
        }

        public Node() {}
    }
    private int size;
    private Node head;

    public void push(char o) {
        head = new Node(head, o);
        size++;
    }

    public char top() {
        assert size != 0;
        return head.value;
    }

    public char pop() {
        char ret = top();
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
