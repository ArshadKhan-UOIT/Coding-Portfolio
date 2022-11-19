//making this the child class of Shape
public class Rectangle extends Shape {
    //protected variable for the length and wdith of a rectangle
    protected float Lenght;
    protected float Width;
    //overload constructor 
    public Rectangle(String Colour, float Lenght, float Width) {
        //using the colour variable from the parent class shape
        super(Colour);
        this.Lenght = Lenght;
        this.Width = Width;
    }
    //area of a rectangle function
    public float getArea() {
        return this.Lenght*this.Width;
    }
    //perimeter of a rectangle function
    public float getPerimeter() {
        return 2*(this.Width+this.Lenght);
    }
    //this is the output for the discription of the rectangle
    public String toString() {
        return this.Colour + " rectangle with length " +  
            this.Lenght + " and width " + this.Width;
    }

    
}               