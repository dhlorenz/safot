# Prolog

## introduction

---

### basic constructs

<!--vert-->

the basic constructs of prolog are terms and statements

<!--vert-->

#### terms - atoms

the simplest term is an **atom**, the following are atoms:

```prolog
john
$<@
'an atom'
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

<!--vert-->

an **atom** is

* a string of letters, digits, and an underscore starting with a **lower-case letter**: `anna` `x_25` `nil`
* a string of special characters (`+ - * / < > = : . & _ ~`): `$<@` `<---->` `.:.`
* a string of characters enclosed in single quotes: `'Tom'` `'2A$'`

<!--vert-->

#### terms - numbers

* integers: `123` `-42`
* real numbers: `3.14` `-0.573` `2.4e3`

<!--vert-->

#### terms - variables

a **variable** is a string of letters, digits and an underscore starting with an upper-case letter or an underscore

```prolog
X_25
_result
```

<!--vert-->

#### compound terms

a **compound term** comprises a functor and arguments

```prolog
course(236319, pl)
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

a functor `f` of arity `n` is denoted `f/n`

<!--vert-->

#### terminology

* a term is **ground** (קונקרטי) if it contains no variables
* a **goal** is an atom or a compound term
* a **predicate** (פרדיקט) is a functor for which a list of clauses is defined
* a **clause** (פסוקית) is a fact or a rule

<!--vert-->

#### facts

a **fact** (עובדה) is a kind of statement

```prolog
eats(bunny, carrot).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

this fact states that the **predicate** `eats` holds for the atoms `bear` and `honey`

<!--vert-->

facts can have any arity

```prolog
summer.
sad(john).
plus(2, 3, 5).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

<!--vert-->

a finite set of facts constitutes a program

```prolog
mammal(rat).
mammal(bear).
fish(salmon).
eats(bear, honey).
eats(bear, salmon).
eats(rat, salmon).
eats(salmon, warm).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" --> 

<!--vert-->

facts can contain variables

```prolog
likes(X, course236319).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" --> 

variables are universally quantified

$$\forall X,likes(X, course236319)$$

<!--vert-->

#### queries

a **query** (שאילתה) is a conjunction of goals

```prolog
?- eats(X, salmon), eats(X, honey).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" --> 

variables are existentially quantified

$$\exists X,eats(X, salmon) \land eats(X, honey)$$

<!--vert-->

#### rules

a **rule** (חוק, כלל) is a statement which enables us to define new relationships in terms of existing ones

```prolog
predicate(term1, ..., termN) :- goal1, ..., goalN.
```

<!--vert-->

`Y` is a survival dependency of `X` if:

* `X` eats `Y`
* or `X` eats `Z` and `Y` is a survival dependency of `Z`

```prolog
survival_dependency(X, Y) :- eats(X, Y).
survival_dependency(X, Y) :-
    eats(X, Z), survival_dependency(Z, Y).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" --> 

```prolog
?- survival_dependency(bear, X).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

---

### writing Prolog programs

* create a file named `prog.pl`
* write clauses in `prog.pl`
* enter the prolog interpreter
* type `consult(prog.pl)`
* query the interpreter

<!--vert-->

#### dynamic clauses

you can add clauses dynamically

```prolog
:- assertz(eats(bear, tuna)).
:- assertz((
  mother(Child, Mother) :-
    parent(Child, Mother),
    female(Mother)
)).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

```prolog
?- eats(bear, tuna).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

`asserta` asserts the clause as first clause of the predicate while `assertz` asserts it as last clause

<!--vert-->

dynamically remove a clause using `retract/1`

```prolog
:- assertz(q(a)).
:- assertz((p(X) :- q(X))).
:- assertz(p(b)).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

```prolog
:- retract(p(X) :- q(a)).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

```prolog
?- p(a).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

<!--vert-->

dynamically remove clauses using `retractall/1`

```prolog
:- assertz(q_2(a)).
:- assertz((p_2(X) :- q_2(X))).
:- assertz(p_2(b)).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

```prolog
:- retractall(p_2(_)).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

