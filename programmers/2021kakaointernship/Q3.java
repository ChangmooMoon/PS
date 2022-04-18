import java.util.*;

class Solution {
    public String solution(int n, int k, String[] cmd) {
        Node head = null;
        Node tail = null;
        Node cursor = null;
        Stack<Node> st = new Stack<>();

        for (int i = 0; i < n; ++i) {
            if (head == null) {
                head = new Node(i, null, null);
                tail = head;
            } else {
                tail.next = new Node(i, tail, null);
                tail = tail.next;
            }
            if (i == k)
                cursor = tail;
        }

        for (String c : cmd) {
            char ch = c.charAt(0);

            if (ch == 'U' || ch == 'D') {
                int jump = Integer.parseInt(c.substring(2));

                if (ch == 'U') {
                    while (jump-- > 0 && cursor.prev != null) {
                        cursor = cursor.prev;
                    }
                } else if (ch == 'D') {
                    while (jump-- > 0 && cursor.next != null) {
                        cursor = cursor.next;
                    }
                }
            } else if (ch == 'C') { // 선택행 삭제, 바로 아래행 선택, 삭제된 행이 tail이면 윗행 선택
                st.push(cursor);
                if (tail == cursor) { // tail이면
                    tail = tail.prev;
                    tail.next = null;
                    cursor = tail;
                } else { // tail 아니면
                    if (cursor.prev != null)
                        cursor.prev.next = cursor.next;
                    cursor.next.prev = cursor.prev;
                    cursor = cursor.next;
                }
            } else if (ch == 'Z') { // 가장 최근 삭제행 복구
                Node node = st.pop();

                if (node.prev != null)
                    node.prev.next = node;
                else
                    head = node;

                if (node.next != null)
                    node.next.prev = node;
                else
                    tail = node;
            }
        }

        StringBuilder sb = new StringBuilder("O".repeat(n));
        while (!st.isEmpty()) {
            Node cur = st.pop();
            sb.setCharAt(cur.idx, 'X');
        }

        return sb.toString();
    }

    class Node {
        int idx;
        Node prev;
        Node next;

        Node(int idx, Node prev, Node next) {
            this.idx = idx;
            this.prev = prev;
            this.next = next;
        }
    }
}
