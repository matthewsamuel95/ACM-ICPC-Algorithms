

class KMP {
    
    static void kmp(String text, String pattern) {
        int lenText = text.length();
        int lenPattern = pattern.length();

        int []b = new int[lenPattern+1];
        int i = 0, j = -1;
        b[0] = -1;
        while(i < lenPattern) {
            while(j >= 0 && pattern.charAt(i) != pattern.charAt(j)) j = b[j];
            i++;
            j++;
            b[i] = j;
        }

        i = 0;
        j = 0;
        while(i < lenText) {
            while(j >= 0 && text.charAt(i) != pattern.charAt(j)) {
                j = b[j];
            }
            i++;
            j++;
            if (j == lenPattern) {
                System.out.println("Pattern is found at index " + (i-j));
                j = b[j];
            }
        }
    }
    public static void main(String[] args) {
        kmp("ABABDABACDABABCABAB", "ABABCABAB");
    }
}