#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#define g gotoxy
#define p printf
#define s scanf
//global variable:
int employee = 1, day = 5, description = 1, ti , to;//para sa employee, day, description counter
int totalWorkhours = 0, weeklySalary = 0, total_late = 0; //calculate the work hours, weekly salary, late, kag undertime
int total_work_hours = 0, total_undertime = 0, weekly_salary = 0;
int late = 0, undertime = 0, hrs_work = 0, total_hrs_work = 0, final_hrs_work = 0;
//variable for convertion
int total_late_hrs, total_late_min, total_undertime_hrs, total_undertime_min;
int final_hrs_work_hrs, final_hrs_work_min, final_late_hrs, final_late_min;  
int undertime_hrs, undertime_min, undertime_in_hrs;
int ttl_late_min, ttl_undertime_hrs, tttl_undertime_min;
int time_in_hrs, time_in_min, time_out_hrs, time_out_min;
int ttl_work_hrs, ttl_work_min, ttl_late_hrs;
int ttl_undertime_min;
int final_undertime_hrs, final_undertime_min;
int late_in_hrs, late_in_min, udertime_in_hrs, undertime_in_min;
int hrs_work_hrs, hrs_work_min;
char ans;
void gotoxy(int x, int y){
    COORD coord;
    coord.X = x - 1;
    coord.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void delete(){
    for (int del = 1; del < 6; del ++){
        g(10, 13 + day);p("  ");
        g(11, 13 + day);p(":");
        g(12, 13 + day);p("  ");
        g(20, 13 + day);p("  ");
        g(22, 13 + day);p(":");
        g(23, 13 + day);p("  ");
        g(31, 13 + day);p("  ");
        g(32, 13 + day);p(":");
        g(33, 13 + day);p("  ");
        g(41, 13 + day);p("  ");
        g(42, 13 + day);p(":");
        g(43, 13 + day);p("  ");
        g(51, 13 + day);p("  ");
        g(52, 13 + day);p(":");
        g(53, 13 + day);p(" ");
    }
       
}
void display_for_late(){
    g(11, 14);
    p("0:0");
    g(21, 14);
    p("0:0");
    g(31, 14);
    p("0:0");
    g(51, 14);
    p("0:0");
}
void display_total(){
    g(13, 20);p("total:");
    g(21, 20);p("%d", final_hrs_work_hrs);
    g(22, 20);p(":");
    g(23, 20);p("%d", final_hrs_work_min);
    g(27, 20);p("total:");
    g(35, 20);p("%d", total_late_hrs);
    g(36, 20);p(":");
    g(37, 20);p("%d", total_late_min);
    g(43, 20);p("total:");
    g(51, 20);p("%d", total_undertime_hrs);
    g(52, 20);p(":");
    g(53, 20);p("%d", total_undertime_min);
    g(2, 21);p("Total HW: ");
    g(14, 21);p("%d", final_hrs_work_hrs);
    g(15, 21);p(":");
    g(16, 21);p("%d", final_hrs_work_min);
    g(2, 22);p("Total LATE: ");
    g(14, 22);p("%d", final_late_hrs);
    g(15, 22);p(":");
    g(16, 22);p("%d", final_late_min);
    g(2, 23);p("Total UNDERTIME: ");
    g(21, 23);p("%d", final_undertime_hrs);
    g(22, 23);p(":");
    g(23, 23);p("%d", final_undertime_min);
    g(27, 21);p("Salar Per week:%d", weekly_salary);
    back:
    g(27, 23);p("ANOTHER EMPLOYEE? ");
    g(45, 23);s("%c", &ans);
    if (ans == 'n' || ans == 'n'){
        g(2, 24);p("ARE YOU SURE YOU WANT TO EXIT? (y/n) ");
        g(25, 24);s("%c", &ans);
        if (ans == 'Y' || ans == 'y'){
            system("cls");
            exit(0);
        } else {
            g(2, 24);p("                                      ");
            goto back;
        }
    }
}
void display_description(){
    g(25, 8);p("EMPLOYEE:");
    g(35, 8);p("%d", employee);
    g(25, 9);p("PAYROLL FOR THE WEEK");
    g(25, 10);p("DAILY TIME RECORD");
    g(2, 13);p("days");
    g(10, 13);p("AM IN");
    g(20, 13);p("AM OUT");
    g(30, 13);p("HRS WORK");
    g(40, 13);p("LATES");
    g(50, 13);p("UNDERTIME");
}
void timeIn_timeOut(){
    display_description();
    loop:
    for (day = 1; day < 6; day ++){
        time_in_again:
        g(2, 5);printf("Time in: \n");
        g(15, 5);printf(":");
        g(21, 5);printf("\n");
        g(2, 6);printf("Time out:\n");
        g(15, 6);printf(":");
        g(14, 6);printf("\n");
        g(13, 5);scanf("%d", &time_in_hrs);
        g(16, 5);scanf("%d", &time_in_min);
        g(2, 7);printf("                 ");
        ti = time_in_hrs * 60 + time_in_min;
        if (time_in_hrs > 4 && time_in_hrs < 13 && time_in_min > -1 && time_in_min < 60){
            if (ti > 570 && ti < 721){
                if (day < 6){//ma stop lang ni sya display if naka 5 day na
                    late = 0;
                    undertime = 0;
                    hrs_work = 0;
                    total_hrs_work = total_hrs_work + hrs_work;            
                    total_undertime = total_undertime + undertime; //
                    //final_hrs_work = total_late + final_hrs_work;
                    final_hrs_work_hrs = final_hrs_work / 60; 
                    final_hrs_work_min = final_hrs_work % 60;
                    total_late_hrs = total_late / 60;
                    total_late_min = total_late % 60;
                    //final_late_hrs = total_late_hrs + final_late_hrs;
                    //final_late_min = total_late_min + final_late_min;
                    total_undertime_hrs = total_undertime / 60;
                    total_undertime_min = total_undertime % 60;
                    //final_undertime_hrs = total_undertime_hrs + final_undertime_hrs;
                    //final_undertime_min = total_undertime_min + final_undertime_min;
                    g(10, 13);p("AM IN");
                    g(11, 13 + day);p("0:0");
                    g(20, 13);p("AM OUT");
                    g(21, 13 + day);p("0:0");
                    g(30, 13);p("HRS WORK");
                    g(31, 13 + day);p("0:0");
                    g(40, 13);p("LATES");
                    g(41, 13 + day);p("4:0");
                    g(50, 13);p("UNDERTIME");
                    g(51, 13 + day);p("0:0");
                    g(13, 5);printf("  ");
                    g(16, 5);printf("  ");
                    g(13, 6);printf("  ");
                    g(16, 6);printf("  ");
                    g(2, 13+day); p("day %d", day);
                    day++;
                    if (day == 6){
                        display_total();
                        break;
                    }
                    goto time_in_again;
                } 
            } 
            g(13, 6);
            scanf("%d", &time_out_hrs);
            g(16, 6);
            scanf("%d", &time_out_min);
            to = time_out_hrs * 60 + time_out_min;
            if (ti > 299 && ti < 451 && to > 689 && to < 721 ){ // scenario 2.0 no late no undertime
                late = 0;
                undertime = 0;
                //convert
                undertime_in_hrs = undertime / 60;
                undertime_in_min = undertime % 60;
                //convert ta man ang late
                late_in_hrs = late / 60;
                late_in_min = late % 60;
                //same man sa hours work
                hrs_work = 240 - undertime - late;
                hrs_work_hrs = hrs_work / 60;
                hrs_work_min = hrs_work % 60;
                //stack
                total_hrs_work = total_hrs_work + hrs_work;    
                total_late = total_late + late;                
                total_undertime = total_undertime + undertime;
                final_hrs_work = total_late + final_hrs_work;
                //convertion f
                final_hrs_work_hrs = final_hrs_work / 60;
                final_hrs_work_min = final_hrs_work % 60;
                //converetion f
                total_late_hrs = total_late / 60;
                total_late_min = total_late % 60;
                //convertion f
                final_late_hrs = total_late_hrs + final_late_hrs;
                final_late_min = total_late_min + final_late_min;
                //convertion f
                total_undertime_hrs = total_undertime / 60;
                total_undertime_min = total_undertime % 60;
                //convertion f
                final_undertime_hrs = total_undertime_hrs + final_undertime_hrs;
                final_undertime_min = total_undertime_min + final_undertime_min;
                if (day < 6){
                    g(10, 13 + day);p("%d", time_in_hrs);
                    g(11, 13 + day);p(":");
                    g(12, 13 + day);p("%d", time_in_min);
                    g(20, 13 + day);p("%d", time_out_hrs);
                    g(22, 13 + day);p(":");
                    g(23, 13 + day);p("%d", time_out_min);
                    g(31, 13 + day);p("%d", hrs_work_hrs);
                    g(32, 13 + day);p(":");
                    g(33, 13 + day);p("%d", hrs_work_min);
                    g(41, 13 + day);p("%d", late_in_hrs);
                    g(42, 13 + day);p(":");
                    g(43, 13 + day);p("%d", late_in_min);
                    g(51, 13 + day);p("%d", undertime_in_hrs);
                    g(52, 13 + day);p(":");
                    g(53, 13 + day);p("%d", undertime_in_min);
                    g(13, 5);printf("  ");
                    g(16, 5);printf("  ");
                    g(13, 6);printf("  ");
                    g(16, 6);printf("  ");
                    g(2, 13 + day); p("day %d", day);
                    day ++;
                    if (day == 6){
                        display_total();
                        break;
                    }
                    goto time_in_again;
                }
            }
            if (ti > 299 && ti < 451 && to > 539 && to < 721){ //scenario 2.1 no late with udertime
                late = ti - 450; 
                undertime = 690 - to;
                undertime_in_hrs = undertime / 60;
                undertime_in_min = undertime % 60;
                //convert ta man ang late
                late_in_hrs = late / 60;
                late_in_min = late % 60;
                //same man sa hours work
                hrs_work = 240 - undertime - late;
                hrs_work_hrs = hrs_work / 60;
                hrs_work_min = hrs_work % 60;
                //stack
                total_hrs_work = total_hrs_work + hrs_work;    
                total_late = total_late + late;                
                total_undertime = total_undertime + undertime;
                final_hrs_work = total_late + final_hrs_work;
                //convertion f
                final_hrs_work_hrs = final_hrs_work / 60;
                final_hrs_work_min = final_hrs_work % 60;
                //converetion f
                total_late_hrs = total_late / 60;
                total_late_min = total_late % 60;
                //convertion f
                final_late_hrs = total_late_hrs + final_late_hrs;
                final_late_min = total_late_min + final_late_min;
                //convertion f
                total_undertime_hrs = total_undertime / 60;
                total_undertime_min = total_undertime % 60;
                //convertion f
                final_undertime_hrs = total_undertime_hrs + final_undertime_hrs;
                final_undertime_min = total_undertime_min + final_undertime_min;
                if (day < 6){
                    g(10, 13 + day);p("%d", time_in_hrs);
                    g(11, 13 + day);p(":");
                    g(12, 13 + day);p("%d", time_in_min);
                    g(20, 13 + day);p("%d", time_out_hrs);
                    g(22, 13 + day);p(":");
                    g(23, 13 + day);p("%d", time_out_min);
                    g(31, 13 + day);p("%d", hrs_work_hrs);
                    g(32, 13 + day);p(":");
                    g(33, 13 + day);p("%d", hrs_work_min);
                    g(41, 13 + day);p("%d", late_in_hrs);
                    g(42, 13 + day);p(":");
                    g(43, 13 + day);p("%d", late_in_min);
                    g(51, 13 + day);p("%d", undertime_in_hrs);
                    g(52, 13 + day);p(":");
                    g(53, 13 + day);p("%d", undertime_in_min);
                    g(13, 5);printf("  ");
                    g(16, 5);printf("  ");
                    g(13, 6);printf("  ");
                    g(16, 6);printf("  ");
                    g(2, 13 + day); p("day %d", day);
                    day ++;
                    if (day == 6){
                        display_total();
                        break;
                    }
                    goto time_in_again;
                }
            }
            if (ti > 299 && ti < 571 && to > 689 && to < 721){ //scenario 3.0 with late with no udertime
                late = ti - 450; 
                undertime = 0;
                undertime_in_hrs = undertime / 60;
                undertime_in_min = undertime % 60;
                //convert ta man ang late
                late_in_hrs = late / 60;
                late_in_min = late % 60;
                //same man sa hours work
                hrs_work = 240 - late;
                hrs_work_hrs = hrs_work / 60;
                hrs_work_min = hrs_work % 60;
                //stack
                total_hrs_work = total_hrs_work + hrs_work;    
                total_late = total_late + late;                
                total_undertime = total_undertime + undertime;
                final_hrs_work = total_late + final_hrs_work;
                //convertion f
                final_hrs_work_hrs = final_hrs_work / 60;
                final_hrs_work_min = final_hrs_work % 60;
                //converetion f
                total_late_hrs = total_late / 60;
                total_late_min = total_late % 60;
                //convertion f
                final_late_hrs = total_late_hrs + final_late_hrs;
                final_late_min = total_late_min + final_late_min;
                //convertion f
                total_undertime_hrs = total_undertime / 60;
                total_undertime_min = total_undertime % 60;
                //convertion f
                final_undertime_hrs = total_undertime_hrs + final_undertime_hrs;
                final_undertime_min = total_undertime_min + final_undertime_min;
                if (day < 6){
                    g(10, 13 + day);p("%d", time_in_hrs);
                    g(11, 13 + day);p(":");
                    g(12, 13 + day);p("%d", time_in_min);
                    g(20, 13 + day);p("%d", time_out_hrs);
                    g(22, 13 + day);p(":");
                    g(23, 13 + day);p("%d", time_out_min);
                    g(31, 13 + day);p("%d", hrs_work_hrs);
                    g(32, 13 + day);p(":");
                    g(33, 13 + day);p("%d", hrs_work_min);
                    g(41, 13 + day);p("%d", late_in_hrs);
                    g(42, 13 + day);p(":");
                    g(43, 13 + day);p("%d", late_in_min);
                    g(51, 13 + day);p("%d", undertime_in_hrs);
                    g(52, 13 + day);p(":");
                    g(53, 13 + day);p("%d", undertime_in_min);
                    g(13, 5);printf("  ");
                    g(16, 5);printf("  ");
                    g(13, 6);printf("  ");
                    g(16, 6);printf("  ");
                    g(2, 13 + day); p("day %d", day);
                    day ++;
                    if (day == 6){
                        display_total();
                        break;
                    }
                    goto time_in_again;
                }
            }
            if (ti > 299 && ti < 571 && to > 539 && to < 721){ //scenario 3.1 late with udertime
                late = ti - 450; //240 is 4 hours
                undertime = 690 - to;
                undertime_in_hrs = undertime / 60;
                undertime_in_min = undertime % 60;
                //convert ta man ang late
                late_in_hrs = late / 60;
                late_in_min = late % 60;
                //same man sa hours work
                hrs_work = 240 - undertime - late;
                hrs_work_hrs = hrs_work / 60;
                hrs_work_min = hrs_work % 60;
                //stack
                total_hrs_work = total_hrs_work + hrs_work;    
                total_late = total_late + late;                
                total_undertime = total_undertime + undertime;
                final_hrs_work = total_late + final_hrs_work;
                //convertion f
                final_hrs_work_hrs = final_hrs_work / 60;
                final_hrs_work_min = final_hrs_work % 60;
                //converetion f
                total_late_hrs = total_late / 60;
                total_late_min = total_late % 60;
                //convertion f
                final_late_hrs = total_late_hrs + final_late_hrs;
                final_late_min = total_late_min + final_late_min;
                //convertion f
                total_undertime_hrs = total_undertime / 60;
                total_undertime_min = total_undertime % 60;
                //convertion f
                final_undertime_hrs = total_undertime_hrs + final_undertime_hrs;
                final_undertime_min = total_undertime_min + final_undertime_min;
                if (day < 6){
                    g(10, 13 + day);p("%d", time_in_hrs);
                    g(11, 13 + day);p(":");
                    g(12, 13 + day);p("%d", time_in_min);
                    g(20, 13 + day);p("%d", time_out_hrs);
                    g(22, 13 + day);p(":");
                    g(23, 13 + day);p("%d", time_out_min);
                    g(31, 13 + day);p("%d", hrs_work_hrs);
                    g(32, 13 + day);p(":");
                    g(33, 13 + day);p("%d", hrs_work_min);
                    g(41, 13 + day);p("%d", late_in_hrs);
                    g(42, 13 + day);p(":");
                    g(43, 13 + day);p("%d", late_in_min);
                    g(51, 13 + day);p("%d", undertime_in_hrs);
                    g(52, 13 + day);p(":");
                    g(53, 13 + day);p("%d", undertime_in_min);
                    g(13, 5);printf("  ");
                    g(16, 5);printf("  ");
                    g(13, 6);printf("  ");
                    g(16, 6);printf("  ");
                    g(2, 13 + day); p("day %d", day);
                    day ++;
                    if (day == 6){
                        display_total();
                        break;
                    }
                    goto time_in_again;
                }
            } else {
                g(13, 5);printf("  ");
                g(16, 5);printf("  ");
                g(13, 6);printf("  ");
                g(16, 6);printf("  ");
                g(13, 5);printf("  ");
                g(2, 7);printf("INVALID INPUT");
                goto time_in_again;
            }
        } else {
            g(13, 5);printf("  ");
            g(16, 5);printf("  ");
            g(13, 6);printf("  ");
            g(16, 6);printf("  ");
            g(13, 5);printf("  ");
            g(2, 7);printf("INVALID INPUT");
            goto time_in_again;
        }
    }
}
int main(){
    system("cls");
    do {
        display_description();
        timeIn_timeOut();   
        display_total();
        another_employee:
        employee += 1;
        system("cls");
    } while (ans == 'Y' || ans == 'y');
    system("cls");//amo ni sya ang syntax sang clear screen sa vs code, magana lang ni sa kung may header file nga <windows.h>
    exit(0);
}
