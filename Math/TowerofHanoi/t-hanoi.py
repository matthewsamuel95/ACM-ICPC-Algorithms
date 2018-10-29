c = int()

def hanoi(discs, main, target, aux):
  global c
  if discs >= 1:
    c = c + 1
    hanoi(discs - 1, main, aux, target)
    print("[{}] -> Move disc {} from {} to {}".format(c, discs, main, target))
    hanoi(discs - 1, aux, target, main)


if __name__ == "__main__":
  discs = int(input())
  hanoi(discs, "main", "target", "aux")