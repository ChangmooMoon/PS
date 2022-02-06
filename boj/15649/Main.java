import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int tc = Integer.parseInt(br.readLine());
		StringBuilder sb = new StringBuilder();

		for (int i = 1; i <= tc; ++i) {
			String line = br.readLine();
			StringTokenizer st = new StringTokenizer(line, " ");
			while (st.hasMoreTokens()) {
				sb.append("print");
			}

			System.out.println(sb);
		}
	}
}