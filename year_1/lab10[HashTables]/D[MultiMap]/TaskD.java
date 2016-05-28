import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

/**
 * Created by Ilnar Sabirzyanov on 26.05.2015.
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
        String name = "multimap.";
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
        HashTable table = new HashTable(1_000_000);
        for (String token = nextToken(); !eof && !token.equals("end"); token = nextToken()) {
            switch (token) {
                case "put":
                    table.insert(nextToken(), nextToken());
                    break;
                case "delete":
                    table.delete(nextToken(), nextToken());
                    break;
                case "deleteall":
                    table.deleteAll(nextToken());
                case "get":
                    table.get(nextToken());
            }
        }
    }
    class HashTable {
        class Pair {
            String key, value;
            Pair() {}
            Pair (String key, String value) {
                this.key = key;
                this.value = value;
            }
        }

        ArrayList<Pair>[] arr;

        HashTable(int n) {
            arr = new ArrayList[n];
            for (int i = 0; i < n; i++) {
                arr[i] = new ArrayList<>(0);
            }
        }

        int getHash (String s) {
            int res = 0;
            int koff = 37;
            for (int i = 0; i < s.length(); i++) {
                res = res * koff + (Character.getNumericValue(s.charAt(i)));
            }
            return Math.abs(res) % arr.length;
        }

        void get (String v) {
            int hs = getHash(v);
            int cnt = 0;
            for (int i = 0; i < arr[hs].size(); i++) {
                if (arr[hs].get(i).key.equals(v)) {
                    cnt++;
                }
            }
            out.print(cnt);
            for (int i = 0; i < arr[hs].size(); i++) {
                if (arr[hs].get(i).key.equals(v)) {
                    out.print(" " + arr[hs].get(i).value);
                }
            }
            out.println("");
        }

        void insert (String x, String y) {
            int hs = getHash(x);
            for (int i = 0; i < arr[hs].size(); i++) {
                if (arr[hs].get(i).key.equals(x) && arr[hs].get(i).value.equals(y)) {
                    return;
                }
            }
            arr[hs].add(arr[hs].size(), new Pair(x, y));
        }

        void delete (String x, String y) {
            int hs = getHash(x);
            for (int i = 0; i < arr[hs].size(); i++) {
                if (arr[hs].get(i).key.equals(x) && arr[hs].get(i).value.equals(y)) {
                    arr[hs].remove(i);
                    i--;
                }
            }
        }

        void deleteAll (String x) {
            int hs = getHash(x);
            for (int i = 0; i < arr[hs].size(); i++) {
                if (arr[hs].get(i).key.equals(x)) {
                    arr[hs].remove(i);
                    i--;
                }
            }
        }
    }
}


