import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Greedy01KnapsackSolver {
  private static class KnapsackItem {
    public int value;
    public int weight;
    public int taken;

    public KnapsackItem(int value, int weight) {
      this.value = value;
      this.weight = weight;
      this.taken = 0;
    }
  }

  private static class ValueByWeightTuple {
    private int index;
    private double valueByWeight;

    public ValueByWeightTuple(int index, double valueByWeight) {
      this.index = index;
      this.valueByWeight = valueByWeight;
    }

    public int getIndex() {
      return index;
    }

    public double getValueByWeight() {
      return valueByWeight;
    }
  }

  public static int solve(int numItems, int capacity, KnapsackItem[] items) {
    // Create list of item index/value by by weight tuples
    List<ValueByWeightTuple> itemsByValueWeightRatio = new ArrayList<ValueByWeightTuple>(items.length);
    for (int i = 0; i < items.length; ++i) {
      itemsByValueWeightRatio.add(new ValueByWeightTuple(i, (double)items[i].value / (double)items[i].weight));
    }

    // Sort the list with the most valuable items by weight at the top
    itemsByValueWeightRatio.sort(Comparator.comparingDouble(ValueByWeightTuple::getValueByWeight).reversed());

    // Select items until the knapsack is full
    int value = 0;
    int weight = 0;

    for (ValueByWeightTuple item : itemsByValueWeightRatio) {
      if (weight + items[item.getIndex()].weight <= capacity) {
        weight += items[item.getIndex()].weight;
        value += items[item.getIndex()].value;
        items[item.getIndex()].taken = 1;
      } else {
        items[item.getIndex()].taken = 0;
      }
    }

    return value;
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("How many items are there?");
    int numItems = sc.nextInt();

    KnapsackItem[] items = new KnapsackItem[numItems];
    for (int i = 0; i < numItems; ++i) {
      int ordinal_idx = i + 1;
      System.out.println("What's the value of item " + ordinal_idx + "?");
      int value = sc.nextInt();
      System.out.println("What's the weight of item " + ordinal_idx + "?");
      int weight = sc.nextInt();
      KnapsackItem newItem = new KnapsackItem(value, weight);
      items[i] = newItem;
    }

    System.out.println("What's the capacity of the knapsack?");
    int capacity = sc.nextInt();

    int value = (new Greedy01KnapsackSolver()).solve(numItems, capacity, items);

    System.out.println("Filled the knapsack with a total value of " + value + ", using the following items:");
    for (int i = 0; i < numItems; ++i) {
      if (items[i].taken == 1) {
        System.out.println("Item " + (i+1));
      }
    }
  }
}
