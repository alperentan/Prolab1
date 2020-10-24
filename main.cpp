#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char *file_path="C:\\Users\\tanal\\Desktop\\den.txt";
int get_size(){
    int i=0;
    char cr;
    FILE *fp=fopen(file_path,"r");
    if(fp!=NULL){
        while(!feof(fp)){
            cr=fgetc(fp);
            if(cr!='{'&&cr!='}'&&cr!=','){
                i++;
            }
        }

        fclose(fp);
        return i;
    }
    else{
        printf("A problem occurs");
    }
}
void read_coordinate(int *crd){
    int i=0;
    char cr;
    FILE *fp=fopen(file_path,"r");
    if(fp!=NULL){
        while(!feof(fp)){
            cr=fgetc(fp);
            if(cr!='{'&&cr!='}'&&cr!=','){
                crd[i]=cr-'0';
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
    int size=get_size()-1;
    int cd[size];
    int j=0;
    read_coordinate(cd);
    for (int i = 0; i <size ; i+=2) {
        printf("x=%d ",cd[i]);
        printf("y=%d ",cd[i+1]);
    }

    printf("\n");
    float ebu=sqrt(pow(cd[j+2]-cd[j],2)+pow(cd[j+3]-cd[j+1],2));
    printf("ebu=%f\n",ebu);
    return 0;
}
