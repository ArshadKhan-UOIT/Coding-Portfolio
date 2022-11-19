public class Move {
    protected String name;
    protected String type;
    protected int power;
    protected float accuracy;
    //overloading constructor
    public Move(String name, String type, int power, float accuracy) {
        this.name = name;
        this.type = type;
        this.power = power;
        this.accuracy = accuracy;
    }
    //getter methods 
    public String getName() { return name; }

    public String getType() { return type; }

    public int getPower() { return power; }

    public float getAccuracy() { return accuracy; }
}