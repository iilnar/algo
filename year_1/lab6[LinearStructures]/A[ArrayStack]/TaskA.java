import java.io.*;
import java.util.StringTokenizer;

/**
 * Created by Ilnar on 31.03.2015.
 */


public class TaskA {
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
        String name = "stack1.";
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
        ArrayStack stack = new ArrayStack();
        String c;
        for (int i = 0; i < n; i++) {
            c = nextToken();
            if (c.equals("+")) {
                stack.push(nextInt());
            } else {
                out.println(stack.pop());
            }
        }

    }
}

class ArrayStack {
    private int[] elements = new int[4];
    private int size;
    private Vector vec = new Vector();

    void ensureCapacity() {
        if (size == elements.length) {
            int[] newElements = new int[size * 2];
            for (int i = 0; i < size; i++) {
                newElements[i] = elements[i];
            }
            elements = newElements;
        }
    }

    public void push(int o) {
        ensureCapacity();
        elements[size++] = o;
    }

    public int top() {
        assert size != 0;
        return elements[size - 1];
    }

    public int pop() {
        assert size != 0;
        int ret = top();
        elements[--size] = 0;
        return ret;
    }

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public void clear() {
        elements = new int[8];
        size = 0;
    }
}
