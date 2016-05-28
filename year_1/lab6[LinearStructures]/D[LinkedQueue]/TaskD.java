import java.io.*;
import java.util.StringTokenizer;

/**
 * Created by Илнар on 31.03.2015.
 */


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
        String name = "queue2.";
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
        LinkedQueue queue = new LinkedQueue();
        for (int i = 0; i < n; i++) {
            String c = nextToken();
            if (c.equals("+")) {
                queue.push(nextInt());
            } else {
                out.println(queue.pop());
            }
        }
     
    }
}


class LinkedQueue {
    private int size = 0;

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public void clear() {
        while (!isEmpty()) {
            pop();
        }
    }

    private static class Node {
        Object value;
        Node prev, next;
        public Node(Node prev, Object value, Node next) {
            this.value = value;
            this.prev = prev;
            this.next = next;
        }
        public Node() {
        }
    }
    private Node head, tail;

    public void push(Object element) {
        size++;
        final Node old = tail;
        final Node newNode = new Node(tail, element, null);
        tail = newNode;
        if (old == null) {
            head = newNode;
        } else {
            old.next = newNode;
        }
    }
    //size = size' + 1 && tail.value = element

    //!isEmpty()
    public Object front() {
        assert size != 0;
        return head.value;
    }
    //result = head.value

    //!isEmpty()
    public Object pop() {
        Object res = front();
        Node next = head.next;
        head = next;
        size--;
        if (next == null) {
            tail = null;
        } else {
            head.prev = null;
        }
        return res;
    }
    //size = size' - 1 && result  = head.value && head = head'.next 

    public LinkedQueue emptyCopy() {
        return new LinkedQueue();
    }
}