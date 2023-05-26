
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

typedef struct products
{ 
    int saree[4];
    int shoes[2];
    int ele_item[2];
    int dress[2];
    struct cart
    {
       int disc;
       int price;
       struct cart *link;
    }*cr,*ps;
    
}pr;

typedef struct profile
{
    char name[20];
    char adress[30];
    long phone;
    long pincode;
}PR;

typedef struct cart_product
{
  long phone;
  char item[25];
  int rate;
  int discou;
}CP;

int choose(char*);
void add_to_cart(int,int);
struct cart* get_memory();
void buy(int,int,int,int);
void buy_cart();
void Payment(int );
int saree();
int Shoes();
int electrical();
int dress();
void shopping();
int Discount=0;
pr product;
int total_rate;
char search_pro[20];
int cnt=0,f,price,Discoun;
int total_price=0;
int st,z=0,x;
CP cart3[50], cart1[50];
long phone;
PR account[100];
int main()
{ 
    int i=0,k=0,g=0,ch,choice,dis,Rate,disc,flag=0,sm,m=0;
    int cho;
    char size[4],size_sh[5];
    long pin;
    char name[25],address[50],suc;
    
    float q;
    FILE *fp;
    FILE *gp;
   
    CP cart2;
    fp=fopen("data.txt","a+");
    gp=fopen("cart.txt","a+");
    printf("MINISHOP!!!\n");
    printf("Hello...Welcome to Our Online Shopping\n\n");
    for(;;)
    {
      printf("Enter\n1:Create account\n2:Login\n3.Exit\n");
      for(;;)
      {
        fscanf(fp,"%s%s%ld%ld",account[i].name,account[i].adress,&account[i].phone,&account[i].pincode);
        if(feof(fp))
        {   
            break;
        }
        i++;
      }
      scanf("%d",&ch);
      switch(ch)
      {
        case 1:printf("Enter your name\n");
               scanf("%s",name);
               printf("Enter address\n");
               scanf("%s",address);
               printf("Enter mobile number\n");
               scanf("%ld",&phone);
               printf("Enter Pincode\n");
               scanf("%ld",&pin);
               for(int j=0;j<i;j++)
               {
                 if(account[j].phone==phone)
                 { 
                   x=j;
                   flag=1;
                 }
               }
               
               if(flag==0)
               {
                 fprintf(fp,"%s %s %ld %ld ",name,address,phone,pin);
                 m++;
                 printf("Congratulations!! your account has been created Successfully...\n");
               }
               else
               {
                 printf("There is already an account associated with this phone number please try logging in...\n");
               } 
               printf("Enter\n1:to logging in\n2:to exit\n");
               scanf("%d",&ch);
               if(ch==1)
               {
                  
               }
              else
                break;
              
        case 2:flag=0;
               printf("Enter mobile number\n");
               scanf("%ld",&phone);
               for(int j=0;j<i;j++)
               {
                 if(account[j].phone==phone)
                 {
                   flag=1;
                 }
               }
               
               if(flag==0&&m==0)
               {
                 printf("We don't have an account associated with this phone numeber..Please! Double check your mobile number or Create an account to login\n");
                 break;
               }
               else if(m==1)
               {
                  printf("You have successfully logged in to your account!!\n");
               }
               else
               {
                 printf("You have successfully logged in to your account!!\n");
               }
              
               for(;;)
               {   
                printf("\n");
                printf("ENTER 1:to buy from cart 2:to search the product 3:to exit " );
                getchar();
                scanf("%d",&cho);
               
                switch(cho)
                {
                  case 1: 
                          fseek(gp,0,SEEK_SET);
                          for(;;)
                          {
                             
                             fscanf(gp,"%ld %s %d %d",&cart1[g].phone,cart1[g].item,&cart1[g].rate,&cart1[g].discou);
                             if(feof(gp))
                             {  
                                break;
                             }
                             
                             g++;
                          }
                         
                          f=0;
                          for(sm=0;sm<6;sm++)
                          {   
                              if(cart1[sm].phone==phone)
                              {
                               printf("%ld\t%s\t%d\t%d\n",cart1[sm].phone,cart1[sm].item,cart1[sm].rate,cart1[sm].discou);
                               cart3[f]=cart1[sm];
                               f++;
                               z++;
                              }
                          }
                         
                         buy_cart();
                         break;
        
                  case 2:printf("Enter product name to search the product \n");
                         printf("Enter digit to exit\n");
                         scanf("%s",search_pro);
                         ch=choose(search_pro);
                    
                         switch(ch)
                         {
                          case 1:printf("\n");
                                  Rate=saree();
                                  dis=10;
                                  printf("ENTER\n1:to buy Saree\n2:to Add to Cart\n");
                                  scanf("%d",&choice);
                                  switch(choice)
                                  {
                                    case 1:q=(((float)dis)/100)*Rate;
                                           buy(Rate,1,2,q);
                                           break;
                                           
                                    case 2:add_to_cart(Rate,dis);
                                           cart2.phone=phone;
                                           strcpy(cart2.item,search_pro);
                                           cart2.rate=Rate;
                                           cart2.discou=Discoun;
                                           printf("****Discount=%d***\n",Discoun);
                                           printf("cart2.discou**=%d\n", cart2.discou);
                                           fseek(gp,0,SEEK_END);
                                           fprintf(gp,"%ld %s %d %d ",cart2.phone,cart2.item,cart2.rate,cart2.discou);
                                           break;
                                 }
                                 break;
                           
                          case 2:printf("\n");
                                 Rate=Shoes();
                                 dis=5;
                                 printf("ENTER\n1:to buy Shoes\n2:to Add to Cart\n");
                                 scanf("%d",&choice);
                                 printf("Select size\n");
                                 printf("4 UK   5 UK   6 UK   7 UK   8 UK  9 UK\n");
                                 scanf("%s",size_sh);
                                 switch(choice)
                                 {
                                   case 1:q=(((float)dis)/100)*Rate;
                                          buy(Rate,1,2,q);
                                          break;
                                          
                                   case 2:add_to_cart(Rate,dis);
                                          cart2.phone=phone;
                                           strcpy(cart2.item,search_pro);
                                           cart2.rate=Rate;
                                           cart2.discou=Discoun;
                                            fseek(gp,0,SEEK_END);
                                           fprintf(gp,"%ld %s %d %d ",cart2.phone,cart2.item,cart2.rate,cart2.discou);
                                          break;
                                 }
                                 break;
                           
                          case 3:printf("\n");
                                 Rate=electrical();
                                 dis=10;
                                 printf("ENTER\n1:to buy Electrical item\n2:to Add to Cart\n");
                                 scanf("%d",&choice);
                                 switch(choice)
                                 {
                                   case 1:q=(((float)dis)/100)*Rate;
                                          buy(Rate,1,2,q);
                                          break;
                                          
                                   case 2:add_to_cart(Rate,dis);
                                          cart2.phone=phone;
                                           strcpy(cart2.item,search_pro);
                                           cart2.rate=Rate;
                                           cart2.discou=Discoun;
                                            fseek(gp,0,SEEK_END);
                                           fprintf(gp,"%ld %s %d %d ",cart2.phone,cart2.item,cart2.rate,cart2.discou);
                                          break;
                                 }
                                 break;
                           
                          case 4:printf("\n");
                                 Rate=dress();
                                 dis=15;
                                 printf("ENTER\n1:to buy Dress\n2:to Add to Cart\n");
                                 scanf("%d",&choice);
                                 printf("Select size\n");
                                 printf("S   M   L   XL   2XL\n");
                                 scanf("%s",size);
                                 switch(choice)
                                 {
                                  case 1:q=(((float)dis)/100)*Rate;
                                         buy(Rate,1,2,q);
                                         break;
                                   
                                  case 2:add_to_cart(Rate,dis);
                                         cart2.phone=phone;
                                           strcpy(cart2.item,search_pro);
                                           cart2.rate=Rate;
                                           cart2.discou=Discoun;
                                            fseek(gp,0,SEEK_END);
                                           
                                           fprintf(gp,"%ld %s %d %d ",cart2.phone,cart2.item,cart2.rate,cart2.discou);
                                         break;
                                 }
                                break;
                            
                          case 5:printf("\n");
                                 printf("Sorry,no result found!!!\nPlease check the spelling or try searching for something else....\n ");
                                 break;
                           
                         default:printf("\n");
                                 printf("Are you sure want to exit?\nEnter:\n1 to exit\n2 to continue \n");
                                 scanf("%d",&choice);
                                 if(choice==1)
                                    exit(0);
                                 break;
                         }
                         break;
                  
                  case 3:exit(0);
                }
               }
               break;
        
        case 3:printf("Are you sure you want to exit\n");
               printf("Enter\tY:Yes  N:NO\n");
               scanf("%c",&suc);
               switch(suc)
               {
                   case 'Y':
                   case 'y':exit(0);
                        
                   case 'N':
                   case 'n':break;

               }
              
    }
}
}

