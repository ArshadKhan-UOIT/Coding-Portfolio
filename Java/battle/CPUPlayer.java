public class CPUPlayer extends Player {
    //overload constructor
    public CPUPlayer(Monster monster) {
        this.monster = monster;
    }
    //for the move options
    public int chooseMove() {
        return rand.nextInt(4) +1;
    }

}