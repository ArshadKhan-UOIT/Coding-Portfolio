public class TicTacToeTreeNode {
    private TicTacToeTreeNode child[];
    private String value;
    
    public TicTacToeTreeNode(String value) { this.value = value; }

    public static TicTacToeTreeNode createNode(String board, String player) {
        TicTacToeTreeNode root = new TicTacToeTreeNode(board); //root node 
        int count = EmptySpaces(board);//counting the number of empty spaces 
        root.child = new TicTacToeTreeNode[count]; //initializing the child nodes array
        String nextPlayer = " ";
        if (player.equals("x")) {   //changing player
            nextPlayer = "o";
        } else {
            nextPlayer = "x";
        }
        int index = 0;
        for (int i=0;i<count;i++) {
            index = board.indexOf(" ", index+1);    //getting indexing the next empty space 
            board = makeMove(board, index, player); //making move for player
            root.child[i] = createNode(board, nextPlayer); //creating child nodes recursively 
            board = makeMove(board, index, " ");    //removing step
        }
        return root;
    }
    //counts the number of empty spaces and returns the count
    private static int EmptySpaces(String board) { 
        int count =0;
        for (int i=0;i<board.length();i++) {
            if (board.charAt(i) == ' ') {
                count++;
            }
        }
        return count;
    }

    public static void printTree(TicTacToeTreeNode root) {
        printTree(" ", root);//recursively 
    }
    //printing it recursively
    public static void printTree(String spaces, TicTacToeTreeNode node) {
        if (node != null) {
            System.out.println(spaces + "'" +node.value + "'");
            //printing child nodes 
            for (int i=0;i<node.child.length;i++) {
                printTree(spaces + "\t", node.child[i]);
            }
        }
    }
    //generates a new string identical to oldBoard, except with the character at positon replaced by player.
    public static String makeMove(String oldBoard, int position, String player) {
        String before = oldBoard.substring(0, position);
        String after = oldBoard.substring(position+1);
        return before + player + after;
    }
       
    public static void main(String[] args) {
        String board = "x ox xo o";
        TicTacToeTreeNode root = createNode(board, "x");
        printTree(root);
    }       
}