int choose(char search_pro[])
{ 
    char S[4][6]={"Saree","saree","sari","Sari"};
    char Sh[4][6]={"Shoes","shoes","shoes","Shoe"};
    char Ele[2][11]={"Electrical","electrical"};
    char Dr[2][7]={"Dress","dress"};
     
    if((strcmp(search_pro,S[0])==0)||(strcmp(search_pro,S[1])==0)||(strcmp(search_pro,S[2])==0)||(strcmp(search_pro,S[3])==0))
        return 1;
    else if((strcmp(search_pro,Sh[0])==0)||(strcmp(search_pro,Sh[1])==0)||(strcmp(search_pro,Sh[2])==0)||(strcmp(search_pro,Sh[3])==0))
        return 2;
    else if((strcmp(search_pro,Ele[0])==0)||(strcmp(search_pro,Ele[1])==0))
        return 3;
    else if((strcmp(search_pro,Dr[0])==0)||(strcmp(search_pro,Dr[1])==0))
      return 4;
    else if(isdigit(search_pro[0]))
       return 8;
    else
    return 5;
}

void add_to_cart(int Rate,int dis)
{
     f=0;
     price=0;
     Discoun=0;
     for(int sm=0;sm<6;sm++)
     {   
        if(cart1[sm].phone==phone)
        {
            printf("%ld\t%s\t%d\t%d\n",cart1[sm].phone,cart1[sm].item,cart1[sm].rate,cart1[sm].discou);
            cart3[f]=cart1[sm];
            f++;
            
        }
    }
    struct cart* t;
    struct cart* temp;
   
    if(product.cr==NULL)
    {   
        product.cr=get_memory();
        product.cr->disc=dis;
        product.cr->price=Rate;
        product.cr->link=NULL;
    }
    else 
    {
        temp=get_memory();
        product.cr->disc=dis;
        product.cr->price=Rate;
        temp->link=NULL;
        t=product.cr;
        while(t->link!=NULL)
        { 
            t=t->link;
        }
        t->link=temp;
     }
     
     while(product.cr!=NULL)
     {
        price=price+ product.cr->price;
        Discoun=(Discoun+(((float)(product.cr->disc)/100)*product.cr->price));
        cnt++;
        product.cr=product.cr->link;
     }
     printf("Your product is added to cart...\n");
}

