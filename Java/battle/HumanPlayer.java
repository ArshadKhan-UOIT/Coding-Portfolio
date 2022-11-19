//child class of player 
public class HumanPlayer extends Player {
    public HumanPlayer(Monster monster) {
        this.monster = monster;
    }

    public int chooseMove() {//choosing the move for the human player
        //for outputting the options 
        String name1 = this.monster.move1.name;
        String name2 = this.monster.move2.name;
        String name3 = this.monster.move3.name;
        String name4 = this.monster.move4.name;
        String type1 = this.monster.move1.type; 
        String type2 = this.monster.move2.type; 
        String type3 = this.monster.move3.type; 
        String type4 = this.monster.move4.type; 
        int power1 = this.monster.move1.power;
        int power2 = this.monster.move2.power;
        int power3 = this.monster.move3.power;
        int power4 = this.monster.move4.power;
        float acc1 = this.monster.move1.accuracy;
        float acc2 = this.monster.move2.accuracy;
        float acc3 = this.monster.move3.accuracy;
        float acc4 = this.monster.move4.accuracy;
        System.out.println("Options:");
        System.out.println("1) Name:" + name1 + " Type:" + type1 + " Power:"  + power1 + " Accuracy:"+ acc1);
        System.out.println("2) Name:" + name2 + " Type:" + type2 + " Power:"  + power2 + " Accuracy:"+ acc2);
        System.out.println("3) Name:" + name3 + " Type:" + type3 + " Power:"  + power3 + " Accuracy:"+ acc3);
        System.out.println("4) Name:" + name4 + " Type:" + type4 + " Power:"  + power4 + " Accuracy:"+ acc4);
        System.out.println("Enter a move (1-4):");
        int choice = input.nextInt();
        while (choice<1 || choice>4) {//for an invalid option
            System.out.println("Invalid please try again. Enter a move from 1 to 4");
            choice = input.nextInt();
        }
        return choice;
    }
}