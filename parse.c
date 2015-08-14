#include"header.h"

int selectRandom()
{
  return rand()%MAX_USERS;
}

int main(int argc,char *argv[])
{
  if(argc!=4){
    printf("Not enough data provided\n");
    exit(1);
  }
  else{
    srand(time(NULL));
    char buff[BUFF_MAX];
    int count[MAX_USERS]={0};
    struct user userInfo[MAX_USERS];
    struct movie movieInfo[MAX_MOVIES];
    int kvalue;
    int i=0,j=0,ncolumns=0,x=0,movieCount=0,genreIndex=0;
    FILE *file1=fopen(argv[1],"r");         //file1 is u.data
    FILE *file2=fopen(argv[2],"r");         //file2 is u.item
    sscanf(argv[3],"%d",&kvalue);
    if(kvalue>14){
      printf("Enter k-value below 15 as some users donot have more than 15 neighboors\n");
      exit(1);
    }
    if(file1==0){
      printf("Could not open file for reading\n");
      exit(1);
    }
    else if(file2==0){
      printf("Could not open file for reading\n");
      exit(1);
    }
    else{
      char temp[BUFF_MAX];
      while(fgets(buff,sizeof(buff),file2)!=NULL){
        while(buff[i]!='\0'){
          while(buff[i]!='|'&&buff[i]!='\0'){
            temp[j++]=buff[i++];
          }
          temp[j]='\0';
          if(buff[i]!='\0'){
          i++;
          }
          if(ncolumns==0){
            sscanf(temp,"%d",&movieInfo[movieCount].movieID);
          }
          else if (ncolumns>4){
            sscanf(temp,"%d",&movieInfo[movieCount].genres[genreIndex]);
            genreIndex++;
          }
          ncolumns++;
          j=0;
          temp[j]='\0';
        }
        i=0,j=0;
        ncolumns=0;
        genreIndex=0;
        movieCount++;
      }
      i=0,j=0,x=0,ncolumns=0;
      while(fgets(buff,sizeof(buff),file1)!=NULL){
        while(buff[i]!='\0'){
          while(buff[i]!='\t'){
            temp[j++]=buff[i++];
          }
          temp[j]='\0';
          sscanf(temp,"%d",&x);
          count[x-1]++;
          while(buff[i]!='\0')
            i++;
            j=0;
        }   
        j=0,i=0; 
      }
      for(i=0;i<MAX_USERS;i++){
        userInfo[i].movieID=(int *)malloc(sizeof(int)*count[i]);
        userInfo[i].ratings=(int *)malloc(sizeof(int)*count[i]);		
      }
      rewind(file1);
      i=0,j=0;
      ncolumns=0;		
      while(fgets(buff,sizeof(buff),file1)!=NULL){
        int tempVar;
        while(buff[i]!='\0'){
          while(buff[i]!='\t'&&buff[i]!='\0'){
            temp[j++]=buff[i++];
          }
          temp[j]='\0';
          if(buff[i]!='\0')
            i++;
          sscanf(temp,"%d",&x);
          if(ncolumns==0){
            tempVar=x;
            userInfo[tempVar-1].userID=tempVar;
          }
          else if(ncolumns==1){
            userInfo[tempVar-1].movieID[userInfo[tempVar-1].index]=x;
          }
          else if(ncolumns==2){
            userInfo[tempVar-1].ratings[userInfo[tempVar-1].index]=x;
          }
          j=0;
          ncolumns++;
          temp[j]='\0';
        }
        userInfo[tempVar-1].index++;
        ncolumns=0;
        j=0;
        i=0;
      }
    }
    int random;
    float error;
    for(i=0;i<NO_OF_USERS;i++){
      random=selectRandom();
      printf("Randomly selected user is %d\n",random+1);
      error=test(userInfo,movieInfo,random,kvalue);
      printf("Error from test data is:%f\n",error);
      unseenPredictions(userInfo,movieInfo,random,kvalue);
      printf("\n\n");	
    }
  }
  return 0;
}
