#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1); 
   
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

int main(){
    int BUFF = 100;
    DIR* dir = opendir("tmp");
	FILE *ex4 = fopen("ex4.txt", "w");
	struct dirent* dirnt;
	if(!dir){
		fprintf(ex4, "directory tmp is not found.\n");
		exit(0);
	}


    int inodes[BUFF];
    int inodesFreq[BUFF];
    char** filenames[BUFF];
    int num = 0;

    for (size_t i = 0; i < BUFF; i++)
    {
        inodesFreq[i] = 0;
        inodes[i] = -1;
        filenames[i] = (char**)malloc(sizeof(char*) * BUFF);
    }
    

    while(dirnt = readdir(dir)){
        if(!strcmp(dirnt->d_name, "."))
            continue;
        if(!strcmp(dirnt->d_name, ".."))
            continue;
        

        FILE* file = fopen(dirnt->d_name, "r");

        struct stat file_stat;
        char* str =  concat("tmp/", dirnt->d_name);
        int ret = stat(str, &file_stat);
        if(ret < 0){
            fprintf(ex4, "error\n");
        }
        int inode = file_stat.st_ino;

        int found = 0;
        for (size_t i = 0; i < num; i++)
        {
            if(inodes[i] == inode){
                inodesFreq[i]++;
                filenames[i][inodesFreq[i]-1] = (char*)malloc(sizeof(char) * BUFF);
                strcpy(filenames[i][inodesFreq[i]-1], dirnt->d_name);
                found = 1;
                break;
            }
        }
        if(found == 0){
            inodes[num] = inode;
            inodesFreq[num] = 1;
            filenames[num][0] = (char*)malloc(sizeof(char) * BUFF);
            strcpy(filenames[num][0], dirnt->d_name);
            num++;
        }   
    }

    for (size_t i = 0; i < num; i++)
    {
        if(inodesFreq[i] < 2)
            continue;
        fprintf(ex4, "%d : %d\n", inodes[i], inodesFreq[i]);
        for (size_t j = 0; j < inodesFreq[i]; j++)
        {
            fprintf(ex4, "%s\n", filenames[i][j]);
        }
        
    }
    

    closedir(dir);
}