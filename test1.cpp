#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <time.h>       /* time */
using namespace std;
int louda,fin,maxSize1=2,maxSize2=2;
void err1()
{
    system("cls");
    cout<<"Champion invalid\n";
    system("pause");
}
/*void pickRandomChampion(string role)
{

} WIP */
void supPick()
{
    system("cls");
    string arr[3];
    ifstream str;
    string champ1,champ2;
    cout<<"champ: ";
    cin>>champ1;
    str.open("adcComp.txt");
    while(champ1!=champ2) //searching for adc
    {
        str>>champ2;
        if(champ2 == "!") //adc not found
            err1();
    }
    str>>champ2; //skipping the opening bracket
    for(int x=0;x<3;x++)
    {
        str>>champ2;
        arr[x]=champ2;
    }
    fin = rand() % 2; //picks 1 random of the 3 best (rand() % 2 returns either 0, 1, or 2)
    cout<<arr[fin]<<" is good with "<<champ1<<".\n";
    system("pause");
}
void adcPick()
{
    system("cls");
    string arr[3];
    ifstream str;
    string champ1,champ2;
    cout<<"champ: ";
    cin>>champ1;
    str.open("supComp.txt");
    while(champ1!=champ2) //searching for supp
    {
        str>>champ2;
        if(champ2 == "!") //supp not found
            err1();
    }
    str>>champ2; //skipping the opening bracket
    for(int x=0;x<3;x++)
    {
        str>>champ2;
        arr[x]=champ2;
    }
    fin = rand() % 2; //picks 1 random of the 3 best
    cout<<arr[fin]<<" is good with "<<champ1<<".\n";
    system("pause");
}
void botPick()
{
    system("cls");
    string arr1[maxSize1],arr2[maxSize2];
    int pickIndex=0;
    ifstream str1,str2;
    string champ1="",champ2;
    str1.open("adcComp.txt"); //picking random adc
    while(1)
    {
        str1>>champ2;//loads line 0(empty) and 1, then 1 and 2, 2 and 3...
        if(champ2=="{") //if the latter line has "{", it means the line above it has an adc
            {
                arr1[pickIndex]=champ1; //throw the adc into the array
                pickIndex++;
            }
        if(champ2=="!" || pickIndex>maxSize1)
            break;
        champ1=champ2;
    } //replace this while loop with void pickRandom(param) later
    str1.close();
    fin = rand() % maxSize1; //picks between 0 and maxSize1
    cout<<arr1[fin]<<" ";

    champ1="";
    champ2="";
    pickIndex=0; //resets champ1, champ2 and pickIndex

    str2.open("supComp.txt"); //picking random sup
    while(1)
    {
        str2>>champ2;//loads line 0(empty) and 1, then 1 and 2, 2 and 3...
        if(champ2=="{") //if the latter line has "{", it means the line above it has a sup
            {
                arr2[pickIndex]=champ1; //throw the sup into the array
                pickIndex++;
            }
        if(champ2=="!" || pickIndex>maxSize2)
            break;
        champ1=champ2;
    } //replace this while loop with void pickRandom(param) later
    str2.close();
    fin = rand() % maxSize2; //picks between 0 and maxSize2
    cout<<arr2[fin]<<" botlane\n";
    system("pause");
}
void mainMenu()
{
    system("cls");
    cout<<"1 to pick a support\n2 to pick a botlaner\n3 to pick both\n4 to exit"<<endl;
    int pick;
    cin>>pick;
    switch(pick)
    {
    case 1:
        supPick();
        break;
    case 2:
        adcPick();
        break;
    case 3:
        botPick();
        break;
    case 4:
        return;
    default:
        mainMenu();
    }
}
int main()
{
    srand (time(NULL));
    mainMenu();
}
