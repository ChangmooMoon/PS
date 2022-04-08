package boj;
import java.io.*;

public class Q22859 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String s = br.readLine()
        .replaceAll("</?main>", "")
        .replaceAll("<div title=\"([\\w ]*)\">", "title : $1\n")
        .replaceAll("</div>", "")
        .replaceAll("<p>", "")
        .replaceAll("</p>", "\n")
        .replaceAll("</?[\\w ]*>", "")
        .replaceAll(" ?\n ?", "\n")
        .replaceAll(" {2,}", " ");

    System.out.println(s);
  }
}
// backreference