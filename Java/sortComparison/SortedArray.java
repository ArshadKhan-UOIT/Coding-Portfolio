public class SortedArray {
    public int assignmentCount = 0; //counting operators
    private Warrior warrior;    //acessing warrior variables
    private int index = 0; //index of the array
    Warrior[] warriorArray = new Warrior[100]; //using arrays 
    
    public void insert(Warrior warrior) {
        warriorArray[index] = warrior; //allocating the elements
        assignmentCount += 1;
        index++;
        //sorting function 
        //nested for loops
        for (int i = index-1; i>=0; i--) {
            //assignmentCount += 2;
            for (int j=1; j<=i;j++) {
                //assignmentCount += 2;
                //swapping statement 
                if (warriorArray[j].getSpeed() >= warriorArray[j-1].getSpeed()) {
                    //if the current element is bigger the previous swap it 
                    Warrior tmp = warriorArray[j-1];
                    warriorArray[j-1] = warriorArray[j];
                    warriorArray[j] = tmp;
                    assignmentCount += 3;
                }
            }
        }
    }
}