```prolog
?- p_2(a).
?- p_2(b).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

<!--vert-->

dynamically remove a predicate using `abolish/1`

```prolog
:- assertz(p(a)).
:- assertz(p(b)).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

```prolog
:- abolish(p/1).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

```prolog
?- p(X).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

---

### meaning of a prolog program

* declarative meaning
  * the inference algorithm is an implementation detail
  * not always easy to achieve
* procedural meaning
  * but thinking procedurally makes it harder to come up with an elegant solution
  * beats the purpose of the paradigm

---

### matching

two terms match if:

* they are identical
* the variables in both terms can be instantiated to make the terms identical

<!--vert-->

the operator `=` performs matching

```prolog
?- course(N, S, 95) = course(X, fall, G).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

<!--vert-->

```prolog
?- course(N, S, 95) = course(Y, M, 96).

?- course(X) = semester(Y).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

<!--vert-->

#### matching rules

terms `S` and `T` match if:

* `S` and `T` are the same atom
* `S` and `T` are the same number
* if one is a variable it's instantiated to the other
* if `S` and `T` are compound terms, they match iff:
  * they have the same functor and arity
  * all their corresponding arguments match
  * the variable instantiations are compatible

<!--vert-->

#### geometric example

use compound terms to represent geometric shapes

```prolog
point(1, 1)
seg( point(1, 1), point(2, 3) )
triangle( point(4, 2), point(6, 4), point(7, 1) )
```

<!--vert-->

```prolog
?- triangle(point(1, 1), A, point(2, 3))
=
triangle(X, point(4, Y), point(2, Z)).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

<!--vert-->

#### matching as means of computation

facts:

```prolog
vertical(seg(
    point(X, Y1),
    point(X, Y2)
)).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

queries:

```prolog
?- vertical(seg(point(1, 1), point(1, 2))).

?- vertical(seg(point(1, 1), point(2, Y))).

?- vertical(seg(point(2,3), P)).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

---

### arithmetic

* the operators `+ - * / div mod` are (infix) binary relations
* but they are arithmetic operators after the operator `is`

```prolog
?- X = 1 + 2.

?- X is 1 + 2.
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

<!--vert-->

#### comparison operators

```prolog
X > Y
X < Y
X >= Y
X =< Y
X =:= Y  % equal
X =\= Y  % not equal
```

<!--vert-->

the comparison operators also force evaluation

```prolog
?- 11 * 6 = 66.

?- 11 * 6 =:= 66.
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

<!--vert-->

#### `=` VS. `=:=`

* `=` is used for matching and may instantiate variables
* `=:=` causes an arithmetic evaluation of its operands and cannot instantiate variables

```prolog
?- 1 + X = Y + 2.

?- 1 + X =:= Y + 2.
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

<!--vert-->

#### GCD

```prolog
gcd(X, X, X).
gcd(X, Y, D) :-
    X < Y,
    Y1 is Y - X,
    gcd(X, Y1, D).
gcd(X, Y, D) :-
    Y < X,
    gcd(Y, X, D).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

```prolog
?- gcd(12, 30, D).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

---

### builtin control predicates

<!--vert-->

#### conjunction `,/2`

the goal `(G1, G2)` succeeds if `G1` and `G2` succeed

<!--vert-->

#### disjunction `;/2`

the goal `(G1 ; G2)` succeeds if `G1` or `G2` succeed

defined as follows:

```prolog
(G1 ; G2) :- G1.
(G1 ; G2) :- G2.
```

<!--vert-->

#### true

the predicate `true/0` always succeeds

<!--vert-->

#### false

the predicates `false/0` and `fail/0` always fail

<!--vert-->

#### negation as failure

* the negation predicate is `\+/1`
* for known predicates, prolog works under a closed world assumption - if something can't be proved then it is false
* it is not logical negation!

<!--vert-->

```prolog
person(jimmy).
person(cindy).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

```prolog
?- person(rick).
?- \+ person(rick).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

<!--vert-->

