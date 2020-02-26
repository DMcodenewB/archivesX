//zadanie 2
//funkcja 2a

def fib (x:Int):Int =
  if (x == 0) 0
  else if (x == 1) 1
  else fib(x-2) + fib(x-1)
  
val a = fib(12)
  
//funkcja 2b

def fibTail (x:Int):Int = {
  def fibTailRec (acc:Int, help1:Int, help2:Int):Int =
    acc match {
    case 0 => help1
    case 1 => help2
    case _ => fibTailRec(acc-1, help2, help1+help2)
  }
fibTailRec(x, 0, 1)
}

val b = fibTail(12)

//zadanie 3



//zadanie 4

val x = 0

def list1 = List(-2,-1,0,1,2)
def list2 = List((1, 2), (0, 1))

//pasujące wzorce:
//a:

List(_,_,x,_,_)
_::_::x::_::_

//b:

List((_,_),(x,_))
_::List((x,_))

//zadanie 5


//xs to segment listy, ys to lista
def initSegment [A](xs:List[A], ys:List[A]):Boolean =
  (xs, ys) match{
  case (Nil, _) => true
  case (_, Nil) => false
  case _ => if (xs.head==ys.head) initSegment(xs.tail, ys.tail)
            else false
}

initSegment(List(1,2,3), List(1,2,3,4))

//zadanie 6

def replaceNth [A](xs:List[A], index:Int, x:A):List[A] =
  (xs, index) match {
  case (Nil,_) => Nil
  case (h::t, 0) => x::t
  case (h::t, _) => h::replaceNth(t, index-1, x)
}
 
replaceNth(List(1,2,3,4,6), 3, 2)


  
  
  
  
  
  
  
  