//zadanie 1

class GenericCellMut[+T](var x:T){}
//<console>:11: error: covariant type T occurs in contravariant position in type T of value x_

class GenericCellMut[T](var x:T){}
//defined class GenericCellMut

class GenericCellMut[-T](var x:T){}
//<console>:11: error: contravariant type T occurs in covariant position in type => T of variable x

//https://docs.scala-lang.org/tour/variances.html

//zadanie 3

class MyQueue[+T] private (private val q:(List[T], List[T])){
  def enqueue[S>:T](e:S):MyQueue[S]={
    q match{
      case (Nil, Nil) => new MyQueue((e, Nil))
      case (xl, yl) => new MyQueue[S](xl, e::yl)
      
    }
  }
  def dequeue()={
    q match {
      case (Nil, Nil) => this
      case (_::Nil, yl) => new MyQueue[T](y1.reverse, Nil)
      case (_::t1, Nil) => new MyQueue[T](t1, yl)
    }
  }
  def first():T ={
    q match{
      case (Nil, Nil) => throw new Exception("empty")
      case (h::_, _) => h
      case (Nil, _::_) => throw new Exception("sth")
    }
  }
  def isEmpty:Boolean ={
    q match{
      case (Nil, Nil) => true
      case _ => false
    }
  }
  object MyQueue{
    def apply[T](xs:T*) = new MyQueue[T](xs.toList, Nil)
  }
  
  //jeszcze jedna metoda była tylko nie przepisałem
  //ten kod nie działa generalnie, trzeba będzie go poprawić
}