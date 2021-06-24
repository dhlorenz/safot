#include "layout.h"

Word::Word(Short s1_, Short s2_): s1(s1_), s2(s2_) {}
Word::Word() {}
Property(Short Word::hash) Is($P_f$ + (unsigned)(l * 31 + 17) % $P_n$);

#include "Test.h"

TEST(Word, hash) { 
  EXPECT_NE(Word(3,4).hash(), Word(4,3).hash());
  EXPECT_NE(Word(3,4).hash(), Word(4,3).hash());
  EXPECT_NE(Word(2,3).hash(), Word(4,5).hash());
  EXPECT_NE(Word(2,3).hash(), Word(4,5).hash());
  EXPECT_GT(Word(2,3).hash(), 4);
  EXPECT_GT(Word(3,4).hash(), 3);
  EXPECT_GT(Word(4,5).hash(), 4);
}

TEST(Word, churnHash) { 
  enum {N = 100000};
  int n = 0;
  for (Short i = 0;  ; i++) { 
    for (Short j = 0;  i <= j; j++) {
      const Short h = Word(i,j).hash();
      EXPECT_GE(h, $P_f$);
      EXPECT_LE(h, $P_t$);
      if (++n >= N)
        return;
    }
  }
}