#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    system("cls");
    /*file pointer declaration*/
    FILE *fp;

    /*function declaration*/
    void displayRecipe(char recipeName[]);                              //used to redirect to recipe page
    void myRecipe();                                                  //displays the recipe that a user might have saved
    void addRecipe();                                                 //lets you add new recipes

    /*local variable declaration*/
    char recipeName[10];                                              //stores the name of the recipe
    char storeCh;                                                     //stores the stream of characters for file pointer
    char userCommand[20];                                             //stores the user command
    int compareStr;



    /*main screen*/
     printf("\t\t\t___________________________________________________________________\n");
    printf("\t\t\t\t\t***WELCOME TO RECIPIE MANAGEMENT***\n");
    printf("\t\t\t___________________________________________________________________\n");
    printf("\t\t\t___________________________________________________________________\n\n\n");


    /*displays the list of recipes*/
    fp=fopen("F:\\project\\recipeDatas\\recipeList.txt","r");
    storeCh=getc(fp);
    while(storeCh!=EOF)
    {
        printf("%c",storeCh);
        storeCh=getc(fp);
    }
    fclose(fp);
    printf("\n\n\t\t\tHELP?\t\tMY RECIPE\t\tADD NEW RECIPE?");
    /*takes the user command*/
    printf("\n\nINPUT USER COMMAND:\t");
    fflush(stdin);
    scanf("%[^\n]s",userCommand);

    /*compare to see the command*/
    fp=fopen("F:\\project\\recipeDatas\\recipeList.txt","r");
    fgets(recipeName,50,fp);                                           //reads the name of recipe
        /*checks the condition*/
        //if((compareStr=strcmpi(dummy,recipeName))==0)


    if((compareStr=strcmpi(userCommand,"my recipe"))==0)
            myRecipe();
    else if((compareStr=strcmpi(userCommand,"add new recipe"))==0)
            addRecipe();
    else if((compareStr=strcmpi(userCommand,"breakfast"))==0)
    {
        system("cls");
        fp=fopen("F:\\project\\recipeDatas\\breakfast.txt","r");
        storeCh=getc(fp);
        while(storeCh!=EOF)
        {
            printf("%c",storeCh);
            storeCh=getc(fp);
        }
        fclose(fp);

        printf("\n\nINPUT NAME OF ITEM YOU WANT TO VIEW:\t");
        fflush(stdin);
        scanf(" %[^\n]s",userCommand);
        displayRecipe(userCommand);
    }
        else if((compareStr=strcmpi(userCommand,"snacks"))==0)
    {
        system("cls");
        fp=fopen("F:\\project\\recipeDatas\\snacks.txt","r");
        storeCh=getc(fp);
        while(storeCh!=EOF)
        {
            printf("%c",storeCh);
            storeCh=getc(fp);
        }
        fclose(fp);

        printf("\n\nINPUT NAME OF ITEM YOU WANT TO VIEW:\t");
        fflush(stdin);
        scanf(" %[^\n]s",userCommand);
        displayRecipe(userCommand);
    }

    else if((compareStr=strcmpi(userCommand,"dessert"))==0)
    {
        system("cls");
        fp=fopen("F:\\project\\recipeDatas\\dessert.txt","r");
        storeCh=getc(fp);
        while(storeCh!=EOF)
        {
            printf("%c",storeCh);
            storeCh=getc(fp);
        }
        fclose(fp);

        printf("\n\nINPUT NAME OF ITEM YOU WANT TO VIEW:\t");
        fflush(stdin);
        scanf(" %[^\n]s",userCommand);
        displayRecipe(userCommand);
    }
    else if((compareStr=strcmpi(userCommand,"all"))==0)
    {
        system("cls");
        fp=fopen("F:\\project\\all.txt","r");
        storeCh=getc(fp);
        while(storeCh!=EOF)
        {
            printf("%c",storeCh);
            storeCh=getc(fp);
        }
        fclose(fp);

        printf("\n\nINPUT NAME OF ITEM YOU WANT TO VIEW:\t");
        fflush(stdin);
        scanf(" %[^\n]s",userCommand);
        displayRecipe(userCommand);
    }
    else if((compareStr=strcmpi(userCommand,"help"))==0)
    {
        system("cls");
        printf("\n\n\n\tHELP    HELP");
        printf("\n\n\n\t\tType  name    of  recipe  to  open    it");
        printf("\n\n\te.g.  breakfast");
        printf("\n\n\n\t\tType the command on the last line");
        printf("\n\n\te.g.  add new recipe");
        printf("\n\n\n\n\t\t\t Hope this tutorial helped you");
        printf("\n\n\n\n\t\t\t press any key to return to home menu");
        getch();
        main();
    }

    else
    {
        printf("\n\n\t;( sorry for the inconvenience\n\n");
        printf("\tpress any key to proceed:");
        getch();
        main();
    }
    return 0;
}

