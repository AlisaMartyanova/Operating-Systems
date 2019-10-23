#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>

char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
    // in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

int main(){
	/*// FILE *fp;
	// fp = fopen()
	DIR *dir;
	int file;
	
	dir = opendir("/home/alice/OSlabs/week10/tmp");
	if(!dir){
		printf("directory tmp is not found.\n");
		exit(0);
	}
	struct dirent* dire;
	while(dire = readdir(dir)){
		//printf("%s\n", dire->d_name);
		if(!strcmp(dire->d_name, "."))
			continue;
		if(!strcmp(dire->d_name, ".."))
			continue;
		char* str =  concat("/home/alice/OSlabs/week10/tmp/", dire->d_name);
		//printf("file name: %s\n", dire->d_name);
		file = open(str, "r");
		if(file){
			struct stat file_stat;
			int ret;  
			ret = fstat (file, &file_stat);  
			int inode = file_stat.st_ino;
			printf("%s %d\n", str, inode);
			close(file);
		}

	}



	closedir(dir);

	// close(fp);*/

	DIR *mydir;
    struct dirent *myfile;
  

    mydir = opendir("/home/alice/OSlabs/week10/tmp");
    int print = 0;
    while((myfile = readdir(mydir)) != NULL)
    {
		struct stat mystat;
		int ret;  
		ret = fstat (myfile, &mystat);  
		__ino_t inode = mystat.st_ino;
		printf("%s %ld\n", myfile->d_name, inode);
        //printf("%ld %s\n", mystat.st_ino , myfile->d_name);

    }

    closedir(mydir);


	
	return 0;
}
