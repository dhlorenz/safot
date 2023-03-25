# Lisp - EVAL

<!--vert-->

```lisp
(LABEL EVAL
	(LAMBDA (E A)
		(COND
        ((ATOM E)
			(COND 
			((EQ E NIL) 
				NIL)
			((EQ E T)
				T)
			(T
				(CDR 
				((LABEL ASSOC 
					(LAMBDA (E A)
						(COND
						((NULL A)
							NIL)
						((EQ E (CAAR A))
							(CAR A))
						(T
							(ASSOC E (CDR A)))))
				) E A)))))
```
<!-- .element: data-thebe-executable-javascript data-language="text/x-lisp" -->

<!--vert-->

```lisp
		((ATOM (CAR E))
			(COND
			((EQ (CAR E) (QUOTE QUOTE))
				(CADR E))
			((EQ (CAR E) (QUOTE CAR))
				(CAR (EVAL (CADR E) A)))
			((EQ (CAR E) (QUOTE CDR))
				(CDR (EVAL (CADR E) A)))
			((EQ (CAR E) (QUOTE ATOM))
				(ATOM (EVAL (CADR E) A)))
			((EQ (CAR E) (QUOTE NULL))
				(NULL (EVAL (CADR E) A)))
			((EQ (CAR E) (QUOTE CONS))
				(CONS (EVAL (CADR E) A) (EVAL (CADDR E) A)))
			((EQ (CAR E) (QUOTE EQ))
				(EQ (EVAL (CADR E) A) (EVAL (CADDR E) A)))
```
<!-- .element: data-thebe-executable-javascript data-language="text/x-lisp" -->

<!--vert-->

```lisp
			((EQ (CAR E) (QUOTE COND))
				((LABEL EVCOND
					(LAMBDA (U A) 
						(COND
						((EVAL (CAAR U) A)
							(EVAL (CADAR U) A))
						(T 
							(EVCOND (CDR U) A))))
				) (CDR E) A))
			(T
				(EVAL 
					(CONS 
						(CDR 
						((LABEL ASSOC
							(LAMBDA (E A)
								(COND
								((NULL A)
									NIL)
								((EQ E (CAAR A))
									(CAR A))
								(T
									(ASSOC E (CDR A)))))
						) (CAR E) A))
						(CDR E))
					A))))
```
<!-- .element: data-thebe-executable-javascript data-language="text/x-lisp" -->

<!--vert-->

```lisp
		((EQ (CAAR E) (QUOTE LAMBDA))
			(EVAL
				(CADDAR E)
				((LABEL FFAPPEND
					(LAMBDA (U V)
						(COND 
						((NULL U) 
							V)
						(T
							(CONS
								(CAR U)
								(FFAPPEND (CDR U) V))))))
					((LABEL PAIRUP
						(LAMBDA (U V)
							(COND
							((NULL U)
								NIL)
							(T
								(CONS 
									(CONS (CAR U) (CAR V))
								(PAIRUP (CDR U) (CDR V)))))))
						(CADAR E)
						((LABEL EVLIS
							(LAMBDA (U A)
								(COND
								((NULL U)
									NIL)
								(T
									(CONS 
										(EVAL (CAR U) A)
										(EVLIS (CDR U) (CDR E) A))))))
							(CDR E)
							A))
					A)))
```
<!-- .element: data-thebe-executable-javascript data-language="text/x-lisp" -->

<!--vert-->

```lisp
		((EQ (CAAR E) (QUOTE LABEL))
			(EVAL 
				(CONS (CADDAR E) (CDR E))
				(CONS (CONS (CADAR E) (CDR E)) A))))))
```
<!-- .element: data-thebe-executable-javascript data-language="text/x-lisp" -->

<!--vert-->

implement `(IF COND THEN ELSE)`

```lisp
(
    (EQ (CAR E) (QUOTE IF))

)
```
<!-- .element: data-thebe-executable-javascript data-language="text/x-lisp" -->

<!--vert-->

```lisp
(
    (EQ (CAR E) (QUOTE IF))
    (COND
        ((EVAL (CADR E) A) (EVAL (CADDR E) A))
        (T (EVAL (CADDDR E) A))
    )
)
```
<!-- .element: data-thebe-executable-javascript data-language="text/x-lisp" -->

<!--vert-->

implement `(LIST X1 X2 ...)`

```lisp
(
    (EQ (CAR E) (QUOTE LIST))

)
```
<!-- .element: data-thebe-executable-javascript data-language="text/x-lisp" -->

<!--vert-->

```lisp
(
    (EQ (CAR E) (QUOTE LIST))
    ((LABEL FLIST (LAMBDA (X A) (
        COND
            ((NULL X) NIL)
            (T (CONS (EVAL (CAR X) A) (FLIST (CDR X) A)))
    ))) (CDR E) A)
)
```
<!-- .element: data-thebe-executable-javascript data-language="text/x-lisp" -->
