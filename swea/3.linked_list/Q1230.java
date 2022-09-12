import java.io.*;
import java.util.*;

public class Q1230 {
  static List<Integer> list;

  public static void main(String[] args) throws IOException {
    // Scanner sc = new Scanner(new FileReader("./input.txt"));
    Scanner sc = new Scanner(System.in);
    StringBuilder sb = new StringBuilder();

    for (int t = 1; t <= 10; ++t) {
      sb.append("#").append(t).append(" ");
      list = new LinkedList<>();
      int n = sc.nextInt();

      for (int i = 0; i < n; ++i) {
        list.add(sc.nextInt());
      }

      int m = sc.nextInt();
      for (int i = 0; i < m; ++i) {
        char ch = sc.next().charAt(0);
        int x, y;
        if (ch == 'I') { // x,y,s // 앞에서부터
          x = sc.nextInt();
          y = sc.nextInt();
          for (int j = x; j < x + y; ++j) {
            list.add(j, sc.nextInt());
          }
        } else if (ch == 'D') { // x,y
          x = sc.nextInt();
          y = sc.nextInt();
          for (int j = 0; j < y; ++j) {
            list.remove(x);
          }
        } else if (ch == 'A') {
          y = sc.nextInt();
          for (int j = 0; j < y; ++j) {
            list.add(sc.nextInt());
          }
        }
      }
      for (int j = 0; j < 10; ++j) {
        sb.append(list.get(j)).append(" ");
      }
      sb.append("\n");
    }
    System.out.println(sb);
  }
}