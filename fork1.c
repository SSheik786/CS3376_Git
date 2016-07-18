//
//  fork1.c
//  CS 3376 Assignment 1
//
//  Created by Sana Sheik on 2/9/16.
//  Copyright © 2016 Sana Sheik. All rights reserved.
//

/* fork1.c - Demonstrate the fork() */

#include <stdio.h>
#include <unistd.h>

main()
{
    int i;
    
    printf("Ready to fork...\n");
    i=fork();
    printf("Fork returned %d\n",i);
}
