import java.io.*;
import java.util.StringTokenizer;

/**
 * Created by Ilnar on 26.04.2015.
 */

public class TaskB {
    boolean eof;
    
    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    public static void main(String[] args) throws IOException {
        new TaskB().run();
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
        String name = "dsu.";
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
        DSU dsu = new DSU(nextInt() + 1);
        for (String s = nextToken(); !eof; s = nextToken()) {
            switch (s) {
                case "union":
                    dsu.union(nextInt(), nextInt());
                    break;
                case "get":
                    out.println(dsu.get(nextInt()));
                    break;
            }
        }
    }
}

class DSU {
    int parent[], rank[], size[], min[], max[];

    public DSU(int n) {
        parent = new int[n];
        rank = new int[n];
        size = new int[n];
        min = new int[n];
        max = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
            size[i] = 1;
            min[i] = i;
            max[i] = i;
        }
    }

    public int findSet(int v) {
        return (parent[v] == v) ? v : (parent[v] = findSet(parent[v]));
    }

    public void union(int u, int v) {
        u = findSet(u);
        v = findSet(v);
        if (u != v) {
            if (rank[u] < rank[v]) {
                parent[u] = v;
                rank[v] += ((rank[u] == rank[v]) ? 1 : 0);
                size[v] = size[v] + size[u];
                min[v] = Math.min(min[v], min[u]);
                max[v] = Math.max(max[v], max[u]);
            } else {
                parent[v] = u;
                rank[u] += ((rank[u] == rank[v]) ? 1 : 0);
                size[u] = size[v] + size[u];
                min[u] = Math.min(min[v], min[u]);
                max[u] = Math.max(max[v], max[u]);
            }
        }
    }

    public String get(int v) {
        v = findSet(v);
        return min[v] + " " + max[v] +  " " + size[v];
    }
}
