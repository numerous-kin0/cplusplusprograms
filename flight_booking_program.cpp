#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//Prints an array that displays plane seats.
void printFormat(string arr[][6]);

//Prints array that displays plane seats
void printFormat(string arr2[][6]);

//Registers the users name
void getName(string & fullName);

//Prints the flight ticket for the user
void displayTicket(string name, string tClass, int dTime, int aTime, string s, int price);

//Stores the flight time slots the user booked
void storeTime(int & option, int & departTime, int & arriveTime,
               int & num1,int & num2, int & num3, int & num4, int & num5);

//Prints the times for plane departure and arrival
void departureArrival(int & option);

//Decides whether seat is first class or economy
void decision(string arr[][6], string arr2[][6], int option,
              int aTime, int & price, string & ticketSeat, string & seat);

//Prints the how many times each time slot was booked.
void printBookings(int n1, int n2, int n3, int n4, int n5);

int main()
{
  int n, dTime, aTime, n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0;
  string arr[4][6], arr2[5][6];
  string fullName, ticketS, seat;
  int option, p;
  char answer;

    do
    {
        getName(fullName);

        departureArrival(option);

        storeTime(option, dTime, aTime, n1, n2, n3, n4, n5);

        decision(arr, arr2, option, dTime, p, ticketS,seat);

        displayTicket(fullName, ticketS, dTime, aTime, seat, p);

        cout << "Do want to book another ticket(Y/N)?" << endl;
        cin >> answer;
        fullName = "";
        cin.get();
    } while((answer == 'Y') || (answer == 'y'));
    cout << endl;
    printBookings(n1, n2, n3, n4, n5);

  return 0;
}
void getName(string & fullName)
{
    char name[20];
    int count = 0;

    cout << "Enter your full name: " << endl;
    cin.getline(name, 20);

    while(name[count] != '\0')
    {
         fullName += name[count];
         count++;
    }
}
// The original array which will  be displayed to show the user the plane's seats.
void printFormat(string arr[][6])
{
   string s;
   char letter = 'A';
   int col = 0, setf = 0;
   for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 6; j++) {
            s = "";
            col++;
            s += letter;
            s += to_string(col);
            arr[i][j] = s;
            cout << "|" << arr[i][j];
                if(col % 3 == 0) {
                    if(setf == 0) {
                        cout << "|" << "----";
                        setf = 1;
                    } else {
                        letter = letter + 1;
                        setf = 0;
                        col = 0;
                    }
                }
        }
        cout << "|" << endl;
    }
}
void printFormat2(string arr2[][6])
{
   string s;
   int col = 0, setf = 0;
   char letter = 'E';
   char answer;
   int seat = 6;

   for(int i = 0; i < 5; i++) {
        if(i == 4)
            seat = 2;
        for(int j = 0; j < seat; j++) {
            s = "";
            col++;
            s += letter;
            s += to_string(col);
            arr2[i][j] = s;
            cout << "|" << arr2[i][j];
                if(col % 3 == 0) {
                    if(setf == 0) {
                        cout << "|" << "----";
                        setf = 1;
                    } else {
                        letter = letter + 1;
                        setf = 0;
                        col = 0;
                    }
                }
        }
        cout << "|" << endl;
    }
}
void departureArrival(int & option)
{
    using namespace std;

    int dTime = 5;
    int aTime = 7;

    cout << "The available travel ";
    cout << "times for flights are: " << endl;
    cout << "    Depart\t" << "Arrival" << endl;

    // Displays the available times
    for(int i = 1; i <= 5; i++)
    {
        cout << i << ".  " << (dTime+= 2) << ":00\t";
        cout << (aTime+=2) << ":30" << endl;
    }
    do
    {
      cout << "Choose the time by entering the option ";
      cout << "number from the displayed list: " << endl;
      cin >> option;
        if((option <= 0) || (option > 5))
        {
            cout << "Incorrect option! Please choose from 1-5." << endl << endl;
        }
    } while((option <= 0) || (option > 5));
}
void storeTime(int & option, int & departTime, int & arriveTime,
               int & num1, int & num2, int & num3, int & num4, int & num5)
{
    /* These variables will store the
    amount of passengers for each time interval
    */
    if(option == 1) {
        departTime = 7;
        arriveTime = 9;
        num1++;
    } else if(option == 2) {
        departTime = 9;
        arriveTime = 11;
        num2++;
    } else if(option == 3) {
        departTime = 11;
        arriveTime = 13;
        num3++;
    } else if(option == 4) {
        departTime = 13;
        arriveTime = 15;
        num4++;
    } else if(option == 5) {
        departTime = 15;
        arriveTime = 17;
        num5++;
    }
}
void decision(string arr[][6], string arr2[][6], int option,
              int dTime, int & price, string & ticketSeat, string & seat)
{
    const double price1 = 1920.00;
    const double price2 = 1600.00;
    int con = 6;

    if(option == 1) {
        cout << "The available seats for " << dTime;
        cout << ":00 are as follows:" << endl << endl;
        cout << "First class(" << price1 << ")" << endl;
        printFormat(arr);
        cout << "Second class(" << price2 << ")" << endl;
        printFormat2(arr2);
        cout << endl;
        cout << "Enter the seat you want to book: ";
        cin >> seat;

        cout << "First class(" << price1 << ")" << endl;
        for(int i = 0; i < 4; i++)
        {
            cout << "|";
                for(int j = 0 ; j < 6; j++)
                {
                    if(arr[i][j] == seat) {
                        arr[i][j] = "**";
                        price = 1920;
                        ticketSeat = "First class";
                    }
                    cout << arr[i][j] << "|";
                        if(j == 3)
                            cout << "----|";
                }
                cout << endl;
        }
        cout << "Economy(" << price2 << ")" << endl;
        for(int x = 0; x < 5; x++)
        {
            if(x == 4)
                con = 2;
            cout << "|";
                for(int v = 0 ; v < con; v++)
                {
                    if(arr2[x][v] == seat) {
                        arr2[x][v] = "**";
                        price = 1600;
                        ticketSeat = "Economy class";
                    }
                    cout << arr2[x][v] << "|";
                        if(v == 3)
                            cout << "----|";
                }
                cout << endl;
        }

    } else if(option == 2) {
        cout << "The available seats for " << dTime;
        cout << ":00 are as follows:" << endl << endl;
        cout << "First class(" << price1 << ")" << endl;
        printFormat(arr);
        cout << "Second class(" << price2 << ")" << endl;
        printFormat2(arr2);
        cout << endl;
        cout << "Enter the seat you want to book: ";
        cin >> seat;

        cout << "First class(" << price1 << ")" << endl;
        for(int i = 0; i < 4; i++)
        {
            cout << "|";
                for(int j = 0 ; j < 6; j++)
                {
                    if(arr[i][j] == seat) {
                        arr[i][j] = "**";
                        price = 1920;
                        ticketSeat = "First class";
                    }
                    cout << arr[i][j] << "|";
                        if(j == 3)
                            cout << "----|";
                }
                cout << endl;
        }
        cout << "Economy(" << price2 << ")" << endl;
            for(int x = 0; x < 5; x++)
            {
                if(x == 4)
                    con = 2;
                cout << "|";
                for(int v = 0 ; v < con; v++)
                {
                    if(arr2[x][v] == seat) {
                        arr2[x][v] = "**";
                        price = 1600;
                        ticketSeat = "Economy class";
                    }
                    cout << arr2[x][v] << "|";
                        if(v == 3)
                            cout << "----|";
                }
                cout << endl;


            }
        } else if(option == 3) {
            cout << "The available seats for " << dTime;
        cout << ":00 are as follows:" << endl << endl;
        cout << "First class(" << price1 << ")" << endl;
        printFormat(arr);
        cout << "Second class(" << price2 << ")" << endl;
        printFormat2(arr2);
        cout << endl;
        cout << "Enter the seat you want to book: ";
        cin >> seat;

        cout << "First class(" << price1 << ")" << endl;
        for(int i = 0; i < 4; i++)
        {
            cout << "|";
                for(int j = 0 ; j < 6; j++)
                {
                    if(arr[i][j] == seat) {
                        arr[i][j] = "**";
                        price = 1920;
                        ticketSeat = "First class";
                    }
                    cout << arr[i][j] << "|";
                        if(j == 3)
                            cout << "----|";
                }
                cout << endl;
        }
        cout << "Economy(" << price2 << ")" << endl;
        for(int x = 0; x < 5; x++)
        {
            if(x == 4)
                con = 2;
            cout << "|";
                for(int v = 0 ; v < con; v++)
                {
                    if(arr2[x][v] == seat) {
                        arr2[x][v] = "**";
                        price = 1600;
                        ticketSeat = "Economy class";
                    }
                    cout << arr2[x][v] << "|";
                        if(v == 3)
                            cout << "----|";
                }
                cout << endl;
        }
        } else if(option == 4) {
            cout << "The available seats for " << dTime;
        cout << ":00 are as follows:" << endl << endl;
        cout << "First class(" << price1 << ")" << endl;
        printFormat(arr);
        cout << "Economy(" << price2 << ")" << endl;
        printFormat2(arr2);
        cout << endl;
        cout << "Enter the seat you want to book: ";
        cin >> seat;

        cout << "First class(" << price1 << ")" << endl;
        for(int i = 0; i < 4; i++)
        {
            cout << "|";
                for(int j = 0 ; j < 6; j++)
                {
                    if(arr[i][j] == seat) {
                        arr[i][j] = "**";
                        price = 1920;
                        ticketSeat = "First class";
                    }
                    cout << arr[i][j] << "|";
                        if(j == 3)
                            cout << "----|";
                }
                cout << endl;
        }
        cout << "Economy(" << price2 << ")" << endl;
        for(int x = 0; x < 5; x++)
        {
            if(x == 4)
                con = 2;
            cout << "|";
                for(int v = 0 ; v < con; v++)
                {
                    if(arr2[x][v] == seat) {
                        arr2[x][v] = "**";
                        price = 1600;
                        ticketSeat = "Economy class";
                    }
                    cout << arr2[x][v] << "|";
                        if(v == 3)
                            cout << "----|";
                }
                cout << endl;

        }
        } else if(option == 5) {
           cout << "The available seats for " << dTime;
        cout << ":00 are as follows:" << endl << endl;
        cout << "First class(" << price1 << ")" << endl;
        printFormat(arr);
        cout << "Economy(" << price2 << ")" << endl;
        printFormat2(arr2);
        cout << endl;
        cout << "Enter the seat you want to book: ";
        cin >> seat;

        cout << "First class(" << price1 << ")" << endl;
        for(int i = 0; i < 4; i++)
        {
            cout << "|";
                for(int j = 0 ; j < 6; j++)
                {
                    if(arr[i][j] == seat) {
                        arr[i][j] = "**";
                        price = 1920;
                        ticketSeat = "First class";
                    }
                    cout << arr[i][j] << "|";
                        if(j == 3)
                            cout << "----|";
                }
                cout << endl;
        }
        cout << "Economy(" << price2 << ")" << endl;
        for(int x = 0; x < 5; x++)
        {
            if(x == 4)
                con = 2;
            cout << "|";
                for(int v = 0 ; v < con; v++)
                {
                    if(arr2[x][v] == seat) {
                        arr2[x][v] = "**";
                        price = 1600;
                        ticketSeat = "Economy class";
                    }
                    cout << arr2[x][v] << "|";
                        if(v == 3)
                            cout << "----|";
                }
                cout << endl;
        }
    }
}
void displayTicket(string name, string tClass, int dTime, int aTime, string s, int price)
{
   cout << "************************" << endl;
   cout << "Travel ticket for Flight" << endl;
   cout << "************************" << endl;
   cout << "Name" << setw(13) << ":  " << name;
   cout << setw(24) << "Travel Ticket class";
   cout << setw(2) << ":  " << tClass << endl;
   cout << setw(39) << "Seat No";
   cout << setw(13) << ":" << setw(4) << s << endl;
   cout << "Departure" << setw(8) << ":  ";
   cout << "Johannesburg" << setw(17) << "Departure Time";
   cout << setw(8) << ":  " << dTime << ":00" << endl;
   cout << "Destination" << setw(6) << ":  ";
   cout << "Cape Town" << setw(18) << "Arrival Time";
   cout<< setw(10) << ":  " << aTime << ":30" << endl;
   cout << "*********************" << endl;
   cout << "Amount: R" << price << ".00 Thank you for booking with COS1511.";
   cout << "Your travel agent is Annie Mathew" << endl;
   cout << "*********************" << endl;

}
void printBookings(int n1, int n2, int n3, int n4, int n5)
{
  cout << "Number of bookings made for 7:00 a.m:" << n1 << endl;
  cout << "Number of bookings made for 9:00 a.m:" << n2 << endl;
  cout << "Number of bookings made for 11:00 a.m:" << n3 << endl;
  cout << "Number of bookings made for 13:00 a.m:" << n4 << endl;
  cout << "Number of bookings made for 15:00 a.m:" << n5 << endl;
}
