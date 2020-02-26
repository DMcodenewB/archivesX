//zadanie 1

def flatten[A](xs:List[List[A]]):List[A] =
  if (xs==Nil) Nil
  else xs.head ++ flatten(xs.tail)
  
def list1 = List(1, 2, 1)
def list2 = List(5,6,7,8)
def list3 = List(list1, list2)
print(list3)
def list4 = flatten(list3)
print(list4)

//zadanie 2

def count [A](a:A, xs:List[A]):Int = 
  if (xs==Nil) 0
  else if (xs.head == a) 1 + count(a, xs.tail)
  else count(a, xs.tail)
  
  count(1, list1)
  
//zadanie 3

def replicate [A](num:Int, word:A):List[A] =
  if (num == 0) Nil
  else word::replicate(num-1, word)
  
def list5 = replicate(4, "ala")
print(list5)

//zadanie 4

def powerFunc (xs:List[Int]):List[Int] = 
  if (xs == Nil) Nil
  else (xs.head * xs.head)::powerFunc(xs.tail)
  
def list6 = powerFunc(list2)
print(list6)

//zadanie 5

def palindrome [A](xs:List[A]):Boolean = 
  if (xs == xs.reverse) true
  else false
  
print(palindrome(List(2,1,3)))

//zadanie 6

def listLength [A](xs:List[A]):Int =
  if (xs==Nil) 0
  else 1 + listLength(xs.tail)
  
print(listLength(List(1,2,3,5)))

