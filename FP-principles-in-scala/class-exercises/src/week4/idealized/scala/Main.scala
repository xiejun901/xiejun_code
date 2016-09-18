package week4.idealized.scala

import sun.nio.cs.FastCharsetProvider

/**
  * Created by xiejun on 16-9-18.
  */
object Main {

    def main(args: Array[String]) {
        println("true: " + True)
        println("false: " + False)
        println("true && true: " + (True && True))
        println("true && false: " + (True && False))
        println("true || true: " + (True || True))
        println("true || false: " + (True || False))
        println("!true: " + !True)
        println("!false: " + !False)

        val n0 = Zero //0
        val n1 = n0.successor
        val n2 = n1.successor
        val n3 = n1 + n2
        val n4 = n2 + n2
        val n5 = n4.successor
        val n5_1 = n5 - n1
        println("0: "  + n0)
        println("1: " + n1)
        println("2: " + n2)
        println("3: " + n3)
        println("4: " + n4)
        println("5: " + n5)
        println("5-1=4: " + n5_1)

    }

}
