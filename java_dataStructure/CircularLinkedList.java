package LinkedList;

class Node {
    public Object data;
    public Node next;

    public Node(Object data) {
        this.data = data;
    }
}

public class CircularLinkedList {
    private Node head = null;
    private Node tail = null;

    public void addNode(Object data) {
        Node newNode = new Node(data);

        if (head == null) {
            head = newNode;
        } else {
            tail.next = newNode;
        }
        tail = newNode;
        tail.next = head;
    }

    public boolean contain(Object data) {
        Node curr = head;
        if (head == null)
            return false;
        do {
            if (curr.data.equals(data))
                return true;
        } while (curr != head);
        return false;
    }

    public void remove(Object data) {
        Node curr = head;
        if (head == null)
            return;
        do {
            Node nextNode = curr.next;
            if (nextNode.data.equals(data)) {
                if (tail == head) {
                    head = null;
                    tail = null;
                } else {
                    curr.next = nextNode.next;
                    if (head == nextNode)
                        head = head.next;
                    if (tail == nextNode)
                        tail = curr;
                }
                break;
            }
            curr = nextNode;
        } while (curr != head);
    }

    public void traverseList() {
        Node curr = head;
        if (head == null)
            return;
        do {
            // Object 출력
            curr = curr.next;
        } while (curr != head);
    }
}
