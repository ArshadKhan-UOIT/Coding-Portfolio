public class QuadraticHashtable<T> extends Hashtable<T> {
    
    public QuadraticHashtable(int capacity) { super(capacity); }

    public int rehash(int previousHash) { return (previousHash*previousHash)%this.capacity; }   //for a quadratic hash table 

}