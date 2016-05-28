import java.io.*;
import java.util.Random;
import java.util.StringTokenizer;

/**
 * Created by Илнар on 17.03.2015.
 */
public class NetBuild {

    boolean eof;
    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    public static void main(String[] args) throws IOException {
        new NetBuild().run();
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
        String name = "netbuild.";
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

    public void solve() {
        int layerCnt = 10;
        String str = "8 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 " +
                "8 1 3 2 4 5 7 6 8 9 11 10 12 13 15 14 16 " +
                "8 1 5 2 6 3 7 4 8 9 13 10 14 11 15 12 16 " +
                "8 1 9 2 10 3 11 4 12 5 13 6 14 7 15 8 16 " +
                "7 2 3 4 13 14 15 5 9 6 11 7 10 8 12 " +
                "7 2 5 12 15 3 9 8 14 4 10 6 13 7 11 " +
                "6 3 5 4 6 7 9 8 10 11 13 12 14 " +
                "4 4 7 6 9 8 11 10 13 " +
                "5 4 5 6 7 8 9 10 11 12 13 ";
        StringTokenizer st = new StringTokenizer(str);
        int n = nextInt();
        Pair[][] arr = new Pair[10][8];
        int[] arr2 = new int[10];
        int ans = 0;
        for (int i = 0; i < 9; i++) {
            int cnt = Integer.parseInt(st.nextToken());
            arr2[i] = 0;
            for (int p = 0; p < cnt; p++) {
                arr[i][arr2[i]] = new Pair(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
                if (arr[i][arr2[i]].x <= n && arr[i][arr2[i]].y <= n) {
                    arr2[i]++;
                }
            }
            ans += arr2[i];
        }
        out.println(n + " " + ans + " " + 9);
        for (int i = 0; i < 9; i++) {
            out.print(arr2[i] + " ");
            for (int j = 0; j < arr2[i]; j++) {
                out.print(arr[i][j].x + " " + arr[i][j].y + " ");
            }
            out.println();
        }

    }
}

class Pair {
    int x, y;
    public Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

