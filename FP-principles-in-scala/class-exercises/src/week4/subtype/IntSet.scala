package week4.subtype

/**
  * Created by xiejun on 16-9-20.
  */
abstract class IntSet {
    def isEmpty:Boolean
}

class Empty extends IntSet{
    def isEmpty = true
}

class NonEmpty extends IntSet{
    def isEmpty = false
}
