import java.util.*;
public class Player {
    protected float accuracyGen;
    protected float attackAccuracy;
    protected int attackPower;
    protected Monster monster;

    Scanner input = new Scanner(System.in);

    Random rand = new Random();
    //see who lost
    public boolean hasLost() {
        if (monster.getHP() <= 0) {
            return true;
        } else {
            return false;
        }
    }

    public Monster getMonster() { return monster; }

    public int chooseMove() { return 0; }

    public boolean isFasterThan(Player enemy) {
        if (this.monster.getSpeed() > enemy.getMonster().getSpeed()) {
            return true;
        } else {
            return false;
        }
    }
    
    public void attack(Player enemy, int playerMove) {
        accuracyGen = rand.nextFloat(); //between 0.0 and 1.0
        //updating the variables for each players move for finding the total damage
        if (playerMove == 1) {
            attackAccuracy = this.getMonster().getMove1().getAccuracy();
            attackPower = this.getMonster().getMove1().getPower();
        }
        else if (playerMove == 2) {
            attackAccuracy = this.getMonster().getMove2().getAccuracy();
            attackPower = this.getMonster().getMove2().getPower();
        }
        else if (playerMove == 3) {
            attackAccuracy = this.getMonster().getMove3().getAccuracy();
            attackPower = this.getMonster().getMove3().getPower();
        }
        else if (playerMove == 4) {
            attackAccuracy = this.getMonster().getMove4().getAccuracy();
            attackPower = this.getMonster().getMove4().getPower();
        }
        //for the accuracy 
        if (accuracyGen<attackAccuracy) {
            int damageDealth = (this.getMonster().getAttack()) + attackPower - 
            (enemy.getMonster().getDefense()); //for get the value of the damage
            //using the types to determine extra damage output
            //the monster side 
            String monType = this.getMonster().getType();
            String enemyType = enemy.getMonster().getType();
            //for extra damage
            if (monType.equals("Fire") && enemyType.equals("Grass")) {
                damageDealth = damageDealth*2;
                System.out.println(damageDealth/2 + " points extra damage was delt ");
            }
            else if (monType.equals("Fire") && enemyType.equals("Normal")) {
                damageDealth = damageDealth*2;
                System.out.println(damageDealth/2 + " points extra damage was delt ");
            }
            else if (monType.equals("Flying") && enemyType.equals("Grass")) {
                damageDealth = damageDealth*2;
                System.out.println(damageDealth/2 + " points extra damage was delt ");
            }
            else if (monType.equals("Flying") && enemyType.equals("Normal")) {
                damageDealth = damageDealth*2;
                System.out.println(damageDealth/2 + " points extra damage was delt ");
            }
            
            System.out.println(monster.getName() + " does " + damageDealth + " damage to " + enemy.getMonster().getName());
            enemy.getMonster().setHP(enemy.getMonster().getHP() - damageDealth); //updating the health of the opponent 
        } else {
            System.out.println(this.getMonster().getName() + " is a miss"); //if the damage was a miss due to accuracy
        }
    }
}