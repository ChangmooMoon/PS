import java.io.*;
import java.util.*;

public class Q1168 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine(), " ");
    StringBuilder sb = new StringBuilder("<");

    int n, k;
    n = Integer.parseInt(st.nextToken());
    k = Integer.parseInt(st.nextToken());

    Queue<Integer> q = new LinkedList<>();
    for(int i = 1; i <= n; ++i) {
        q.add(i);
    }

    while(q.size() != 1) {
        for(int i = 1; i < k; ++i) {
            q.add(q.poll());
        }
        sb.append(q.poll() + ", ");
    }

    sb.append(q.poll() + ">");
    System.out.println(sb);
  }
}
