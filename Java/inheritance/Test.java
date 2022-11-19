
import java.util.*;
//the testing class for testing the output of the classes i created
public class Test {
    public static void main(String[] args) {
        ArrayList<Shape> shapes = new ArrayList<>();
        //circle and rectangle class
        shapes.add(new Circle("Red", 2.0f));
        shapes.add(new Rectangle("Blue", 1.5f, 3.0f));
        //for loop for the output for both classes
        for (Shape shape: shapes) {
            System.out.println("");
            System.out.println(shape.toString());
            System.out.printf("Area: \t   %.2f\n", shape.getArea());
            System.out.printf("Perimeter: %.2f\n", shape.getPerimeter());
        }

    }
}