import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

/**
 * Created by Ilnar Sabirzyanov on 26.05.2015.
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
        String name = "set.";
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
        String token;
        int value;
        HashTable table = new HashTable(1_000_000);
        for (token = nextToken(), value = nextInt(); !eof; token = nextToken(), value = nextInt()) {
            switch (token) {
                case "insert":
                    table.insert(value);
                    break;
                case "delete":
                    table.delete(value);
                    break;
                case "exists":
                    out.println(table.exist(value));
            }
        }
    }
}

class HashTable {
    class Pair {
        int key;
        boolean value;
        Pair() {}
        Pair (int key) {
            this.key = key;
            this.value = true;
        }
    }

    ArrayList<Pair>[] arr;

    HashTable(int n) {
        arr = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            arr[i] = new ArrayList<>(0);
        }
    }

    int getHash (int v) {
        return Math.abs(v) % arr.length;
    }

    boolean exist (int v) {
        int hs = getHash(v);
        if (arr[hs] == null) return false;
        for (int i = 0; i < arr[hs].size(); i++) {
            if (arr[hs].get(i).key == v) {
                return true;
            }
        }
        return false;
    }

    void insert (int v) {
        if (exist(v)) {
            return;
        }
        int hs = getHash(v);
        arr[hs].add(arr[hs].size(), new Pair(v));
    }

    void delete (int v) {
        int hs = getHash(v);
        if (arr[hs] == null) return;
        for (int i = 0; i < arr[hs].size(); i++) {
            if (arr[hs].get(i).key == v) {
                arr[hs].remove(i);
                return;
            }
        }
    }
}
