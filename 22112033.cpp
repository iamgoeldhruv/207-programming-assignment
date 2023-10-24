#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
int main(int argc, char* argv[]) {
    string pageTableFile = argv[1];
    string tlbAccessesFile = argv[2];
    string tlbReplacementPolicy = argv[3];
    int tlbSize = atoi(argv[4]);
    ifstream pgtfile(pageTableFile);
    ifstream tlbfile(tlbAccessesFile);
    vector<long long int>vpn;
    vector<long long int>pfn;
    


    
  
    return 0;

}
    
   
       
      

    

   

    