it might not work like you'd expect

```prolog
?- person(X).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

```prolog
?- \+ person(X).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

why doesn't prolog answer with `X = rick` or simply with `true`?

<!--vert-->

`person(X)` succeeds so its negation fails

* if `G` fails `\+ G` succeeds
* if `G` succeeds `\+ G` fails

<!--vert-->

`\+/1` allows for non-monotonic reasoning - a fact can become false by adding clauses to the database

```prolog
illegal(murder).
legal(X) :- \+ illegal(X).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

```prolog
illegal(theft).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

```prolog
?- legal(theft).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

---

### exercise - family tree

you have a database with the following predicate

```prolog
parent(X, Y).  % X is Y's parent
```

```prolog
% examples:
parent(adam, cain).
parent(eve, cain).
parent(cain, enoch).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

define a predicate `grandparent(X)` that holds when `X` is a grandparent

<!--vert-->

```prolog
...
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

```prolog
?- grandparent(X).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

<!--vert-->

```prolog
grandparent(X) :- parent(X, Y), parent(Y, _).
```

<!--vert-->

define a predicate `nuclear(X, Y)` that holds when `X` and `Y` are in the same nuclear family

a nuclear family consists of 2 parents and their common children

<!--vert-->

```prolog
...
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

```prolog
?- nuclear(adam, X).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

<!--vert-->

```prolog
nuclear(X, Y) :-  % siblings
    parent(P1, X), parent(P2, X),
    parent(P1, Y), parent(P2, Y),
    \+(P1 = P2).  % alternatively: `P1 \= P2`

nuclear(X, Y) :-
    parent(X, C), parent(Y, C).

nuclear(X, Y) :-
    (parent(X, Y); parent(Y, X)).
```

---

### exercise - binary trees

we represent binary trees as terms:

* `nil` is the empty tree
* `node(N, Tl, Tr)` is a tree node where `N` is some number and `Tl` and `Tr` are binary trees

define a predicate `tree_size(T, S)` such that `T` is a binary tree and `S` is its size

<!--vert-->

```prolog
...
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

```prolog
?- tree_size(node(1,
	node(2, 
		nil, 
		nil
	),
	node(3,
		node(4, nil, nil),
		nil
	)),
	S).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

<!--vert-->

```prolog
tree_size(nil, 0).
tree_size(node(_, Tl, Tr), S) :-
    tree_size(Tl, Sl),
    tree_size(Tr, Sr),
    S is Sl + Sr + 1.
```

<!--vert-->

define a predicate `tree_max(T, M)` such that `T` is a binary tree and `M` is the max of the values of `T`'s nodes

you may use the arithmetic function `max/2`

```prolog
...
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

<!--vert-->

```prolog
?- tree_max(node(10,
    node(-3, 
        nil, 
        nil
    ),
    node(14,
        node(4, nil, nil),
        nil
    )),
    M).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

<!--vert-->

```prolog
tree_max(node(N, nil, nil), N).
tree_max(node(N, nil, Tr), M) :-
    tree_max(Tr, Mr), M is max(N, Mr).
tree_max(node(N, Tl, nil), M) :-
    tree_max(Tl, Ml), M is max(N, Ml).
tree_max(node(N, Tl, Tr), M) :-
    tree_max(Tl, Ml),
    tree_max(Tr, Mr),
    M is max(N, max(Ml, Mr)).
```

<!--vert-->

define a predicate `perfect_tree(T, H)` such that `T` is a perfect binary tree and `H` is its height

a node's value should be its height

a perfect binary tree is a binary tree in which all interior nodes have two children and all leaves have the same depth

<!--vert-->

```prolog
...
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

```prolog
?- perfect_tree(T, 2).
```
<!-- .element: data-thebe-executable-prolog data-language="text/x-prolog" -->

<!--vert-->

```prolog
perfect_tree(nil, 0).
perfect_tree(node(H, Tl, Tl), H) :-
    H > 0,
    H1 is H - 1,
    perfect_tree(Tl, H1).
```
