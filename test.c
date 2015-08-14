#include"header.h"
float test(struct user *userInfo,struct movie *movieInfo,int randomUser,int kvalue)
{
  float error=-1.0;
  int learning,i,rating,correct=0;
  int count=0;
  int temp;
  learning=(userInfo[randomUser].index+1)*75/100;
  for(i=learning;i<userInfo[randomUser].index;i++){
    temp=userInfo[randomUser].movieID[i];
    rating=knn(userInfo,movieInfo,randomUser,kvalue,learning,temp);
    if(userInfo[randomUser].ratings[i]==rating)
      correct++;
    count++;
  }
  if(userInfo[randomUser].index-learning!=0)
    error=(correct*100)/(userInfo[randomUser].index-learning);
  return error;
}
