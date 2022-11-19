//making this the child class of Shape
public class Circle extends Shape {
    //protected variable for the radius of a circle 
    protected float Radius;
    //overload constructor 
    public Circle(String Colour, float Radius) {
        //using the colour variable from the parent class shape
        super(Colour);
        this.Radius = Radius;
    }
    //area of a circle function
    public float getArea() {
        //casting Pi to a float
        double d = Math.PI; // i googled how to get the Pi constant https://stackoverflow.com/questions/12594058/how-to-use-math-pi-in-java/12594064
        float f = (float)d;
        return (f*this.Radius*this.Radius);
    }
    //perimeter of a circle function
    public float getPerimeter() {
        //casting Pi to a float
        double d = Math.PI;
        float f = (float)d;
        return (2.0f*f*this.Radius);
    }
    //this is the output for the discription of the circle
    public String toString() {
        return (this.Colour + " circle with radius " + this.Radius);
    }

}