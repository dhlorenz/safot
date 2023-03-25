# Prolog

## lists

---

a **list** is a sequence of any number of terms

```prolog
[1, 2, 3]
[a, b, c, d]
[a, [1, 2, 3], tom, 15, date(1, may, 1995)]
```

<!--vert-->

a list is actually a pair of a head and a tail

```prolog
[Head | Tail]
[A, B, C] = [A | [B | [C | []]]] = [A, B | [C]]
```

---

### length/2

```prolog
length([], 0).
length([_|Tail], N) :-
    length(Tail, N1),
    N is 1 + N1.
```

```prolog
?- length([a, b, [c, d], e], N).

?- length(L, 4).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

<!--vert-->

### length with CLP(FD)

```prolog
length([], 0).
length([_|Tail], N) :-
    N #= N1 + 1,
    length(Tail, N1).
```

---

### list predicates

<!--vert-->

#### is_list/1 (predefined)

```prolog
...
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

```prolog
?- is_list(17).
?- is_list([1, 2, 3]).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

<!--vert-->

```prolog
is_list([]).
is_list([X|Xs]) :- is_list(Xs).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

<!--vert-->

#### member/2 (predefined)

```prolog
...
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

```prolog
?- member(X, [17, 13, 2, 5]).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

<!--vert-->

```prolog
member(X, [X|Xs]).
member(X, [Y|Ys]) :- member(X, Ys).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

<!--vert-->

#### prefix/2

```prolog
...
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

```prolog
?- prefix(X, [a, b, c, d]).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

<!--vert-->

```prolog
prefix([], L).
prefix([X|Xs], [X|Ys]) :- prefix(Xs, Ys).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

<!--vert-->

#### suffix/2

```prolog
...
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

```prolog
?- suffix(X, [1, 2, 3]).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

<!--vert-->

```prolog
suffix(Xs, Xs).
suffix(Xs, [Y|Ys]) :- suffix(Xs, Ys).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

<!--vert-->

#### del/3

```prolog
del(X, L, R)
```

`R` is `L` without one of the occurrences of `X`

```prolog
...
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

```prolog
?- del(2, [1, 2, 3, 2, 3, 2], X).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

<!--vert-->

```prolog
del(X, [X|Xs], Xs).
del(X, [Y|Ys], [Y|Zs]) :- del(X, Ys, Zs).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

<!--vert-->

#### insert/3

```prolog
...
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

```prolog
?- insert(3, [1, 2, 3], X).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

<!--vert-->

```prolog
insert(X, L, R) :- del(X, R, L).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

<!--vert-->

#### append/3

```prolog
...
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

```prolog
?- append([1, 2], [3, 4, 5], X).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

<!--vert-->

```prolog
append([], Ys, Ys).
append([X|Xs], Ys, [X|Zs]) :- append(Xs, Ys, Zs).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

<!--vert-->

#### define member/2 using append/3

```prolog
...
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

<!--vert-->

```prolog
member(X, Xs) :- append(_, [X|_], Xs).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

<!--vert-->

#### sublist/2

```prolog
...
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

<!--vert-->

```prolog
sublist(Xs, Ys) :-
    append(As, Bs, Ys),
    append(Xs, Cs, Bs).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

<!--vert-->

```prolog
prefix(Xs, Ys) :- append(Xs, _, Ys).

suffix(Xs, Ys) :- append(_, Xs, Ys).

sublist(Xs, Ys) :-
    prefix(Ps, Ys),
    suffix(Xs, Ps).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

<!--vert-->

#### permutation/2

```prolog
...
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

```prolog
?- permutation([1, 2, 3], X).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

<!--vert-->

```prolog
permutation([], []).
permutation([X|L], P) :-
    permutation(L, L1),
    insert(X, L1, P).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->
