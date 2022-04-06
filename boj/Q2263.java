package boj;
import java.io.*;
import java.util.*;

// 트리 순회 방식 // preorder루왼오 inorder왼루오 postorde왼오루
public class Q2263 {
    static int[] in = new int[100001]; 
    static int[] post = new int[100001];
    static int[] idx = new int[100001]; 
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int n = Integer.parseInt(br.readLine());
    StringTokenizer st = new StringTokenizer(br.readLine());
    for(int i = 0; i < n; ++i) {
        in[i] = Integer.parseInt(st.nextToken());
        idx[in[i]] = i;
    }
    st = new StringTokenizer(br.readLine());
    for(int i = 0; i < n; ++i) {
        post[i] = Integer.parseInt(st.nextToken());
    }

    go(0, n - 1, 0, n - 1);
  }

  static void go(int inStart, int inEnd, int postStart, int postEnd) { // preorder 루왼오
      if(inStart > inEnd || postStart > postEnd) return;

      int root = post[postEnd];
      int rootIdx = idx[root];
      int leftLen = rootIdx - inStart;

      System.out.printf("%d ", root);
      go(inStart, rootIdx - 1, postStart, postStart + leftLen - 1);
      go(rootIdx + 1, inEnd, postStart + leftLen, postEnd - 1);
  }
}
