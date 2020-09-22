//
//  main.cpp
//  Gale-Shapley Algorithm
//
//  Created by Saurabh Savara on 8/24/20.
//  Copyright © 2020 Saurabh Savara. All rights reserved.
//

#include <iostream>
#include "GaleShapley.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    if(argc<5 || argc>5)
    {
        cout<<"Invalid number of parameters"<<endl;
        cout<<"Try Running *programname* %find/stable% %men file% %women file% %output/doubtful file%"<<endl;
        return 0;
    }
    else
    {
    string command(argv[1]);
    string manfile(argv[2]);
    string womanfile(argv[3]);
    string thirdfile(argv[4]);
        
        if(string(argv[1])==string("find"))
        {
        vector<Man> list1=readManfile("/Users/savara/Documents/man.txt");
        vector<Woman> list2=readWomanfile("/Users/savara/Documents/woman.txt");
        matchmaking(list1, list2,thirdfile);
        }
        else if(string(argv[1])==string("stable"))
        {
            vector<Man> list1=readManfile("/Users/savara/Documents/man.txt");
            vector<Woman> list2=readWomanfile("/Users/savara/Documents/woman.txt");
            matchmaking(list1, list2,"");
            checkStability("/Users/savara/Documents/unstable.txt");
        }
       // return availableMen;
    return 0;
}
    

}
