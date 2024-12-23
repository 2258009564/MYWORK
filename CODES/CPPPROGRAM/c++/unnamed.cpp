#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum{pen=1,book,paint,otherc}Category;//类别枚举
typedef enum{chenguang=1,deli,banma,baile,otherb}Brand;//品牌枚举

typedef struct 
{
    int id;
    char name[20];
    Category cate;
    Brand brand;
    float price;
    int num;    
} Thing; 
//一个包含商品编号，商品名称，类别，品牌，商品单价，库存数量的商品类

void menu();//总菜单
void menu3();//功能3菜单
void thingShow(Thing th);//展示一件商品
int readOneThing(Thing *t,FILE *fp);//从文件读一个商品
int findSameID(Thing th[],int top,int temp);//找相同id
int findSameName(Thing th[],int top,char str[]);//找相同名称
void DeleteOne(Thing th[],int *top,int n);//删掉一个商品
void changeTowThing(Thing *t1,Thing *t2);//交换两个商品的位置
const char* LeiBie(Category c);//枚举类别转字符
const char* PingPai(Brand b);//枚举品牌转字符
void readThing(FILE *fp,Thing th[],int *top);//读文件到数组
void writeThing(FILE *fp,Thing th[],int top);//写数组到文件

void function1(FILE *fp);
void function2(FILE *f);
void function3(FILE *f);
void function4(FILE *f);
void function5(FILE *f);
void function6(FILE *f);
void function7(FILE *f);
void function8(FILE *f);
void function9(FILE *f);

int main()
{
    int option;
    FILE *fp=fopen("store.txt", "a");             //确认仓库文件store.txt是否存在
    if(fp==NULL)                                  //没有就新建一个
    {
        printf("\t* 仓库文件打开失败！请退出程序重试。*\t\n");
        return 1;
    }
    fclose(fp);
    
    while(1)
    {
        menu();
        printf("\n请选择您的选项:");
        scanf("%d",&option);
        switch (option)
        {
            case 1:function1(fp);break;
            case 2:function2(fp);break;
            case 3:function3(fp);break;
            case 4:function4(fp);break;     
            case 5:function5(fp);break;
            case 6:function6(fp);break;
            case 7:function7(fp);break;
            case 8:function8(fp);break;
            case 9:function9(fp);break;
            case 10:
                int temp;
                printf("您已选择 [10]退出\n\t* 请问您是否要退出？*\n\t* 确认退出请输入0,输入其他整数则返回菜单 *\n");
                while(1)   //增加了确认退出，检查有没有错误输入
                {
                    printf("请输入您的选择：");
                    int sc=scanf("%d",&temp);
                    if(sc!=1)
                    {
                        getchar();
                        printf("\t* 输入有误，请重新输入一个整数。*\n");                        
                    }
                    else{break;}
                };
                
                if(temp==0)
                {
                    printf("\n\t* 感谢使用~ *\n\n");
                    system("pause");
                    return 0;
                }
                else
                {
                    printf("\n\t* 即将返回菜单...*\n\n");
                    system("pause");
                }
                break;
            default:getchar();printf("\t* 没有此功能,请重新输入! *\n");system("pause");    
        }
        system("cls");//可以实现清屏效果   
    }
    return 0;
}

void menu() 
{
    printf("\n");
    printf(" ____ ____ ___ __  __ ____   \n");
    printf("/ ___/ ___|_ _|  \\/  / ___|  \n");
    printf("\\___ \\___ \\| || |\\/| \\___ \\  \n");                                                  
    printf(" ___) |__) | || |  | |___) | \n");
    printf("|____/____/___|_|  |_|____/  \n");
    printf("Stationery Store Inventory Management System\n");
    printf("\n");
    printf("          *********** 欢迎使用文具店商品管理系统 ***********\n");
    printf("     *                                                        *\n");
    printf("     *  [1] 批量录入初始商品信息                              *\n");
    printf("     *  [2] 浏览全部商品信息                                  *\n");
    printf("     *  [3] 查询商品信息                                      *\n");
    printf("     *  [4] 增加商品信息                                      *\n");                                
    printf("     *  [5] 删除商品信息                                      *\n");
    printf("     *  [6] 修改商品信息                                      *\n");
    printf("     *  [7] 按类别统计商品数量                                *\n");
    printf("     *  [8] 按单价对商品排序                                  *\n");
    printf("     *  [9] 计算当前库存商品的总价值                          *\n");
    printf("     *  [10] 退出                                             *\n");
    printf("     *                                                        *\n");
    printf("        ***************************************************\n"); 
}

