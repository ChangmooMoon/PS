public class Queue {
    Node front, rear;

    private class Node {
        Object data;
        Node next;

        Node(Object data) {
            this.data = data;
            this.next = null;
        }
    }

    public Queue() {
        this.front = this.rear = null;
    }

    void enqueue(Object data) {
        Node newNode = new Node(data);
        if (this.rear == null) {
            this.front = this.rear = newNode;
            return;
        }

        this.rear.next = newNode;
        this.rear = newNode;
    }

    void dequeue() {
        if (this.front == null)
            return;

        this.front = this.front.next;

        if (this.front == null) {
            this.rear = null;
        }
    }
}
