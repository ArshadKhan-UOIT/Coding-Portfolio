import java.util.Random;

public class ComparisonDriver {
    public static void main(String[] args) {
        SortedDoublyLinkedList list = new SortedDoublyLinkedList();
        SortedArray array = new SortedArray();
        // insert 100 elements into both lists (randomly generated)
        for (int i = 0; i < 100; i++) {
            Warrior newWarrior = new Warrior("Generic",
                                            genStat(50),
                                            genStat(50),
                                            genStat(200));
            list.insert(newWarrior);
            array.insert(newWarrior);
        }
        // compare the number of assignment operations:
        System.out.println("Linked List assignmentCount: " +
                            list.assignmentCount);
        System.out.println("Sorted Array assignmentCount: " +
                            array.assignmentCount);
    }
    public static int genStat(int max) {
        // randomly choose an integer between 1 and max
        Random rand = new Random();
        return rand.nextInt(max) + 1;
    }
}
/*
it seems like 
for doubly linked list: best case is 4n average case is 2(n-1)! And worst case is 4(n-1)! 
for the sorted array: best case is 2(n-1)! Average case is 2(n-1)! And the worst case is 2(n-1)!
hence, the sorted array is constant but doubly linked can be better depending on what values are given
*/