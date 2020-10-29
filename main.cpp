#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <graphics.h>
struct point{
int x;
int y;
};
int get_size(){
    FILE *f=fopen("C:\\Users\\tanal\\Desktop\\den.txt","r");

if(f!=NULL){
   int i=0;
   while(!feof(f)){

       if(fgetc(f)!='{'&&fgetc(f)!='}'){
          i++;
       }
   }
   fclose(f);
   return i;
}
else{
    printf("File does not exist");
}
}
void readfile(char *coordinate){
FILE *f=fopen("C:\\Users\\tanal\\Desktop\\den.txt","r");
int i=0;
if(f!=NULL){
   while(!feof(f)){
       char c;
        c=fgetc(f);
       if(c!='{'&&c!='}'){
          coordinate[i]=c;
        i++;
       }
   }
   fclose(f);
}
else{
    printf("File does not exist");
}
}
void parse_coordinate(char *coor,struct point pt[],int size){
char *say;
    say=strtok(coor," ,");
    pt[0].x=(float)atoi(say);
    say = strtok (NULL, " ,");
    pt[0].y=(float)atoi(say);
    for (int i = 2; i < size; i+=2) {
        say = strtok (NULL, " ,");
        pt[i/2].x=(float)atoi(say);
        say = strtok (NULL, " ,");
        pt[i/2].y=(float)atoi(say);
    }
}
int main()
{   int size=get_size();
    char coordinate[size];
    struct point pt[size/2];
    readfile(coordinate);
    //printf("%s",coordinate);
    parse_coordinate(coordinate,pt,size);
    float x,y,x2,y2;
    for(int i=0;i<size/2;i++){
       printf("( %d , %d )",pt[i].x,pt[i].y);
    }
    printf("\n");
    float mer_x=0;
    float mer_y=0;
    float yaricap=0;
    if(size==2){
        printf("Cemberin merkezi=(%d %d)\nCemberin yaricapi=0(nokta)\n",pt[0].x,pt[0].y);
    }
    else if(size==4)   {
    mer_x=(pt[0].x+pt[1].x)/2.0;
    mer_y=(pt[0].y+pt[1].y)/2.0;
    yaricap=sqrt(pow(pt[1].x-mer_x,2)+pow(pt[1].y-mer_y,2));
    printf("Cemberin merkezi=(%f %f)\nCemberin yaricapi=%f\n",mer_x,mer_y,yaricap);   }

    else{
    float ebu=sqrt(pow(pt[1].x-pt[0].x,2)+pow(pt[1].y-pt[0].y,2));
    for(int i=0;i<size/2;i++)   {
    for(int j=i+1;j<size/2;j++)   {
        if(sqrt(pow(pt[j].x-pt[i].x,2)+pow(pt[j].y-pt[i].y,2))>ebu){
            ebu=sqrt(pow(pt[j].x-pt[i].x,2)+pow(pt[j].y-pt[i].y,2));
            x=pt[i].x;
            y=pt[i].y;
            x2=pt[j].x;
            y2=pt[j].y;}
        }   }
    printf("Iki nokta arasi en buyuk uzaklik=%f\nEn uzak noktalarin koordinatlari=(%f,%f)-(%f,%f)\n",ebu,x,y,x2,y2);
    float x3,y3,enuzakucuncuuzunluk=0;
    for(int i=0;i<size/2;i++){
    if(sqrt(pow(pt[i].x-x,2)+pow(pt[i].y-y,2))+sqrt(pow(pt[i].x-x2,2)+pow(pt[i].y-y2,2))>enuzakucuncuuzunluk){
        enuzakucuncuuzunluk=sqrt(pow(pt[i].x-x,2)+pow(pt[i].y-y,2))+sqrt(pow(pt[i].x-x2,2)+pow(pt[i].y-y2,2));
        x3=pt[i].x;
        y3=pt[i].y;}}
    printf("(%f,%f)-(%f,%f)'ya en uzak ucuncu nokta=(%f,%f)\n",x,y,x2,y2,x3,y3);
    mer_x=(x2+x)/2;
    mer_y=(y2+y)/2;
    yaricap=sqrt(pow(x-mer_x,2)+pow(y-mer_y,2));
    if((sqrt(pow(x3-mer_x,2)+pow(y3-mer_y,2)))>yaricap)   {
    float egri1=0;
    float egri2=0;
    float sabit1=0;
    float sabit2=0;
    float orta1x=0;
    float orta1y=0;
    float orta2x=0;
    float orta2y=0;
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
    yaricap=sqrt(pow(x-mer_x,2)+pow(y-mer_y,2));
    printf("Cemberin merkezi= x:%f y:%f\nCemberin yaricapi=%f\n",mer_x,mer_y,yaricap);   }
    else   {
        printf("Cemberin merkezi= x:%f y:%f\nCemberin yaricapi=%f\n",mer_x,mer_y,yaricap);   }   }

    return 0;   }
