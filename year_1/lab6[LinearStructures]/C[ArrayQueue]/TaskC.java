import java.io.*;
import java.util.StringTokenizer;

/**
 * Created by Илнар on 31.03.2015.
 */


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
        String name = "queue1.";
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
        ArrayQueue queue = new ArrayQueue();
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


class ArrayQueue {
    private int size = 8, head = 0, tail = 0;
    private int[] elements = new int[8];
    private Vector vec = new Vector();

    private void ensureCapacity() {
        if ((tail + 1) % size == head) {
            int[] newElements = new int[size * 2];
            for (tail = 0; tail < size; tail++) {
                newElements[tail] = elements[(tail + head) % size];
            }
            tail = size - 1;
            head = 0;
            size *= 2;
            elements = newElements;
        }
    }

    public void push(int element) {
        ensureCapacity();
        elements[tail] = element;
        tail = (tail + 1) % size;
        
    }                             

    public Object top() {
        assert !isEmpty();
        return elements[head];
    }

    public Object pop() {
        assert !isEmpty();
        int res = elements[head];
        elements[head] = 0;
        head = (head + 1) % size;
        return res;
    }

    public int size() {
        return (head <= tail) ? tail - head : size - head + tail;
    }
    
    public boolean isEmpty() {
        return head == tail;
    }

    public void clear() {
        for (int i = 0; i < size; i++) {
            elements[i] = 0;
        }
        head = 0;
        tail = 0;
    }
}

class Vector {
    int[] elem = new int[1];
}