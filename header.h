#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX_USERS 943
#define MAX_MOVIES 1682
#define MAX_GENRES 19
#define NO_OF_USERS 50
#define BUFF_MAX 2048

struct user{
   int userID;
   int *movieID;
   int *ratings;
   int index;
}user;
struct movie{
   int movieID;
   int genres[MAX_GENRES];
}movie;

int selectRandom();
float test(struct user *,struct movie *,int ,int );
float distance(int *,int *,int );
void swap1(float *,float *);
void swap2(int *,int *);
void sort(float *,int *,int ,int );
int maxCount(int *,int );
int knn(struct user *,struct movie *,int ,int ,int ,int );
void unseenPredictions(struct user *,struct movie *,int ,int );
