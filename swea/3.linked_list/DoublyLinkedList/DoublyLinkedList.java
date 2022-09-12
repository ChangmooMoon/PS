import java.io.*;
import java.util.*;

public class DoublyLinkedList {
  final int MAX_NODE = 100_000;

  Node[] node;
  int nodeCnt;
  Node head, tail;

  static class Node {
    int data;
    Node prev;
    Node next;
  }

  Node getNode(int data) {
    node[nodeCnt].data = data;
    node[nodeCnt].prev = null;
    node[nodeCnt].next = null;
    return node[nodeCnt++];
  }

  void init() {
    node = new Node[MAX_NODE];
    nodeCnt = 0;
    this.head = this.tail = null;
  }

  void addNode2Head(int data) {
    Node nNode = getNode(data);
    if (nodeCnt == 1) {
      this.head = this.tail = nNode;
      return;
    }

    this.head.prev = nNode;
    nNode.next = this.head;
    this.head = nNode;
  }

  void addNode2Tail(int data) {
    Node nNode = getNode(data);
    if (nodeCnt == 1) {
      this.head = this.tail = nNode;
      return;
    }

    tail.next = nNode;
    nNode.prev = tail;
    tail = nNode;
  }

  void addNode2Num(int data, int num) { // replace하지 않고 한칸씩 오른쪽으로 민다
    if (nodeCnt + 1 < num)
      return;

    int idx = 1;
    Node target = this.head;
    while (idx != num) {
      target = target.next;
      ++idx;
    }

    Node nNode = getNode(data);
    if (target == head) {
      nNode.next = target;
      target.prev = nNode;
      head = nNode;
      return;
    }

    Node before = target.prev;
    before.next = nNode;
    nNode.prev = before;
    nNode.next = target;
    target.prev = nNode;
  }

  int findNode(int data) {
    Node curr = head;
    int idx = 1;
    while (curr != null) {
      if (curr.data == data)
        return idx;

      curr = curr.next;
      ++idx;
    }

    return -1;
  }

  void removeNode(int data) {
    Node curr = head;
    while (curr != null) {
      if (curr.data != data) {
        curr = curr.next;
        continue;
      }

      if (curr == head) {
        head = curr.next;
        curr.next.prev = null;
      } else if (curr == tail) {
        tail = curr.prev;
        curr.prev.next = null;
      } else {
        curr.prev.next = curr.next;
        curr.next.prev = curr.prev;
      }
      return;
    }
  }

  public static void main(String[] args) throws IOException {
    Scanner sc = new Scanner(new File("./sll_input.txt"));
    // StringBuilder sb = new StringBuilder();
    // StringTokenizer st = new StringTokenizer();

    String str;
    while (sc.hasNextLine()) {
      str = sc.nextLine();
      System.out.println(str);
    }

    sc.close();
  }
}