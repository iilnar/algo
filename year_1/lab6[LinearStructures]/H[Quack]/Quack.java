import java.io.*;
import java.util.HashMap;
import java.util.StringTokenizer;;

/**
 * Created by Илнар on 17.03.2015.
 */

public class Quack {
    boolean eof;
    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    public static void main(String[] args) throws IOException {
        new Quack().run();
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
        String name = "quack.";
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

    void solve() throws IOException{
        String s;
        LinkedQueue queue = new LinkedQueue();
        Register register = new Register();
        int MODULE = 65536;
        String[] input = new String[1000010];
        int n = 0;
        HashMap map = new HashMap<String, Integer>();
        while (!eof) {
            input[n++] = nextLine();
            if (eof || input[n - 1] == null) {
                n--;
                break;
            }
            if (input[n - 1].charAt(0) == ':') {
                map.put(input[n - 1].substring(1), n - 1);
            }
        }
        int a, b;
        for (int i = 0; i < n; i++){
            s = input[i];
            switch (s.charAt(0)) {
                case '+':
                    queue.push((queue.pop() + queue.pop()) % MODULE);
                    break;
                case '-':
                    queue.push((MODULE + queue.pop() - queue.pop()) % MODULE);
                    break;
                case '*':
                    queue.push((int)(((long)queue.pop() * queue.pop()) % (long)MODULE));
                    break;
                case '/':
                    a = queue.pop();
                    b = queue.pop();
                    queue.push((b == 0) ?  (0) : ((a / b) % MODULE));
                    break;
                case '%':
                    a = queue.pop();
                    b = queue.pop();
                    queue.push((b == 0) ?  (0) : ((a % b) % MODULE));
                    break;
                case '>':
                    register.set(s.charAt(1), queue.pop());
                    break;
                case '<':
                    queue.push(register.get(s.charAt(1)));
                    break;
                case 'P':
                    out.println((s.length() == 1) ? (queue.pop()) : (register.get(s.charAt(1))));
                    break;
                case 'C':
                    out.print(Character.toChars(((s.length() == 1) ? (queue.pop()) : (register.get(s.charAt(1)))) % 256));
                    break;
                case ':':
                    break;
                case 'J':
                    i = ((Integer) map.get(s.substring(1))).intValue();
                    break;
                case 'Z':
                    if (register.get(s.charAt(1)) == 0) {
                        i = (((Integer) map.get(s.substring(2))).intValue());
                    }
                    break;
                case 'E':
                    i = (register.get(s.charAt(1)) == register.get(s.charAt(2))) ? (((Integer) map.get(s.substring(3))).intValue()) : i;
                    break;
                case 'G':
                    i = (register.get(s.charAt(1)) > register.get(s.charAt(2))) ? (((Integer) map.get(s.substring(3))).intValue()) : i;
                    break;
                case 'Q':
                    return;
                default:
                    queue.push(Integer.parseInt(s) % MODULE);
            }
        }
    }
}

class LinkedQueue{
    private int size;
    private   static class Node {
        int value;
        Node prev, next;
        public Node(Node prev, int value, Node next) {
            this.value = value;
            this.prev = prev;
            this.next = next;
        }
        public Node() {
        }
    }
    private Node head, tail;

    public void push(int element) {
        size++;
        final Node old = tail;
        final Node newNode = new Node(tail, element, null);
        tail = newNode;
        if (old == null) {
            head = newNode;
        } else {
            old.next = newNode;
        }
    }

    public int element() {
        assert size != 0;
        return head.value;
    }

    public int pop() {
        int res = element();
        Node next = head.next;
        head = next;
        size--;
        if (next == null) {
            tail = null;
        } else {
            head.prev = null;
        }
        return res;
    }

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public void clear() {
        while (!isEmpty()) {
            pop();
        }
    }
}

class Register {
    private int[] elements = new int[26];

    public void set(char i, int value) {
        elements[(int)i - 97] = value;
    }

    public int get(char i) {
        return elements[(int)i - 97];
    }
}