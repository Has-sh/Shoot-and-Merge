#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
int randomPowerTwo(int);
int shootMerge(int[5][4],int,int);
int fullorNot(int[5][4]);
void displayBoard(int[5][4]);
void flushboard(int[5][4]);

int main()
{
    char play_again='Y';
    while(play_again=='Y')
    {
        int Board[5][4],choice,max_value=32,num_shots=1,r=0;


        printf("\nLets get started!\n");
        printf("\tC1\tC2\tC3\tC4");
        r=randomPowerTwo(max_value);
        flushboard(Board);
        while(fullorNot(Board)!=1)
        {
            printf("\n\nYou have %d, which column would you like to shoot [1-4]?",r);
            scanf("%d",&choice);
            while(choice>4 || choice<1)
            {
                printf("Sorry, that is not a valid column, try again!");
                printf("\nYou have %d, which column would you like to shoot [1-4]?",r);
                scanf("%d",&choice);
            }
            r=shootMerge(Board,r,choice);
            r=randomPowerTwo(r);
            displayBoard(Board);
            printf("\n%d shot so far!",num_shots);
            num_shots++;
            fullorNot(Board);
            if(fullorNot(Board)==1)
            {
                printf("\nThe board is full now with %d shots!\nGame over!",num_shots-1);
                printf("\nWould you like to play again (Y/N)? ");
                scanf("\n%c",&play_again);
                while(play_again!='Y' && play_again!='N')
                {
                    fflush(stdin);
                    printf("That is not valid, please try again!");
                    scanf("%c",&play_again);
                }
            }
        }

    }
    printf("Byeee!");
    return 0;
}
int randomPowerTwo(int max_value)
{
    int counter=0,exponent,random_value,random_exponent;
    {
        srand(time(NULL));
        exponent=(log(max_value)/log(2));
        random_exponent=rand()%exponent+1;
        random_value=pow(2,random_exponent);
    }
}
int shootMerge(int Board[5][4],int random_value, int choice)
{
    int new_max=0,i=0,j,k,end_counter=0,merge_possible=1;

    while(end_counter==0 && i<5)
    {
        if(Board[i][choice-1]==0)
        {
            if(i==0)
            {
                Board[i][choice-1]=random_value;
                end_counter++;
            }
            else
            {
                Board[i][choice-1]=random_value;
                end_counter++;
                while(merge_possible==1)
                {
                    if(Board[i-1][choice-1]==Board[i][choice-1] && i!=0)
                    {
                        Board[i-1][choice-1]+=Board[i][choice-1];
                        Board[i][choice-1]=0;
                        i=i-1;
                    }
                    else
                    {
                        merge_possible=0;
                    }
                }
            }
        }
        else
        {
            i++;
        }
    }
    for(j=0; j<5; j++)
    {
        for(k=0; k<4; k++)
        {
            if(Board[j][k]>new_max)
            {
                new_max=Board[j][k];
            }
        }
    }
    return new_max;
}
int fullorNot(int Board[5][4])
{
    int i,j;
    for(i=0; i<5; i++)
    {
        for(j=0; j<4; j++)
        {
            if(Board[i][j]>0)
            {
                if(i==4 && j==3 && Board[4][3]>0)
                {
                    return 1;
                }
            }
            else
                return 0;
        }
    }
}
void displayBoard(int Board[5][4])
{
    int counter=0,i,j;
    printf("\n\tC1\tC2\tC3\tC4");
    for(i=0; i<5; i++)
    {
        printf("\n");
        for(j=0; j<4; j++)
        {
            if(Board[i][j]>0)
            {
                printf("\t%d",Board[i][j]);
            }
            else
            {
                printf("\t");
            }
        }
    }
}
void flushboard(int Board[5][4])
{
    int a,b;
    for(a=0; a<5; a++)
    {
        for(b=0; b<4; b++)
        {
            {
                Board[a][b]=0;
            }
        }
    }
}
