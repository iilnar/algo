import java.io.*;
import java.util.*;

import static java.lang.Math.sqrt;

public class ProbA {
    boolean eof;
    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    public static void main(String[] args) throws IOException {
        new ProbA().run();
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

    void run() throws IOException {
        InputStream input = System.in;
        PrintStream output = System.out;
        String name = "spantree";
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
        int n = nextInt();
        Vershina v[] = new Vershina[n];

        for (int i = 0; i < n; i++) {
            v[i] = new Vershina();
            v[i].x = nextInt();
            v[i].y = nextInt();
            v[i].number = i;
            if (v[i].x >= 0) {
                if (v[i].y >= 0) {
                    v[i].chetvert = 1;
                } else {
                    v[i].chetvert = 4;
                }
            }
            if (v[i].x < 0) {
                if (v[i].y >= 0) {
                    v[i].chetvert = 2;
                } else {
                    v[i].chetvert = 3;
                }
            }
            if (v[i].chetvert == 1) {
                v[i].ToNullX = v[i].x;
                v[i].ToNullY = v[i].y;
            }
            if (v[i].chetvert == 2) {
                v[i].ToNullX = v[i].x * (-1);
                v[i].ToNullY = v[i].y;
            }
            if (v[i].chetvert == 3) {
                v[i].ToNullX = v[i].x * (-1);
                v[i].ToNullY = v[i].y * (-1);
            }
            if (v[i].chetvert == 4) {
                v[i].ToNullX = v[i].x;
                v[i].ToNullY = v[i].y * (-1);
            }
            if (i != 0) {
                v[i].weight = Double.MAX_VALUE;
            }
            if (i == 0) {
                v[i].weight = 0;
            }
            v[i].color = false;

        }
        Vershina min = new Vershina();

        for (int j = 0; j < n; j++) {
            min.color=true;
            System.out.println(min.x);
            System.out.println(min.y);
            for (int i = 0; i < n; i++) {

                if (v[i] == min) {
                    continue;
                } else {
                    double k = v[i].weight;
                    v[i].weight = sqrt((min.x - v[i].x) * (min.x - v[i].x) + (min.y - v[i].y) * (min.y - v[i].y));
                    if (v[i].weight > k && k != 0) {
                        v[i].weight = k;
                    } else {
                        v[i].ToKey = min.number;
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                if (min.weight != 0 && v[i].weight < min.weight && !v[i].color) {
                    min = v[i];
                }
            }
        }
        double sum = 0;
        double bo = 0;
        for (int i = 0; i < n; i++) {
            sum = sum + v[i].weight;
            bo = Double.MAX_VALUE;
            if (bo > v[i].weight) {
                bo = v[i].weight;
            }
        }
        out.print(sum - bo);
    }


    public static class Vershina implements Comparable<Vershina> {
        int x;
        int y;
        int number;
        int chetvert;
        int ToNullX;
        int ToNullY;
        double weight;
        int ToKey;
        boolean color;

        public int compareTo(Vershina o) {
            if (weight > o.weight) {
                return 1;
            }
            if (weight == o.weight) {
                if (number > o.number) {
                    return 1;
                }
                if (number == o.number) {
                    return 0;
                }
                if (number < o.number) {
                    return -1;
                }
                return 0;
            }
            if (weight < o.weight) {
                return -1;
            }
            return 0;
        }


    }
}
