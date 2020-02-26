(*zadanie 2

funkcja 2a*)

let rec fib x =
	if x==0 then 0
	else if x==1 then 1
	else fib(x-1) + fib(x-2);;
	
	fib 15;;

(*funkcja 2b*)

let fibTail x =
	let rec fibTailRec(acc, help1, help2) =
		match acc with 
		| 0 -> help1
		| 1 -> help2
		| _ -> fibTailRec(acc-1, help2, help1+help2)
	in fibTailRec(x, 0, 1)
	
	fibTail 20;;

(*zadanie 3*)

(* let findCubeRoot (x, sigma) =     *)

(*zadanie 4*)
(*przykłady takich wzorców*)

let x = 0;;
let list1 = [-2;-1;0;1;2]
let list2 = [(1,2);(0,1)]

let [_;_;x;_;_] = [-2;-1;0;1;2]
let _::_::x::_::_::[] = list1
let [(_,_);(x,_)] = list2

let _::(-1)::x::_ = list1


(* przykłady działających wzorców: *)
(* a: *)
[_;_;x;_;_]
_::_::x::_::_::[]
(* b: *)
[(_,_);(x,_)]
_::[(x,_)]


let list3 = 1::2::3::4::[]


(*zadanie 5*)

(*xs to fragment listy, ys to lista*)
let rec initSegment(xs, ys) =
	match (xs, ys) with
	| ([], _) -> true
	| (_, []) -> false
	| _ -> if List.hd xs == List.hd ys then initSegment(List.tl xs, List.tl ys)
	 			 else false;;

let segment1 = [1;2;3;4]
let segment2 = [2;3;4;6]
let segment3 = [4;5]
let newlist = [1;2;3;4;5;6]

initSegment(segment1, newlist)
initSegment(segment2, newlist)
initSegment(segment3, newlist)


(*zadanie 6*)


let rec replaceNth (xs, index, x) =
	match (xs, index) with
	| ([],_) -> []
	| (h::t, 0) -> x::t
	| (h::t, index) -> h::replaceNth(t, index-1, x);;

replaceNth([1;2;3;4;5;5;6;7;9], 4, 5);;

(*dla wartości index większej niż 2 *)
(*program wyrzuca Exception: Match_failure ("//toplevel//", 10, 1).*)




