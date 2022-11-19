
public class SortedDoublyLinkedList implements LinkedList {
    public class Node {
        private Node next;
        private Node prev;
        private Warrior element;
        //Node overloading constructor
        public Node(Warrior element, Node prev, Node next) {
            this.element = element;
            this.prev = prev;
            this.next = next; 
        }
        //setters
        public void setPrev(Node prev) { this.prev = prev; }
        public void setNext(Node next) { this.next = next; }
        //getters
        public Node getPrev() { return prev; }
        public Node getNext() { return next; }
        public Warrior getElement() { return element; }
    }
    public int assignmentCount = 0;
    private Node header, trailer;
    private int size;
    //initializing the variables
    public SortedDoublyLinkedList() {
        header = new Node(null, null, null);
        trailer = new Node(null, header, null);
        header.setNext(trailer);
        assignmentCount += 2;
        size = 0;
    }
    //i used the same outline that was on the powerpoint from the linkedlist lecture a lot
    //this adds elements to the list
    private void add(Warrior warrior, Node predecessor, Node successor) {
        Node newWarrior = new Node(warrior, predecessor, successor);
        predecessor.setNext(newWarrior);
        successor.setPrev(newWarrior);
        assignmentCount += 1;
        size++;
    }
   
    public void insert(Warrior warrior) {
        Node current = header.getNext();//starting at beginning of the list 
        assignmentCount += 1;
        //comparing speeds 
        //for the first element
        if (current == trailer || current.getElement().getSpeed() < warrior.getSpeed()) {
            assignmentCount += 1;
            //adding between header and header.next
            add(warrior, header, header.getNext());
        }
        else {//goes through this for the rest of the elements
            while (current.getNext() != trailer){//while its not empty
                assignmentCount += 1;
                //if the current element is less then go on to the next
                if (current.getElement().getSpeed() < warrior.getSpeed()) {
                    break;
                }
                else{
                    current = current.getNext();//continue to the next element in the iist
                    assignmentCount += 1;
                }
            }
            //if its the last element 
            if (current.getNext() == trailer) {
                add(warrior, trailer.getPrev() , trailer);//adding it before the null
                assignmentCount += 1;
            }else {//if its not the last element 
                add(warrior, current, current.getNext());//adding between current and current.next
            }
        }
    }
    //outputting
    public String toString() {
        String result = "";
        Node current = header.getNext();
        if (header == trailer) {
            return "";
        }
        //going through the list 
        while (current != trailer) {
            result += current.element + " ";
            current=current.next;
        }
        return "[ " + result + "]";//returning the result
    }
    
}