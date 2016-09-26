package week5

import scala.util.Random

/**
  * Created by xiejun on 16/9/24.
  */
object Main {

    def main(args: Array[String]): Unit = {
        val x = (1 until 20).toList
        val randomX = Random.shuffle(x)
        println(randomX)
        println(mergeSort(randomX))
        println(squareList(randomX))
        println(squareList2(randomX))
        val x2 = List("a", "a", "a", "b", "c", "c", "a")
        x2.reduce(_ + _)
        println(pack(x2))
        println(encode(x2))
        println(mapFun(randomX,(x:Int) => x*x))
        println(lengthFun(randomX))
    }

    def mergeSort(x:List[Int]):List[Int] = {
        val index = x.length / 2
        if(index == 0) x
        else{
            def merge(xs:List[Int], ys:List[Int]):List[Int] = {
                (xs, ys) match {
                    case(Nil, ys) => ys
                    case(xs, Nil) => xs
                    case(x1::xs1, y1::ys1) =>
                        if(x1 < y1) x1::merge(xs1, ys)
                        else y1::merge(xs, ys1)
                }
            }
            def splitN(xs:List[Int], n:Int) =
                (xs.take(n), xs.drop(n))
            val (left, right) = x.splitAt(index)
            merge(mergeSort(left), mergeSort(right))
        }
    }
    def squareList(xs:List[Int]):List[Int] = xs match {
        case Nil => Nil
        case y::ys => y*y :: squareList(ys)
    }
    def squareList2(xs:List[Int]) = xs.map(x=>x*x)

    def pack[T](xs:List[T]):List[List[T]] = xs match {
        case Nil => Nil
        case x::xs1 =>
            val (first, rest) = xs.span(_ == x)
            first :: pack(rest)

    }

    def encode[T](xs: List[T]):List[(T, Int)] = {
        pack(xs).map(xs1 =>(xs1.head, xs1.length))
    }

    def mapFun[T, U](xs: List[T], f: T => U): List[U] =
        (xs foldRight List[U]())(f(_) :: _)

    def lengthFun[T](xs: List[T]): Int =
        (xs foldRight 0)((x, y)=> 1+y)


}
