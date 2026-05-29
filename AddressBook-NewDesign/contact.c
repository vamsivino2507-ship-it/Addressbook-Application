#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
int deletearray[100];
int deletecount=0;

void listContacts(AddressBook *addressBook) 
{
    if(addressBook->contactCount==0)
    {
        printf("ZERO CONTACT");
    }
  else
  {
 
    for(int i=0;i<addressBook->contactCount;i++)      //change
    {

        printf("%d %s %s %s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        
    }
  }
    
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    
    
    
    loadContactsFromFile(addressBook);

}

/*void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}*/
int namevalidation(Contact*people)
{
   //  AddressBook addressBook;
   // static int count =0;
    int alphcount=0;

    int numericcount=0;

    int l=strlen(people->name);

    for(int i=0;people->name[i]!=0;i++)
    { 
         if(people->name[l]>=97&&people->name[l]<=122||people->name[l]>=65&&people->name[l]<=90||people->name[l]>='1'&&people->name[l]<='9')
        {

               //alphcount++;
               return 1;

        }
        
       /* if(people->name[0]>='0'&&people->name[0]<='9')
        {
           
            printf("invalid name : you entered number in first index\n");
            return 0;
            
        }*/

        if(people->name[i]>=33&&people->name[i]<=47||people->name[i]>=58&&people->name[i]<=64)
        {
             printf("invalid name:you enter special character in name\n");
              return 0;

        }
           
       if(people->name[i]>=97&&people->name[i]<=122||people->name[i]>=65&&people->name[i]<=90)
        {

               alphcount++;

        }

        if(people->name[i]>=48&&people->name[i]<=57)
        {

           // numericcount++;
           printf("invalid name : name should be in character:\n");
           return 0;

        }
    }

        if(alphcount<=2)
        {
            printf("invalid name:you entered less then three character\n");
          return 0;
        }

        // if(alphcount<numericcount)
        // {
        //     return 0;
             
        // }   

        return 1;     
    

}


int phonenovalidation(Contact*people,AddressBook*addressBook)
{

  //  AddressBook addressBook;

    int numcount=0;
     if(people->phone[0]<'6'||people->phone[0]>'9')
    {
        printf("invalid number:starting num should start with 6 to 9\n");

        return 0;
    }

   for(int i=0;people->phone[i]!=0;i++)
   {

   

     if(people->phone[i]>='0'&&people->phone[i]<='9')
     {

         numcount++;

     }

  
     if(people->phone[i]<48||people->phone[i]>57)
     {
        printf("invalid number: you should enter only number\n");
        return 0;
     }
     
   
     
    
    }
     if(addressBook->contactCount>0)
     {
       
        for(int j=0;j<addressBook->contactCount;j++)
        {
       if(strcmp(addressBook->contacts[j].phone,people->phone)==0)
       {
        printf("this number is alredy available in call log\n");
         return 0;

       }
      }
        
     }
     
     
   
  // printf("numcoun%d",numcount);

     if(numcount!=10)
     {
        
      printf("invalid number:you entered less then 10 numbers\n");

       return 0;
       
     }
    

     

   
    return 1;
    

}

int emailinvalid(Contact*people,AddressBook*addressBook)
{

     // AddressBook addressBook;

      int atcount=0;

      int dotcount=0;

      int index,dotindex;

    for(int i=0;people->email[i]!=0;i++)
    {
       if(addressBook->contactCount>0)
       {
        for(int j=0;j<addressBook->contactCount;j++)
        {
        if(strcmp(addressBook->contacts[j].email,people->email)==0)
        {
            printf("This email is already available in call log\n");
            return 0;
        }
       }
       }
      

        if(people->email[0]>='0'&&people->email[0]<='9'||people->email[i]>=32&&people->email[i]<=45||people->email[i]>=65&&people->email[i]<=90)
        {

           
         

            printf("invalid email: character  should be in lowercase and dont use special character and numbers in email except @ and.\n");
           return 0;
            
        }
     
    

   
       
        if(people->email[i]=='@')
        {
            index=i;

            if(people->email[i]=='@'&&people->email[i+1]=='.')
            {

               printf("invalid email:you need to enter some characters between @ and .\n");

               return 0;
                
            }

            atcount++;

        }

        else if(people->email[i]=='.')
        {

            dotindex=i;
            dotcount++;

        }

        
              
    }
             // printf("%d",atcount);
              if(atcount>1||atcount==0)
              {

                
                printf("invalid email:you use @ more then onces\n");

                return 0;
              }

              else if(dotcount>1||dotcount==0)
              {

                 printf("invalid email:you use . more then onces\n");
                

                 return 0;


              }


              for(int i=index+1;i<dotindex;i++)
              {

                  if(people->email[i]<97||people->email[i]>122)
                  {
                    
                    
                  printf("invalid email:email should be only in chacaters between @ and .\n");

                    return 0;

                  }

              }
              if(index>dotindex)
              {
                printf("invalid email: dot(.) should present  in email \n");
                
                return 0;

              }

              
         
               if(people->email[dotindex+1]!='c'||people->email[dotindex+2]!='o'||people->email[dotindex+3]!='m')
                 {
                   
                    printf("invalid email:last 3 letter should be (com)\n");

                   return 0;
                }
             

              return 1;

    
}

void createContact(AddressBook *addressBook)
{
    Contact people;

  
  int nameattempt=0;
  int phoneattempt=0;
  int emailattempt=0;

  if(addressBook->contactCount>MAX_CONTACTS)
{
    printf("Address book full:\n");

    return;
}
   
  
   while(nameattempt<3)
   {
       getchar();

       printf("Enter your name:");

	   scanf("%[^\n]",people.name);

      if(namevalidation(&people))
      {

        break;

      }

    //  printf("invalid name");

       nameattempt++;

   }

   if(nameattempt==3)
   {

    printf("attemptover");

    return;

   }
   
   
  

   while(phoneattempt<3)
   {
   // AddressBook addressBook;
       getchar();

       printf("Enter your number:");

       scanf("%[^\n]",people.phone);
    
       if(phonenovalidation(&people,addressBook))
       {

          break;

       }
      // printf("invalid number");

       phoneattempt++;
    }

   if(phoneattempt==3)
   {
    printf("attempt over");
    return;
    
   }


    while(emailattempt<3)
    { 

    getchar();

    printf("Enter your email id :");

    scanf("%[^\n]",people.email);

    if(emailinvalid(&people,addressBook))
    {
        break;
    }

   // printf("invalid email");

    emailattempt++;

    }
    if(emailattempt==3)
    {
        printf("attempt over");
        return ;
    }

  

  


  // }




    strcpy( addressBook->contacts[addressBook->contactCount].name,people.name);

    strcpy(addressBook->contacts[addressBook->contactCount].phone,people.phone);

    strcpy(addressBook->contacts[addressBook->contactCount].email,people.email);

     addressBook->contactCount++;

    

//printf("contact saved");


    
}

int searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    int choice;
if(addressBook->contactCount==0)
{
    printf("ZERO CONTACT");
}
else{
   

    printf("1.Search by Name\n");

    printf("2.search by number\n");

    printf("3.Search by email\n");

    printf("4.Exit\n");

    printf("Enter one number: ");

    scanf("%d",&choice);

    getchar();

    
   
    
    switch(choice)
    {

        case 1:
        {

             char searchname[100];

             printf("Enter the name:\n");

             scanf(" %[^\n]",searchname);

             int count=0;

            for(int i=0;i<addressBook->contactCount;i++)   //change
            {

                if(strcmp(addressBook->contacts[i].name,searchname)==0)
                {
                       deletearray[deletecount++]=i;
                    printf("%d %s %s %s\n",deletecount,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);

                    

                    count++;

                }
               

            }

            if(count==0)
            {

                printf("Not Found\n");
                return 0;


            }

            break;

        }

        case 2:
        {

            char searchnum[100];

            printf("Enter the number :\n");

            scanf(" %[^\n]",searchnum);

            int count=0;

            for(int i=0;i<addressBook->contactCount;i++)  //change
            {

                if(strcmp(addressBook->contacts[i].phone,searchnum)==0)
                {

                    printf("%s %s %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);

                    count++;

                }
               
            }
           
            if(count==0)
            {

                printf("Not Found\n");
                return 0;

            }

            break;

        }

        case 3:
        {
            char searchemail[100];

            printf("Enter the email:\n");

            scanf(" %[^\n]",searchemail);

            int count=0;
             
            int i;

             for(i=0;i<addressBook->contactCount;i++)  //change
            {

                if(strcmp(addressBook->contacts[i].email,searchemail)==0)
                {

                    printf("%s %s %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);

                    count++;

                }

            }

             if(count==0)
            {

                printf("Not Found\n");
                return 0;

            }
         
           

            break;

        }
        
        case 4:
        {

            return 0;
          //  break;

        }

        default:

        printf("invalid choice\n");

        searchContact(addressBook);
        

        break;

       

    }
    return choice;

       
   

}
      
}

void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */

 int choice= searchContact(addressBook);

    Contact people;
 if(addressBook->contactCount==0)
 {
    printf("ZERO CONTACT");

 }
 else
 {
    if(deletecount!=0)
    {
        if(choice==1)
        {

            int editnameattempt=0;
            int x;
           if(deletecount!=1)
           {
             do
            {
               
              
               
                printf("there are %d contact\n",deletecount);
                printf("which contact do you want to edit:\n");
                scanf("%d",&x);
               
            if(x>deletecount||x<1)
            {
                printf("invalid num\n");
            }

            } while (x>deletecount||x<1);
        }
    
   
    
               
            while(editnameattempt<3)
            {
                 printf("Enter new name:\n");
                scanf(" %[^\n]",people.name);
                if(namevalidation(&people))
                {

    
    
                    for(int i=deletearray[x-1];i<=deletearray[x-1];i++)
                    {
                        strcpy(addressBook->contacts[i].name,people.name);
                    }
                    deletecount=0;
                        break;

                }
                else
                {
                        printf("invalid name\n");

                        editnameattempt++;
        
                }
            }
                if(editnameattempt==3)
                {
                    printf("attempt over");

                    return;
                }
        }
        else if(choice==2)
        {
            int editnumattempt=0;
            //int y;
            // do
            // {
            //     printf("there are %d contact:\n",deletecount);
            //     printf("which contact do you want to change:\n");
            //     scanf("%d",&y);
            //     if(y>deletecount||y<1)
            //     {
            //         printf("invalid number");
            //     }
            // } while (y>deletecount||y<1);
            while(editnumattempt<3)
            {
            printf("Enter new number:\n");
            scanf(" %[^\n]",people.phone);
            if(phonenovalidation(&people,addressBook))
            {
                for(int i=deletearray[deletecount-1];i<=deletearray[deletecount-1];i++)
                {
                    strcpy(addressBook->contacts[i].phone,people.phone);
                }
                break;
            }
            else
            {
                printf("attempt over:\n");
                editnumattempt++;
            }
            }
            if(editnumattempt==3)
            {
                printf("invalid number:\n");
                return;
            }

            
        }
        else if(choice==3)
        {
            int editemailcount=0;
           // int z;
            
            // do
            // {
            //     printf("there are %d contact",deletecount);
            //     printf("which one do you want to edit:\n");
            //     scanf("%d",&z);
            //     if(z>deletecount||z<1)
            //     {
            //         printf("invalid number:\n");
            //     }
            // } while (z>deletecount||z<deletecount);
            while(editemailcount<3)
            {
                printf("Enter new name:\n");
                scanf(" %[^\n]",people.email);
                if(emailinvalid(&people,addressBook))
                {
                    for(int i=deletearray[deletecount-1];i<=deletearray[deletecount-1];i++)
                    {
                       strcpy(addressBook->contacts[i].email,people.email);
                    }
                    break;
                }
                else
                {
                    printf("invalid email:\n");
                    editemailcount++;
                }
            }
            if(editemailcount==3)
            {
                printf("attempt over:\n");
                return;
            }
            
        }

    }  
 }

}

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
 if(addressBook->contactCount==0)
 {
    printf("ZERO CONTACT:\n");
 }
 else
 {
    if(searchContact(addressBook))
    {
         int x=deletecount;

         if(deletecount>1)
         {
       

   printf("there are %d contact:\n",deletecount);

  

   printf("which one you want to delete:\n");

   scanf("%d",&x);
         }

   for(int i=deletearray[x-1];i<addressBook->contactCount-1;i++)
   {

      addressBook->contacts[i]=addressBook->contacts[i+1];
    
   }
   deletecount=0;

   addressBook->contactCount--;
}
else
{
    
    return;
}
}

   
   

}
