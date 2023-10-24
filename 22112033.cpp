#include<iostream>
#include<fstream>
#include<vector>
#include<map>
using namespace std;
int main(int argc, char* argv[]) {
    string pageTableFile = argv[1];
    string tlbAccessesFile = argv[2];
    string tlbReplacementPolicy = argv[3];
    int tlbSize = atoi(argv[4]);
    ifstream pgtfile(pageTableFile);
    ifstream tlbfile(tlbAccessesFile);
    map<int,int>vpn;
    map<int,int>pfn;
    vector<int>tlbaccess;
   
    string vpnvalues;
    int cvpn=0;
    int i=1;
    while(pgtfile>>vpnvalues){
        cvpn++;
        if(cvpn>4 and cvpn%2!=0){

            vpn[i]=stoi(vpnvalues);
           

        }
        if(cvpn>4 and cvpn%2==0){

            pfn[i]=stoi(vpnvalues);
            i++;
           

        }
       
    }
    int tlbaccessvalues;
    int z=0;
    while(tlbfile>>tlbaccessvalues){
        z++;
        if(z>1){
            tlbaccess.push_back(tlbaccessvalues);

        }

    }
     cout<<tlbaccess[1]<<endl;
    
    


 

  
    return 0;

}
    
   
       
      

    

   

    
