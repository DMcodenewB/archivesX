(*zadanie 1*)
let f1 x = x 2 2

(* val f1 : (int -> int -> 'a) -> 'a = <fun> *)

let f2 x y z = x(y^z)

(* val f2 : (string -> 'a) -> string -> string -> 'a = <fun> *)

(*zadanie 2*)

let curry3 f x y z = f(x,y,z)
(* val curry3 : ('a * 'b * 'c -> 'd) -> 'a -> 'b -> 'c -> 'd = <fun> *)

let uncurry3 f(x,y,z) = f x y z
(*val uncurry3 : ('a -> 'b -> 'c -> 'd) -> 'a * 'b * 'c -> 'd = <fun>*)


(*zadanie 4*)

let rec quicksort = function              
[] -> []
| [x] -> [x]         
|  xs -> let small = List.filter (fun y -> y < List.hd xs ) xs                     
						and large = List.filter (fun y -> y >= List.hd xs ) xs                     
		in quicksort small @ quicksort large;;

quicksort([1;4;7;3;5])

(*funkcja quicksort powoduje stack overflow poprzez nieskończoną pętlę*)

let rec quicksort' = function
	| [] -> []
	| x::xs -> let small = List.filter (fun y -> y < x) xs
						 and large = List.filter (fun y -> y >x) xs
in quicksort' small@(x::quicksort' large)

quicksort'[3;2;1]
quicksort'[3;2;3]

(*funkcja quicksort' pomija powtarzające się elementy listy*)