struct cart* get_memory()
{
     struct cart* temp;
     temp =(struct cart*)malloc(sizeof(struct cart));
     return temp;
}

void buy_cart()
{
    Discount=0;
    total_price=0;
    for(int t=0;t<f;t++)
     {
        
         Discount=Discount+cart3[t].discou;
         total_price= total_price+cart3[t].rate;
         
     }
    buy((total_price+price),(cnt+f),3,(Discount+Discoun));
}

void buy(int Rate,int item_no,int st,int Discount)
{
     char str[20],name[20];
     int choice;
     float q;
     long int phone_no,pincode;
     int  t_d,t_mon,t_y;
     time_t ct;
     time_t t;
     long int Id;
     srand((unsigned) time(&t));
     Id=rand();
     time(&ct);
     struct tm *local=localtime(&ct);
     t_d=local->tm_mday;
     t_mon=local->tm_mon+1;
     t_y=local->tm_year+2000-100;
     if(t_d==31||t_d==30||t_d==29||t_d==28||t_d==27)
     {
        t_d=((t_d+1)%26)+1;
        t_mon=((t_mon+1)%12);
     }
     else
     {
        t_d=t_d+3;
     }
     if(item_no==0&&z==0)
     {
       printf("CART IS EMPTY\n"); 
       return;
     }
     else
     {
       printf("**************\n");
       printf("price(%d item)\t\t%d\n",item_no,Rate);
       printf("Discount\t\t-%d\n",Discount);
       printf("Delivery Charges\tFREE Delivery\n");
       printf("Total Amount\t\t%d\n",(Rate-Discount));
       printf("**************\n");
     }
     if(item_no==1&&st==2)
     {
       printf("You choose product ₹%d\nAre you sure to buy?\nEnter\n1:to buy now\t2:to add to cart\t3:to see other products\t4:to exit\n",(Rate-Discount));
       scanf("%d",&choice);
       
       switch(choice)
       {
         case 1:
                Payment((Rate-Discount));
                printf("Hi %s,\n",account[x].name);
                printf("\n");
                printf("Order Successfully Placed.\n");
                printf("Your Order will be delivered to %s-%ld by %d/%d/%d\n",account[x].adress,account[x].pincode,t_d,t_mon,t_y);
                printf("We are pleased to confirm your order number %ld\n",Id);
                printf("Thank you for Shopping with Minishop!!\n");
                printf("\n\n");
                break;
               
         case 2:add_to_cart(Rate,((Discount*100)/Rate));
                break;
               
         case 3:return;
         
         case 4:exit(0);
        }
     }
    else
     {
        printf("You choose the products for ₹%d\nAre you sure to buy?\nEnter\n1:to place order\t2:to see other products\t   3:to exit\n",(Rate-Discount));
        scanf("%d",&choice);
        
        switch(choice)
        {
         case 1:
                Payment((Rate-Discount));
                printf("Hi %s,\n",account[x].name);
                printf("\n");
                printf("Order Successfully Placed.\n");
                printf("Your Order will be delivered to %s-%ld by %d/%d/%d\n",account[x].adress,account[x].pincode,t_d,t_mon,t_y);
                printf("We are pleased to confirm your order number %ld\n",Id);
                printf("Thank you for Shopping with Minishop!!\n");
                printf("\n\n");
                break;
                
         case 2:return;
         
         case 3:exit(0);
       }
     }    
}


