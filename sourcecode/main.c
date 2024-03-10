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
int ttl_late_min = 0, ttl_undertime_hrs = 0, tttl_undertime_min;
int time_in_hrs, time_in_min, time_out_hrs, time_out_min;
int ttl_work_hrs = 0, ttl_work_min = 0, ttl_late_hrs;
int ttl_undertime_min = 0;
int final_undertime_hrs, final_undertime_min;
int late_in_hrs, late_in_min, udertime_in_hrs, undertime_in_min;
int hrs_work_hrs, hrs_work_min;
char ans;

//notesss: tanan nga may Division kag Modulo nga sign gina convert ina from hours to mins basically daw gina disect naton ang o'clock form
//notesss: comment lang diri sa top if may gusto kamo e add or gin bag o
//notesss: pwede nyo ni nga e revise para ma try nyo man
//ruleeee: hindi pag e ABBREVIATE ang VARIABLES para dasig ma bal an kung ano ina nga variable (abbreviation e.g TWH, HRH, WS...)
//muna lang salamat!!


//since lain ang visual studio code sa turbo c ma himo ta function para sa gotoxy (source W3school & stackoverflow)
void gotoxy(int x, int y){
    COORD coord;
    coord.X = x - 1;
    coord.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//user define function call by no value sytnax: void variablename (){statements}
//first problem if late ang employer, ma ubra ta separate nga display para sa hrs work, late, undertime, usually if late mean 0 works, late, and undertime.
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
//second ma ubra naman kita fuction para sa pag display sang total sang hrs work, late, undertime, kag salary
void display_total(){
    g(13, 20);
    p("total:");
    g(21, 20);
    p("%d", final_hrs_work_hrs);
    g(22, 20);
    p(":");
    g(23, 20);
    p("%d", final_hrs_work_min);
    g(27, 20);
    p("total:");
    g(35, 20);
    p("%d", total_late_hrs);
    g(36, 20);
    p(":");
    g(37, 20);
    p("%d", total_late_min);
    g(43, 20);
    p("total:");
    g(51, 20);
    p("%d", total_undertime_hrs);
    g(52, 20);
    p(":");
    g(53, 20);
    p("%d", total_undertime_min);
    g(2, 21);
    p("Total HW: ");
    g(14, 21);
    p("%d", final_hrs_work_hrs);
    g(15, 21);
    p(":");
    g(16, 21);
    p("%d", final_hrs_work_min);
    g(2, 22);
    p("Total LATE: ");
    g(14, 22);
    p("%d", final_late_hrs);
    g(15, 22);
    p(":");
    g(16, 22);
    p("%d", final_late_min);
    g(2, 23);
    p("Total UNDERTIME: ");
    g(21, 23);
    p("%d", final_undertime_hrs);
    g(22, 23);
    p(":");
    g(23, 23);
    p("%d", final_undertime_min);
    g(27, 21);p("Salar Per week:%d", weekly_salary);
    g(27, 23);p("ANOTHER EMPLOYEE? (y/n) ");
    g(43, 23);s("%c", &ans);
}
//ma ubra naman liwat kita function ma display na isahan ng description
void display_description(){
    g(25, 8);
    p("EMPLOYEE:");
    g(35, 8);
    p("%d", employee);
    g(25, 9);
    p("PAYROLL FOR THE WEEK");
    g(25, 10);
    p("DAILY TIME RECORD");
    g(2, 13);
    p("days");
    g(10, 13);
    p("AM IN");
    g(20, 13);
    p("AM OUT");
    g(30, 13);
    p("HRS WORK");
    g(40, 13);
    p("LATES");
    g(50, 13);
    p("UNDERTIME");
}
//ma ubra naman kita liawt function para mag kuha sang time in kag time out sang employee
void timeIn_timeOut(){
    display_description(); //pwede naton ma call out or invoke ang isa ka function as long as na declare sa before sang function nga paga call out naton
    /*goto:*/loop:
    for (day = 1; day < 6; day++){ //loop control para sa entire time in time out sang aton program
/*goto:*/time_in_again:
        g(2, 5);printf("Time in: \n");
        g(15, 5);printf(":");
        g(21, 5);printf("\n");
        g(2, 6);printf("Time out:\n");
        g(15, 6);printf(":");
        g(14, 6);printf("\n");
        g(13, 5);scanf("%d", &time_in_hrs);
        g(16, 5);scanf("%d", &time_in_min);
        g(2, 7);printf("                 ");
        ti = time_in_hrs * 60 + time_in_min; //formula to convert the ti in hours format to min format 7:30hours form is 450minutes form
        if (time_in_hrs > 4 && time_in_hrs < 13 && time_in_min > -1 && time_in_min < 60){//sentinel data
            if (ti> 570 && ti < 721){ //SCENARIO 1 ABSENT
                total_late = total_late + 240; //add naton ang previous nga total anytime kung absent sya because may instances nga mag absent sa 2nd day 3rd day and so on
                if (day < 6){//ma stop lang ni sya display if naka 5 day na
                    late = 0;
                    undertime = 0;
                    hrs_work = 0;
                    total_hrs_work = total_hrs_work + hrs_work;    // in minutes form
                    total_late = total_late + late;                // in minutes form
                    total_undertime = total_undertime + undertime; // in minutes form
                    final_hrs_work = total_late + final_hrs_work;
                    final_hrs_work_hrs = final_hrs_work / 60; 
                    final_hrs_work_min = final_hrs_work % 60;
                    total_late_hrs = total_late / 60;
                    total_late_min = total_late % 60;
                    final_late_hrs = total_late_hrs + final_late_hrs;
                    final_late_min = total_late_min + final_late_min;
                    total_undertime_hrs = total_undertime / 60;
                    total_undertime_min = total_undertime % 60;
                    final_undertime_hrs = total_undertime_hrs + final_undertime_hrs;
                    final_undertime_min = total_undertime_min + final_undertime_min;
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
                    }
                    goto time_in_again;
                } 
            }
            g(13, 6);
            scanf("%d", &time_out_hrs);
            g(16, 6);
            scanf("%d", &time_out_min);
            to = time_out_hrs * 60 + time_out_min;
            if (ti > 299 && ti < 721 && to >  450 && to < 721){
                if (ti > 299 && ti < 451){ // if this condition is true meaning wala sya it late kag undertime
                    if (to > 689 && to < 721){ //SCENARIO 2 NO LATE, NO UNDERTIME
                        //set talang nga 0 para wala conflict
                        late = 0;
                        undertime = 0;
                        //convert ta lang ang undertime sa minutes form
                        undertime_in_hrs = undertime / 60;
                        undertime_in_min = undertime % 60;
                        //convert ta man ang late
                        late_in_hrs = late / 60;
                        late_in_min = late % 60;
                        //same man sa hours work
                        hrs_work = undertime - 240 - late;
                        hrs_work_hrs = hrs_work / 60;
                        hrs_work_min = hrs_work % 60;
                        //e stack naton ang accumulated data sa variables nga ni
                        total_hrs_work = total_hrs_work + hrs_work;    // in minutes form
                        total_late = total_late + late;                // in minutes form
                        total_undertime = total_undertime + undertime; // in minutes form
                        final_hrs_work = total_late + final_hrs_work;
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
                            final_hrs_work_hrs = final_hrs_work / 60;
                            final_hrs_work_min = final_hrs_work % 60;
                            total_late_hrs = total_late / 60;
                            total_late_min = total_late % 60;
                            final_late_hrs = total_late_hrs + final_late_hrs;
                            final_late_min = total_late_min + final_late_min;
                            total_undertime_hrs = total_undertime / 60;
                            total_undertime_min = total_undertime % 60;
                            final_undertime_hrs = total_undertime_hrs + final_undertime_hrs;
                            final_undertime_min = total_undertime_min + final_undertime_min;
                            day ++;
                            if (day == 6){
                                display_total();
                            }
                        goto time_in_again;
                        }
                    }
                    else if (to > 529 && to < 690){ //SCENARIO 2.1 NO LATE WITH UNDERTIME
                        late = 0;
                        undertime = 690 - to;
                        undertime_in_hrs = undertime / 60;
                        undertime_in_min = undertime % 60;
                        late_in_hrs = late / 60;
                        late_in_min = late % 60;
                        hrs_work = undertime - 240 - late;
                        hrs_work_hrs = hrs_work / 60;
                        hrs_work_min = hrs_work % 60;
                        total_hrs_work = total_hrs_work + hrs_work;    // in minutes form
                        total_late = total_late + late;                // in minutes form
                        total_undertime = total_undertime + undertime; // in minutes form
                        final_hrs_work = total_late + final_hrs_work;
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
                            final_hrs_work_hrs = final_hrs_work / 60;
                            final_hrs_work_min = final_hrs_work % 60;
                            total_late_hrs = total_late / 60;
                            total_late_min = total_late % 60;
                            final_late_hrs = total_late_hrs + final_late_hrs;
                            final_late_min = total_late_min + final_late_min;
                            total_undertime_hrs = total_undertime / 60;
                            total_undertime_min = total_undertime % 60;
                            final_undertime_hrs = total_undertime_hrs + final_undertime_hrs;
                            final_undertime_min = total_undertime_min + final_undertime_min;
                            day ++;
                            if (day == 6){
                                display_total();
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
                }
                if (ti > 450 && ti < 571){ //SCENARIO 3 WITH LATE NO UNDERTIME
                    if (to > 689 && to < 721){
                        late = ti - 240;
                        undertime = 0;
                        undertime_in_hrs = undertime / 60;
                        undertime_in_min = undertime % 60;
                        late_in_hrs = late / 60;
                        late_in_min = late % 60;
                        hrs_work = 240 - late;
                        hrs_work_hrs = hrs_work / 60;
                        hrs_work_min = hrs_work % 60;
                        total_hrs_work = total_hrs_work + hrs_work;    // in minutes form
                        total_late = total_late + late;                // in minutes form
                        total_undertime = total_undertime + undertime; // in minutes form
                        final_hrs_work = total_late + final_hrs_work;
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
                            final_hrs_work_hrs = final_hrs_work / 60;
                            final_hrs_work_min = final_hrs_work % 60;
                            total_late_hrs = total_late / 60;
                            total_late_min = total_late % 60;
                            final_late_hrs = total_late_hrs + final_late_hrs;
                            final_late_min = total_late_min + final_late_min;
                            total_undertime_hrs = total_undertime / 60;
                            total_undertime_min = total_undertime % 60;
                            final_undertime_hrs = total_undertime_hrs + final_undertime_hrs;
                            final_undertime_min = total_undertime_min + final_undertime_min;
                            day ++;
                            if (day == 6){
                                display_total();
                            }
                        goto time_in_again;
                        }
                    }
                    else if (to > 529 && to < 689){ //SCENARIO 3.1 WITH LATE WITH UNDERTIME
                        late = ti - 240;
                        undertime = 690 - to;
                        undertime_in_hrs = undertime / 60;
                        undertime_in_min = undertime % 60;
                        late_in_hrs = late / 60;
                        late_in_min = late % 60;
                        hrs_work = undertime - 240 - late;
                        hrs_work_hrs = hrs_work / 60;
                        hrs_work_min = hrs_work % 60;
                        total_hrs_work = total_hrs_work + hrs_work;    // in minutes form
                        total_late = total_late + late;                // in minutes form
                        total_undertime = total_undertime + undertime; // in minutes form
                        final_hrs_work = total_late + final_hrs_work;
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
                            final_hrs_work_hrs = final_hrs_work / 60;
                            final_hrs_work_min = final_hrs_work % 60;
                            total_late_hrs = total_late / 60;
                            total_late_min = total_late % 60;
                            final_late_hrs = total_late_hrs + final_late_hrs;
                            final_late_min = total_late_min + final_late_min;
                            total_undertime_hrs = total_undertime / 60;
                            total_undertime_min = total_undertime % 60;
                            final_undertime_hrs = total_undertime_hrs + final_undertime_hrs;
                            final_undertime_min = total_undertime_min + final_undertime_min;
                            day ++;
                            if (day == 6){
                               display_total();
                            }
                        goto time_in_again;
                        }
                    }
                }
            }
        } 
        else {
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
//main function diri na ma run aton tanan nga function nga gin ubra 
int main(){
    system("cls");
    do {
        display_description();
        timeIn_timeOut();   
        display_total();
        employee += 1;
        back:
        g(27, 23);p("ANOTHER EMPLOYEE? (y/n) ");
        g(43, 23);s("%c", &ans);
        if (ans == 'n' || ans == 'n'){
            g(2, 24);p("ARE YOU SURE YOU WANT TO EXIT? (y/n) ");
            g(25, 24);s("%c", &ans);
            if (ans == 'Y' || ans == 'y'){
                system("cls");
                exit(0);
            } else {
                g(2, 24);p("                                         ");
                goto back;
            }
        }
    } while (ans == 'Y' || ans == 'y');
    system("cls");//amo ni sya ang syntax sang clear screen sa vs code, magana lang ni sa kung may header file nga <windows.h>
    exit(0);
}
