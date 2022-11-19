public class LinearHashtable<T> extends Hashtable<T> {
    
    public LinearHashtable(int capacity) { super(capacity); }   

    public int rehash(int previousHash) { return (previousHash+1)%this.capacity; }  //for a linear hash table 

}