//
//  fork2.c
//  CS 3376 Assignment 1
//
//  Created by Sana Sheik on 2/9/16.
//  Copyright © 2016 Sana Sheik. All rights reserved.
//

/* fork2.c - Child process can run different code than parent process */

#include <stdio.h>
#include <unistd.h>

main()
{
    int i,j;
    j=0;
    
    printf("Ready to fork...\n");
    
    i=fork();
    
    if (i == 0) {
        printf("The child executes this code.\n");
        for (i=0; i<5; i++) {
            j=j+i;
        }
        
        printf("Child j=%d\n",j);
    }
    else {
        printf("The parent executes this code.\n");
        for (i=0; i<3; i++) {
            j=j+i;
        }
        
        printf("Parent j=%d\n",j);
    }
}
