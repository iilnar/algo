import java.io.*;
import java.util.StringTokenizer;

/**
 * Created by Илнар on 31.03.2015.
 */


public class TaskG {
    boolean eof;
    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    public static void main(String[] args) throws IOException {
        new TaskG().run();
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
        String name = "queuemin2.";
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
        int n = nextInt(), m = nextInt(), k = nextInt();
        int a = nextInt(), b = nextInt(), c = nextInt();
        long ans = 0;
        int[] arr = new int[k + 1];
        ArrayQueue queue = new ArrayQueue();
        for (int i = 1; i <= k; i++) {
            arr[i] = nextInt();
        }
        int x0 = arr[k - 1];
        int x1 = arr[k], x2;
        int y0 = 0, y1 = 0, y2 = 0;
        for (int i = 1; i <= n; i++) {
            x2 = (i <= k) ? (arr[i]) : (a * x0 + b * x1 + c);
            x0 = x1;
            x1 = x2;
            queue.push(x2);
            if (i >= m) {
                y2 = (i - m  + 1 <= k) ? (arr[i - m + 1]) : (a * y0 + b * y1 + c);
                y0 = y1;
                y1 = y2;                 
                ans += queue.top();
                if (y2 == queue.top()) {
                    queue.pop();
                }                
            }
        }
        out.println(ans);
    }
}

class Pair {
    int x, y;
    public Pair(){}

    public Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

class LinkedStack {
    private class Node {
        Node prev;
        Pair value;

        public Node(Node prev, int value) {
            this.prev = prev;
            this.value = new Pair(value, (size == 0) ? (value) : (Math.min(value, prev.value.y)));
        }

        public Node(Node prev, Pair value) {
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
        return head.value.x;
    }

    public int min() {
        assert size != 0;
        return head.value.y;
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
}

class LinkedQueue {
    private LinkedStack st1 = new LinkedStack(), st2 = new LinkedStack();

    public void push(int o) {
        st1.push(o);
    }

    public int min() {
        if (st1.isEmpty() || st2.isEmpty()) {
            return (st1.isEmpty()) ? (st2.min()) : (st1.min());
        } else {
            return Math.min(st1.min(), st2.min());
        }
    }

    public void pop() {
        if (st2.isEmpty()) {
            while (!st1.isEmpty()) {
                st2.push(st1.pop());
            }
        }
        st2.pop();
    }
} 

class ArrayQueue {
    private int[] arr;
    private int left, right;

    public ArrayQueue() {
        left = 0;
        right = 0;
        arr = new int[30000010];
    }

    public void push(int o) {
        while (left <= right - 1 && o < arr[right - 1]) {
            right--;
        }
        arr[right++] = o;
    }

    public int top() {
        return arr[left];
    }

    public void pop() {
        left++;
    }
}