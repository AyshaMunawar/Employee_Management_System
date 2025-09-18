#include <stdio.h> ///for input output functions like printf, scanf
#include <stdlib.h>
#include <conio.h>
#include <string.h>  ///string operations

 struct emp
    {
    	int id[5];
        char name[30]; 
        char gender[5];    
	char position[20];
	int experience;       
        float salary;            
    };

void addRecord(struct emp e,int another,long int recSize,FILE *fopen)
{
	while(another == 'y')  /// if user want to add another record
            {
                printf("\nEnter Employee ID(i.e. Emp01): ");
                scanf("%d",&e.id);
                printf("\nEnter Name(i.e. without space): ");
                scanf("%s",e.name);
                printf("\nEnter Gender(i.e. M/F): ");
                scanf("%s",e.gender);
                printf("\nEnter Job Position(i.e. internee/Developer): ");
                scanf("%s",e.position);
                printf("\nEnter Experience in Years:(i.e. 1/2) ");
                scanf("%d", &e.experience);
                printf("\nEnter Basic Salary: ");
               scanf("%f", &e.salary);

                fwrite(&e,recSize,1,fopen); // write the record in the file

                printf("\nAdd Another Record(y/n): ");
               fflush(stdin);
                another = getche();
            }
	
}
void showBelowBasicpay(struct emp e,long int recSize,FILE *fopen) 
{
	 rewind(fp); //this moves file cursor to start of the file
	      while(fread(&e,recSize,1,fopen)<=1)  
            {
            	
            	if(e.salary<20000)
				 {
       
                printf("\n%d %s %s %s %d %.2f",e.id,e.name,e.gender,e.position,e.experience,e.salary); 
                
				}
				break;
            }
            
        getch();

}
void searchByID(struct emp e,long int recSize,FILE *fopen,int eid) 
{
	 rewind(fp); //this moves file cursor to start of the file
           	int found=0;
        	while(fread(&e,recSize,1,fopen)==1)
		{
			
		if(e.id == eid)
				{
			found=1;
		 
		
			printf("\n%d %s %s %s %d %.2f",e.id,e.name,e.gender,e.position,e.experience,e.salary); 
	
		break;	

				}
			}
			if(found==0)
   				printf("\n Record Not found in this file!");
        getch();
	
}
void showAllRecord(struct emp e,long int recSize,FILE *fopen) 
{
	  
            rewind(fp); 
            while(fread(&e,recSize,1,fopen)==1)  
            {
                printf("\n%d %s %s %s %d %.2f",e.id,e.name,e.gender,e.position,e.experience,e.salary); 
            }
            getch();
}


int main()
{
    FILE *fopen, *ftemp; // file pointers
	char another, choice;

    /* structure that represent a employee */
   
    struct emp e; // structure variable creation
 	
	 char empname[40];
    int eid;
	long int recSize; // size of each record of employee

    fp = fopen("emp_Project.txt","a+");
    if(fp == NULL)
    {
        fp = fopen("emp_Project.txt","r");
        if(fp == NULL)
        {
            printf("Connot Open File");
            exit(1);
        }
	}
int found;

    recSize = sizeof(e);

    while(1)
    {
        system("cls"); 
        printf("1. Add Records\n"); 
        printf("2. Search a record by ID\n"); 
        printf("3. Show all Records\n"); 
        printf("4. Show employee having pay less then basic pay(20000)\n");
        printf("5. Save and Exit\n"); 
        printf("Enter Your Choice: "); 
        fflush(stdin); 
        choice  = getche(); 
        switch(choice)
        {
        case '1': 
            system("cls");
            
            another = 'y';
            addRecord(e,another,recSize,fopen); 
            
            break;
            
        case '2':
        	system("cls");
		    
            printf("\n Enter ID of Employee to Search Record=");
			scanf("%d",&eid);
          	searchByID(e,recSize,fopen,eid);
          
            break;

        case '3':
        	system("cls");
      
        	showAllRecord(e,recSize,fopen);
        	
            break;
        
        case '4':
        	system("cls");
        	
			showBelowBasicpay(e,recSize,fopen);
        	
			break;
        	
        case '5':
        	
            fclose(fopen);  
            exit(0);
        }
	}
    return 0;
}
