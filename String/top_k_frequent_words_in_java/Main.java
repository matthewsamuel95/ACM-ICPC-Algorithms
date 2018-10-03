import java.util.*;
import java.util.Map.Entry;
import java.lang.*;
import java.util.ArrayList;

class Main
{
    public static void main(String[] args)
    {
        ArrayList<String> ar = new ArrayList<String>();
        // ar.add("i");
        // ar.add("love");
        // ar.add("leetcode");
        // ar.add("i");
        // ar.add("love");
        // ar.add("coding");
        ar.add("the");
        ar.add("day");
        ar.add("is");
        ar.add("sunny");
        ar.add("the");
        ar.add("the");
        ar.add("the");
        ar.add("sunny");
        ar.add("is");
        ar.add("is");
        Analyzer analyzer = new Analyzer(ar);
        ar = analyzer.return_final_ar();
        System.out.println(ar);

    }
}