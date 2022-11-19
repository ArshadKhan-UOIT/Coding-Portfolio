//abstract parent class
public abstract class Shape {
    //protected variable 
    protected String Colour;
    //overload constructor
    public Shape(String Colour) {
        this.Colour = Colour;
    }
    //abstract functions for the child class
    public abstract float getArea();
    public abstract float getPerimeter();
    public abstract String toString();
}