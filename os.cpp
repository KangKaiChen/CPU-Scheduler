// 10727102 康愷辰 10727128吳婕瑄 
#include<vector> 
#include <cstdlib>
#include<stdio.h>
#include<iostream>
#include<cmath>
#include <iomanip> // 取小數點位數 
#include <stdlib.h>
#include<string >
#include <string.h> // c_str
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
using namespace std;



struct data { //用來存發訊著運算式子 
	int slice =0 ;
	int id = 0 ;
	int CpuBurstTime = 0 ;
	int ArrivalTime = 0 ;
	int Priority = 0 ;
	int TurnArround = 0 ;
	int Waiting = 0 ;
    int Finish = 0 ;
    
    double HRR ;
    bool completed = false ;
    bool inq = false ;
    bool havedobefore = false ;
} ; // data


class Scheduling {
public :
	vector<data> DataList ;
	vector<data> HRRNqueue ;
	vector<data> mission1 ;
	vector<data> mission2 ;
	vector<data> mission3 ;
	vector<data> mission4 ;
	vector<data> mission5 ;
	queue<data> RRqueue ;
	vector<string> FCFSgrantt ;
	vector<string> RRgrantt ;
	vector<string> SRTFgrantt ;
	vector<string> PPRRgrantt ;
	vector<string> HRRNgrantt ;
	vector<data> samepriority ;
	FILE * OutFile = NULL ;
void readfile( string filename, int & command) {
	
	
  FILE * inFile = NULL ;	
  string name = "" ;
  name = filename + ".txt" ;
  char str[50];
  inFile = fopen( name.c_str(), "r" );
  int slice = 0 ;
  int eof = 0 ;
  data load ;
  if ( !inFile ) {
  	cout << name << " does not exist!\n\n";
  } // if
 
  else {
  	fscanf( inFile, "%d", &command );
    fscanf( inFile, "%d ", &slice );

    fscanf( inFile, "%s%s%s%s%s%s", &str ,&str, &str ,&str, &str ,&str ); 	
    eof = fscanf( inFile, "%d ", &load.id );  
	while( eof != EOF ) {
		fscanf( inFile, "%d %d %d", &load.CpuBurstTime, &load.ArrivalTime, &load.Priority );
		load.slice = slice ;
    	DataList.push_back( load );
        eof = fscanf( inFile, "%d ", &load.id );
    } // while

     fclose(inFile) ;
   } // else

} // readbinary


string Changetostring( int number ) {
	string s = "" ;
	
	if( number == 0)
		s = "0" ;
	else if( number == 1 )
		s = "1" ; 
	else if( number == 2 )
		s = "2" ; 	
	else if( number == 3 )
		s = "3" ; 	
	else if( number == 4 )
		s = "4" ; 	
	else if( number == 5 )
		s = "5" ; 		
	else if( number == 6 )
		s = "6" ; 		
	else if( number == 7 )
		s = "7" ; 		
	else if( number == 8 )
		s = "8" ; 		
	else if( number == 9 )
		s = "9" ; 		
	else if( number == 10 )
		s = "A" ; 		
	else if( number == 11)
		s = "B" ; 
	else if( number == 12)
		s = "C" ; 	
	else if( number == 13 )
		s = "D" ; 	
	else if( number == 14 )
		s = "E" ; 	
	else if( number == 15 )
		s = "F" ; 		
	else if( number == 16 )
		s = "G" ; 		
	else if( number == 17 )
		s = "H" ; 		
	else if( number == 18 )
		s = "I" ; 		
	else if( number == 19 )
		s = "J" ; 		
	else if( number == 20 )
		s = "K" ; 			
	else if( number == 21 )
		s = "L" ; 
	else if( number == 22 )
		s = "M" ; 	
	else if( number == 23 )
		s = "N" ; 	
	else if( number == 24 )
		s = "O" ; 	
	else if( number == 25 )
		s = "P" ; 		
	else if( number == 26 )
		s = "Q" ; 		
	else if( number == 27 )
		s = "R" ; 		
	else if( number == 28 )
		s = "S" ; 		
	else if( number == 29 )
		s = "T" ; 		
	else if( number == 30 )
		s = "U" ; 			
	else if( number == 31 )
		s = "V" ; 				
	else if( number == 32 )
		s = "W" ; 				
	else if( number == 33 )
		s = "X" ; 				
	else if( number == 34 )
		s = "Y" ; 				
	else if( number == 35 )
		s = "Z" ; 				

	return s ;			
		
	
} // change


void bubbleSort() {
  bool pass = false; //have we passed through the array without a swap?
  data temp;

  while (!pass){
    pass = true;
    for (int i=0; i<DataList.size()-1; i++){
      if (DataList[i].ArrivalTime > DataList[i+1].ArrivalTime ){
        pass = false;
        temp = DataList[i];
        DataList[i] = DataList[i+1];
        DataList[i+1] = temp;
      } // if
      else if( DataList[i].ArrivalTime == DataList[i+1].ArrivalTime ){
      	
      	if ( DataList[i].id > DataList[i+1].id ){
        	pass = false;
        	temp = DataList[i];
       		DataList[i] = DataList[i+1];
    	    DataList[i+1] = temp;      	
        } // if
	  } // else if
    } // for
    
  } // while

} // bubbleSort


void bubbleSortid(){
  bool pass = false; //have we passed through the array without a swap?
  data temp;

  while (!pass){
    pass = true;
    for (int i=0; i<DataList.size()-1; i++){
      if (DataList[i].id > DataList[i+1].id ){
        pass = false;
        temp = DataList[i];
        DataList[i] = DataList[i+1];
        DataList[i+1] = temp;
      } // if

    } // for
    
  } // while

} // bubbleSort

void bubbleSortid1(vector<data>& list){
  bool pass = false; //have we passed through the array without a swap?
  data temp;

  while (!pass){
    pass = true;
    for (int i=0; i<list.size()-1; i++){
      if (list[i].id > list[i+1].id ){
        pass = false;
        temp = list[i];
        list[i] = list[i+1];
        list[i+1] = temp;
      } // if

    } // for
    
  } // while

} // bubbleSort

void bubbleSortSrtf( vector<data>& list){
  bool pass = false; //have we passed through the array without a swap?
  data temp;

  while (!pass){
    pass = true;
    for (int i=0; i<list.size()-1; i++){
      if (list[i].CpuBurstTime > list[i+1].CpuBurstTime ){
        pass = false;
        temp = list[i];
        list[i] = list[i+1];
        list[i+1] = temp;
      } // if
      else if (list[i].CpuBurstTime == list[i+1].CpuBurstTime ){
      	
      	if( list[i].ArrivalTime > list[i+1].ArrivalTime ) {
        pass = false;
        temp = list[i];
        list[i] = list[i+1];
        list[i+1] = temp;
        } // if
        
      } // else if 
      else if (list[i].CpuBurstTime == list[i+1].CpuBurstTime ){    	
      	if( list[i].ArrivalTime == list[i+1].ArrivalTime ) {
      		if( list[i].id > list[i+1].id ){
        		pass = false;
        		temp = list[i];
       	 		list[i] = list[i+1];
       			 list[i+1] = temp;
       		 } // if
        } // if
        
      } // else if 
    } // for
    
  } // while

} // bubbleSort


void bubbleSortpprr( vector<data>& list, bool & have ){
  bool pass = false; //have we passed through the array without a swap?
  data temp;

  while (!pass){
    pass = true;
    for (int i=0; i<list.size()-1; i++){
      if (list[i].Priority > list[i+1].Priority ){
        pass = false;
        temp = list[i];
        list[i] = list[i+1];
        list[i+1] = temp;
      } // if
      else if (list[i].Priority == list[i+1].Priority ){
      	if( list[i].ArrivalTime > list[i+1].ArrivalTime ) {
        pass = false;
        temp = list[i];
        list[i] = list[i+1];
        list[i+1] = temp;
        } // if
        
      } // else if 
      else if (list[i].Priority == list[i+1].Priority ){    	
      	if( list[i].ArrivalTime == list[i+1].ArrivalTime ) {
      		if( list[i].id > list[i+1].id ){
        		pass = false;
        		temp = list[i];
       	 		list[i] = list[i+1];
       			list[i+1] = temp;
       		 } // if
        } // if
        
      } // else if 
    } // for
    
  } // while
  
  
  int k = 0 ;
  
      for (k = 1; k<list.size(); k++){
      	if( list[0].Priority == list[k].Priority ) {
      		have = true ;
      		samepriority.push_back(list[k]) ;
      		list.erase(list.begin() + k ) ;
      		k = 0 ;
		  } // if
      } // for

} // bubbleSort



void bubbleSortpprr1 ( vector<data> & list){
  bool pass = false; //have we passed through the array without a swap?
  data temp;

  while (!pass){
    pass = true;
    for (int i=0; i<list.size()-1; i++){
		//cout << list[i].id <<"	vs	"<< list[i+1].id<< endl;
      if (list[i].ArrivalTime > list[i+1].ArrivalTime ){
        pass = false;
        temp = list[i];
        list[i] = list[i+1];
        list[i+1] = temp;
      	//cout <<"	casw1 " <<  ;
      } // if
      else if( list[i].ArrivalTime == list[i+1].ArrivalTime ){
      	if ( list[i].Priority > list[i+1].Priority ){
      		//cout <<"	casw2 \n" ;
        	pass = false;
        	temp = list[i];
       		list[i] = list[i+1];
    	    list[i+1] = temp;      	
        } // if
	  } // else if
    } // for
    
  } // while

} // bubbleSort

void FCFS() {
	
bubbleSort() ;


int duration = 0 ;
string s = "" ;

int i = 0 ;

for( i = 0 ; i < DataList.size() ; i++) 
    mission1.push_back(DataList[i]) ;
    
if( mission1[0].ArrivalTime != 0 ) {
	for( int j = 0 ; j < mission1[0].ArrivalTime; j++) 
		FCFSgrantt.push_back("-") ;  
	
 } // if
 
 
mission1[0].Finish = mission1[0].CpuBurstTime +  mission1[0].ArrivalTime ;

mission1[0].TurnArround = mission1[0].Finish - mission1[0].ArrivalTime ;

mission1[0].Waiting = mission1[0].TurnArround - mission1[0].CpuBurstTime ;

duration = mission1[0].Finish ;
s = Changetostring(mission1[0].id ) ;

for( int j = 0 ; j < mission1[0].CpuBurstTime; j++) 
	FCFSgrantt.push_back( s );
	
	
for( int i = 1 ; i < mission1.size(); i++){
	
	
	if( duration < mission1[i].ArrivalTime ) {
		
		int temp = mission1[i].ArrivalTime - duration ;
		duration = mission1[i].ArrivalTime	;
		for( int j = 0 ; j < temp ; j++) { 
			FCFSgrantt.push_back( "-" );
	     } // for 
	} // if

	
	s = Changetostring(mission1[i].id ) ;
	
	for( int j = 0 ; j < mission1[i].CpuBurstTime; j++) 
		FCFSgrantt.push_back( s );
	
	mission1[i].Finish = duration + mission1[i].CpuBurstTime  ;

	mission1[i].TurnArround = mission1[i].Finish - mission1[i].ArrivalTime;	

    mission1[i].Waiting = mission1[i].TurnArround - mission1[i].CpuBurstTime  ; 
    
    duration = mission1[i].Finish ;
} // for 


bubbleSortid1(mission1) ;


for( int i = 0 ; i < FCFSgrantt.size(); i++) 

	fprintf( OutFile, "%s", FCFSgrantt[i].c_str() );

fprintf( OutFile, "\n" ) ;
cout << "   FCFS " << endl ;

for( int i = 0 ; i < mission1.size(); i++) {
	
	cout <<mission1[i].id << "  "<<  mission1[i].Waiting << "  " << mission1[i].TurnArround <<endl ;
} 

FCFSgrantt.clear() ;
//DataList.clear() ;
	
} // FCFS


void RR(){
	
	
bubbleSort() ;
int i = 0 ;

int duration = 0 ; 
string s = "" ; 


for( i = 0 ; i < DataList.size() ; i++) 
    mission2.push_back(DataList[i]) ;
    


if( mission2[0].ArrivalTime != 0 ) {
	for( int j = 0 ; j < mission2[0].ArrivalTime; j++) 
		RRgrantt.push_back("-") ;  
	
 } // if
 
 
		mission2[0].Finish = mission2[0].slice +  mission2[0].ArrivalTime ;

		if(  mission2[0].CpuBurstTime - mission2[0].slice > 0 ) {
			
		s = Changetostring(mission2[0].id ) ;	
		for( int j = 0 ; j < mission2[0].slice ; j++) 	
			RRgrantt.push_back( s );
			
			duration = mission2[0].Finish ;
		    mission2[0].CpuBurstTime -= mission2[0].slice ;
		    
		} // if
		else if(  mission2[0].CpuBurstTime - mission2[0].slice < 0 ) {
			
			s = Changetostring(mission2[0].id ) ;	
			
			for( int j = 0 ; j < mission2[0].CpuBurstTime ; j++) 	
				RRgrantt.push_back( s );
			mission2[0].completed = true ;
			duration += mission2[0].CpuBurstTime ;
			mission2[0].TurnArround = duration - mission2[0].ArrivalTime ;
  			mission2[0].Waiting = mission2[0].TurnArround - DataList[0].CpuBurstTime ;
			mission2[0].CpuBurstTime = 0 ;
		} // else if
		else {                                         
		
			s = Changetostring(mission2[0].id ) ;	
			for( int j = 0 ; j < mission2[0].slice ; j++) 	
				RRgrantt.push_back( s );
			mission2[0].completed = true ;
			duration += mission2[0].CpuBurstTime ;
			mission2[0].TurnArround = duration - mission2[0].ArrivalTime ;
			
  			mission2[0].Waiting = mission2[0].TurnArround - DataList[0].CpuBurstTime ;
			mission2[0].CpuBurstTime -= mission2[0].slice ;

		} // else 
				
				
	  	for(  int j = 1 ; j < mission2.size(); j++) { // 算根據第一筆的waiting  
			if( mission2[j].ArrivalTime <= duration && 	mission2[j].inq == false  ) {
				mission2[j].inq = true ;
				RRqueue.push(mission2[j]) ;
			} // if 
	   } // for 	
	  
	  	if (  mission2[0].completed == false ){

 			RRqueue.push(mission2[0]) ;	
			mission2[0].inq = true	;
		} // if 
 			
 		if( RRqueue.empty() && mission2[0].inq == true ) {
 			
 			if( i != mission2.size() ) {
			mission2[1].inq = true ;
 			RRqueue.push(mission2[1]) ;
 			
 			duration = mission2[1].ArrivalTime ;
 		    } // if
 		 		
	    } // if 
	    

data temp ;

	while( !RRqueue.empty() ) {
		
		temp = RRqueue.front() ;
		
		RRqueue.pop() ;
		
		
      	for( i = 0 ; i < mission2.size(); i++) { // 算根據第一筆的waiting 
    
        	if( temp.id == mission2[i].id ){
        		break ;
			} // if
        } // for	
        
        
		if(  mission2[i].CpuBurstTime - mission2[i].slice > 0 ) {
			
			s = Changetostring(mission2[i].id ) ;	
			for( int j = 0 ; j < mission2[i].slice ; j++) 	
				RRgrantt.push_back( s );
            mission2[i].Finish = duration + mission2[i].slice ;
			duration = mission2[i].Finish ;
		    mission2[i].CpuBurstTime -= mission2[i].slice ;
		    
		} // if
		else if(  mission2[i].CpuBurstTime - mission2[i].slice < 0 ) {
			
			s = Changetostring(mission2[i].id ) ;	
			for( int j = 0 ; j < mission2[i].CpuBurstTime ; j++) 	
				RRgrantt.push_back( s );
			mission2[i].completed = true ;
			duration += mission2[i].CpuBurstTime ;
			mission2[i].TurnArround = duration - mission2[i].ArrivalTime ;
  			mission2[i].Waiting = mission2[i].TurnArround - DataList[i].CpuBurstTime ;
			mission2[i].CpuBurstTime = 0 ;
		} // else if
		else {              
		
			s = Changetostring(mission2[i].id ) ;	
			for( int j = 0 ; j < mission2[i].slice ; j++) 	
				RRgrantt.push_back( s );                           
			mission2[i].completed = true ;
			duration += mission2[i].CpuBurstTime ;
			mission2[i].TurnArround = duration - mission2[i].ArrivalTime ;
			
  			mission2[i].Waiting = mission2[i].TurnArround - DataList[i].CpuBurstTime ;
			mission2[i].CpuBurstTime -= mission2[i].slice ;
		} // else 
		
		//cout << duration << endl ;
				
	  	for(  int j = 0 ; j < mission2.size(); j++) { // 算根據第一筆的waiting  
	
			if( mission2[j].ArrivalTime <= duration && 	mission2[j].inq == false  ) {
				mission2[j].inq = true ;
			//	cout << DataList[j].id << "*****";
				RRqueue.push(mission2[j]) ;
			} // if 
		
	   } // for 	
	  
	  	if (  mission2[i].completed == false ) {
		
 			RRqueue.push(mission2[i]) ;
 		   } // 
 			
 			
 			
 		
 		if( RRqueue.empty() && mission2[i+1].inq == false ) {
 			if( i != mission2.size()-1 ) {
				mission2[i+1].inq = true ;
 				RRqueue.push(mission2[i+1]) ;
 				int temptemp = mission2[i+1].ArrivalTime - duration ;
 				duration = mission2[i+1].ArrivalTime ;
				for( int j = 0 ; j < temptemp ; j++) 
					RRgrantt.push_back( "-" );
 				
	
 		    } // if 
 		 		
	    } // if   
			
  } // while 
  
bubbleSortid1(mission2) ; 
for( int i = 0 ; i < RRgrantt.size(); i++) 

	fprintf( OutFile, "%s", RRgrantt[i].c_str() );

fprintf( OutFile, "\n" ) ;


cout << "   RR " << endl ;
for( int i = 0 ; i < mission2.size(); i++) {
	
	cout <<mission2[i].id << "  "<<  mission2[i].Waiting << "  " << mission2[i].TurnArround <<endl ;
}   



} // RR

void SRTF(){
	
	
	int i,temp = 0 ;
	int j = 0 ;
	string s = "" ;
	int duration = 0 ;


	vector<data> SRTFqueue ;

	bubbleSort() ;


	for( i = 0 ; i < DataList.size() ; i++) 
    	mission3.push_back(DataList[i]) ;
    	
    	
	
	data min = mission3[0];
    for( i = 0 ; i < mission3.size(); i++) { // 算根據第一筆的waiting 
    
        if( min.ArrivalTime > mission3[i].ArrivalTime) {
	       
            min = mission3[i];
            temp = i ;
            
       } // if
       else if( min.ArrivalTime == mission3[i].ArrivalTime) {
       	
    	if( min.CpuBurstTime > mission3[i].CpuBurstTime) { 
    		
            min = mission3[i];
            temp = i ;
		
		} // if
       	
	   } // else if   
			 
     } // for
     
     
    if( mission3[temp].ArrivalTime != 0 ) {
		for( int j = 0 ; j < mission3[temp].ArrivalTime; j++) 
			SRTFgrantt.push_back("-") ;  
	
	 } // if
     
     if( mission3[temp].ArrivalTime > duration )
     	duration = mission3[temp].ArrivalTime ;
     	
     SRTFqueue.push_back( mission3[temp] ) ;
     
     
     
     

    while( !SRTFqueue.empty() ) {  
     			
        		
		for( i = 0 ; i < mission3.size(); i++) { 
    
        	if( SRTFqueue[0].id== mission3[i].id ){
        		mission3[i].inq = true ;
        		SRTFqueue.erase(SRTFqueue.begin() + 0) ;
        		break ;
			} // if
			
        	} // for  
			
			if( mission3[i].CpuBurstTime == 0 ) {
				
				
				mission3[i].TurnArround = duration - mission3[i].ArrivalTime ;

 				mission3[i].Waiting = mission3[i].TurnArround - DataList[i].CpuBurstTime ;
 				
				mission3[i].completed = true ;
			} // if
			else if( mission3[i].CpuBurstTime > 0 ) { 
			
			
    			s = Changetostring(mission3[i].id ) ;
				SRTFgrantt.push_back( s );
			
			
				duration++ ;
				mission3[i].CpuBurstTime -- ;	
				SRTFqueue.push_back(mission3[i]) ;
				
			} // else if 
			
			
		   
	 for(  j = 0 ; j < mission3.size(); j++) { // 算根據第一筆的waiting  
			if( mission3[j].ArrivalTime <= duration && 	mission3[j].inq == false  ) {
				mission3[j].inq = true ;
				SRTFqueue.push_back(mission3[j]) ;

				
			} // if 
			
	 } // for
	 
	if(  SRTFqueue.size() > 1 ) 
		bubbleSortSrtf(SRTFqueue) ; 
		
	if( SRTFqueue.empty() && mission3[i+1].inq == false ) {
 		if( i != mission3.size()-1 ) {
			mission3[i+1].inq = true ;
 			SRTFqueue.push_back(mission3[i+1]) ;
 			int temptemp = mission2[i+1].ArrivalTime - duration ;
 				duration = mission3[i+1].ArrivalTime ;
				for( int j = 0 ; j < temptemp ; j++) 
					SRTFgrantt.push_back( "-" );
 		    } // if
 		 		
	    } // if 
} // while 

	 
	 
	   
	   
	   
bubbleSortid1(mission3) ;

for( int i = 0 ; i < SRTFgrantt.size(); i++) 

	fprintf( OutFile, "%s", SRTFgrantt[i].c_str() );

fprintf( OutFile, "\n" ) ;



  
cout << "      SRTF" << endl ;
  
for( int i = 0 ; i < mission3.size(); i++) {
	
	cout <<mission3[i].id << "  "<<  mission3[i].Waiting << "  " << mission3[i].TurnArround <<endl ;
} 	   
	   
    

SRTFqueue.clear() ;
	
	
	
	
	
	
} // SRTF


void PPRR(){
	
int i,f,j = 0 ;
bool have = false ;
int duration = 0 ; 
string s = "" ;
int tempi = 0;	
bool change = false ;

vector<data>  PPRRqueue ;
vector<int> tempList1;
bool process = false ;
// bubbleSort() ;
	for( i = 0 ; i < DataList.size() ; i++) {
   		mission4.push_back(DataList[i]) ;
		//cout <<mission4[i].id <<endl;
	}	
   		
   	 
    bubbleSortpprr1(mission4) ;
	
	for( j = 0 ; j < mission4.size() ; j++) {
		tempi = mission4[j].CpuBurstTime ;
		tempList1.push_back(tempi) ;	
	}
   	have = false ;
	samepriority.clear();
	
	if( mission4[0].ArrivalTime != 0 ) {
		for( int j = 0 ; j < mission4[0].ArrivalTime; j++) 
			PPRRgrantt.push_back("-") ;  
	
	 } // if
     if( mission4[0].ArrivalTime > duration )
     	duration = mission4[0].ArrivalTime ;
        		
				
	mission4[0].inq = true ;	
    PPRRqueue.push_back( mission4[0] ) ;
    
     
    while( !PPRRqueue.empty() ) {  
     			
        		
		for( i = 0 ; i < mission4.size(); i++) { 
    
        	if( PPRRqueue[0].id== mission4[i].id ){
 
        		PPRRqueue.erase(PPRRqueue.begin()) ;
        		break ;
			} // if
			
        	} // for 
        	
        	
		if(  mission4[i].CpuBurstTime > 0 ) {
			
			if( have == true  ){ // 有無相同優先等級  
				samepriority.insert( samepriority.begin(), mission4[i])  ;
				for( f = 0 ; f < samepriority.size(); f++) { 
				   	
					for( i = 0 ; i < mission4.size(); i++) { 
    
        				if( samepriority[f].id== mission4[i].id ){
        					 //samepriority.erase(samepriority.begin()+f) ;
        					break ;
						} // if
			
        				} // for 
        			
        			if( mission4[i].ArrivalTime != duration && process == false  ){
        				    
					        if(  mission4[i].CpuBurstTime - mission4[i].slice > 0 ) { 
					        					        
					        if( mission4[i].havedobefore == false) {
					        	
					        	s = Changetostring(mission4[i].id ) ;
								for(  j = 0 ; j < mission4[i].slice; j++) 
									PPRRgrantt.push_back( s );
									
					        	duration += mission4[i].slice ;
					        	mission4[i].CpuBurstTime -= mission4[i].slice ;
					        	
							} // if
							else {
								
									
								int tempduration =  duration - mission4[i].ArrivalTime ;
								
								
								s = Changetostring(mission4[i].id ) ;
								for(  j = 0 ; j < tempduration; j++) 
									PPRRgrantt.push_back( s );
									
        						duration += tempduration ;
								mission4[i].CpuBurstTime -= tempduration ;
							} // else 

							//	cout << mission4[i].id << "	same "<< mission4[i].CpuBurstTime<< "  " <<  duration << endl ;
								process = true ;	
								PPRRqueue.push_back(mission4[i]) ;
							} // if
							else if(  mission4[i].CpuBurstTime - mission4[i].slice <= 0 ) {
								
								s = Changetostring(mission4[i].id ) ;
								for(  j = 0 ; j < mission4[i].CpuBurstTime; j++) 
									PPRRgrantt.push_back( s );
									
								duration +=  mission4[i].CpuBurstTime ;
								mission4[i].CpuBurstTime = 0 ;
								process = true ;	
							//	cout << mission4[i].id << "	sameDone "<< mission4[i].CpuBurstTime<< "  " <<  duration << endl ;
								mission4[i].TurnArround = duration - mission4[i].ArrivalTime ;

 								mission4[i].Waiting = mission4[i].TurnArround - tempList1[i] ;
 								mission4[i].completed = true ;
							} // else if

				    } // if
				    else {  
				    
				    	    if(  mission4[i].CpuBurstTime - mission4[i].slice > 0 ) { 
				    	    
				    	    	s = Changetostring(mission4[i].id ) ;
								for(  j = 0 ; j < mission4[i].slice; j++) 
									PPRRgrantt.push_back( s );
					
					        	duration += mission4[i].slice ;
					        	mission4[i].CpuBurstTime -= mission4[i].slice ;
					        //	cout << mission4[i].id << "	newIn "<< mission4[i].CpuBurstTime<< "  " <<  duration << endl ;
					        	
							} // if
				    		else if(  mission4[i].CpuBurstTime - mission4[i].slice <= 0 ) {
				    			
				    			s = Changetostring(mission4[i].id ) ;
								for(  j = 0 ; j < mission4[i].CpuBurstTime; j++) 
									PPRRgrantt.push_back( s );
									
								duration +=  mission4[i].CpuBurstTime ;
								mission4[i].CpuBurstTime = 0 ;
								process = true ;	
							//	cout << mission4[i].id << "	sameDone "<< mission4[i].CpuBurstTime<< "  " <<  duration << endl ;
								mission4[i].TurnArround = duration - mission4[i].ArrivalTime ;

 								mission4[i].Waiting = mission4[i].TurnArround - tempList1[i] ;
 								mission4[i].completed = true ;
							} // else if
				    
		
					   for( int t = 0 ; t < mission4.size(); t++) {  // !!!!!!!!!!!!!!!!!!!!!!!!!! 
    
        					if( duration >= mission4[t].ArrivalTime &&  mission4[t].Priority <  mission4[i].Priority && mission4[t].inq == false  ){
        						
        						if( change == false ) {
									int tempduration1 = duration - mission4[t].ArrivalTime ;
									
									s = Changetostring(mission4[t].id ) ; 
									for(  j = 0 ; j < tempduration1; j++) 
										PPRRgrantt.erase( PPRRgrantt.end() );
									
									duration -= tempduration1 ;
									mission4[i].CpuBurstTime += tempduration1 ;
									
					    			change = true ;
					    	    } // if
					    	   
					    	   
					    	   duration++ ;
					    	   	s = Changetostring(mission4[t].id ) ; 
								PPRRgrantt.push_back( s );
					    	   mission4[t].CpuBurstTime-- ;
        					 //samepriority.erase(samepriority.begin()+f) ;
        					 	if(mission4[t].CpuBurstTime == 0 ) {
        					 //		cout << mission4[t].id << "---"<< duration  << endl ;	
        					 		mission4[t].inq = true ;
        					 		mission4[t].TurnArround = duration - mission4[t].ArrivalTime ;

 									mission4[t].Waiting = mission4[t].TurnArround - tempList1[t] ;
									mission4[t].completed = true ;
        					   		break ;  
        					    } // if
        					   	t = 0 ;
							} // if	
					} // for 

						
						if( mission4[i].completed == false )
						    PPRRqueue.push_back(mission4[i]) ;
					} // else 
					
			   } // for
			} // if							
			else {
				
				s = Changetostring(mission4[i].id ) ; 
				PPRRgrantt.push_back( s );
				//cout << mission4[i].id << " no same "<< duration  << endl ;
				duration ++ ;
				mission4[i].CpuBurstTime -- ;	
				mission4[i].havedobefore = true ;
				PPRRqueue.push_back(mission4[i]) ;
		    } // else	
		    
		    have = false ;
		    samepriority.clear();
		} // if
		else if( mission4[i].CpuBurstTime == 0 ) {
				//cout << mission4[i].id << "---"<< duration  << endl ;		
				mission4[i].TurnArround = duration - mission4[i].ArrivalTime ;

 				mission4[i].Waiting = mission4[i].TurnArround - tempList1[i] ;
				mission4[i].completed = true ;
		} // if
		
        	
	 for(  j = 0 ; j < mission4.size(); j++) {  
			if( mission4[j].ArrivalTime <= duration && 	mission4[j].inq == false  ) {
				mission4[j].inq = true ;
				process = false ;
				change = false ;
				PPRRqueue.push_back(mission4[j]) ;

				
			} // if 
			
	 } // for
	 
	 
	if(  PPRRqueue.size() > 1 ) {
	//	   for(  j = 0 ; j < PPRRqueue.size(); j++) 
	   // 	cout << PPRRqueue[j].id << "**********" << PPRRqueue.size()<<endl ;	
	    	
	    	
		bubbleSortpprr(PPRRqueue, have) ; 
			
	   // for(  j = 0 ; j < samepriority.size(); j++) 
	   // 	cout << samepriority[j].id << "samepriority"<<endl ;
	    
     } // if
     
     	     
  	if( PPRRqueue.empty() ) {
  			
  	 data min = mission4[mission4.size()-1];
  		int temp = 0 ;
	    for( i = 0 ; i < mission4.size(); i++) { // 算根據第一筆的waiting 
	    
	        if( min.ArrivalTime > mission4[i].ArrivalTime && mission4[i].inq == false) {
		       
	            min = mission4[i];
	            temp = i ;
	            
	       } // if
	       else if( min.ArrivalTime == mission4[i].ArrivalTime && mission4[i].inq == false ) {
	       	
	    	if( min.CpuBurstTime > mission4[i].CpuBurstTime) { 
	    		
	            min = mission4[i];
	            temp = i ;
			
			} // if
	       	
		   } // else if   
				 
	     } // for
  		
 		if( temp != mission4.size()-1 && mission4[temp].inq == false ) {
			mission4[temp].inq = true ;
 			PPRRqueue.push_back(mission4[temp]) ;
 			int temptemp = mission4[temp].ArrivalTime - duration ;
 			duration = mission4[temp].ArrivalTime ;
				for( int j = 0 ; j < temptemp ; j++) 
					PPRRgrantt.push_back( "-" );
 		    } // if
 		 		
	    } // if    	
			      	
} // while 
	
	
bubbleSortid1(mission4) ;

for( int i = 0 ; i < PPRRgrantt.size(); i++) 

	fprintf( OutFile, "%s", PPRRgrantt[i].c_str() );

fprintf( OutFile, "\n" ) ;



  
cout << "    PPRR" << endl ;
for( int i = 0 ; i < mission4.size(); i++) {
	
	cout <<mission4[i].id << "  "<<  mission4[i].Waiting << "  " << mission4[i].TurnArround <<endl ;
} 


tempList1.clear() ;
PPRRqueue.clear() ;
	
} // PPRR


void HRRN() {                                     

  bubbleSort() ;
  int duration = 0 ;
   int i = 0 ;
   string s = "" ;
  int j = 0 ;
  int tempi = 0 ;
  
	for( i = 0 ; i < DataList.size() ; i++) 
   		mission5.push_back(DataList[i]) ;

	if( mission5[0].ArrivalTime != 0 ) {
		for( int j = 0 ; j < mission5[0].ArrivalTime; j++) 
			HRRNgrantt.push_back("-") ;  
	
	 } // if	
	
	
	s = Changetostring(mission5[0].id ) ;
	for(  j = 0 ; j < mission5[0].CpuBurstTime; j++) 
		HRRNgrantt.push_back( s );
  mission5[0].Finish = mission5[0].CpuBurstTime +  mission5[0].ArrivalTime ;

  mission5[0].TurnArround = mission5[0].Finish - mission5[0].ArrivalTime ;

  mission5[0].Waiting = mission5[0].TurnArround - mission5[0].CpuBurstTime ;
  	
  duration = mission5[0].Finish ;
  mission5[0].completed = true ;
  
  for(  i = 1 ; i < mission5.size(); i++) { // 算根據第一筆的waiting  

	if( mission5[i].ArrivalTime <= duration && mission5[i].completed == false ) {
		mission5[i].completed = true ;
		HRRNqueue.push_back(mission5[i]) ;
	} // if 
	
  } // for 
  
  
  if( HRRNqueue.empty() && mission5[0].completed == true ) {
  	
 		HRRNqueue.push_back(DataList[1]) ;
		mission5[1].completed = true ;
		
		int temptemp = mission5[1].ArrivalTime - duration ;
 		duration = mission5[1].ArrivalTime ;
		for( int j = 0 ; j < temptemp ; j++) 
			HRRNgrantt.push_back( "-" );	
   		 //cout  << mission5[1].id << "    "<< duration << endl ;
		 	
} // if  

  
  while( !HRRNqueue.empty() ) {
  	
  	for( i = 0 ; i < HRRNqueue.size(); i++) { // 算根據第一筆的waiting 
  	
  	
	    HRRNqueue[i].Waiting = duration - HRRNqueue[i].ArrivalTime  ;
	    
  		HRRNqueue[i].HRR = ( HRRNqueue[i].Waiting + ( HRRNqueue[i].CpuBurstTime * 1.0 ) ) / HRRNqueue[i].CpuBurstTime ;     // 等待時間	
  	
     } // for
     
     
     
  	
    data max = HRRNqueue[0];
    
    int temp = 0 ;
    
    for( i = 0 ; i < HRRNqueue.size(); i++) { // 算根據第一筆的waiting 
    
        if( max.HRR < HRRNqueue[i].HRR) {
	
	
            max = HRRNqueue[i];
            temp = i ;
            
       } // if
			 
     } // for
     
     HRRNqueue.erase(HRRNqueue.begin()+temp) ;
     
      for( i = 1 ; i < mission5.size(); i++) { // 算根據第一筆的waiting 
    
        if( max.id == mission5[i].id){
        	break ;
		}
        
     } // for
     
     
    s = Changetostring(mission5[i].id ) ;
     
    for(  j = 0 ; j < mission5[i].CpuBurstTime; j++) 
		HRRNgrantt.push_back( s );
		
		
    mission5[i].Finish = duration + mission5[i].CpuBurstTime  ;

	mission5[i].TurnArround = mission5[i].Finish - mission5[i].ArrivalTime;	

    mission5[i].Waiting = mission5[i].TurnArround - mission5[i].CpuBurstTime  ; 
     
    duration = mission5[i].Finish ; 
    mission5[i].completed = true ;
    tempi = i ;
    for(  i = 0 ; i < mission5.size(); i++) { // 算根據第一筆的waiting  

	  if( mission5[i].ArrivalTime <= duration && mission5[i].completed == false ) {
		mission5[i].completed = true ;
		HRRNqueue.push_back(mission5[i]) ;
	  } // if 	  
    } // for 




    if( HRRNqueue.empty() && mission5[tempi].completed == true ) {
    	    if( tempi + 1 != mission5.size() ) {
				mission5[tempi+1].completed = true ;
 				HRRNqueue.push_back(mission5[tempi+1]) ;
 				
 				int temptemp = mission5[tempi+1].ArrivalTime - duration ;
 				duration = mission5[tempi+1].ArrivalTime ;	
				for( int j = 0 ; j < temptemp ; j++) 
					HRRNgrantt.push_back( "-" );

	    } // if 
 		 		
	} // if  
    
  } // while
  
  
  
bubbleSortid1(mission5) ;


for( int i = 0 ; i < HRRNgrantt.size(); i++) 

	fprintf( OutFile, "%s", HRRNgrantt[i].c_str() );

fprintf( OutFile, "\n" ) ;


  cout << "   HRRN " << endl ;
  
for( int i = 0 ; i < mission5.size(); i++) {
	
	cout <<mission5[i].id << "  "<<  mission5[i].Waiting << "  " << mission5[i].TurnArround <<endl ;
} 
	

HRRNqueue.clear() ;
duration = 0 ;
tempi = 0 ;
} // HRRN

void All(){
	


fprintf( OutFile, "\n");
fprintf( OutFile, "%s\n", "waiting" );	
fprintf( OutFile, "%s\n", "ID	FCFS	RR	SRTF	PPRR	HRRN" );	
fprintf( OutFile, "%s\n", "===========================================================" );
	
	for( int i =  0; i < mission5.size() ; i++) {
		
	fprintf( OutFile, "%d\t", mission1[i].id );		
	fprintf( OutFile, "%d\t", mission1[i].Waiting );		
	fprintf( OutFile, "%d\t", mission2[i].Waiting );	
	fprintf( OutFile, "%d\t", mission3[i].Waiting );	
	fprintf( OutFile, "%d\t", mission4[i].Waiting );	
	fprintf( OutFile, "%d\n", mission5[i].Waiting );
	
	} // for 


fprintf( OutFile, "%s\n", "===========================================================" );	
	
fprintf( OutFile, "\n");
fprintf( OutFile, "%s\n", "Turnaround Time" );	
fprintf( OutFile, "%s\n", "ID	FCFS	RR	SRTF	PPRR	HRRN" );	
fprintf( OutFile, "%s\n", "===========================================================" );	
	

	for( int i =  0; i < mission5.size() ; i++) {
		
		fprintf( OutFile, "%d\t", mission1[i].id );		
		fprintf( OutFile, "%d\t", mission1[i].TurnArround );		
		fprintf( OutFile, "%d\t", mission2[i].TurnArround );	
		fprintf( OutFile, "%d\t", mission3[i].TurnArround );	
		fprintf( OutFile, "%d\t", mission4[i].TurnArround );	
		fprintf( OutFile, "%d\n", mission5[i].TurnArround );
	
	} // for 	
	
fprintf( OutFile, "%s\n", "===========================================================" );	
fprintf( OutFile, "\n");

mission1.clear() ;
mission2.clear() ;
mission3.clear() ;
mission4.clear() ;
mission5.clear() ;
FCFSgrantt.clear() ;
RRgrantt.clear() ;
SRTFgrantt.clear() ;
PPRRgrantt.clear() ;
HRRNgrantt.clear() ;
} // ALL



void PrintOne( int command ) {
	
vector<data> tempList ;
fprintf( OutFile, "\n");
fprintf( OutFile, "%s\n", "waiting" );

string temps = "" ;



if( command == 1 ) {
	
	for( int j = 0 ; j < mission1.size() ; j++) 
   		tempList.push_back(mission1[j]) ;	
   		
   	temps = "FCFS" ;

} // if
else if( command == 2 ) {
	
	for( int j = 0 ; j < mission2.size() ; j++) 
   		tempList.push_back(mission2[j]) ;
   	temps = "RR" ;  		
} // else if
else if( command == 3 ) {
		for( int j = 0 ; j < mission3.size() ; j++) 
   		tempList.push_back(mission3[j]) ;
   	temps = "SRTF" ;	
} // else if
else if( command == 4 ) {
	
		for( int j = 0 ; j < mission4.size() ; j++) 
   		tempList.push_back(mission4[j]) ;
   	temps = "PPRR" ;		
} // else if
else if( command == 5 ) {
	
		for( int j = 0 ; j < mission5.size() ; j++) 
   		tempList.push_back(mission5[j]) ;
	   	temps = "HRRN" ;	
} // else if

	
fprintf( OutFile, "%s%s\n", "ID  ",temps.c_str() );	
fprintf( OutFile, "%s\n", "===========================================================" );	

	for( int i =  0; i < tempList.size() ; i++) {
		
	fprintf( OutFile, "%d\t", tempList[i].id );		
	fprintf( OutFile, "%d\n", tempList[i].Waiting );		
	} // for 
	
	fprintf( OutFile, "%s\n", "===========================================================" );	
	
	fprintf( OutFile, "\n");
	fprintf( OutFile, "%s\n", "Turnaround Time" );	
	fprintf( OutFile, "%s%s\n", "ID  ",temps.c_str() );			
	fprintf( OutFile, "%s\n", "===========================================================" );	
	
	for( int i =  0; i < tempList.size() ; i++) {
		
	fprintf( OutFile, "%d\t", tempList[i].id );		
	fprintf( OutFile, "%d\n", tempList[i].TurnArround );		

	} // for 	
	


}


} ; // Scheduling
int main(int argc, char** argv) {
    int command = 0 ;
    int num = 0 ;
    string inputmodel ;
    Scheduling user ;  
    cout << endl <<("**********************") ;
    cout << endl <<("*1. FCFS             *") ;
    cout << endl <<("*2. RR             *") ; 
    cout << endl <<("*3. SRTF             *") ;
    cout << endl <<("*4. PPRR               *") ; 
    cout << endl <<("*5. HRRN               *") ;
    cout << endl <<("*6. ALL CPU Schedule *") ;
    cout << endl <<("**********************") ;
    cout << endl << ( "請輸入檔名") ; 
    cin >> inputmodel ;
    user.readfile(inputmodel, command ) ;
    while ( command != 0 ){
    	
      if ( command == 1 ){
      	inputmodel = "my_out_" + inputmodel + ".txt" ;
      	user.OutFile = fopen( inputmodel.c_str(), "w" );
      	fprintf( user.OutFile, "%s\n", "FCFS" );
      	user.FCFS() ;
      	fprintf( user.OutFile, "%s\n", "===========================================================" );
      	user.PrintOne(command) ;
      } // if
      else if ( command == 2 ){
      	inputmodel = "my_out_" + inputmodel + ".txt" ;
      	user.OutFile = fopen( inputmodel.c_str(), "w" );
      	fprintf( user.OutFile, "%s\n", "RR" );
      	user.RR() ;
        fprintf( user.OutFile, "%s\n", "===========================================================" );
      	user.PrintOne(command) ;
      } // else if
      else if ( command == 3 ) {
      	inputmodel = "my_out_" + inputmodel + ".txt" ;
      	user.OutFile = fopen( inputmodel.c_str(), "w" );
      	fprintf( user.OutFile, "%s\n", "SRTF" );
        user.SRTF() ;
        fprintf( user.OutFile, "%s\n", "===========================================================" );
        user.PrintOne(command) ;

      } // else if
      else if ( command == 4 ) {
      	
      	inputmodel = "my_out_" + inputmodel + ".txt" ;
      	user.OutFile = fopen( inputmodel.c_str(), "w" );
      	fprintf( user.OutFile, "%s\n", "PPRR" );
        user.PPRR()  ;
        fprintf( user.OutFile, "%s\n", "===========================================================" );
        user.PrintOne(command) ;

      } // else if
      else if ( command ==5 ) {
      	inputmodel = "my_out_" + inputmodel + ".txt" ;
      	user.OutFile = fopen( inputmodel.c_str(), "w" );
      	fprintf( user.OutFile, "%s\n", "HRRN" );
        user.HRRN() ;
        fprintf( user.OutFile, "%s\n", "===========================================================" );
        user.PrintOne(command) ;
      } // else if
      else if ( command ==6 ) {
      	inputmodel = "my_out_" + inputmodel + ".txt" ;
      	user.OutFile = fopen( inputmodel.c_str(), "w" );
      	fprintf( user.OutFile, "%s\n", "All" );
        //user.ALL() ;
        fprintf( user.OutFile, "%s\n", "==        FCFS==" );
        user.FCFS() ;
        fprintf( user.OutFile, "%s\n", "==          RR==" );
      	user.RR() ;
        fprintf( user.OutFile, "%s\n", "==        SRTF==" );
        user.SRTF() ;
        fprintf( user.OutFile, "%s\n", "==        PPRR==" );
        user.PPRR()  ;
        fprintf( user.OutFile, "%s\n", "==        HRRN==" );
        user.HRRN() ;
        fprintf( user.OutFile, "%s\n", "===========================================================" );
        user.All() ;

      } // else if      
      else {
        cout << endl << "Command does not exist!" ;
      } // else
      
    user.DataList.clear() ;
    fclose( user.OutFile) ; 
    cout << endl <<("**********************") ;
    cout << endl <<("*1. FCFS             *") ;
    cout << endl <<("*2. NSJF             *") ; 
    cout << endl <<("*3. PSJF             *") ;
    cout << endl <<("*4. RR               *") ; 
    cout << endl <<("*5. PP               *") ;
    cout << endl <<("*6. ALL CPU Schedule *") ;
    cout << endl <<("**********************") ;
    cin >> inputmodel ;
    user.readfile(inputmodel, command ) ;
    } // while

return 0 ;
} // main

