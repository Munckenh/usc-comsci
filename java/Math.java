import java.utils.*;

class Math {
    public static void main(String[] args) {
        System.out.println(getDifference(5, 3));
    }
    
    public static int subtract(int a, int b) {
        return a + (~b + 1);
    }
    
    public static void sort(int numbers[]) {
        numbers.sort();
    }
}