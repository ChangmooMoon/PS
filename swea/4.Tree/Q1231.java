
// 완전이진트리를 배열로 표현해본 문제. 중위순회
import java.util.*;

public class Q1231 {
    static char[] tree;
    static int size;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        StringTokenizer st;

        for (int t = 1; t <= 10; ++t) {
            size = sc.nextInt();
            sc.nextLine();
            tree = new char[101];

            for (int i = 1; i <= size; ++i) {
                st = new StringTokenizer(sc.nextLine(), " ");
                st.nextToken();
                tree[i] = st.nextToken().charAt(0);
            }

            sb.append("#").append(t).append(' ');
            inorder_traverse(1);
            sb.append("\n");
        }
        System.out.println(sb);
        sc.close();
    }

    static void inorder_traverse(int curr) {
        if (curr > size)
            return;

        inorder_traverse(curr * 2);
        sb.append(tree[curr]);
        inorder_traverse(curr * 2 + 1);
    }
}
