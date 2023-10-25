#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
int main(int argc, char* argv[]) {
    string pageTableFile = argv[1];
    string tlbAccessesFile = argv[2];
    string tlbReplacementPolicy = argv[3];
    int tlbSize = atoi(argv[4]);
    string tlbSize1 = (argv[4]);
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

            vpn[stoi(vpnvalues)]=i;
           

        }
        if(cvpn>4 and cvpn%2==0){

            pfn[i]=stoi(vpnvalues);
            i++;
           

        }
       
    }
    int tlbaccessvalues;
    int z=0;
    int pageoffset;
    while(tlbfile>>tlbaccessvalues){
        z++;
        if(z==1){
            pageoffset=tlbaccessvalues;

        }
        if(z>1){
            tlbaccess.push_back(tlbaccessvalues);

        }

    }
    int totalaccess=0;
    int totalhits=0;
    int totalmiss=0;
    vector<pair<int,int>>mytlb;
   int pageoffsetvalue;
    vector<pair<int,string>>output;
    for(int i=0;i<tlbaccess.size();i++){
        int x=(tlbaccess[i]>>pageoffset);
        int w=0;
        int u;
     pageoffsetvalue = tlbaccess[i] % static_cast<int>(pow(2, pageoffset));


        for(int j=0;j<mytlb.size();j++){
            if(mytlb[j].first==x){
                w++;
                u=j;

                break;
            }

        }
        totalaccess++;
        if(w==1){
            totalhits++;
            int physicaladdress1=(mytlb[u].second)*pow(2,pageoffset)+pageoffsetvalue;
            pair<int,string>p;
            p.first=physicaladdress1;
            p.second="hit";
            output.push_back(p);
            pair<int,int>p1=mytlb[u];
            for(int j=u+1;j<mytlb.size();j++){
                mytlb[j-1]=mytlb[j];
            }
            mytlb[mytlb.size()-1]=p1;
        }
        if(w==0){
            totalmiss++;
            if(mytlb.size()< tlbSize){
                pair<int,int>p3;
                p3.first=x;
                p3.second=pfn[vpn[x]];
                mytlb.push_back(p3);
                int physicaladdress3=(pfn[vpn[x]])*pow(2,pageoffset)+pageoffsetvalue;
                pair<int,string>p6;
                p6.first=physicaladdress3;
                p6.second="miss";
                output.push_back(p6);

            }
            else{
                for(int j=1;j<mytlb.size();j++){
                     mytlb[j-1]=mytlb[j];

                }
                pair<int,int>p4;
                p4.first=x;
                p4.second=pfn[vpn[x]];

                mytlb[mytlb.size()-1]=p4;
                int physicaladdress2=(pfn[vpn[x]])*pow(2,pageoffset)+pageoffsetvalue;
                pair<int,string>p5;
                p5.first=physicaladdress2;
                p5.second="miss";
                output.push_back(p5);

            }
        }

        
    }
    
     
      fstream file; 
      string outputfilename="22112033_"+pageTableFile+"_"+tlbAccessesFile+"_LRU_"+tlbSize1;
      
       file.open(outputfilename,ios::out);
       file << "TOTAL_ACCESSES = " << totalaccess << endl;
       file << "TOTAL_MISSES = " << totalmiss << endl;
       file << "TOTAL_HITS = " << totalhits << endl;

        for (int i = 0; i < output.size(); i++) {
            file << output[i].first << " " << output[i].second << endl;
        }

        file.close();
    


    
   


   return 0;


}
    
   
       
      

    

   

    