void Payment(int Rate)
{
    int choice,MM,YY,CVV;
    char ch,bank_name[20];
    long  int UPI,link_no,user_ID,password,card_no;
    time_t t;
    unsigned short Id,Captcha;
    srand((unsigned) time(&t));
    Id=rand();
    printf("ENTER\n1:UPI\n2:wallet/Postpaid\n3:Credit/ATM/Debit card\n4:Net banking\n5:Cash on Delivery\n6: exit\n");  
    scanf("%d",&choice);
    
    switch(choice)
    {
       case 1:printf("ENTER:\n1:Phonepay\n2:Gpay\n3:Your UPI ID\n");
              getchar();
              scanf("%c",&ch);
              
              switch(ch)
              {
                 
                  case 1:printf("ENTER UPI PIN\n");
                           scanf("%ld",&UPI);
                           break;
                           
                
                  case 2:printf("ENTER UPI PIN\n");
                           scanf("%ld",&UPI);
                           break;
                           
                 
                  case 3:printf("ENTER YOUR UPI Id\n");
                           scanf("%ld",&UPI);
                           break;
                 
              } 
              printf("\n");
              printf("\a");
              break;
              
       case 2:printf("ENTER:\nA:Paytm Wallet\nB:Paytm Postpaid\nC:Phonepe Wallet\n");
              getchar();
              scanf("%c",&ch);
              switch(ch)
              {
                 case 'A':
                 case 'a':printf("Enter Paytm Wallet Linked no.\n");
                            scanf("%ld",&link_no);
                            break;
                     
                 case 'B':
                 case 'b':printf("Enter Paytm Postpaid Linked no.\n");
                            scanf("%ld",&link_no);
                            break;
                  
                 case 'C':
                 case 'c':printf("Enter Phonepe Wallet Linked no.\n");
                            scanf("%ld",&link_no);
                            break;
               }
               printf("\n");
               printf("\a");
               break;
                            
               
       case 3:printf("Enter Card number\n");
              scanf("%ld",&card_no);
              printf("enter\n");
              printf("MM:\n");
              scanf("%d",&MM);
              printf("YY:\n");
              scanf("%d",&YY);
              printf("CVV:\n");
              scanf("%d",&CVV);
              printf("\n");
              printf("\a");
              break;
               
       case 4:printf("Enter your Bank name\n");
              scanf("%s",bank_name);
              printf("Enter your Bank User ID\n");
              scanf("%ld",&user_ID);
              printf("Enter password\n");
              scanf("%ld",&password);
              printf("\n");
              printf("\a");
              break;
        
       case 5:printf("CAPTCHA\n%d\n",Id);
              printf("Enter the Captcha\n");
              scanf("%hd",&Captcha);
              if(Id==Captcha)
              {
                   return;
              }
              else
              {
                   while(Id!=Captcha)
                   {
                    printf("Incorrect Captcha..please try Again\n");
                    scanf("%hd",&Captcha);
                   }
                   printf("\n");
                   return;
               } 
               printf("\a");
               break;
               
               
       case 6:exit(0);
   }
}

