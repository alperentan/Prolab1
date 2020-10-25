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
    int x,y,x2,y2;
    read_coordinate(cd);
    for (int i = 0; i <size ; i+=2) {
        printf("x%d=%d ",i,cd[i]);
        printf("y%d=%d \n",i,cd[i+1]);
    }

    printf("\n");
    float ebu=sqrt(pow(cd[j+2]-cd[j],2)+pow(cd[j+3]-cd[j+1],2));
    for(int i=0;i<size;i+=2)   {
    for(int j=i+2;j<size;j+=2)   {
        if(sqrt(pow(cd[j]-cd[i],2)+pow(cd[j+1]-cd[i+1],2))>ebu){
            ebu=sqrt(pow(cd[j]-cd[i],2)+pow(cd[j+1]-cd[i+1],2));
            x=cd[i];
            y=cd[i+1];
            x2=cd[j];
            y2=cd[j+1];}
        }   }
    printf("Iki nokta arasi en buyuk uzaklik=%f\nEn uzak noktalarin koordinatlari=(%d,%d)-(%d,%d)\n",ebu,x,y,x2,y2);
    int enuzakucuncunoktax1,enuzakucuncunoktay1,enuzakucuncuuzunluk=0;
    for(int i=0;i<size;i+=2){
    if(sqrt(pow(cd[i]-x,2)+pow(cd[i+1]-y,2))+sqrt(pow(cd[i]-x2,2)+pow(cd[i+1]-y2,2))>enuzakucuncuuzunluk){
        enuzakucuncuuzunluk=sqrt(pow(cd[i]-x,2)+pow(cd[i+1]-y,2))+sqrt(pow(cd[i]-x2,2)+pow(cd[i+1]-y2,2));
        enuzakucuncunoktax1=cd[i];
        enuzakucuncunoktay1=cd[i+1];}}
    printf("(%d,%d)-(%d,%d)'ya en uzak ucuncu nokta=(%d,%d)\n",x,y,x2,y2,enuzakucuncunoktax1,enuzakucuncunoktay1);

    return 0;
}
