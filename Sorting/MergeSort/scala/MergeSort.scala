object MergeSort {

    def merge(list1 : List[Int], list2 : List[Int]) : List[Int] = {
  
       (list1, list2) match{
       case(list1, Nil) => list1
       case(Nil, list2) => list2
       case(leftHead :: leftTail, rightHead :: rightTail) =>
       if(leftHead<rightHead)
        leftHead::merge(leftTail,list2)
       else
        rightHead :: merge(list1,rightTail)
       }

    }

    def sort(list : List[Int]) : List[Int] = {
      
        val mid = list.length/2
        if(mid ==0) list
        else {
        val leftl = list.slice(0,mid)
        val rightl = list.slice(mid,list.length)
        merge(sort(leftl),sort(rightl))
        }
    }

    def main(args : Array[String]) {
        println(sort(List(9,5,7,3,1,4,6,2,8,0)));
    }

}
