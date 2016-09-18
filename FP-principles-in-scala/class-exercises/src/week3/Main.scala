package week3

/**
  * Created by xiejun on 16-9-17.
  */
object Main {
    def main(args: Array[String]) {
        println("hello world")
        val l1 = List(1)
        val l2 = new Cons[Int](2, l1)
        val l3 = new Cons[Int](3, l2)
        try {
            println(l3 at 1)
            println(l3 at 2)
            println(l3 at 3)
            println(l3 at 4)
        } catch {
            case e: Exception => print(e)
        }
    }

}

trait List[T]{
    def empty:Boolean
    def head:T
    def tail: List[T]
    def at(index:Int):T
}

class Nil[T] extends List[T]{
    def empty = true
    def head:Nothing = throw new NoSuchElementException("Nil.head")
    def tail:Nothing = throw new NoSuchElementException("Nil.tail")
    def at(index:Int):T = throw new IndexOutOfBoundsException("")
    override def toString = ""
}

class Cons[T](val head:T, val tail:List[T]) extends List[T]{
    def empty = false
    override def toString = head + "," + tail
    def at(index:Int) = {
        if(index == 0) head
        else tail.at(index - 1)
    }

}

object List{
    def apply[T](elem:T): List[T] = new Cons[T](elem, new Nil[T])
}
