//
//  Header.h
//  Gale-Shapley Algorithm
//
//  Created by Saurabh Savara on 8/25/20.
//  Copyright © 2020 Saurabh Savara. All rights reserved.
//

#ifndef GaleShapley_h
#define GaleShapley_h
#include <iostream>
#include <fstream>
# include <queue>
#include <string>
#include <vector>

using namespace std;

//Linked list node
struct node
{
    int data;
    node *next;
};
//Woman object for all women , preferences are stored in array

class Woman{

private:
    int* preference;
    int size;

public:

   Woman(int preferences[],int size)
    {
        preference=new int[size];
        for(int i=0;i<size;i++)
        {
            preference[i]=preferences[i];
        }
        this->size=size;
    }
    ~Woman()
    {
        
    }
    int* getpreference()
    {
        return preference;
    }
    int getsize()
    {
        return size;
        
    }
};
//Man object for all men, preferences are stored in a linked list
class Man
{
private:
    

public:
    node *head,*tail;
    
    Man()
    {
        head=NULL;
        tail=NULL;
    }
    void addNode(int data)
    {
        node *temp=new node;
            temp->data=data;
            temp->next=NULL;
            if(head==NULL)
            {
                head=temp;
                tail=temp;
                temp=NULL;
            }
            else
            {
                tail->next=temp;
                tail=temp;
            }
        }
    void display()
    {
        //node *temp=new node;
       node  *temp=this->head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"\t";
            temp=temp->next;
        }
    }
    void delete_position(int pos)
    {
        node *current=new node;
        node *previous=new node;
        current=head;
        for(int i=1;i<pos;i++)
        {
            previous=current;
            current=current->next;
        }
        previous->next=current->next;
    }
    void delete_first()
    {
        node *temp=new node;
        temp=head;
        head=head->next;
        delete temp;
    }
    int GetNth(node* head, int index)
    {
        
        node* current = head;
        int count = 0;
        int datap;
        while (current != NULL)
        {
            if (count == index)
            {
                datap=current->data;
                return datap;
            }
            else{
            count++;
            current = current->next;
            }
        }
        assert(0);
    }
};

//function definations

vector<Man> readManfile(string filename);
vector<Woman> readWomanfile(string filename);
vector<pair<int,int>> matchmaking(vector<Man> listofmen,vector<Woman> listofwomen,string filename);
vector<pair<int,int>> readCheckfile(string filename);
int checkStability(string filename);
int rankwoman(vector<Man> listofmen,int woman,int man);
int rankmen(vector<Woman> listofwomen,int woman,int man);
bool checkpartners(vector<Woman> listofwomen,vector<Man> listofmen,vector<pair<int,int>> checklist);


//global variables
extern vector<Man> availableMen;
extern vector<Woman> availableWoman;
extern vector<pair<int,int>> matches;
extern int num;

#endif /* Header_h */
