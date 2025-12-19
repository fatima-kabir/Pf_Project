#include <iostream>
using namespace std;
struct Room{
    int roomNo;
    int price;
    bool isAvailable;
};

struct Customer{
    int id;
    int roomNo[5];
    int numRooms;
    int days;
    int extraCharges;
    int totalBill;
};

Room rooms[5] = {
    {1, 2000, true},
    {2, 2000, true},
    {3, 2500, true},
    {4, 3000, true},
    {5, 3000, true}
};

Customer customers[10];
int customerCount = 0;

void mainMenu();
void showAllCustomers();

void checkOut(int roomNo);
void showAvailableRooms();
bool isRoomAvailable(int roomNumber, int &index);

void addCustomer();
void generateReceipt(Customer c);


    
    



    
    
        
        
        
        
        
        
        
        
        
           
       
            
       
            
            
           
           
        
        
           
        
            
        
            
    



    
  
       
            
            
        
    



    
            

   
        
                           
                  
                             
                                
        
			
               
                                
            
        
    
                          
        
    
                            



    
        
            
            
            
        
    
    


void addCustomer(){
    int availableRoomsCount = 0;
    for(int i = 0; i<5; i++){
        if(rooms[i].isAvailable)
            availableRoomsCount++;
    }
    if(availableRoomsCount == 0){
        cout<<"Sorry! No rooms are available right now"<<endl;
        return; 
    }

    Customer *cPtr = &customers[customerCount]; 

    cout<<"Available rooms: "<<availableRoomsCount<<endl;
    showAvailableRooms(); 

    int requestedRooms;
    do{
        cout<<"Enter number of rooms to book (max " <<availableRoomsCount<< "): ";
        cin>>requestedRooms;

        if(requestedRooms>availableRoomsCount){
            cout <<"Sorry! Only " <<availableRoomsCount<< " rooms are available"<<endl;
        }
    }while(requestedRooms > availableRoomsCount); 

    (*cPtr).numRooms = requestedRooms;

    cout<<"Enter Customer ID: ";
    cin>>(*cPtr).id;

    int bookedRooms = 0;
    (*cPtr).totalBill = 0;

    for(int i = 0; i<(*cPtr).numRooms; i++){
        int roomNumber, roomIndex;
        cout<<"Enter room number " <<(i + 1)<<" : ";
        cin>>roomNumber;
        if(isRoomAvailable(roomNumber, roomIndex)){
            (*cPtr).roomNo[bookedRooms] = roomNumber;
            rooms[roomIndex].isAvailable = false; 
            (*cPtr).totalBill += rooms[roomIndex].price;
            bookedRooms++;
        }
		else{
            cout<<"Room " << roomNumber <<" is not available. Choose another one"<<endl;
            i--; 
        }
    }

    (*cPtr).numRooms = bookedRooms;

    cout<<"Enter the number of days: ";
    cin>>(*cPtr).days;
    cout<<"Enter extra charges: ";
    cin>>(*cPtr).extraCharges;
    (*cPtr).totalBill = ((*cPtr).totalBill * (*cPtr).days) + (*cPtr).extraCharges;
    generateReceipt(*cPtr);
    customerCount++; 
}

void generateReceipt(Customer c){
    cout<<"RECEIPT"<<endl;
    cout<<"Customer ID: " << c.id<<endl;
    cout<<"Rooms Booked: ";
    for(int i = 0; i<c.numRooms; i++){
        cout<<" "<<c.roomNo[i];
    }
    cout<<"Days: " <<c.days<<endl;
    cout<<"Extra Charges: " <<c.extraCharges<<endl;
    cout<<"Total Bill: " <<c.totalBill<<endl;
}


    
        
       
    
    
    
       
        
        
            
       
        
    
