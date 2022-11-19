public class HashtableDriver {
  private static String characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";

  public static String generateRandomString(int length) {
    StringBuilder result = new StringBuilder();
    for (int i = 0; i < length; i++) {
      int index = (int)(Math.random() * 62.0);
      result.append(characters.charAt(index));
    }
    return result.toString();
  }

  public static void main(String[] args) {
    int size = 10007; // prime number
    int numValues = 1000;
    
    LinearHashtable<String> linearTable = new LinearHashtable<>(size);
    QuadraticHashtable<String> quadraticTable = new QuadraticHashtable<>(size);

    // generate random strings and insert them into both tables
    for (int i = 0; i < numValues; i++) {
      String newValue = generateRandomString(25);
      linearTable.insert(newValue, newValue);
      quadraticTable.insert(newValue, newValue);
    }

    System.out.println("# probes linear:    " + linearTable.getProbeCount());
    System.out.println("# probes quadratic: " + quadraticTable.getProbeCount());
  }
}