int saree()
{
    int ch;
    FILE *fp=fopen("Sar_rate.txt","r");
    printf("SAREES COLLECTION\n");
    printf("* 10%% Off *\n");
    printf("Enter\n1:to BANARASI SAREES\n2:to KANCHIPURAM SILK SAREES\n3:to COTTON SAREES\n4:to MYSORE SILK SAREES\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:printf("BANARASI SAREES\n\n");
               fseek(fp,0,SEEK_SET);
               fscanf(fp,"%d%d%d%d",&product.saree[0],&product.saree[1],&product.saree[2],&product.saree[3]);
               printf("Saree-1\ncost:%d\ncolour:Red\n\nSaree-2\ncost:%d\ncolour:Pink\n\nSaree-3\ncost:%d\ncolour:Red\n\nSaree-4\ncost:%d\ncolour:Red\n\n",product.saree[0],product.saree[1],product.saree[2],product.saree[3]);
               printf("Enter\n1:to Saree-1\n2:to Saree-2\n3:to Saree-3\n4:to Saree-4\n");
               scanf("%d",&ch);
               
               switch(ch)
               {
                   case 1:return product.saree[0];
                          break;
                          
                   case 2:return product.saree[1];
                          break;
                          
                   case 3:return product.saree[2];
                          break;
                   
                   case 4:return product.saree[3];
                          break;
               }  
               break;
               
        case 2:printf("KANCHIPURAM SILK SAREES\n\n");
               fseek(fp,20,SEEK_SET);
               fscanf(fp,"%d%d%d%d",&product.saree[0],&product.saree[1],&product.saree[2],&product.saree[3]);
               printf("Saree-1\ncost:%d\ncolour:Red\n\nSaree-2\ncost:%d\ncolour:Pink\n\nSaree-3\ncost:%d\ncolour:Red\n\nSaree-4\ncost:%d\ncolour:Red\n\n",product.saree[0],product.saree[1],product.saree[2],product.saree[3]);
               printf("Enter\n1:to Saree-1\n2:to Saree-2\n3:to Saree-3\n4:to Saree-4\n");
               scanf("%d",&ch);
               
               switch(ch)
               {
                   case 1:return product.saree[0];
                          break;
                          
                   case 2:return product.saree[1];
                          break;
                          
                   case 3:return product.saree[2];
                          break;
                   
                   case 4:return product.saree[3];
                          break;
               }  
               break;
               
        case 3:printf(" COTTON SAREES\n\n");
               fseek(fp,39,SEEK_SET);
               fscanf(fp,"%d%d%d%d",&product.saree[0],&product.saree[1],&product.saree[2],&product.saree[3]);
               printf("Saree-1\ncost:%d\ncolour:Red\n\nSaree-2\ncost:%d\ncolour:Pink\n\nSaree-3\ncost:%d\ncolour:Red\n\nSaree-4\ncost:%d\ncolour:Red\n\n",product.saree[0],product.saree[1],product.saree[2],product.saree[3]);
               printf("Enter\n1:to Saree-1\n2:to Saree-2\n3:to Saree-3\n4:to Saree-4\n");
               scanf("%d",&ch);
               
               switch(ch)
               {
                   case 1:return product.saree[0];
                          break;
                          
                   case 2:return product.saree[1];
                          break;
                          
                   case 3:return product.saree[2];
                          break;
                   
                   case 4:return product.saree[3];
                          break;
               }  
               break;
               
        case 4:printf("MYSORE SILK SAREES\n\n");
               fseek(fp,55,SEEK_SET);
               fscanf(fp,"%d%d%d%d",&product.saree[0],&product.saree[1],&product.saree[2],&product.saree[3]);
               printf("Saree-1\ncost:%d\ncolour:Red\n\nSaree-2\ncost:%d\ncolour:Pink\n\nSaree-3\ncost:%d\ncolour:Red\n\nSaree-4\ncost:%d\ncolour:Red\n\n",product.saree[0],product.saree[1],product.saree[2],product.saree[3]);
               printf("Enter\n1:to Saree-1\n2:to Saree-2\n3:to Saree-3\n4:to Saree-4\n");
               scanf("%d",&ch);
               
               switch(ch)
               {
                   case 1:return product.saree[0];
                          break;
                          
                   case 2:return product.saree[1];
                          break;
                          
                   case 3:return product.saree[2];
                          break;
                   
                   case 4:return product.saree[3];
                          break;
               }  
               break;
    }
}

