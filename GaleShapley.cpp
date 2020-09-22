//
//  GaleShapley.cpp
//  Gale-Shapley Algorithm
//
//  Created by Saurabh Savara on 8/26/20.
//  Copyright © 2020 Saurabh Savara. All rights reserved.
//

#include <stdio.h>
#include "GaleShapley.h"

vector<pair<int,int>> matches;
int num;

vector<pair<int,int>> matchmaking(vector<Man> listofmen,vector<Woman> listofwomen,string filename)
{
    //queue for free single men
    queue<int> freeMen;
    //reducing the size variable since we had one null object at the start
    //listofwomen and listofmen have the same size
    num=(int)listofwomen.size()-1;
    //men ranking
    int ranking[num+1][num+1];
    int next[num+1];
    int current[num+1];
    
    for(int i = 1;i <= num;++i)
    {
       int *temp=listofwomen[i].getpreference();
        for(int j = 1;j <=num;++j)
        {
            //[temp[j-1]] is also the mens preference list 
            ranking[i][temp[j-1]]=j;
        }
    }
    for(int i = 1;i <= num;++i)
    {
        freeMen.push(i);
        next[i] = 1;
    }
    //fill in "current" array with  with 0
    
    memset(current,0,sizeof current);
    
    while(!freeMen.empty())
    {
        //below are assigning my current man 'm' and current woman 'w'
        int m = freeMen.front();
        int a=next[m]++;
        //listofmen[m].GetNth(listofmen[m].head,a-1) also is the women preference list
        int w=listofmen[m].GetNth(listofmen[m].head,a-1);
        if(current[w] == 0 )
        {
            current[w] = m;
            freeMen.pop();
        }
        else if(ranking[w][m] < ranking[w][current[w]])
        {
            freeMen.pop();
            freeMen.push(current[w]);
            current[w] = m;
        }
    }
    //print the matching to the console and fill in the matching to a vector pair
    ofstream myfile;
    if(filename!="")
    {
        myfile.open(filename);
        for (int i = 1; i<= num; i++)
        {
            myfile<<" "<<current[i] <<" "<< i<<"\n";
            
        }
        myfile.close();
    }
    
    for (int i = 1; i<= num; i++)
    {
        cout<<" "<<current[i] <<" "<< i<<endl;
        matches.push_back(make_pair(current[i], i));
        
    }
    return matches;
}

//read the "unstable" or file to check the matchings in

int checkStability(string filename)
{
    //Create a couples pair for the matches in the unstable file
    vector<pair<int,int>> checkfile=readCheckfile(filename);
    bool flag=true;
    int counter=0;
    //checking to see if the provided file is actually containing new pairs  or just a jumbled up version of the Gale Shapley output
    
    for(int i=0;i<(int)checkfile.size();i++)
    {
        int temp1=checkfile[i].first;
        int temp2=checkfile[i].second;
        counter =0;
        while(flag)
        {
            if(matches[counter].first==temp1 && matches[counter].second==temp2)
            {
                flag=true;
                break;
            }
            else if(counter<checkfile.size())
            {
                counter++;
            }
            else
                flag =false;
        }
        
    }
    
    //if some pairs are not correct in the provided file, we can find ONE counter example to another pair that might be better
    if(flag==false)
    {
        cout<<"File provided doesnt seem stable"<<endl;
        checkpartners(availableWoman, availableMen, checkfile);
    }
    //check if provided file is missing any pairs and reports error and halts program
    else if(checkfile.size()!=matches.size())
    {
        cout<<"File provided has too few matches"<<endl;
        return 0;
    }
    
    
    return 0;
}

//Check rankings of current partners with other available partners and provide 1 example of a pair that could be better .

bool checkpartners(vector<Woman> listofwomen,vector<Man> listofmen,vector<pair<int,int>> checklist)
{
    bool flag=true;
    for(int i=1;i<=num;i++)
    {
        int m=checklist[i].first;
        int w=checklist[i].second;
        for(int j=1;j<=num;j++)
        {
            cout<<"came here"<<endl;
            if(rankwoman(listofmen,w,j)>rankwoman(listofmen,w,m)&&flag==true)
            {
                cout<<"came here too"<<endl;
                if(rankmen(listofwomen,j,m)>rankmen(listofwomen,w,m) && flag ==true)
                {
                    cout<<"Woman "<<w<<"seems to have better compatibility with man "<<j<<endl;
                    flag=false;
                    return false;
                    
                }
            }
        }
    }
return false;
}



//get womans rank in the mans list
int rankwoman(vector<Man> listofmen,int woman,int man)
{
    int rank=-1;
    for(int j=1;j<=num;j++)
    {
        if(listofmen[man].GetNth(listofmen[man].head, j-1)==woman)
        {
            rank=j;
        }
    }
    return rank;
}

//get mans ranking in womens list
int rankmen(vector<Woman> listofwomen,int woman,int man)
{
    int rank=-1;
    int *temp=listofwomen[woman].getpreference();
    for(int i=1;i<=num;++i)
    {
        if(temp[i]==man)
        {
            rank=i;
        }
    }
    return rank;
}

