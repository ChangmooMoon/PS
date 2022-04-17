import java.util.*;

class Solution {
    public String solution(int n, int k, String[] cmd) {
        Stack<Node> st = new Stack<>();
        LinkedList list = new LinkedList();

        for (int i = 0; i < n; ++i) {
            if (list.head == null) {
                list.head = new Node(i, null, null);
                list.tail = list.head;
            } else {
                list.tail.next = new Node(i, list.tail, null);
                list.tail = list.tail.next;
            }
            if (i == k)
                list.cursor = list.tail;
        }

        for (String c : cmd) {
            char ch = c.charAt(0);

            if (ch == 'U' || ch == 'D') {
                int jump = Integer.parseInt(c.substring(2));

                if (ch == 'U') {
                    while (jump-- > 0 && list.cursor.prev != null) {
                        list.cursor = list.cursor.prev;
                    }
                } else if (ch == 'D') {
                    while (jump-- > 0 && list.cursor.next != null) {
                        list.cursor = list.cursor.next;
                    }
                }
            } else if (ch == 'C') { // 선택행 삭제, 바로 아래행 선택, 삭제된 행이 tail이면 윗행 선택
                st.push(list.cursor);
                if (list.tail == list.cursor) { // tail이면
                    list.tail = list.tail.prev;
                    list.tail.next = null;
                    list.cursor = list.tail;
                } else { // tail 아니면
                    if (list.cursor.prev != null)
                        list.cursor.prev.next = list.cursor.next;
                    list.cursor.next.prev = list.cursor.prev;
                    list.cursor = list.cursor.next;
                }
            } else if (ch == 'Z') { // 가장 최근 삭제행 복구
                Node node = st.pop();

                if (node.prev != null)
                    node.prev.next = node;
                else
                    list.head = node;

                if (node.next != null)
                    node.next.prev = node;
                else
                    list.tail = node;
            }
        }

        StringBuilder sb = new StringBuilder("O".repeat(n));
        while (!st.isEmpty()) {
            Node cur = st.pop();
            sb.replace(cur.idx, cur.idx + 1, "X");
        }

        return sb.toString();
    }

    class LinkedList {
        Node head;
        Node tail;
        Node cursor;

        LinkedList() {
            this.head = null;
            this.tail = null;
        }
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
