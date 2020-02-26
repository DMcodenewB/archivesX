//zadanie 1a
class Time (private var h:Int) {    
  if (h<0) h=0      
  def hour:Int=h                              
  
  def hour_=(newHour:Int){
    if(newHour<0) h=0              
    else h=newHour
  }
}

val t = new Time(5)
t.hour
                      //tu sobie sprawdzałem to po prostu
t.hour = -12
t.hour

//zadanie 1b

class Time (private var h:Int) {     
  if (h<0) h=0                            
  def hour:Int=h                              
  
  def hour_=(newHour:Int){
    if(newHour<0) h=0              
    else h=newHour
  }
}
object Time {
  def apply (hour:Int) = new Time(hour)
  
  def main(args:Array[String]){
    var time1 = apply(5)
  }
}                                          //klasę i obiekt trzeba zadeklarować jednocześnie

var time2 = Time.apply(5);                 //tutaj nie jestem pewien, 
                                           //ale chyba time2 dostaje wartość lokalnej zmiennej time1
time2.hour                                 //w sensie sam to napisałem ale nie jestem pewien jak działa xD

//zadanie 2

class Time (private var h:Int, private var min:Int){
 require(h >= 0 && h <= 23, "incorrect hour")
 require(min >= 0 && min <= 59, "incorrect minute")
 
 def hour:Int = h
 def minute:Int = min
 
 def hour_=(newHour:Int){
   require(newHour >= 0 && newHour <= 23, "incorrect hour")
   h = newHour
 }
 
 def minute_=(newMinute:Int){
   require(newMinute >= 0 && newMinute <= 59, "incorrect minute")
   min = newMinute
 }
 
 def before(other:Time):Boolean =
   h < other.h || h == other.h && min < other.min
}

val time3 = new Time(2, 28)
val time4 = new Time(23, 59)
time3.hour
time3.minute
time3.minute_=(1)
//------------taka drobna metoda do drukowania czasu
def printTime(time:Time):Unit=
  println(time.hour.toString() + ":" + time.minute.toString);

printTime(time3)
printTime(time4)
//------------

time3.before(time4) //działa

//zadanie 3
class Pojazd(private val producent:String, private val model:String, private var numer_rej:String, private val rocznik:Int){
  
  def this(producent:String, model:String){
    this(producent, model, "", -1)
    println("brak rocznika oraz rejestracji")
  }
  def this(producent:String, model:String, numer_rej:String){
    this(producent, model, numer_rej, -1)
    println("brak rocznika")
  }
  def this(producent:String, model:String, rocznik:Int){
    this(producent, model, "", rocznik)
    println("brak rejestracji")
  }
  
}

val poj1 = new Pojazd("Seat", "Ibiza")
val poj2 = new Pojazd("Ford", "Focus", "DW 221OP")
val poj3 = new Pojazd("Bugatti", "Veyron", 2015)
val poj4 = new Pojazd("Skoda", "Octavia", "DW 239EW", 2016)


//opcjonalnie można by dodać toStringa jeszcze
//polecam stronę 
//https://alvinalexander.com/scala/how-to-create-multiple-class-constructors-in-scala-alternate-constructors

