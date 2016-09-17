package week2.fixpoint

import scala.annotation.tailrec

/**
  * Created by xiejun on 16-9-16.
  */
object Main {

    val tolerance = 0.0001

    def main(args: Array[String]): Unit = {
        def sqrt(x: Double) = fixedPointIter(averageDamp(y => x / y))(1.0)
        val result = sqrt(2)
        println(result)
    }

    def isClosedEnough(x: Double, y: Double) = {
        math.abs((x - y) / x) / x < tolerance
    }

    def fixedPoint(f: Double => Double)(x: Double): Double = {
        if (isClosedEnough(f(x), x)) x
        else fixedPoint(f)(f(x))
    }

    def fixedPointIter(f: Double => Double)(x: Double) = {
        def iterate(guess: Double): Double = {
            val next = f(guess)
            if (isClosedEnough(guess, next)) guess
            else iterate(next)
        }
        iterate(x)
    }

    def averageDamp(f: Double => Double)(x: Double) = (x + f(x)) / 2
}
