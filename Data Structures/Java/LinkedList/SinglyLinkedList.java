public class SinglyLinkedList {

    private static Node root;

    public static void insertNode(int data){
        if(root == null){
            root = new Node(data, null);
        }else{
            Node temp = root;
            while(temp.next!=null){
                temp = temp.next;
            }
            temp.next = new Node(data,null);
        }
    }

    public static void removeNode(int data){
        Node temp = root;
        Node tempPointer = temp;
        while(temp.data!=data){
            tempPointer = temp;
            temp = temp.next;
        }
        tempPointer.next = temp.next;
    }

    public static void printList(){
        Node temp = root;
        while(temp!=null){
            System.out.print(temp+" ");
            temp = temp.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        insertNode(30);
        insertNode(40);
        insertNode(20);
        insertNode(10);
        insertNode(70);
        insertNode(60);
        printList();
        removeNode(20);
        printList();
    }

}

class Node{

    int data;
    Node next;

    public Node(int data, Node next) {
        this.data = data;
        this.next = next;
    }

    @Override
    public String toString() {
        return String.valueOf(data);
    }
}
