#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[]) {
    int base = getancestorcount();
    
    int rc0 = fork();

    // Process A & B
    if (rc0 > 0) {
	    (void) wait();
       	
        int rc1 = fork();
        
        //Process A
        if (rc1 > 0) {
            (void) wait();
	        int parentB = getancestorcount();
            printf(1, "Ancestors of Process A after fork(): %d\n", parentB - base);
            if(parentB == 2) printf(1, "You are right! (Process A)\n");
            else printf(1, "You are wrong.. (Process A)\n");
        }
        //Process B
        else {
	        int childB = getancestorcount();
            printf(1, "Ancestors of Process B after fork(): %d\n", childB - base);
	        if(childB == 3) printf(1, "You are right! (Process B)\n");
            else printf(1, "You are wrong.. (Process B)\n");
        }
    }

    // Process C & D
    else { 
        (void) wait();
	    
        int rc2 = fork();
    
        // Process C
        if (rc2 > 0) {
            (void) wait();
	        int parentC = getancestorcount();
            printf(1, "Ancestors of Process C after fork(): %d\n", parentC - base);
            if(parentC == 3) printf(1, "You are right! (Process C)\n");
            else printf(1, "You are wrong.. (Process C)\n");
        }
        // Process D
        else {
	        int childC = getancestorcount();
            printf(1, "Ancestors of Process D after fork(): %d\n", childC - base);
	        if(childC == 4) printf(1, "You are right! (Process D)\n");
            else printf(1, "You are wrong.. (Process D)\n");
        }
     }
    
    exit();
}
