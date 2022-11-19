import java.util.*;

public abstract class Hashtable<T> {
  protected int capacity = 0;
  private List<String> keys = null;
  private List<T> values = null;

  private int probeCount = 0;

  public int getProbeCount() {
    return this.probeCount;
  }

  public void resetProbeCount() {
    this.probeCount = 0;
  }

  public Hashtable(int capacity) {
    this.keys = new ArrayList<String>();
    for (int i = 0; i < capacity; i++) {
      this.keys.add(null);
    }
    this.values = new ArrayList<T>();
    for (int i = 0; i < capacity; i++) {
      this.values.add(null);
    }
    this.capacity = capacity;
  }

  public int hash(String key) {
    int sum = 0;
    for (int i = 0; i < key.length(); i++) {
      sum += (int)key.charAt(i);
    }
    return sum % capacity;
  }

  public abstract int rehash(int previousHash); //in quad and linear class
  
  public void insert(String key, T value)  {
    // determine the hash
    // TODO
    int hash = this.hash(key);  
    this.probeCount++;  //updating 
    // if the hash is taken, continuously until a free space
    // is found
    // TODO
    while (this.keys.get(hash) != null) { 
      hash = rehash(hash);  //rehash uses the quad or linear class 
      this.probeCount++;  //updating 
    }
    // insert the value at that position
    // TODO
    this.keys.set(hash, key); //updating the string list 
    this.values.add(hash, value); //updating the generic list 
  }
}
