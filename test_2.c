#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[]) {
    int rc = fork();
    int base = getreadcount();
    int right = 0;

    if (rc > 0) {
	(void) wait();
	for (int i = 0; i < 1000; i++) {
	    char buf[100];
	    (void) read(4, buf, 1);
        }
	int parent = getreadcount();
        printf(1, "Parent: %d\n", parent-base);
	if(parent == 1000){
	    right = 1;
	}
    }
    else {
	for (int i = 0; i < 500; i++) {
	    char buf[100];
	    (void) read(4, buf, 1);
	}
	int child = getreadcount();
        printf(1, "Child: %d\n", child-base);
	if(child - base == 500){
	  right = 1;
	}
    }
    if(right){
      printf(1, "You are right!\n");
    }
    else{
      printf(1, "You are wrong..\n");
    }
    
    exit();
}
