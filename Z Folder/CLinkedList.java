package com.company;

public class CLinkedList<Type> {
    private class Node {
        Type data;
        Node next, previous;
        public Node(Type data) {
            this.data = data;
        }
    }

    Node head, tail;

    public void remove(Node node) {
        // base case
        if(head == null || node == null) {
            return;
        }

        // if node is first node
        if(head == node) {
            head = head.next;
            head.previous = null;
            return;
        }

        // if node is end node
        if(tail == node) {
            if(head != tail) {
                tail = tail.previous;
                tail.next = null;
            } else {
                head = tail = null;
            }
            return;
        }

        // if node is middle
    }
}
