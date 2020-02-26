//zadanie 2

def curry3[A,B,C,D](f:(A,B,C)=>D) = 
  (x:A)=>(y:B)=>(z:C)=>f(x,y,z)
  
def uncurry3 [A,B,C,D](f: A=>B=>C=>D) =
  (x:A, y:B, z:C)=> f(x)(y)(z)
  
  