int Shoes()
{
    int ch;
    FILE *fs=fopen("shoe_rate.txt","r");
    printf("SHOES COLLECTION\n");
    printf("* 5%% Off *\n");
    printf("Enter\n1:to MEN SHOES\n2:to WOMEN SHOES\n");
    scanf("%d",&ch);
    
    switch(ch)
    {
       case 1:printf("MEN SHOES\n\n");
              fseek(fs,0,SEEK_SET);
              fscanf(fs,"%d%d",&(product.shoes[0]),&(product.shoes[1]));
              printf("1.ADIDAS SHOE\ncolour:Black\nCost:%d\n\n2.NIKE SHOE\ncolour:White\nCost:%d\n",(product.shoes[0]),(product.shoes[1]));
              printf("Enter\n1.to ADIDAS BRAND\n2.to NIKE BRAND\n");
              scanf("%d",&ch);
              
              switch(ch)
              {
                   case 1:return product.shoes[0];
                          break;
                   case 2:return product.shoes[1];
                          break;
              }
              break;
               
       case 2:printf("WOMEN SHOES\n\n");
              fseek(fs,10,SEEK_SET);
              fscanf(fs,"%d%d",&(product.shoes[0]),&(product.shoes[1]));
              printf("1.SPARX SHOE\ncolour:Black\nCost:%d\n\n2.PUMA SHOE\ncolour:White\nCost:%d\n",(product.shoes[0]),(product.shoes[1]));
              printf("Enter\n1.to SPARX BRAND\n2:to PUMA BRAND\n");
              scanf("%d",&ch);
              
              switch(ch)
              {
                   case 1:return product.shoes[0];
                          break;
                   case 2:return product.shoes[1];
                          break;
              }
              break;
    }
}

