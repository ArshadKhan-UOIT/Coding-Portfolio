public class Monster {
    protected String name;//named it protected for becasue i wanted to use it in the Humanplayer
    protected String type;
    protected int hp;
    protected int speed;
    protected int attack;
    protected int defense;
    protected Move move1;
    protected Move move2;
    protected Move move3;
    protected Move move4;
    //overload constructor
    public Monster(String name, String type, int hp, int speed, int attack,
        int defense, Move move1, Move move2, Move move3, Move move4 ) {
        this.name = name;
        this.type = type;
        this.hp = hp;
        this.speed = speed;
        this.attack = attack;
        this.defense = defense;
        this.move1 = move1;
        this.move2 = move2;
        this.move3 = move3;
        this.move4 = move4;
    }
    //setter method
    public void setHP(int hp) { this.hp = hp; }
    //getter methods
    public String getName() { return name; }
    public String getType() { return type; }
    public int getHP() { return hp; }
    public int getSpeed() { return speed; }
    public int getAttack() { return attack; }
    public int getDefense() { return defense; }
    public Move getMove1() { return move1; }
    public Move getMove2() { return move2; }
    public Move getMove3() { return move3; }
    public Move getMove4() { return move4; }
    
}