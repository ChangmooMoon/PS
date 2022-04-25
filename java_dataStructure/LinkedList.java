public class LinkedList {
    private Node head;
    private Node tail;
    private int size = 0;

    private class Node {
        private Object data;
        private Node next;

        public Node(Object input) {
            this.data = input;
            this.next = null;
        }

        public String toString() {
            return String.valueOf(this.data);
        }
    }

    public void addFirst(Object input) {
        Node newNode = new Node(input);
        newNode.next = head;
        head = newNode;
        ++size;
        if (head.next == null) {
            tail = head;
        }
    }

    public void addLast(Object input) {
        Node newNode = new Node(input);
        if (size == 0) {
            addFirst(input);
        } else {
            tail.next = newNode;
            tail = newNode;
            ++size;
        }
    }

    Node node(int idx) {
        Node x = head;
        for (int i = 0; i < idx; ++i) {
            x = x.next;
        }
        return x;
    }

    public void add(int k, Object input) {
        if (k == 0) {
            addFirst(input);
        } else {
            Node tmp1 = node(k - 1);
            Node tmp2 = tmp1.next;
            Node newNode = new Node(input);
            tmp1.next = newNode;
            newNode.next = tmp2;
            ++size;
            if (newNode.next == null) {
                tail = newNode;
            }
        }
    }

    public String toString() {
        if (head == null) {
            return "[]";
        }

        Node tmp = head;
        StringBuilder sb = new StringBuilder("[");
        while (tmp.next != null) {
            sb.append(tmp.data).append(", ");
            tmp = tmp.next;
        }
        sb.append(tmp.data).append("]");
        return sb.toString();
    }

    public Object removeFirst() {
        Node tmp = head;
        head = tmp.next;
        Object retData = tmp.data;
        tmp = null;
        --size;
        return retData;
    }

    public Object remove(int k) {
        if (k == 0)
            return removeFirst();

        Node tmp = node(k - 1);
        Node todoDeleted = tmp.next;
        tmp.next = tmp.next.next;
        Object retData = todoDeleted.data;
        if (todoDeleted == tail) {
            tail = tmp;
        }

        todoDeleted = null;
        --size;
        return retData;
    }

    public int size() {
        return size;
    }

    public Object get(int k) {
        Node tmp = node(k);
        return tmp.data;
    }

    public int indexOf(Object data) {
        Node tmp = head;
        int idx = 0;

        while (tmp.data != data) {
            tmp = tmp.next;
            ++idx;
            if (tmp == null)
                return -1;
        }
        return idx;
    }

    public ListIterator listIterator() {
        return new ListIterator();
    }

    public class ListIterator {
        private Node lastReturned;
        private Node next;
        private int nextIdx;

        ListIterator() {
            next = head;
            nextIdx = 0;
        }

        public Object next() {
            lastReturned = next;
            next = next.next;
            ++nextIdx;
            return lastReturned.data;
        }

        public boolean hasNext() {
            return nextIdx < size();
        }

        public void add(Object input) {
            Node newNode = new Node(input);
            if (lastReturned == null) {
                head = newNode;
            } else {
                lastReturned.next = newNode;
            }
            newNode.next = next;
            lastReturned = newNode;
            ++nextIdx;
            ++size;
        }

        public void remove() {
            if (nextIdx == 0) {
                throw new IllegalStateException();
            }
            LinkedList.this.remove(nextIdx - 1);
            --nextIdx;
        }
    }
}