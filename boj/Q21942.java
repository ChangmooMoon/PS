package boj;
import java.io.*;
import java.util.*;

public class Q21942{
    static int[] monthDay = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    static int N, L, F;
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String[] s = br.readLine().split(" ");

    N = Integer.parseInt(s[0]);
    L += Integer.parseInt(s[1].substring(0, 3)) * 60 * 24;
    L += Integer.parseInt(s[1].substring(4, 6)) * 60;
    L += Integer.parseInt(s[1].substring(7, 9));
    F = Integer.parseInt(s[2]);
    
    Map<String, Integer> record = new HashMap<>(); // id+parts, time
    Map<String, Long> fine = new HashMap<>(); // id, fine

    for(int i = 0; i < N; ++i) { // 80000
        String[] info = br.readLine().split(" ");

        int t = tParse(info[0], info[1]);
        String parts = info[2];
        String id = info[3];

        if(!record.containsKey(id + parts)) {
            record.put(id + parts, t);
        } else {
            int t2 = record.get(id + parts);
            
            if(t - t2 > L) fine.put(id, fine.getOrDefault(id, 0L) + (t - t2 - L) * F);
            record.remove(id + parts);
        }
    }

    if(fine.isEmpty()) {
        System.out.print(-1);
        return;
    }

    List<String> list = new ArrayList<>(fine.keySet());
    Collections.sort(list);
    StringBuilder sb = new StringBuilder();
    for(String id: list) {
        sb.append(id).append(" ").append(fine.get(id)).append("\n");
    }
    System.out.println(sb);
  }

  static int tParse(String date, String time) {
        int ret = 0;
        int M = Integer.parseInt(date.substring(5, 7));
        int D = Integer.parseInt(date.substring(8, 10));
        int H = Integer.parseInt(time.substring(0, 2));
        int m = Integer.parseInt(time.substring(3, 5));
        
        for(int i = 1; i < M; ++i) {
            ret += monthDay[i] * 24 * 60;
        }
        return ret += D * 24 * 60 + H * 60 + m;
  }
}
