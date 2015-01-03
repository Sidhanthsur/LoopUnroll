#include<iostream>
#include<stdio.h>

#include<string.h>
#include<fstream>
using namespace std;

/*
 * INPUT FORMAT
 * Instrution_ID	Parent_Instruction	Loop_Type	Loop_Skip	Initial_Condition	Condition_type	Final_Value	Child
 * 
 * */


void unroll(string id, char pi[],int lt,string ls,int in,int co,int fi,int child)
{
	int i;
	switch(co)
	/*
	 * 1	->	<
	 * 2	->	<=
	 * 3	->	>
	 * 4	->	>=
	 * */
	{
		case 1:
		cout<<"\n unrolling loop with id :"<<id;
		for(i=0;i<fi;i++)
		{
			cout<<"\n"<<i<<": Instructions scheduling and executing ";
		}
		break;
		case 2:
		
		cout<<"\n unrolling loop with id :"<<id;
		for(i=0;i<=fi;i++)
		{
			cout<<"\n"<<i<<": Instructions scheduling and executing ";//i denotes the ith time instructions are being scheduled
		}
		break;
		case 3:
	
		cout<<"\n unrolling loop with id :"<<id;
		for(i=0;i>fi;i++)
		{
			cout<<"\n"<<i<<": Instructions scheduling and executing ";
		}
		break;
	}
}

void unrollchild(string nid, char npi[],int nlt,string nls,int nin,int nco,int nfi,int nchild)
{ int y=1;
	string id;
	 char pi[2];
	 int lt;
	 string ls;
	 int in,co,fi;
	 string lot;
int child;
	ifstream fc("input.txt");
	 while(y==1)
	 {
	 fc>>id;
	 fc>>pi;
	 fc>>lt;
	 fc>>ls>>in>>co>>fi>>child;
	 if(id == nid)
	 {
		  fc>>id;
	 fc>>pi;
	 fc>>lt;
	 fc>>ls>>in>>co>>fi>>child;
	 if(child > 0)
	 {
		 unrollchild(id,pi,lt,ls,in,co,fi,child);
	 }
	 else
	 unroll(id, pi,lt,ls,in,co,fi,child);
	 
	 unroll(nid, npi,nlt,nls,nin,nco,nfi,nchild);
	 y=0;
 }
}
fc.close();
}
	 
		 
	
	
		
	
			

int main()
{
	
	/*
	 * INITIALIZATION
	 **/
	 ifstream f1;
	 string id;
	 char pi[2];
	 int lt;
	 string ls;
	 int in,co,fi;
	 string lot;
int child;
	 
	 /*********************************************SECTION ENDS **********************************************/
	 
	 
	 
	 /*
	  * RREADING FROM THE INPUT FILE
	  * 
	  * */
	 f1.open("input.txt");
	 while(!f1.eof())
	 {
	 f1>>id;
	 f1>>pi;
	 f1>>lt;
	 f1>>ls>>in>>co>>fi>>child;
	 if(lt == 1)
	 lot="For";
	 else if(lt == 2)
	 lot="while";
	 else if(lt == 3)
	 lot="do-while";
	 else if(lt == 4)
	 lot ="if-else";
	 else
	 lot="no loop";	
	 //cout<<"\nID="<<id<<"\nParent instruction="<<pi<<"\nLoop type="<<lot<<"\nloop skip"<<ls<<"\nIntial value="<<in<<"\nConditional type="<<co<<"\nfinal value ="<<fi<<"\n child="<<child<<"\n\n";
 if((strcmp(pi,"o") == 0) && lt != 0 && child == 0)//if its a instruction that has no child
	 {
		unroll(id, pi,lt,ls,in,co,fi,child);
	 }
	 else if((strcmp(pi,"o") == 0) && lt >0 && child == 1)//instruction with a child
	  unrollchild(id,pi,lt,ls,in,co,fi,child);
	  else//instruction other than loop instructions
	  cout<<" ";
	 
		  
	 
 
 
}
f1.close();
 /*************************************************SECTION ENDS****************************************************/
	 f1.open("input.txt");
	 while(!f1.eof())
	 {
	 f1>>id;
	 f1>>pi;
	 f1>>lt;
	 f1>>ls>>in>>co>>fi>>child;
	 if(lt == 1)
	 lot="For";
	 else if(lt == 2)
	 lot="while";
	 else if(lt == 3)
	 lot="do-while";
	 else if(lt == 4)
	 lot ="if-else";
	 else
	 lot="no loop";	
	 
	 cout<<"\nID="<<id<<"\nParent instruction="<<pi<<"\nLoop type="<<lot<<"\nloop skip"<<ls<<"\nIntial value="<<in<<"\nConditional type="<<co<<"\nfinal value ="<<fi<<"\n child="<<child<<"\n\n"; 
 }

f1.close();
return 0;
}
