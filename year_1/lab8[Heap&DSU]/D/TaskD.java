import java.io.*;
import java.util.StringTokenizer;

/**
 * Created by Илнар on 26.04.2015.
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
        String name = "parking";
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
        int n = nextInt(), k;
        DSU dsu = new DSU(n);
        for (int i = 1; i <= n; i++) {
            k = dsu.findSet(nextInt() - 1);
            out.print((k + 1) + " ");
            dsu.union(k, (k + 1) % n);
        }
    }
}

class DSU {
    int parent[];

    public DSU(int n) {
        parent = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    public int findSet(int v) {
        return (parent[v] == v) ? v : (parent[v] = findSet(parent[v]));
    }

    public void union(int u, int v) {
        u = findSet(u);
        v = findSet(v);
        if (u != v) {
            parent[u] = v;
        }
    }
}

