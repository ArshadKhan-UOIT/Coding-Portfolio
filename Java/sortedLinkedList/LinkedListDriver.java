
import java.util.*;

public class LinkedListDriver {
    public static void main(String[] args) {
        LinkedList list = new SortedDoublyLinkedList();
    
        System.out.println(list);
        Warrior krogg = new Warrior("Krogg", 30, 50, 200);
        list.insert(krogg);

        System.out.println(list);
        Warrior gurkh = new Warrior("Gurkh", 40, 45, 180);
        list.insert(gurkh);
    
        System.out.println(list);
        Warrior brynn = new Warrior("Brynn", 45, 40, 190);
        list.insert(brynn);
        
        System.out.println(list);
        Warrior dolf = new Warrior("Dolf", 20, 65, 210);
        list.insert(dolf);
        
        
        System.out.println(list);
        Warrior zuni = new Warrior("Zuni", 50, 35, 170);
        list.insert(zuni);
       
        System.out.println(list);
    }
}    