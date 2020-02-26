
let k3 = (3+4, 2. , 2<4);;

let k2 = (k3, 5);;

(*zadanie 1*)


(*Zdefiniuj funkcję flatten : 'a list list -> 'a list, która dla argumentu będącego listą list
 tworzy listę, złożoną z elementów wszystkich podlist z zachowaniem ich kolejności,
 np. flatten [[5;6];[1;2;3]] zwraca [5; 6; 1; 2; 3], czyli spłaszcza listę o jeden poziom.
 Scala flatten: [A] (xss: List[List[A]]) List[A]*)

let list11 = [1; 4; 7];;
let list12 = [2; 12; 9];;
let list13 = [list1; list2];;

let rec flatten xss = 
	if xss=[] then []
	else (List.hd xss)@flatten(List.tl xss);;

let list14 = flatten(list3)

(*zadanie 2*)

let list21 = ["a"; "b"; "a"; "c"; "a"; "d"];

let rec count (a, xs) =
	if xs=[] then 0
	else if List.hd xs = a then 1 + count (a, List.tl xs)
	else count(a, List.tl xs)


count("a", list21)

(*Zadanie 3*)



	