void menu3()
{
    printf("\n");
    printf("          *********** 请选择查询方式 ***********\n");
    printf("     *                                               *\n");
    printf("     *  1. 根据商品编号查询                          *\n");
    printf("     *  2. 根据商品名称查询                          *\n");
    printf("     *  3. 根据商品品牌查询                          *\n");
    printf("     *  4. 根据商品类别查询                          *\n");                                
    printf("     *                                               *\n");
    printf("         ****************************************\n"); 
}

void thingShow(Thing th)
{
    printf("\n");
    printf("         *********** 商品信息 ***********\n\n");
    printf("        商品编号                   :%d\t\n",th.id);
    printf("        商品名称                   :%s\t\n",th.name);
    printf("        商品类别                   :%s\t\n",LeiBie(th.cate));
    printf("        商品品牌                   :%s\t\n",PingPai(th.brand));
    printf("        商品单价                   :%.2f\t\n",th.price);
    printf("        商品库存                   :%d\t\n\n",th.num);                               
    printf("          *******************************\n"); 
}

int readOneThing(Thing *t,FILE *fp)     //从文件里面读取一个商品并存进Thing
{                                       //如果成功读取返回1，读取结束或者失败返回0
    if (t==NULL||fp==NULL) 
    {
        return 0;
    }

    if (fscanf(fp,"%d %19s %d %d %f %d",&(t->id),t->name,&(t->cate),&(t->brand),&(t->price),&(t->num))==6)
    {        
        return 1;
    } 
    else
    {
        return 0;
    }
}

int findSameID(Thing th[],int top,int temp)   //从Thing数组中找相同id
{                                             //没有返回-1，有则返回下标
    for(int i=0;i<top;i++)
    {
        if(th[i].id==temp)
        {
            return i;
        }
    }
    return -1;
}

int findSameName(Thing th[],int top,char str[])  //从Thing数组中找相同名称
{                                                //没有返回-1，有返回下标
    for(int i=0;i<top;i++)
    {
        if(strcmp(th[i].name,str)==0)
        {
            return i;
        }
    }
    return -1;
}

void DeleteOne(Thing th[],int *top,int n)  //删除Thing数组里面下标为n的元素
{
    for (int i=n;i<*top-1;i++) 
    {
        th[i].id=th[i+1].id;
        strcpy(th[i].name,th[i+1].name);
        th[i].cate=th[i+1].cate;
        th[i].brand=th[i+1].brand;
        th[i].price=th[i+1].price;
        th[i].num=th[i+1].num;
    }
    (*top)--;    //商品个数-1
}

void changeTowThing(Thing *t1,Thing *t2)  //交换两个商品的位置
{
    int temp=t1->id;
    t1->id=t2->id;
    t2->id=temp;

    char temp_name[20];
    strcpy(temp_name, t1->name);
    strcpy(t1->name, t2->name);
    strcpy(t2->name, temp_name);
    
    Category c;
    c=t1->cate;
    t1->cate=t2->cate;
    t2->cate=c;
    
    Brand b;
    b=t1->brand;
    t1->brand=t2->brand;
    t2->brand=b;

    temp=t1->num;
    t1->num=t2->num;
    t2->num=temp;

    float f;
    f=t1->price;
    t1->price=t2->price;
    t2->price=f;
}

const char* LeiBie(Category c) //枚举类别转字符
{
    switch(c)
    {
    case pen:return"笔";break;
    case book:return"本";break;
    case paint:return"颜料";break;
    case otherc:return"其他";break;
    default:return"未知";
    }
}

const char* PingPai(Brand b) //枚举品牌转字符
{
    switch (b)
    {
    case chenguang:return"晨光";break;
    case deli:return"得力";break;
    case banma:return"斑马";break;
    case baile:return"百乐";break;
    case otherb:return"其他";break;
    default:return"未知";
    }
}

void readThing(FILE *fp,Thing th[],int *top) //把仓库文件的商品导出到Thing数组
{
    fp=fopen("store.txt","r"); 
    Thing *t=th;
    while(readOneThing(t,fp))
    {
        (*top)++;
        t++;
    }
    fclose(fp);
}

