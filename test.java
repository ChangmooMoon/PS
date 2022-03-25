import java.util.*;

public class test {
	public static void main(String[] args) {
		int[] ans = { -1 };

		int[] v = new int[10];
		ans = Arrays.copyOf(v, 10);

		System.out.println(Arrays.toString(ans));
	}
}
// [40, 10, 30, 20]
// [10, 30, 40, 20]
// [10, 40, 20, 30]
// [40, 10, 30, 20]
// [10, 30, 40, 20]
// [10, 40, 20, 30]
// [40, 10, 30, 20]
// [10, 30, 40, 20]
// [10, 40, 20, 30]
// [40, 10, 30, 20]
// [10, 30, 40, 20]
// [10, 40, 20, 30]