int electrical()
{
    int ch;
    FILE *fp=fopen("ele_rate.txt","r");
    printf("ELECTRONIC DEVICES\n");
    printf("* 10%% Off *\n");
    printf("Enter\n1:to LAPTOP\n2:to IRON BOX\n");
    scanf("%d",&ch);
    
    switch(ch)
    {
        case 1:printf("LAPTOP\n\n");
               fseek(fp,0,SEEK_SET);
               fscanf(fp,"%d%d",&(product.ele_item[0]),&(product.ele_item[1]));
               printf("1.HP\nCost:%d\n\n2.DELL\nCost:%d\n",(product.ele_item[0]),(product.ele_item[1]));
               printf("Enter\n1.to HP\n2.to DELL\n");
               scanf("%d",&ch);
               
               switch(ch)
               {
                   case 1:return product.ele_item[0];
                          break;
                   case 2:return product.ele_item[1];
                          break;
               }
               break;
               
        case 2:printf("IRON BOX\n\n");
               fseek(fp,12,SEEK_SET);
               fscanf(fp,"%d%d",&(product.ele_item[0]),&(product.ele_item[1]));
               printf("1.PHILIPS\nCost:%d\n\n2.BAJAJ\nCost:%d\n",(product.ele_item[0]),(product.ele_item[1]));
               printf("Enter\n1.to PHILIPS\n2.to BAJAJ");
               scanf("%d",&ch);
               
               switch(ch)
               {
                   case 1:return product.ele_item[0];
                          break;
                   case 2:return product.ele_item[1];
                          break;
               }
               break;
    }
}

int dress()
{
    int ch;
    FILE *fp=fopen("dress_rate.txt","r");
    printf("DRESS COLLECTION\n");
    printf("* 15%% Off *\n");
    printf("Enter\n1:to MEN DRESS\n2:to WOMEN DRESS\n");
    scanf("%d",&ch);
    
    switch(ch)
    {
        case 1:printf("MEN DRESS\n\n");
               fseek(fp,0,SEEK_SET);
               fscanf(fp,"%d%d",&(product.dress[0]),&(product.dress[1]));
               printf("1.JEANS\nColour:Blue\nCost:%d\n\n2.SHIRT\nColour:Black\nCost:%d\n",(product.dress[0]),(product.dress[1]));
               printf("Enter\n1.to JEANS\n2.to SHIRT\n");
               scanf("%d",&ch);
               
               switch(ch)
               {
                   case 1:return product.dress[0];
                          break;
                   case 2:return product.dress[1];
                          break;
               }
               break;
               
        case 2:printf("WOMEN DRESS\n\n");
               fseek(fp,9,SEEK_SET);
               fscanf(fp,"%d%d",&(product.dress[0]),&(product.dress[1]));
               printf("1. WESTERN WEAR\nColour:Red\nCost:%d\n\n2.MODERN WEAR\nColour:Black\nCost:%d\n",(product.dress[0]),(product.dress[1]));
               printf("Enter\n1.to WESTERN WEAR\n2.to MODERN WEAR\n");
               scanf("%d",&ch);
             
               switch(ch)
               {
                   case 1:return product.dress[0];
                          break;
                   case 2:return product.dress[1];
                          break;
               }
               break;
    }
 }