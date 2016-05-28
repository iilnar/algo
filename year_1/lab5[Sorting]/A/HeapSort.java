import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class HeapSort {

    boolean eof;
    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    public static void main(String[] args) throws IOException {
        new HeapSort().run();
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
        String name = "sort.";
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
        int a[] = new int[n];
        Heap heap = new Heap();
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
            heap.add(a[i]);
        }
        for (int i = n - 1; i >= 0; i--) {
            a[i] = heap.removeMax();
        }
        for (int i = 0; i < n; i++) {
            out.print(a[i] + " ");
        }
        out.println("");
        
    }
}
    class Heap {
        private int[] arr = new int[1];
        private int size = 0;

        private void siftUp(int v) {
            while (v > 0 && arr[(v - 1) / 2] < arr[v]) {
                int temp = arr[(v - 1) / 2];
                arr[(v - 1) / 2] = arr[v];
                arr[v] = temp;
                v = (v - 1) / 2;
            }
        }

        private void siftDown(int v) {
            while (v * 2 + 2 <= size && arr[v] < Math.max(arr[v * 2 + 1], arr[v * 2 + 2])) {
                if (arr[v * 2 + 1] < arr[v * 2 + 2]) {
                    int temp = arr[v];
                    arr[v] = arr[v * 2 + 2];
                    arr[v * 2 + 2] = temp;
                    v = v * 2 + 2;
                } else {
                    int temp = arr[v];
                    arr[v] = arr[v * 2 + 1];
                    arr[v * 2 + 1] = temp;
                    v = v * 2 + 1;
                }     
            }
        }

        private void ensureCapacity() {
            if (size == arr.length) {
                int[] newArray = new int[size * 2];
                Arrays.fill(newArray, Integer.MIN_VALUE);
                for (int i = 0; i < size; i++) {
                    newArray[i] = arr[i];
                }
                arr = newArray;
            }
        }

        public void add(int x) {
            ensureCapacity();
            arr[size] = x;
            siftUp(size++);
        }

        public int max() {
            assert size != 0;
            return arr[0];
        }

        public int removeMax() {
            int res = max();
            arr[0] = arr[--size];
            arr[size] = Integer.MIN_VALUE;
            siftDown(0);
            return res;
        }

        public String toString() {
            String s = "";
            for (int i = 0; i < size; i++) {
                s = s + " " + arr[i];
            }
            return s;
        }
    }
