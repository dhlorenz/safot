#import "chic.h"
#import "Handle.cc"
Occasionally(Id, Handle, // An S-expression represented by its Knob
  using Handle::handle;
  typedef Handle Inner;
  // Composition
  Id(Short);
)
inline auto operator ==(const Id s1, const Id s2) is (s1.handle() == s2.handle())
