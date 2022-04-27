#include <iostream>
#include <fstream>
#include <stdio.h>   
#include <time.h>    
using namespace std;
int createFile(char name){
 
time_t curr_time;
tm * curr_tm;
char date_string[100];

time(&curr_time);
curr_tm = localtime(&curr_time);

strftime(date_string, 50, "%B-%d-%Y", curr_tm);

const char* directory = "../output/";
const char* fileName = date_string + name;
const char* fileType = ".txt";
 
char name_buffer[512];
FILE* f = NULL;
    //Print to character buffer
    sprintf(name_buffer,"%s%s%s",directory,fileName,fileType);
 
    f = fopen(name_buffer,"w");
 
    /* Write Data */

    fclose(f);

    cout << "Created file" << endl;
}