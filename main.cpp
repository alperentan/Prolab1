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
    int x3,y3,enuzakucuncuuzunluk=0;
    for(int i=0;i<size;i+=2){
    if(sqrt(pow(cd[i]-x,2)+pow(cd[i+1]-y,2))+sqrt(pow(cd[i]-x2,2)+pow(cd[i+1]-y2,2))>enuzakucuncuuzunluk){
        enuzakucuncuuzunluk=sqrt(pow(cd[i]-x,2)+pow(cd[i+1]-y,2))+sqrt(pow(cd[i]-x2,2)+pow(cd[i+1]-y2,2));
        x3=cd[i];
        y3=cd[i+1];}}
    printf("(%d,%d)-(%d,%d)'ya en uzak ucuncu nokta=(%d,%d)\n",x,y,x2,y2,x3,y3);
    float egri1=0;
    float egri2=0;
    float sabit1=0;
    float sabit2=0;
    float orta1x=0;
    float orta1y=0;
    float orta2x=0;
    float orta2y=0;
    float mer_x=0;
    float mer_y=0;
    egri1=(y2-y)/(x2-x);
    egri2=(y2-y3)/(x2-x3);
    orta1x=(x+x2)/2;
    orta1y=(y+y2)/2;
    orta2x=(x2+x3)/2;
    orta2y=(y2+y3)/2;

    sabit1=orta1y+(1/egri1)*orta1x;
    sabit2=orta2y+(1/egri2)*orta2x;
    //printf("%f %f\n",sabit1,sabit2);
    mer_x=(sabit2-sabit1)/(((x3-x2)/(y2-y3))+((x2-x)/(y-y2)));
    mer_y=(-1/egri2)*mer_x+sabit2;
    printf("Cemberin merkezi= x:%f y:%f",mer_x,mer_y);

    return 0;
}
