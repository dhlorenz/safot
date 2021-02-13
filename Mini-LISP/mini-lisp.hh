#include <cstdint>

#define perspective(...) struct{__VA_ARGS__;};
#define	returns(x) const {return x;}
#define representation union
#define define(...) enum{__VA_ARGS__};
#define function
#define property inline
#define procedure void
#define construct
#define destruct ~
#define by(...) :__VA_ARGS__{}

#define array(name,type,min,max) \
    static type buffer##__LINE__[(max)-(min)+1]; \
    static type *const name = buffer##__LINE__ - min;

#define let static
typedef const char *const String;

typedef int32_t W; // A full word of  32 bits; two half words
typedef int16_t H; // Half a word including 16 bits.

representation Pair { // Representation of a dotted pair
  perspective(W cons: 32)
  perspective(H car,cdr :16)
  perspective(H next :16)
};

namespace Pairs {
   extern Pair *const pool;
   extern H allocate(H car, H cdr);
   extern void free(H index);
};
namespace Strings { // Atoms are never freed in mini-lisp
  extern const char *const pool;
  extern H allocate(String s);
};


union S; 
extern S cons(S car, S cdr);
extern bool eq(S car, S cdr);
extern bool islist(S s); 

representation S { // Representation of an S expression.
  perspective(H index)
  construct S(H h) by (index(h));
  property bool null() returns  (index == 0)
  property bool atom() returns  (index <= 0)
  property String asAtom() returns  (Strings::pool + index)

  property Pair asCons() returns  (Pairs::pool[index])
  property S car() returns (asCons().car)
  property S cdr() returns (asCons().cdr)

  property S cons(const S s) returns (::cons(*this,s));
  property S eq(const S s) returns (::eq(*this, s));
  property bool islist() returns (::islist(*this));
  operator bool() const { return !null(); }

  perspective( H bits : 15;  bool sign: 1)
  construct S() by(bits(0), sign(0))

  construct S(S s1, S s2) by(index(Pairs::allocate(s1.index,s2.index)))
  construct S(String s) by(index(Strings::allocate(s)))
};


extern S alist;
extern const S NIL,T;

extern S list() ;
extern S list(S s);
extern S list(S s1, S s2);
extern S list(S s1, S s2, S s3);
extern S list(S s1, S s2, S s3, S s4);

extern S cons(S car, S cdr);
extern S car(S s);
extern S cdr(S s);
extern bool eq(S s1, S s2);
extern S atom(S s);
extern S eval(S s);
extern S set(S name, S value);

#undef construct