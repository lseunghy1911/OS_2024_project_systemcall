#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[]) {
    char buf[100];
	int base_read = getreadcount();
	
    for (int i = 0; i < 1000; i++) (void) read(4, buf, 1);

    int rc = fork();
    int right = 0;

    if (rc > 0) {
	    (void) wait();
		for (int i = 0; i < 1000; i++) (void) read(4, buf, 1);
    	
		int parent_read = getreadcount();

    	printf(1, "Parent Read: %d\n", parent_read - base_read);

		if(parent_read - base_read == 2000)	right = 1;
		
    }
    else {
		char buf[100];
		for (int i = 0; i < 500; i++) (void) read(4, buf, 1);
		
		int child_read = getreadcount();

        printf(1, "Child Read: %d\n", child_read - base_read);

		if(child_read - base_read == 1500) right = 1;
    }
    
    if(right) printf(1, "You are right!\n");
    
    else printf(1, "You are wrong..\n");
    
    exit();
}
