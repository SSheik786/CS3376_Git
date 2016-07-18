//
//  printdir1.c
//  CS 3376 Assignment 1
//
//  Created by Sana Sheik on 2/9/16.
//  Copyright © 2016 Sana Sheik. All rights reserved.
//

/* printdir1.c
 * Documentation intentially left out as part of the assignment
 */

#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

void printdir(char *dir, int depth)
{
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    
    if((dp = opendir(dir)) == NULL) {
        fprintf(stderr,"cannot open directory: %s\n", dir);
        return;
    }
    
    chdir(dir);
    
    while((entry = readdir(dp)) != NULL) {
        lstat(entry->d_name,&statbuf);
        
        if(S_ISDIR(statbuf.st_mode)) {
            /* Found a directory, but ignore . and .. */
            if(strcmp(".",entry->d_name) == 0 ||
               strcmp("..",entry->d_name) == 0) {
                continue;
            }
            
            printf("%*s%s/\n",depth,"",entry->d_name);
            
            /* Recurse at a new indent level */
            printdir(entry->d_name,depth+4);
        }
        else {
            printf("%*s%s\n",depth,"",entry->d_name);
        }
    }
    chdir("..");
    closedir(dp);
}

/*  Now we move onto the main function.  */

int main()
{
    printf("Directory scan of /home:\n");
    printdir("./",0);   // print current directory entries
    printf("done.\n");
    
    exit(0);
}
