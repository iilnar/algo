import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * Created by Илнар on 26.04.2015.
 */

class Heap {
    class Pair {
        private int x, id;
        Pair() {}

        Pair(int x, int id) {
            this.x = x;
            this.id = id;
        }
    }

    private Pair[] arr = new Pair[1];
    private int pos[] = new int[100_001];
    private int size = 0;

    public Heap() {
        for (int i = 0; i < 100_001; i++) {
            pos[i] = -1;
        }
    }

    private void swap(int i, int j) {
        Pair temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        int t = pos[arr[i].id];
        pos[arr[i].id] = pos[arr[j].id];
        pos[arr[j].id] = t;
    }

    private void siftUp(int v) {
        while (v > 0 && arr[(v - 1) / 2].x > arr[v].x) {
            swap(v, (v - 1) / 2);
            v = (v - 1) / 2;
        }
    }

    private void siftDown(int v) {
        while (v * 2 + 2 <= size && arr[v].x > Math.min(arr[v * 2 + 1].x, arr[v * 2 + 2].x)) {
            if (arr[v * 2 + 1].x > arr[v * 2 + 2].x) {
                swap(v, v * 2 + 2);
                v = v * 2 + 2;
            } else {
                swap(v, v * 2 + 1);
                v = v * 2 + 1;
            }
        }
    }

    private void ensureCapacity() {
        if (size == arr.length) {
            Pair[] newArray = new Pair[size * 2 + 1];
            Arrays.fill(newArray, new Pair(Integer.MAX_VALUE, 0));
            System.arraycopy(arr, 0, newArray, 0, size);
            arr = newArray;
        }
    }

    public void add(int x, int p) {
        ensureCapacity();
        arr[size] = new Pair(x, p);
        pos[p] = size;
        siftUp(size++);
    }

    public int min() {
        assert size != 0;
        return arr[0].x;
    }

    public int removeMin() {
        assert size > 0;
        int res = min();
        pos[arr[0].id] = -1;
        arr[0] = arr[--size];
        pos[arr[0].id] = 0;
        arr[size] = new Pair(Integer.MAX_VALUE, 0);
        siftDown(0);
        return res;
    }

    public void decreaseKey(int p, int val) {
        arr[pos[p]].x = val;
        siftUp(pos[p]);
        siftDown(pos[p]);
    }

    public String toString() {
        String s = "";
        for (int i = 0; i < size; i++) {
            s = s + ((i == 0) ? "" : " ") + arr[i];
        }
        return s;
    }

    public int size() {
        return size;
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
        String name = "priorityqueue.";
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
        Heap heap = new Heap();
        int i = 1;
        for (String s = nextToken(); !eof; s = nextToken(), i++) {
            switch (s) {
                case "push":
                    heap.add(nextInt(), i);
                    break;
                case "extract-min":
                    if (heap.size() == 0) {
                        out.println("*");
                    } else {
                        out.println(heap.removeMin());
                    }
                    break;
                case "decrease-key":
                    heap.decreaseKey(nextInt(), nextInt());
                    break;
            }
        }
    }
}

