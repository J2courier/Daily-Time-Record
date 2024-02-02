#include <stdio.h>
#include <conio.h>
#include <windows.h>
#define g gotoxy
#define p printf
//Initialization
int emp = 1, day = 1, des = 1, twh = 0, tl = 0, tu = 0, undertime_hrs, undertime_min;
int late, late_hours, late_min, undertime, hrs_work, hrs_work_hrs, hrs_work_min, ti, to;
int time_out_hrs, time_out_min;
char ans[5];
//gotoxy for structural purpose
void gotoxy(int x, int y) {
  COORD coord;
  coord.X = x - 1; // Adjust for zero-based indexing
  coord.Y = y - 1; // Adjust for zero-based indexing
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//user defined function
void hoursWork(){
    hrs_work = 240 - late - undertime;
    hrs_work_hrs = hrs_work / 60; 
    hrs_work_min = hrs_work % 60;
}

void day_display(){
    if (day == 1){
        g(2, 14);p("DAY %d", day);
    }
    if (day == 2){
         g(2, 15);p("DAY", day);
    }
    if (day == 3){
    g(2, 16);p("DAY", day);
   }
    if (day == 4){
        g(2, 17);p("DAY", day);
    }
    if (day == 5){
        g(2, 18);p("DAY", day);
    }
}

void display_description(){
    g(25, 8);p("EMPLOYEE:");
    g(35, 8);p("%d", emp);
    g(25, 9);p("PAYROLL FOR THE WEEK");
    g(25, 10);p("DAILY TIME RECORD");
    g(2, 13);p("DAYS");
    g(10, 13);p("AM IN");
    g(20, 13);p("AM OUT");
    g(30, 13);p("HRS WORK");
    g(40, 13);p("LATES");
    g(50, 13);p("UNDERTIME");
}

void timeIn (){
    //we meed to get the time in of the employee by getting the hours in 00: and minutes in 00, 00:00
    //we need to convert the time in that is in hours form into minutes using the formula x = hours in * 60 + minutes in
    int time_in_hrs, time_in_min, late, to;
    g(2, 5);printf("Time in: \n");
    g(15, 5);printf(":");
    g(21, 5);printf("\n"); 
    g(13,5);scanf("%d", &time_in_hrs);
    g(16,5);scanf("%d", &time_in_min);
    int time_out_hrs, time_out_min;
    ti = time_in_hrs * 60 + time_in_min;
    if (ti > 570 && ti < 721)
    {
        g(2, 6);printf("Time out:\n");
        g(13, 6);printf("00:00");
        g(14, 6);printf("\n"); 
        g(20, 8);p("EMPLOYEE:");
        g(35, 8);p("%d", emp);
        g(20, 9);p("PAYROLL FOR THE WEEK");
        g(20, 10);p("DAILY TIME RECORD");
        g(2, 13);p("DAYS");
        g(2, 14);p("DAY %d", day);
        g(10, 13);p("AM IN");
        g(11, 14);p("0:0");
        g(20, 13);p("AM OUT");
        g(21, 14);p("0:0");
        g(30, 13);p("HRS WORK");
        g(31, 14);p("0:0");
        g(40, 13);p("LATES");    
        g(41, 14);p("4:0");
        g(50, 13);p("UNDERTIME");
        g(51, 14);p("0:0");
    }
    if (ti > 299 && ti < 451)//NOT LATE
    {
        late = 0;
    }
    if (ti > 450 && ti < 721)//LATE
    {   
        late = ti - 450; 
    }
}   
void timeOut(){
        g(2, 6);printf("Time out:\n");
        g(15, 6);printf(":");
        g(14, 6);printf("\n"); 
        g(13, 6);scanf("%d", &time_out_hrs);
        g(16, 6);scanf("%d", &time_out_min);
        to = time_out_hrs * 60 + time_out_min;
        if (to > 689 && to < 721)
        {
            undertime = 0;
        }
        if (to < 960)
        {
            undertime = 690 - to;
        }
        if (undertime >= 0 && undertime <= 240)
        {
            undertime_hrs = undertime / 60;
            undertime_min = undertime % 60;
        }
}
int main (){
    while (emp == 1){
    timeIn();
    timeOut();
    display_description();
    day_display();
    emp ++;
    day ++;
    }   
}