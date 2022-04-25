package LinkedList;

interface StackInterface {
    boolean isEmpty();

    void push(Object o);

    Object pop();

    Object peek();
}

public class Stack implements StackInterface {
    private Node top;

    private class Node {
        Object data;
        Node link;

        Node(Object input, Node link) {
            this.data = input;
            this.link = link;
        }
    }

    public boolean isEmpty() {
        return top == null;
    }

    public void push(Object o) {
        top = new Node(o, top);
    }

    public Object pop() {
        if (isEmpty())
            throw new IllegalStateException();

        Object data = top.data;
        top = top.link;
        return data;
    }

    public Object peek() {
        if (isEmpty())
            throw new IllegalStateException();
        return top.data;
    }

    public String toString() {
        if (isEmpty())
            throw new IllegalStateException();
        StringBuilder sb = new StringBuilder("[");
        Node tmp = top;
        while (tmp.link != null) {
            sb.append(tmp.data).append(",");
        }
        sb.append(tmp.data).append("]");
        return sb.toString();
    }
}
