#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

struct lib
{
    char category[20],name[20],author[20],issue[20];
    int page,id,quantity,b_quantity;
    float price;
};
int main (void)
{
    struct lib book[1000];
    char bname[20],del[10];
    int choice,i,j,n,count=0,flag=0;
    while(1)
    {

        system("cls");
        printf("\n\t\t\t\t Library Management System \n\n");
        printf("\t\t\t\t\t[1]   Add Books\n\n");
        printf("\t\t\t\t\t[2]   Search Books\n\n");
        printf("\t\t\t\t\t[3]   Issue Books\n\n");
        printf("\t\t\t\t\t[4]   View Book List\n\n");
        printf("\t\t\t\t\t[5]   Quit\n\n");
        printf("\n\t\t\t\t      Enter your Choice: ");
        scanf("%d",&choice);
        system("color 3c");
        if(choice==5)
        {
            system("cls");
            printf("\n\t\t\t\t You Quit the Program !!!!!\n");
            break;
        }
        if(choice==1)// Add Book Start
        {
            system("color 50");
            system("cls");
            printf("\n\t\t\t How many Book you want to Add ?\n");
            printf("\n\t\t\t\tQuantity : ");
            scanf("%d",&n);
            printf("\n\n\t\t\t\t You want to Add %d Books \n\n",n);
            n=n+count;

            for(i=count; i<n; i++)
            {
                printf("\t\t\t         Enter Information For Book: %d \n",i+1);
                printf("\n\t\t\t\t Enter Category (Above 7 letters): ");
                fflush(stdin);
                gets(book[i].category);
                printf("\n\t\t\t\t  Enter Name (Above 7 letters): ");
                fflush(stdin);
                gets(book[i].name);

                printf("\n\t\t\t\t  Enter ID (4-7 numbers): ");
                scanf("%d",&book[i].id);

                printf("\n\t\t\t\t  Enter Author (Above 7 letters): ");
                fflush(stdin);
                gets(book[i].author);

                printf("\n\t\t\t\t  Enter Price (Above 3 numbers): ");
                scanf("%f",&book[i].price);

                printf("\n\t\t\t\t  Book Quantity: ");// new copy
                scanf("%d",&book[i].quantity);
                book[i].b_quantity=book[i].quantity;

                printf("\n\t\t\t\t  Issue status (Yes/No): ");
                fflush(stdin);
                gets(book[i].issue);
                printf("\n\n\t\t\t\t\t Done Successfully \n");
                count++;
            }
            printf("\n\n\n\t\t\t Press any key for go to Main menu........");
            getch();
        }//Add Book End

        if(choice==2)// Search Book Start
        {
            system("color 23");
            system("cls");

            while(1)
            {
                printf("\n\n\t\t\t\t Enter the Book Name for Search: \n");
                printf("\n\t\t\t\tBook Name : ");
                fflush(stdin);
                gets(bname);

                flag=0;
                for(i=0; i<count; i++)
                {
                    if(!strcmp(book[i].name,bname))
                    {
                        printf("\n\t\t\t\t   Searched Book Details");
                        printf("\n\n\t\t\t\t\tBook Category : %s",book[i].category);
                        printf("\n\n\t\t\t\t\tBook Name : %s",book[i].name);
                        printf("\n\n\t\t\t\t\tBook ID : %d",book[i].id);
                        printf("\n\n\t\t\t\t\tBook Author : %s",book[i].author);
                        printf("\n\n\t\t\t\t\tBook Price : %.2f",book[i].price);
                        printf("\n\n\t\t\t\t\tBook quantity : %d",book[i].quantity);// new copy
                        printf(" of %d",book[i].b_quantity);
                        printf("\n\n\t\t\t\t\tIssue status : %s",book[i].issue);
                        printf("\n\n\n\t\t\t\t\t Successfully Searched ");
                        flag++;
                    }
                }
                if(flag==0)
                {
                    printf("\n\n\t\t\t There is no book with this name...Please try again..\n");
                }
                else
                    break;
            }
            printf("\n\n\n\t\t\t\tPress any key for go to Main menu........");
            getch();
        }
        if(choice==3)// Issue Book Start
        {
            system("color 44");
            system("cls");
            while(1)
            {
                printf("\n\n\t\t\t\t Enter the Book Name for Issue: \n");
                printf("\n\t\t\t\tBook Name : ");
                fflush(stdin);
                gets(bname);

                flag=0;
                for(i=0; i<count; i++)
                {
                    if(!strcmp(book[i].name,bname))
                    {
                        printf("\n\t\t\t\t    Issue Book Details ");
                        printf("\n\n\t\t\t\t\tBook Category : %s",book[i].category);
                        printf("\n\n\t\t\t\t\tBook Name : %s",book[i].name);
                        printf("\n\n\t\t\t\t\tBook ID : %d",book[i].id);
                        printf("\n\n\t\t\t\t\tBook Author : %s",book[i].author);
                        printf("\n\n\t\t\t\t\tBook Price : %.2f",book[i].price);
                        printf("\n\n\t\t\t\t\tBook quantity : %d",book[i].quantity);// new copy
                        printf(" of %d",book[i].b_quantity);
                        printf("\n\n\t\t\t\t\tIssue status : %s",book[i].issue);
                        if(book[i].b_quantity==book[i].quantity)
                        {
                            printf("\n\n\n\t\t\t\t Change issue status (Type 'Yes'): ");
                            fflush(stdin);
                            gets(book[i].issue);
                        }
                        printf("\n\n\n\t\t\t\t\t Successfully Issued ");
                        book[i].quantity--;
                        flag++;
                    }
                }
                if(flag==0)
                {
                    printf("\n\n\t\t\t   There is no book with this name...Please try again \n");
                }

                else
                    break;
            }
            printf("\n\n\n\t\t\t\tPress any key for go to Main menu........");
            getch();
        }

        if(choice==4)// View Book Start
        {
            system("color 89");
            system("cls");
            printf("\n\n  Total books: %d \n",count);// was n....
            printf("\n     Information For Book ");
            printf("\n  Category  \t\t Name  \t\t ID  \t\t Author \t\t Price  \t\t Quantity  \t Issue status");
            for(i=0; i<count; i++)
            {
                printf("\n%s",book[i].category);
                printf("\t\t%s",book[i].name);
                printf("\t%d",book[i].id);
                printf("\t\t%s",book[i].author);
                printf("\t\t%.2f",book[i].price);
                printf("  \t%d",book[i].quantity);// new copy
                printf(" of %d",book[i].b_quantity);// new copy
                printf("\t\t%s",book[i].issue);
            }
            printf("\n\n\nPress any key for go to Main menu........");
            getch();
        }
        printf("\n\n");
        printf("\n\n");
    }
    return 0;
}



