
//fibonacci sequence 0,1,1,2,3,5,8,13,21
public class comparingRec_Iter {
    //Part 1 : Fibonacci Recursice and iterative
    public static int count = 0;

    public static void resetCallCount() { count = 0; }
    //recursive 
    private static int fibonacciRec(int n) {
        count++;
        if (n <= 1) { //case for if its 0 or 1 
            return n; 
        } 
        //otherwise it returns the addition of the addition of the last 2 numbers
        return fibonacciRec(n-1) + fibonacciRec(n-2); 
    }

    private static int getCallCount() { return count; }

    private static int fibonacciIter(int n) {
        if (n <= 1) { //case for 0 or 1
            count++;
            return n; 
        }   //    2nd       3rd
        int fibPP = 1, fibP = 1, add;
        for (int i=2;i<n;i++) { //goes throught starting after the 3rd nth term 
            add = fibPP + fibP; //adds the two previous numbers 
            fibPP = fibP; //sets it to the next prev
            fibP = add; //sets it to the nth result
            count++;
        }
        return fibP; //returns it 
    }

    //Part 2 : Towers of Hanoi
    public static void move1(int source, int dest) {
        System.out.printf("Move top ring from %d to %d.\n", source, dest);
    }
    //fromPeg is the source and tempPeg is the destination 
    public static void solveHanoi(int fromPeg, int toPeg, int tempPeg, int numDisks) {
        if (numDisks == 1) { // for when there is 1 left
            move1(fromPeg, toPeg);
        } else {
            //peg1 to peg2, peg3 is temp
            solveHanoi(fromPeg, tempPeg, toPeg, numDisks-1);
            //outputting 
            move1(fromPeg, toPeg);
            //peg2 to peg3, peg1 is temp
            solveHanoi(tempPeg, toPeg, fromPeg, numDisks-1);
        }
    }
       
    public static void main(String[] args) {

        //Part 1
        System.out.println("Fibonacci:");
        int n = 15;
        resetCallCount();
        int recursiveResult = fibonacciRec(n);
        int recursiveCalls = getCallCount();
        System.out.printf("Recursive result: %d (%d recursive calls)\n",
                            recursiveResult, recursiveCalls);
        resetCallCount();
        int iterativeResult = fibonacciIter(n);
        int iterations = getCallCount();
        System.out.printf("Iterative result: %d (%d iterations)\n",
                          iterativeResult, iterations);

        //Part 2
        System.out.println("\nTowers of Hanoi:");
        solveHanoi(1, 3, 2, 4);

    }
}