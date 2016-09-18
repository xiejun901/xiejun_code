package week4.idealized.scala

/**
  * Created by xiejun on 16-9-18.
  */
abstract class Boolean {
    def ifThenElse[T](t: => T, e: => T ): T

    def &&(x: => Boolean): Boolean = ifThenElse(x, False)
    def ||(x: => Boolean): Boolean = ifThenElse(True, x)
    def unary_! : Boolean = ifThenElse(False, True)

    def ==(x: => Boolean): Boolean = ifThenElse(x, x.unary_!)
    def !=(x: => Boolean): Boolean = ifThenElse(x.unary_!, x)

    def <(x: => Boolean): Boolean = ifThenElse(False, x)
    override def toString = ifThenElse("true", "false")
}


object True extends Boolean{
    def ifThenElse[T](t: => T, e: => T): T = t
}

object False extends Boolean{
    def ifThenElse[T](t: => T, e: => T): T = e
}

abstract class Nat {
    def isZero: Boolean
    def predecessor: Nat
    def successor: Nat = new Succ(this)
    def + (that: Nat): Nat
    def - (that: Nat): Nat
}

object Zero extends Nat{
    def isZero = True
    def predecessor: Nothing = throw new NoSuchElementException("Zero.predessor")
    def + (that: Nat): Nat = that
    def - (that: Nat): Nothing = throw new UnsupportedOperationException("")
    override def toString = ""
}
class Succ(n: Nat) extends Nat{
    def isZero = False
    def predecessor = n
    def + (that: Nat): Nat = new Succ(n + that)
    def - (that: Nat): Nat = that.isZero.ifThenElse(this, predecessor - that.predecessor)
    override def toString = "| " + n
}