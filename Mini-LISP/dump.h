#ifndef DUMP_H_
#define DUMP_H_

// Make a FOREACH macro
#define FE_0(WHAT, BETWEEN, ...)    <<""
#define FE_1(WHAT, BETWEEN, X, ...) WHAT(X) FE_0(WHAT, BETWEEN, __VA_ARGS__) 
#define FE_2(WHAT, BETWEEN, X, ...) WHAT(X) BETWEEN FE_1(WHAT, BETWEEN, __VA_ARGS__)
#define FE_3(WHAT, BETWEEN, X, ...) WHAT(X) BETWEEN FE_2(WHAT, BETWEEN, __VA_ARGS__)
#define FE_4(WHAT, BETWEEN, X, ...) WHAT(X) BETWEEN FE_3(WHAT, BETWEEN, __VA_ARGS__)
#define FE_5(WHAT, BETWEEN, X, ...) WHAT(X) BETWEEN FE_4(WHAT, BETWEEN, __VA_ARGS__)
#define FE_6(WHAT, BETWEEN, X, ...) WHAT(X) BETWEEN FE_5(WHAT, BETWEEN, __VA_ARGS__)
//... repeat as needed

#define GET_MACRO(_0,_1,_2,_3,_4,_5,_6,NAME,...) NAME 
#define FOR_EACH(action,between, ...) \
  GET_MACRO(_0,__VA_ARGS__,FE_6,FE_5,FE_4,FE_3,FE_2,FE_1,FE_0)(action, between,__VA_ARGS__)

#include <iostream>
#define LOCATION std::cerr << __FILE__  << "(" << __LINE__ << ")/" << __FUNCTION__ << "(): "
#define DUMP(X) <<#X<<"="<<X
#define SEP   <<"; " 
#define D(...) LOCATION FOR_EACH(DUMP,SEP,__VA_ARGS__) << std::endl

#if 0
void main() {
  int A, B, C, D, E, F;
  L FOR_EACH(DUMP,SEP) << std::endl;
  L FOR_EACH(DUMP,<<"; ") << std::endl;
  L FE_0(DUMP,SEP) << std::endl;

  D(A);
  D(A,B);
  D(A,B,C);
  D(A,B,C,D);
  D(A,B,C,D,E);
  D(A,B,C,D,E,F);
}
#endif


#define normally(x) if (x); else  {\
  fprintf(stderr,"\n\n** Aborting at %s/%s (%d): Expression (%s) evaluated to false\n",__FILE__, __FUNCTION__, __LINE__,#x); \
  throw (__LINE__); \
}

// #define D(...) LOCATION FOR_EACH(DUMP,__VA_ARGS__) << std::endl



#endif /* DUMP_H_ */
