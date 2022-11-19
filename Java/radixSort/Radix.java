
import java.util.*;

public class Radix {
    public static void main(String[] args) {
        //in Radix sort we want to start from the right side to the left side of the binary numbers 
        String[] origNumbers = {"0011", "1001", "1000", "0111", "0101"};
        List<String> numbers = new ArrayList<>();
        for (String num: origNumbers) {
            numbers.add(num);
        
        }
        print(numbers);
        //ones place in the binary number
        Buckets one = new Buckets();
        getDigits(one, 3, numbers); //getting the digits of all the ones place in string array 
        numbers = one.getAllInOrder();  //using bucket class to have 1's first then 0's after
        print(numbers); //outputting the order
        //then im just repeating for each place
        //tens place in the binary number
        Buckets tens = new Buckets();
        getDigits(tens, 2, numbers);    //getting the digits of all the tens place in string array
        numbers = tens.getAllInOrder();
        print(numbers);
        //hundreds place in the binary number
        Buckets hundreds = new Buckets();
        getDigits(hundreds, 1, numbers);    //getting the digits of all the hundreds place in string array
        numbers = hundreds.getAllInOrder();
        print(numbers);
        //thousands place in the binary number
        Buckets thousands = new Buckets();
        getDigits(thousands, 0, numbers);   //getting the digits of all the thousands place in string array
        numbers = thousands.getAllInOrder();
        print(numbers);
    }

    public static void getDigits(Buckets place, int position, List<String> num) {
        for(int i=0;i<5;i++) {
            String temp = num.get(i); //current binary in list
            char tempChar = temp.charAt(position);  //the position you want for each place for the binary
            if(tempChar=='1') { //if its 1, then you add it to the ones in the bucket
                place.addOne(temp);
            } 
            else if (tempChar=='0') {   //if its 0, then you add it to the zeros in the bucket
                place.addZero(temp);
            }
        }
    }
    
    public static void print(List<String> num) {    //prints the list  
        System.out.print("[");
        for(int i=0; i<5; i++) {
            System.out.print(" " + num.get(i));
        }
        System.out.println(" ]");
    }

}