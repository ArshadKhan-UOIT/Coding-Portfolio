public class AVLNode {
  public AVLNode left = null;
  public AVLNode right = null;
  public int value = 0;
  public AVLNode parent = null;

  public AVLNode insert(int newValue) {
    // perform binary-search style insertion
    if (newValue < this.value) {
      // insert the value to the left sub-tree
      if (this.left == null) {
        AVLNode newNode = new AVLNode();
        newNode.value = newValue;
        newNode.parent = this;
        this.left = newNode;
      } else {
        this.left.insert(newValue);
      }
    } else {
      // insert the value into the right sub-tree
      if (this.right == null) {
        AVLNode newNode = new AVLNode();
        newNode.value = newValue;
        newNode.parent = this;
        this.right = newNode;
      } else {
        this.right.insert(newValue);
      }
    }

    return rebalance();
  }

  public AVLNode rebalance() {
    // balance the tree (if necessary)
    int balance = this.getBalance();
    if (balance <= -2) { //left node is out of balance, right rotation 
      if(this.left.right.left != null) {  
        this.parent = this.left;  //making parent the left 
        this.left.parent = null;  //left parent null
        this.left=this.left.right;  //making the new left the left right
        this.parent.right = this; 
      } else {  
        this.left.parent=this.left.right; // left parent the left right
        this.left.right=this.left.parent.left;  //left right the left left 
        this.left.parent.left=this.left; //left most the new left
        this.left=this.left.parent; //left parent 
        this.left.parent.parent=this; //giving the left parent its child
        this.parent = this.left;
        this.left.parent = null;  //getting tid of the old parent
        this.left=this.left.right;
        this.parent.right = this; //giving the right parent its child
      }
    } else if (balance >= 2) {//right node is out of balance, left rotation  
      if (this.right.right.left != null) {  
        this.parent = this.right; //making parent the right
        this.right.parent = null; //right parent null
        this.right = this.right.left; //making the new right the right left 
        this.parent.left = this;
      } else { 
        this.right.parent = this.right.left;  //right parent the right left 
        this.right.left=this.right.parent.right;  //right left the right right
        this.right.parent.right=this.right; //right most the new right 
        this.right=this.right.parent; //the right parent 
        this.right.parent.parent=this;  //giving the right parent its child
        this.parent = this.right; 
        this.right.parent = null; //getting tid of the old parent
        this.right=this.right.left; 
        this.parent.left = this;  //giving the left parent its child 
      }
    } 
    return null;
  }

  public int getBalance() {
    int rightHeight = 0;
    if (this.right != null) {
      rightHeight = this.right.getHeight();
    }

    int leftHeight = 0;
    if (this.left != null) {
      leftHeight = this.left.getHeight();
    }

    return rightHeight - leftHeight;
  }

  public void print(int depth) {
    if (this.right != null) {
      this.right.print(depth + 1);
    }

    for (int i = 0; i < depth; i++) {
      System.out.print("\t");
    }
    System.out.println(this.value);

    if (this.left != null) {
      this.left.print(depth + 1);
    }
  }

  public int getHeight() {
    int leftHeight = 1;
    if (left != null) {
      leftHeight = left.getHeight() + 1;
    }

    int rightHeight = 0;
    if (right != null) {
      rightHeight = right.getHeight() + 1;
    }

    return (leftHeight > rightHeight) ? leftHeight : rightHeight;
  }
}
