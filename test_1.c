#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[]) {
    char buf[100];
	int base_read = getreadcount();
    int base_write = getwritecount();
	
    for (int i = 0; i < 1000; i++) (void) read(4, buf, 1);

    int rc = fork();
    int right = 0;

    if (rc > 0) {
	    (void) wait();
		for (int i = 0; i < 1000; i++) {
	    	(void) read(4, buf, 1);
        	if(i % 3 == 0) (void) write(4, buf, 1);
    	}

		int parent_read = getreadcount();
    	int parent_write = getwritecount();

    	printf(1, "Parent Read: %d\n", parent_read - base_read);
    	printf(1, "Parent Write: %d\n", parent_write - base_write);

		if(parent_read - base_read == 2000)	right = 1;
    	if(parent_write - base_write == 334) right *= 1;
		
    }
    else {
		char buf[100];
		for (int i = 0; i < 500; i++) {
	    	(void) read(4, buf, 1);
      		(void) write(4, buf, 1);
		}

		int child_read = getreadcount();
  		int child_write = getwritecount();

        printf(1, "Child Read: %d\n", child_read - base_read);
        printf(1, "Child Write: %d\n", child_write - base_write);

		if(child_read - base_read == 1500) right = 1;
 		if(child_write - base_write == 500)	right *= 1;
    }
    
    if(right) printf(1, "You are right!\n");
    
    else printf(1, "You are wrong..\n");
    
    exit();
}
