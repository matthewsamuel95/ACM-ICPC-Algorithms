import java.util.*;
import java.awt.List;
import java.io.*;
import java.lang.*;
import java.lang.reflect.Array;

public class code8 {

	
	
	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter pw = new PrintWriter(System.out);

		// Code starts..

		int n = in.nextInt();
		int[] a = in.nextIntArray(n);
		query[] qr1 = new query[n];
		pair[] p = new pair[n];
		q = n;
		HashMap<Integer, Integer> map = new HashMap<>();
		for(int i=0; i<n; i++)
			map.put(a[i],i);
		Arrays.sort(a);
		for(int i=n-1; i>=0; i--)
		{
			p[n-i-1] = new pair(-a[i], map.get(a[i])); 
			int l = 0;
			int r = map.get(a[i])-1;
			int x = a[i];
			qr1[n-i-1] = new query(l, r, -a[i], map.get(a[i]));
			//  pw.println(qr1[n-i-1].l+" "+qr1[n-i-1].x+" "+p[n-i-1]);
				
		}
		
		int[] ans = answerQueries(n, qr1, q, p);
			
		for(int i=0; i<n; i++)
		{
			int l = map.get(a[i])+1;
        	int r = n-1;
        	int x = a[i];
        	qr1[i].l = l;
        	qr1[i].r = r;
        	qr1[i].x = x;
        	qr1[i].idx = map.get(a[i]);
        	
          	p[i].x = x;
          	p[i].y = map.get(a[i]);
        //    pw.println(qr1[i].l+" "+qr1[i].x+" "+p[i]+" ");
			
		}
	
	
		
		int[] ans2 = answerQueries(n, qr1, q, p);
		long sum = 0;
		for(int i=0; i<q; i++)
		{
			sum += (long)ans[i]*ans2[i];
			//pw.println(ans[i]+" "+ans2[i]);
		}
		
		
		pw.print(sum);
		// code ends...

		pw.flush();
		pw.close();
	}

	
	
	public static void update(int bit[], int idx, int val, int n) {
	
		
		for(; idx<=n; idx+= (idx&-idx))
			bit[idx] += val;
	}
	
	    
	
	public static int query(int bit[], int idx, int n) {
		int sum = 0;
		for (; idx > 0; idx -= idx&-idx)
	        sum += bit[idx];
		return sum;
	}
	
	
	
	public static int[] answerQueries(int n, query[] qr, int q,
            pair[] p)

	{

		int[] bit = new int[n+1];
		/*p = suffle(p, new Random());
		qr = suffle(qr, new Random());
		
		//Arrays.sort(p);
		Arrays.sort(qr);
		*/
		int curr = 0;
		int[] ans = new int[q];
		for (int i=0; i<q; i++)
		{
			//System.out.println(p[curr]+" "+i+" "+curr);
			if(curr<n)
			while (p[curr].x <= qr[i].x && curr<n)
			{
					update(bit, p[curr].y+1, 1, n);
					curr++;
					if(curr==n)
						break;
			}
		
			ans[qr[i].idx] = query(bit, qr[i].r+1, n) -
		            query(bit, qr[i].l, n);
		}

		return ans;

		
}
	
	
	
	

	static class InputReader
	{

		private final InputStream stream;
		private final byte[] buf = new byte[8192];
		private int curChar, snumChars;
		private SpaceCharFilter filter;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		public int snext() {
			if (snumChars == -1)
				throw new InputMismatchException();
			if (curChar >= snumChars) {
				curChar = 0;
				try {
					snumChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (snumChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		public int nextInt() {
			int c = snext();
			while (isSpaceChar(c)) {
				c = snext();
			}
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = snext();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public long nextLong() {
			int c = snext();
			while (isSpaceChar(c)) {
				c = snext();
			}
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = snext();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public int[] nextIntArray(int n) {
			int a[] = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = nextInt();
			}
			return a;
		}

		public String readString() {
			int c = snext();
			while (isSpaceChar(c)) {
				c = snext();
			}
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = snext();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		public String nextLine() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = snext();
			} while (!isEndOfLine(c));
			return res.toString();
		}

		public boolean isSpaceChar(int c) {
			if (filter != null)
				return filter.isSpaceChar(c);
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		private boolean isEndOfLine(int c) {
			return c == '\n' || c == '\r' || c == -1;
		}

		public interface SpaceCharFilter {
			public boolean isSpaceChar(int ch);
		}
	}
}
