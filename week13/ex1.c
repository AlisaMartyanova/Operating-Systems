#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int processNum = 0;
int resourcesNum = 0;

struct Process{
    int* current;
    int* request;
    int locked;
    int checked;
};

FILE *input;
FILE *output = NULL;
char ch = ' ';
int A[3] = {0,0,0};
int E[3] = {0,0,0};
struct Process* processes;

int checked = 0;
int locked = 0;


void detection(char *inputName, char *outputName){

    input = fopen(inputName, "r");
    output = fopen(outputName, "w+");

     //initialization

    fscanf(input, "%d", &processNum); // number of processes (1st row in input)
    fscanf(input, "%d", &resourcesNum); // number of resources (2nd row in input)

    processes = (struct Process*)malloc(sizeof(struct Process)*processNum);
    for(int i = 0; i<processNum; i++){
        processes[i].current = (int*)malloc(sizeof(int)*resourcesNum);
        processes[i].request = (int*)malloc(sizeof(int)*resourcesNum);
        for(int j = 0; j<3; j++){
            
            processes[i].current[j] = 0;
            
            processes[i].request[j] = 0;
        }
        processes[i].locked = 1;
        processes[i].checked = 0;

    }

    
    
    
    //reading input
    for(int i = 0; i<resourcesNum; i++)
        fscanf(input, "%d", &E[i]);


    for(int i = 0; i<resourcesNum; i++)
        fscanf(input, "%d", &A[i]);
  

    for(int i = 0; i<processNum; i++){
        for(int j = 0; j<resourcesNum; j++)
            fscanf(input, "%d", &processes[i].current[j]);
                          
    }
  

    for(int i = 0; i<processNum; i++){
        for(int j = 0; j<resourcesNum; j++)
            fscanf(input, "%d", &processes[i].request[j]);
            
    }

    
   //deadlock detection
    int i = 0;
        while (i<processNum){
            if(processes[i].checked == 0){
                if(A[0]>=processes[i].request[0]){
                    if(A[1]>=processes[i].request[1]){
                            if(A[2]>=processes[i].request[2]){
                                A[0]+=processes[i].current[0];
                                A[1]+=processes[i].current[1];
                                A[2]+=processes[i].current[2];
                                checked++;
                                processes[i].checked=1;
                                processes[i].locked = 0;
                                i = -1;
                    
                            } 
                    }
                }
            }
            i++;  
        }

    //printing output
    for (int i = 0; i<processNum; i++){
        if(processes[i].locked == 1){
            char str[80];
            sprintf(str, "%s %d %s", "Process ", i, " is deadlocked\n");
            fprintf(output, str);
            locked++;
        }
    }
    if(locked == 0)
        fprintf(output, "No deadlock is detected\n");

    
    free(processes);
   
    fclose(input);
    fclose(output);
}

int main(){
    
    detection("input_ok.txt", "output_ok.txt");
    detection("input_dl.txt", "output_dl.txt");


    return 0;
}