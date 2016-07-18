//
//  fork3.c
//  CS 3376 Assignment 1
//
//  Created by Sana Sheik on 2/9/16.
//  Copyright © 2016 Sana Sheik. All rights reserved.
//

/* fork3.c -  fork can be called iteratively */

#include <stdio.h>
#include <unistd.h>

main()
{
    int i;
    
    i=getpid();
    
    printf("Parent=%d\n",i);
    
    fork();
    fork();
    
    i=getpid();
    
    printf("Who am I? %d\n",i);
}
