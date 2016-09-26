package week6

/**
  * Created by xiejun on 16/9/25.
  */
object Main {

    def main(args: Array[String]): Unit = {
        println(nquens(8).size)
    }

    def nquens(n:Int):Set[List[Int]] = {
        def placeQuensK(k:Int):Set[List[Int]] =
            if(k == 0) Set(Nil)
            else {
                for {
                    quen <- placeQuensK(k - 1)
                    k <- 0 until n
                    if (isSafe(k, quen))
                } yield k :: quen
            }
        def isSafe(k:Int, quen:List[Int]) = {
            val row = quen.length
            val quenWithRow = ((row -1) to 0 by -1) zip quen
            quenWithRow.forall{
                case (r, c) => c != k && math.abs(k -c) != row -r
            }
        }
        placeQuensK(n)
    }

}
