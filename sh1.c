//
//  sh1.c
//  CS 3376 Assignment 1
//
//  Created by Sana Sheik on 2/9/16.
//  Copyright © 2016 Sana Sheik. All rights reserved.
//

/*
 * sh1.c
 * Not documented for assignment purposes
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char line[256];
    char prompt[] = "sh1 % ";
    
    printf("%s", prompt );
    
    while( fgets(line, sizeof line, stdin) != NULL ) {
        line[strlen(line)-1] = '\0';
        
        system( line );
        printf("%s", prompt );
    }
    
    return 0;
}