void writeThing(FILE *fp,Thing th[],int top) //把数组重新写回去
{
    fp=fopen("store.txt","w"); 
    for (int i=0;i<top;i++)
    {   
        fprintf(fp,"%d\t  %-14s\t%d\t%d\t%-14.2f\t%d\n",th[i].id,th[i].name,(int)th[i].cate,(int)th[i].brand,th[i].price,th[i].num);
    }
    fclose(fp);
}

void show(int top,Thing th[])//统一展示
{
    if(top!=0)
    {
        printf("当前商品信息如下：\n"
            "-------------------------------------------------------------------------------------\n"
            "|  序号 |    商品编号   |    商品名称   | 商品类别 | 商品品牌 | 商品单价 | 商品库存 |\n"
            "-------------------------------------------------------------------------------------\n");
        for(int i=0;i<top;i++)
        {
        printf("| %d\t| %d\t\t| %-14s| %s \t   | %s     | %.2f\t | %d\t    |\n",i+1,th[i].id,th[i].name,LeiBie(th[i].cate),PingPai(th[i].brand),th[i].price,th[i].num);
        }
        printf("-------------------------------------------------------------------------------------\n");
    }
    else
    {
        printf("\t* 当前仓库无商品 *\n");
    }
}

void function1(FILE *fp)         //文件批量录入.把仓库导入。批量一条一条筛选有无id重复 无则存 有则跳过（覆盖）
{
    printf("\n您已选择 [1]批量录入初始商品信息\n请输入要录入的文件名：");
    
    char filename[100];//用户输入要导入的文件名
    scanf("%99s",filename);
    
    if(strcmp(filename,"store.txt")==0)//输入仓库文件store.txt就退出返回菜单
    {
        printf("\n\t* 不可以选择仓库文件store.txt！即将返回菜单... *\n");
        system("pause");
        system("cls");
        return;
    }
    
    fp=fopen("store.txt","r"); //把仓库文件的商品导出到Thing数组
    Thing th[1000];
    Thing *t=th;
    int top=0; //商品的个数
    while(readOneThing(t,fp))
    {
        top++;
        t++;//指向下一个数组位置的指针
    }
    fclose(fp);

    FILE *fptemp=fopen(filename,"r");
    if(fptemp==NULL)                                                         
    {
        printf("\n\t* 未找到该文件:( ,请重试 *\n");
        system("pause");
        return;
    }
    
    int n=0; //新导入商品的个数
    printf("\n\t* 正在从文件 %s 导入商品信息... *\n",filename);
    while(readOneThing(t,fptemp))
    {
        if(findSameID(th,top,t->id)!=-1)
        {
            printf("商品编号 %d 已存在，跳过该商品。\n",t->id);
        }
        else
        {
            n++;
            top++;
            if(top==1000)
            {
                printf("已达到库存最大商品种类1000种，停止导入。\n");
                break; 
            }
            t++;   
        }
    }
    fclose(fptemp);
    writeThing(fp,th,top);
    printf("\n\t* %d条商品信息录入完成，即将返回菜单... *\n",n);
    system("pause");
}

void function2(FILE *f)     //先读到数组依次输出
{
    printf("您已选择 [2]浏览全部商品信息\n");
    Thing th[1000];int top=0;
    readThing(f,th,&top);
    
    show(top,th);

    system("pause");
}