void displayRecipe(char recipe[])
{
    system("cls");
    FILE *fp;

    /*function declaration*/
    void addComment(char recipe[]);
    void addFavourite(char recipe[]);

    /*local variable declaration*/
    char userCommand[30];
    int compareStr;
    char storeCh;

    /*variable that stores the file path for views*/
    char fileToOpen1[]="F:\\project\\viewCounter\\";
    strcat(fileToOpen1,recipe);
    strcat(fileToOpen1,".txt");

    /*in the name of view counting*/
    int viewCounter=0;
    int likes=0;

    /*reads the views*/
    fp=fopen(fileToOpen1,"r");
    fscanf(fp,"%d",&viewCounter);
    fclose(fp);
    /*to increment the views*/
    fp=fopen(fileToOpen1,"w");
    fprintf(fp,"%d",viewCounter+1);
    fclose(fp);
    printf("%d views",viewCounter+1);

    /*variable that stores the file path*/
    char fileToOpen3[]="F:\\project\\recipeDatas\\";
    strcat(fileToOpen3,recipe);
    strcat(fileToOpen3,".txt");

    /*to open a file*/
    fp=fopen(fileToOpen3,"r");
    storeCh=getc(fp);
    while(storeCh!=EOF)
    {
        printf("%c",storeCh);
        storeCh=getc(fp);
    }
    fclose(fp);
    fflush(stdin);

    printf("\n\n\t\t\tHOME\t\tCOMMENT?\t\tADD TO FAVOURITES?");

    /*waits for user to input any command*/
    printf("\n\nINPUT USER COMMAND:");
    scanf(" %[^\n]s",userCommand);

    /*user commands, checking the condition*/
    if((compareStr=strcmpi(userCommand,"comment"))==0)
        addComment(recipe);
    else if((compareStr=strcmpi(userCommand,"add to favourites"))==0)
        addFavourite(recipe);
    else if((compareStr=strcmpi(userCommand,"home"))==0)
        main();
    else
    {
        printf("\n\n\t;( sorry for the inconvenience\n\n");
        printf("\tpress any key to proceed to home menu:");
        getch();
        main();
    }
}

void addComment(char recipe[])
{
    system("cls");
    FILE *fp;

    printf("\n\n\n\tCOMMENT SECTION\n\n");

    /*function declaration*/
    void displayRecipe(char recipe[]);

    /*local variable declaration*/
    char userName[50];
    char storeCh;
    char comment[150];

    /*variable that stores the file path*/
    char fileToOpen[]="F:\\project\\recipeDatas\\";
    strcat(fileToOpen,recipe);
    strcat(fileToOpen,".txt");

    /*to open a file and to add comment*/
    fp=fopen(fileToOpen,"a");
    printf("\n\n\t\tPlease enter your username:");
    scanf(" %[^\n]s",userName);
    printf("\n\n\t\tNow you can enter your comment on this topic:");
    scanf(" %[^\n]s",comment);
    fprintf(fp,"\n%s says %s",userName,comment);
    fclose(fp);

    /*to return to the previous page*/
    printf("\n\n\tPress any key to return to the previous page:");
    getch();
    displayRecipe(recipe);


}

void myRecipe()
{
    system("cls");

    FILE *fp;

    printf("\n\n\n\tMY RECIPE\n\n");
    printf("\t\twould you like to sign up?Press (y/n)\t");

    char userName[20];
    char storeCh;
    char userCommand;
    int compareStr;

    scanf(" %c",&userCommand);

    if (userCommand=='y')
        {
            printf("\n\n\n\t\tenter a username to open an account:");
            scanf(" %[^\n]s",userName);

            char fileToOpen[]="F:\\project\\userDatas\\";
            strcat(fileToOpen,userName);
            strcat(fileToOpen,".txt");

            fp=fopen(fileToOpen,"w");
            if(fp!=NULL)
                printf("\n\n\n\tCongratulations! Account opened successfully");
        }

    else if(userCommand=='n')
        {
            printf("\n\n\n\t\tPlease,enter your username to view your saved recipes:\t");
            scanf(" %[^\n]s",userName);

            char fileToOpen[]="F:\\project\\userDatas\\";
            strcat(fileToOpen,userName);
            strcat(fileToOpen,".txt");

            fp=fopen(fileToOpen,"r");
            storeCh=getc(fp);
            while(storeCh!=EOF)
            {
                printf("%c",storeCh);
                storeCh=getc(fp);
            }
        }
    else
        {
            printf("\n\n\t;( sorry for the inconvenience\n\n");
            printf("\tpress any key to proceed:");
            getch();
            myRecipe();
        }
    printf("\n\n\n\t\tEnter any key to return to main menu");
    getch();
    main();
}

