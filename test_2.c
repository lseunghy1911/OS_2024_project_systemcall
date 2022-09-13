#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[]) {
    int x1 = getreadcount();

    int rc = fork();

    int total = 0;
    int i;
    for (i = 0; i < 100000; i++) {
	char buf[100];
	(void) read(4, buf, 1);
    }

    if (rc > 0) {
	(void) wait();
	int x2 = getreadcount();
	total += (x2 - x1);
	printf(1, "Output: %d\n", total);
	printf(1, "Answer: %d\n", 100000);
	if(total == 100000){
	  printf(1, "You are right!\n");
	}
	else{
	  printf(1, "You are wrong..\n");
	}
    }
    exit();
}