void function3(FILE *f)  //先选择查询方式 然后循环有对应的就输出
{
    f=fopen("store.txt","r");
    Thing th[1000];int top=0;
    readThing(f,th,&top);


    printf("您已选择 [3]查询商品信息\n");
    menu3();
    int temp;
    while(1)
    {
        printf("请输入您的选择：");
        int sc=scanf("%d",&temp);
        if(sc!=1)
        {
            getchar();
            printf("\n\t* 输入有误，请重新输入1~4中的一个整数。*\n");  
        }
        else
        {
            if(temp!=1&&temp!=2&&temp!=3&&temp!=4)
            {
                printf("\n\t* 输入有误，请重新输入1~4中的一个整数。*\n");
            }
            else{break;}
        }
    };

    if(temp==1)
    {
        int id;
        while(1)
        {
            printf("请输入商品编号：");
            int sc=scanf("%d",&id);
            if(sc!=1)
            {
                getchar();
                printf("\n\t* 输入有误，请重新输入一个整数。*\n");          
            }
            else{break;}
        }
        
        int temp1=findSameID(th,top,id);
        if(temp1==-1)
        {
            printf("\n\t* 未找到符合条件的商品，即将返回菜单... *\n");
            system("pause");
        }
        else
        {
            thingShow(th[temp1]);
            printf("即将返回菜单...\n");
        }
    }
    else if(temp==2)
    {
        char name[20];
        printf("请输入商品名称：");
        int sc=scanf("%19s",&name);

        int temp2=findSameName(th,top,name);
        if(temp2==-1)
        {
            printf("\n\t* 未找到符合条件的商品，即将返回菜单 *\n");
        }
        else
        {
            for(int i=0;i<top;i++)
            {
                if(strcmp(th[i].name,name)==0)
                {
                    thingShow(th[i]);
                }
            }
            printf("即将返回菜单...\n");
        }
    }
    else if(temp==3)
    {
        int temp3,n=0;
        printf("请输入商品品牌(1.晨光 2.得力 3.斑马 4.百乐 5.其他)：");
        while(1)
        {
            int sc=scanf("%d",&temp3);
            if(sc!=1)
            {
                getchar();
                printf("\n\t* 输入有误，请重新输入1~5中的一个整数。*\n"); 
            }
            else
            {
                if(temp3!=5&&temp3!=1&&temp3!=2&&temp3!=3&&temp3!=4)
                {
                    printf("\n\t* 输入有误，请重新输入1~5中的一个整数。*\n");
                }
                else{break;}
            }
        };//检查有没有输入错误
        
        for(int i=0;i<top;i++)
        {
            if(th[i].brand==temp3)
            {
                thingShow(th[i]);
                n++;
            }
        }
        printf("以上为搜索到的%d条商品信息\n即将返回首页...\n",n);
    }
    else if(temp==4)
    {
        int temp4,n=0;
        printf("请输入商品品牌(1.笔 2.本 3.颜料 4.其他)：");
        while(1)
        {
            int sc=scanf("%d",&temp4);
            if(sc!=1)
            {
                getchar();
                printf("\n\t* 输入有误，请重新输入1~4中的一个整数。*\n");                      
            }
            else
            {
                if(temp4!=4&&temp4!=1&&temp4!=2&&temp4!=3)
                {
                    printf("\n\t* 输入有误，请重新输入1~4中的一个整数。*\n");
                }
                else{break;}
            }
        };//检查有没有输入错误
        
        for(int i=0;i<top;i++)
        {
            if(th[i].cate==temp4)
            {
                thingShow(th[i]);
                n++;
            }
        }
        printf("以上为搜索到的%d条商品信息\n即将返回首页...\n",n);        
    }
    system("pause");
}

void function4(FILE *f)
{
    printf("您已选择 [4]增加商品信息\n");
    Thing th[1000];int top=0;
    readThing(f,th,&top);

    if(top==1000)
    {
        printf("仓库已满！不能再录入\n");
        system("pause");
        return;
    }
    
    printf("请输入商品编号：");
    while(1)
    {
        int sc=scanf("%d",&th[top].id);
        if(sc!=1)
        {
            getchar();
            printf("输入有误，请重新输入一个整数:");
        }
        else{break;}
    }
    
    if(findSameID(th,top,th[top].id)!=-1)
    {
        printf("此商品编号已存在，未能成功录入。\n即将返回菜单...\n");
        system("pause");
        return;
    }

    printf("请输入商品名称：");
    scanf("%19s",&th[top].name);
    printf("请输入商品类别(1.笔 2.本 3.颜料 4.其他)：");
    while(1)
    {
        int sc=scanf("%d",&th[top].cate);
        if(sc!=1)
        {
            getchar();
            printf("输入有误，请重新输入1~4中的一个整数:\n");                
        }
        else
        {
            if(th[top].cate!=1&&th[top].cate!=2&&th[top].cate!=3&&th[top].cate!=4)
            {
                printf("输入有误，请重新输入1~4中的一个整数:\n");
            }
            else{break;}
        }
    };
    printf("请输入商品品牌(1.晨光 2.得力 3.斑马 4.百乐 5.其他)：");
    while(1)
    {
        int sc=scanf("%d",&th[top].brand);
        if(sc!=1)
        {
            getchar();
            printf("输入有误，请重新输入1~5中的一个整数:\n");                
        }
        else
        {
            if(th[top].brand!=1&&th[top].brand!=2&&th[top].brand!=3&&th[top].brand!=4&&th[top].brand!=5)
            {
                printf("输入有误，请重新输入1~5中的一个整数:\n");
            }
            else{break;}
        }
    };
    printf("请输入商品单价：");
    while(1)
    {
        int sc=scanf("%f",&th[top].price);
        if(sc!=1)
        {
            getchar();
            printf("请重新输入一个数字：");
        }
        else{break;}
    }
    printf("请输入商品库存：");
    while(1)
    {
        int sc=scanf("%d",&th[top].num);
        if(sc!=1)
        {
            getchar();
            printf("请重新输入一个整数：");
        }
        else{break;}
    }
    
    f=fopen("store.txt","a");
    fprintf(f,"%d %19s %d %d %f %d\n",th[top].id,th[top].name,(int)th[top].cate,(int)th[top].brand,th[top].price,th[top].num);
    fclose(f);

    printf("已成功添加一条商品信息到仓库！即将返回菜单...\n");
    system("pause");    
}

