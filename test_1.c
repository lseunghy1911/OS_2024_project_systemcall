#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[]) {
  int x1 = getreadcount();
  int x2 = getreadcount();
  char buf[100];
  (void) read(4, buf, 1); 
  int x3 = getreadcount();
  int i;
  for (i = 0; i < 1000; i++) {
    (void) read(4, buf, 1); 
  }
  int x4 = getreadcount();
  printf(1, "Output: %d %d %d\n", x2-x1, x3-x2, x4-x3);
  printf(1, "Answer: %d %d %d\n", 0, 1, 1000);
  if(x2 - x1 == 0 && x3 - x2 == 1 && x4 - x3 == 1000){
    printf(1, "You are right!\n");
  }
  else{
    printf(1, "You are wrong..\n");
  }
  exit();
}
