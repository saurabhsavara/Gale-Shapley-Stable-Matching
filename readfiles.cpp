//
//  readfiles.cpp
//  Gale-Shapley Algorithm
//
//  Created by Saurabh Savara on 8/25/20.
//  Copyright © 2020 Saurabh Savara. All rights reserved.
//

#include "GaleShapley.h"
vector<Man> availableMen;
vector<Woman> availableWoman;
vector<Man> readManfile(string filename)
{
    ifstream inFile;
    
    Man x;
    availableMen.push_back(x);//add one dummy object since we want to start at postion 1 
    
    inFile.open(filename); //filename
    if(inFile.is_open())
    {
        inFile>>num;  //number of men
       
        for(int i=1;i<=num;i++) //create objects based on number of men
        {
            Man temp;
            int data=0;
            
            //Assign values to nodes, link nodes, add man object to list of men
           
            for(int j=1;j<=num;j++)
            {
                inFile>>data;
                temp.addNode(data);
            }
            //Add all men to a queue
           availableMen.push_back(temp);
}
        inFile.close();
    }
    return availableMen;
}

vector<Woman> readWomanfile(string filename)
{
    
    int women=0;
    ifstream inFile;
   
    int x1[]={0};
    Woman x(x1,0);
    availableWoman.push_back(x);
    
    inFile.open(filename);
    if(inFile.is_open())
    {
        inFile>>women;  //number of women
        //push 1 NULL object to list since we want to start at postion 1
        
        for( int i=0;i<women;i++)
        {
            int data[women];
            
            for (int j=0;j<women;j++)
            {
                
                inFile>>data[j];
                
            }
            //Add women objects to vector 
            Woman temp=Woman(data,women);
            
            //Add all women to queue 
            availableWoman.push_back(temp);
        }
      inFile.close();
    }
    
    return availableWoman;
    
}
vector<pair<int,int>> readCheckfile(string filename)
{
   vector <pair<int,int>> checkfile;
    ifstream inFile;
    inFile.open(filename);
     if(inFile.is_open())
     {
         int m,w;
         while(inFile.peek()!=EOF)
         {
             inFile>>m;
             inFile>>w;
             checkfile.push_back(make_pair(m,w));
         }
         inFile.close();
     }
          return checkfile;
}