void function5(FILE *f)
{
    printf("您已选择 [5]删除商品信息\n");
    Thing th[1000];int top=0;
    readThing(f,th,&top);


    printf("请选择删除方式：\n"
           "1.按商品编号删除\n2.按商品名称删除\n输入你的选择：");
    int temp;
    char ch;//接收Y/N
    while(1)
    {
        int sc=scanf("%d",&temp);
        getchar();//吸收回车
        if(sc!=1)
        {
            printf("请重新输入1/2：");
        }
        else
        {
            if(temp!=1&&temp!=2)
            {
                printf("请重新输入1/2：");
            }
            else break;
        }
    }

    if(temp==1)
    {
        int id;
        printf("请输入要删除的商品编号：");
        while(1)
        {
            int sc=scanf("%d",&id); 
            getchar();//吸收回车
            if(sc!=1)
            {
                printf("请重新输入一个整数：");
            }
            else{break;}
        }
        
        int i=findSameID(th,top,id);
        if(i==-1)
        {
            printf("未找到相应编号,即将返回菜单。\n");
        }
        else
        {
            thingShow(th[i]);
            printf("确认要删除该商品吗？(Y/N):");
            while(ch=getchar())
            {
                getchar();//吸收回车
                if(ch=='Y')
                {
                    DeleteOne(th,&top,i);
                    printf("商品编号%d的商品已成功删除。\n即将返回菜单...\n",id);
                    break;
                }
                else if(ch=='N')
                {
                    printf("取消删除，即将返回菜单。\n");
                    break;
                }
                else
                {
                    printf("请重新输入Y或N:");
                }
            }
        }
    }
    else if(temp==2)
    {
        printf("请输入要删除的商品名称：");
        char name[20];
        scanf("%19s",&name);
        getchar();//吸收回车
        int num=0,a[1000]={0};
        for(int i=0;i<top;i++)
        {
            if(strcmp(th[i].name,name)==0)
            {
                thingShow(th[i]);
                a[num]=i;
                num++;
            }
        }

        if(num==0)
        {
            printf("未找到对应商品\n即将返回菜单...\n");
        }
        else if(num==1)
        {
            printf("确认要删除该商品吗？(Y/N):");
            while(ch=getchar())
            {
                getchar();//吸收回车
                if(ch=='Y')
                {
                    DeleteOne(th,&top,a[0]);
                    printf("%s已成功删除。\n即将返回菜单...\n",name);
                    break;
                }
                else if(ch=='N')
                {
                    printf("取消删除，即将返回菜单。\n");
                    break;
                }
                else
                {
                    printf("请重新输入Y或N:");
                }
            }
        }
        else
        {
            printf("找到多条同名商品，将同时删除。\n");
            printf("确认要删除这些商品吗？(Y/N):");
            
            while(ch=getchar())
            {
                getchar();//吸收回车
                if(ch=='Y')
                {
                    for(int i=num-1;i>=0;i--)
                    {
                        DeleteOne(th,&top,a[i]);
                    }
                    printf("以上已成功删除。\n即将返回菜单...\n");
                    break;
                }
                else if(ch=='N')
                {
                    printf("取消删除，即将返回菜单。\n");
                    break;
                }
                else
                {
                    printf("请重新输入Y或N:");
                }
            }
        }
    }
    writeThing(f,th,top);
    system("pause");
}