void addFavourite(char recipe[])
{
    system("cls");

    FILE *fp;

    void displayRecipe(char recipe[]);

    printf("\n\n\tADD THIS RECIPE TO YOUR FAVOURITES?");
    printf("\n\n\n\tWould you like to sign up?Press (y/n)\t");

    char userName[20];
    char storeCh;
    char userCommand;
    int compareStr;

    scanf(" %c",&userCommand);

    if (userCommand=='y')
        {
            printf("\n\n\n\t\tenter a username to open an account:");
            scanf(" %[^\n]s",userName);

            char fileToOpen[]="F:\\project\\userDatas\\";
            strcat(fileToOpen,userName);
            strcat(fileToOpen,".txt");

            fp=fopen(fileToOpen,"w");
            fprintf(fp,"%s",recipe);
            fclose(fp);

            if(fp!=NULL)
                printf("\n\n\tCongratulations! Account opened");
        }

    else if(userCommand=='n')
        {
            printf("\n\n\n\t\tPlease, enter your username to add this recipe to your favourites:");
            scanf(" %[^\n]s",userName);

            char fileToOpen[]="F:\\project\\userDatas\\";
            strcat(fileToOpen,userName);
            strcat(fileToOpen,".txt");

            fp=fopen(fileToOpen,"a");
            fprintf(fp,"%s",recipe);
            fclose(fp);
        }
    displayRecipe(recipe);
}


void addRecipe()
{
    system("cls");

    printf("\n\n\tADD NEW RECIPE");
    printf("\n\t_______________");
    printf("\n\n\tHELP OTHERS SPICE UP THEIR LIFE");
    //file pointer
    FILE *fp;

    //structure declaration
    struct recipe
    {
        char title[20];
        char userName[20];
        char ingredients[100];
        char directions[500];
    };

    //local variable declaration
    int numIngredients=0;
    int numDirection=0;
    int i=0;
    char recipeName[20];

    //structure variable
    struct recipe name;

    //name of the recipe
    printf("\n\n\n\t\tenter the name of your recipe\t");
    scanf(" %[^\n]s",&name.title);
    strcpy(recipeName,name.title);

    //to open a file for recipe
    char fileToOpen[]="F:\\project\\recipeDatas\\";
    strcat(fileToOpen,name.title);
    strcat(fileToOpen,".txt");
    fp=fopen(fileToOpen,"w");
    fclose(fp);

    //enters username
    printf("\n\n\n\t\tenter username\t");
    scanf(" %[^\n]s",&name.userName);
    fp=fopen(fileToOpen,"a");
    fprintf(fp,"%d\n%s\n%s",i,name.title,name.userName);

    //to add ingredients
    printf("\n\n\n\t\thow many ingredients does your recipe has?\t");
    scanf(" %d",&numIngredients);
    for(i=0;i<numIngredients;i++)
    {
        printf("step[%d]:",i+1);
        scanf(" %[^\n]s",&name.ingredients);
        fprintf(fp,"[%d]\n%s",i+1,name.ingredients);
    }

    //to add directions
    printf("\n\n\n\t\thow many steps does it takes to prepare your dish?\t");
    scanf(" %d",&numDirection);
    for(i=0;i<numDirection;i++)
    {
        printf("step[%d]:",i+1);
        scanf(" %[^\n]s",&name.directions);
        fprintf(fp,"step[%d]\n%s",i+1,name.directions);
    }
    fprintf(fp,"\n%s","comment");
    //add to the recipe list
    fp=fopen("F:\\project\\all.txt","a");
    fprintf(fp,"\t\n\n%s",recipeName);
    fclose(fp);

    printf("\n\n\n\t\tenter any key to proceed to home menu");
    getch();
    main();
}

