#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *file_path="den.txt";//Koordinatların bulunduğu text dosyasının yolu
int get_size(){
    int i=0;
    char cr;
    FILE *fp=fopen(file_path,"r");
    if(fp!=NULL){
        while(!feof(fp)){
            cr=fgetc(fp);
            if(cr==','){
                i++;
            }
        }
        i++;
        fclose(fp);
        return i;
    }
    else{
        printf("A problem occurs");
    }
}
void read_coordinate(char *crd){
    int i=0;
    char cr;
    FILE *fp=fopen(file_path,"r");
    if(fp!=NULL){
        while(!feof(fp)){
            cr=fgetc(fp);
            if(cr!='{'&&cr!='}'){
                crd[i]=cr;
                i++;
            }
        }

        fclose(fp);
    }
    else{
        printf("A problem occurs");
    }
}

int main() {

    char *coordinate;
    char *say;
    read_coordinate(coordinate);
    int size=get_size();
    float x[size/2];
    float y[size/2];
    say=strtok(coordinate," ,");
    x[0]=(float)atoi(say);
    say = strtok (NULL, " ,");
    y[0]=(float)atoi(say);
    printf("%.2f %.2f",x[0],y[0]);
    for (int i = 2; i < size; i+=2) {
        say = strtok (NULL, " ,");
        x[i/2]=(float)atoi(say);
        say = strtok (NULL, " ,");
        y[i/2]=(float)atoi(say);
    }
    return 0;
}