void function6(FILE *f)
{
    printf("您已选择 [6]修改商品信息\n\n");
    Thing th[1000];int top=0;
    readThing(f,th,&top);    

    int id;
    printf("请输入要修改的商品编号：");
    while(1)
    {
        int sc=scanf("%d",&id);
        if(sc!=1)
        {
            printf("请重新输入一个整数：");
        }
        else{break;}
    }
    
    int i=findSameID(th,top,id);
    if(i==-1)
    {
        printf("未找到相应编号,即将返回菜单。\n");
    }
    else
    {
        thingShow(th[i]);
        printf("\n请选择要修改的信息:\n\n\t1.商品名称\n\t2.商品类别\n\t3.商品品牌\n\t4.商品单价\n\t5.商品库存\n\n请输入选择：");
        int c;
        scanf("%d",&c);
        if(c==1)
        {
            printf("请输入新的商品名称：");
            scanf("%19s",&th[i].name);
            printf("商品名称已修改为%s\n",th[i].name);
        }
        else if(c==2)
        {
            printf("请输入新的商品类别(1.笔 2.本 3.颜料 4.其他)：");
            scanf("%d",&th[i].cate);
            printf("商品类别已修改为%s\n",LeiBie(th[i].cate));
        }
        else if(c==3)
        {
            printf("请输入新的商品品牌(1.晨光 2.得力 3.斑马 4.百乐 5.其他)：");
            scanf("%d",&th[i].brand);
            printf("商品品牌已修改为%s\n",PingPai(th[i].brand));
        }
        else if(c==4)
        {
            printf("请输入新的商品单价：");
            scanf("%f",&th[i].price);
            printf("商品单价已修改为%.2f\n",th[i].price);
        }
        else if(c==5)
        {
            printf("请输入新的商品库存：");
            scanf("%d",&th[i].num);
            printf("商品库存已修改为%d\n",th[i].num);
        }
    }
    writeThing(f,th,top); 
    system("pause");
}

void function7(FILE *f)
{
    printf("您已选择 [7]按类别统计商品数量\n\n");
    Thing th[1000];int top=0;
    readThing(f,th,&top);

    printf("请选择要统计的商品类别：\n1.笔\n2.本\n3.颜料\n4.其他\n请输入类别编号（1-4）：");
    int cate;
    while(1)
    {
        int sc=scanf("%d",&cate);
        if(sc!=1)
        {
            getchar();
            printf("请重新输入一个1~4的整数：");
        }
        else
        {
            if(cate!=1&&cate!=2&&cate!=3&&cate!=4)
            {
                printf("请重新输入一个1~4的整数：");
            }
            else{break;}
        }
    }

    int num=0;
    for(int i=0;i<top;i++)
    {
        if(th[i].cate==cate)
        {
            num++;
        }
    }

    if(num==0)
    {
        printf("未找到该类别的商品信息\n即将返回菜单...\n");
    }
    else
    {
        printf("商品类别'%s'中共有%d个商品\n",LeiBie((Category)cate),num);
    }

    system("pause");
}

void function8(FILE *f)
{
    printf("您已选择 [8]按单价对商品排序\n\n请选择排序方式\n1.按价格升序排序\n2.按价格降序排序\n请输入选项（1/2）：");
    Thing th[1000];int top=0;
    readThing(f,th,&top);
    
    int temp;
    while(1)
    {
        int sc=scanf("%d",&temp);
        if(sc!=1)
        {
            getchar();
            printf("请重新输入1/2：");
        }
        else
        {
            if(temp!=1&&temp!=2)
            {
                printf("请重新输入1/2：");
            }
            else{break;}
        }
    }

    if(temp==1)  //冒泡
    {
        for(int i=0;i<top-1;i++)
        {
            for(int j=0;j<top-i-1;j++)
            {
                if(th[j].price>th[j+1].price)
                {
                    changeTowThing(&th[j],&th[j+1]);
                }
            }
        }   
    }
    else if(temp==2)
    {
        for(int i=0;i<top-1;i++)
        {
            for(int j=0;j<top-i-1;j++)
            {
                if(th[j].price<th[j+1].price)
                {
                    changeTowThing(&th[j],&th[j+1]);
                }
            }
        }   
    }
    show(top,th);
    system("pause");
}

void function9(FILE *f)
{
    printf("您已选择 [9]计算当前库存商品的总价值\n\n");
    Thing th[1000];int top=0;
    readThing(f,th,&top);

    float sum=0.0;
    for(int i=0;i<top;i++)
    {
        sum+=(th[i].price*th[i].num);
    }

    printf("\t* 当前商品的总价值为：%.2f *\n\n",sum);
    system("pause");
}