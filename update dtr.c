#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#define g gotoxy
#define p printf

// Initialization
int emp = 1, day = 5, des = 1, twh = 0, tl = 0, tu = 0, d;
int undertime_hrs, undertime_min, late_in_hrs, late_in_min, undertime_in_hrs, undertime_in_min;
int late, late_hours, late_min, undertime, hrs_work, hrs_work_hrs, hrs_work_min, ti, to;
int time_out_hrs, time_out_min, time_in_hrs, time_in_min, start;
int total_late = 0, grand_total_work_hrs = 0, grand_total_work_min = 0;
int ttl_work_hrs = 0, ttl_work_min = 0, ttl_late_hrs, ttl_late_min = 0, ttl_undertime_hrs = 0;
int ttl_undertime_min = 0, weekly_salary = 0, total_hrswork = 0;
int day_ti[5] = {1, 2, 3, 4, 5};
int total_hrs_work = 0, total_hrs_work_hrs, total_hrs_work_min;
int total_late_hrs, total_late_min;
int total_undertime = 0, total_undertime_hrs, total_undertime_min;
int final_hrs_work_hrs = 0, final_hrs_work_min = 0, final_late_hrs = 0, final_late_min = 0, final_undertime_hrs = 0, final_undertime_min = 0;
int final_hrs_work = 0;
char ans[5];
// gotoxy for structural purpose
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x - 1; // Adjust for zero-based indexing
    coord.Y = y - 1; // Adjust for zero-based indexing
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
// New issue can't display consecutive absences
// we need new versatile condition that is applicable for both function of time in and time out.
// we need to add another variable, variable for day 1 that stores the value of time in each day day1_ti, day2_ti etc...
// we need to add a new description for total of am in, am out, late, undertime
// total hrs work aswell, and another employee
// Issues: negative -30 (FIXED)
/*void calc(){

}*/

void display()
{
    g(11, 14);
    p("0:0");
    g(21, 14);
    p("0:0");
    g(31, 14);
    p("0:0");
    g(51, 14);
    p("0:0");
}

/*void day_display()
{
    for(d = 1; d < 6; d++){
        g(2, 14+d); p("day 1");
    }
}*/

void display_total()
{
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
}

void display_description()
{
    g(25, 8);
    p("EMPLOYEE:");
    g(35, 8);
    p("%d", emp);
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

void timein()
{
    int d = 0;
    display_description();
loop:
    for (day = 1; day < 6; day++)
    {
        g(2, 13+day); p("day %d", day);
    time_in_again:
        g(2, 5);
        printf("Time in: \n");
        g(15, 5);
        printf(":");
        g(21, 5);
        printf("\n");
        g(2, 6);
        printf("Time out:\n");
        g(15, 6);
        printf(":");
        g(14, 6);
        printf("\n");
        g(13, 5);
        scanf("%d", &time_in_hrs);
        g(16, 5);
        scanf("%d", &time_in_min);
        ti = time_in_hrs * 60 + time_in_min;
        if (ti > 570 && ti < 721)
        {
            total_late = total_late + 240;
            if (day == 1)
            {
                g(10, 13);
                p("AM IN");
                g(11, 14);
                p("0:0");
                g(20, 13);
                p("AM OUT");
                g(21, 14);
                p("0:0");
                g(30, 13);
                p("HRS WORK");
                g(31, 14);
                p("0:0");
                g(40, 13);
                p("LATES");
                g(41, 14);
                p("4:0");
                g(50, 13);
                p("UNDERTIME");
                g(51, 14);
                p("0:0");
                g(13, 5);
                printf("  ");
                g(16, 5);
                printf("  ");
                g(13, 6);
                printf("  ");
                g(16, 6);
                printf("  ");
                day++;
                goto time_in_again;
            }
            if (day == 2)
            {
                g(10, 13);
                p("AM IN");
                g(11, 15);
                p("0:0");
                g(20, 13);
                p("AM OUT");
                g(21, 15);
                p("0:0");
                g(30, 13);
                p("HRS WORK");
                g(31, 15);
                p("0:0");
                g(40, 13);
                p("LATES");
                g(41, 15);
                p("4:0");
                g(50, 13);
                p("UNDERTIME");
                g(51, 15);
                p("0:0");
                g(13, 5);
                printf("  ");
                g(16, 5);
                printf("  ");
                g(13, 6);
                printf("  ");
                g(16, 6);
                printf("  ");
                day++;
                goto time_in_again;
            }
            if (day == 3)
            {
                g(10, 13);
                p("AM IN");
                g(11, 16);
                p("0:0");
                g(20, 13);
                p("AM OUT");
                g(21, 16);
                p("0:0");
                g(30, 13);
                p("HRS WORK");
                g(31, 16);
                p("0:0");
                g(40, 13);
                p("LATES");
                g(41, 16);
                p("4:0");
                g(50, 13);
                p("UNDERTIME");
                g(51, 16);
                p("0:0");
                g(13, 5);
                printf("  ");
                g(16, 5);
                printf("  ");
                g(13, 6);
                printf("  ");
                g(16, 6);
                printf("  ");
                day++;
                goto time_in_again;
            }
            if (day == 4)
            {
                g(10, 13);
                p("AM IN");
                g(11, 17);
                p("0:0");
                g(20, 13);
                p("AM OUT");
                g(21, 17);
                p("0:0");
                g(30, 13);
                p("HRS WORK");
                g(31, 17);
                p("0:0");
                g(40, 13);
                p("LATES");
                g(41, 17);
                p("4:0");
                g(50, 13);
                p("UNDERTIME");
                g(51, 17);
                p("0:0");
                g(13, 5);
                printf("  ");
                g(16, 5);
                printf("  ");
                g(13, 6);
                printf("  ");
                g(16, 6);
                printf("  ");
                day++;
                goto time_in_again;
            }
            if (day == 5)
            {
                g(10, 13);
                p("AM IN");
                g(11, 18);
                p("0:0");
                g(20, 13);
                p("AM OUT");
                g(21, 18);
                p("0:0");
                g(30, 13);
                p("HRS WORK");
                g(31, 18);
                p("0:0");
                g(40, 13);
                p("LATES");
                g(41, 18);
                p("4:0");
                g(50, 13);
                p("UNDERTIME");
                g(51, 18);
                p("0:0");
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
                display_total();
            }
        }
        // case scenario with no late
        g(13, 6);
        scanf("%d", &time_out_hrs);
        g(16, 6);
        scanf("%d", &time_out_min);
        to = time_out_hrs * 60 + time_out_min;
        if (ti > 299 && ti < 721 && to > 569 && to < 721)
        { // Sentinel Data: input must be 5-12 in time-in and time-out
            if (ti > 299 && ti < 451){
                if (to > 689 && to < 721){
                late = 0;
                undertime = 0;
                undertime_in_hrs = undertime / 60;
                undertime_in_min = undertime % 60;
                late_in_hrs = late / 60;
                late_in_min = late % 60;
                hrs_work = 240;
                hrs_work_hrs = hrs_work / 60;
                hrs_work_min = hrs_work % 60;
                total_hrs_work = total_hrs_work + hrs_work;    // in minutes form
                total_late = total_late + late;                // in minutes form
                total_undertime = total_undertime + undertime; // in minutes form
                final_hrs_work = total_late + final_hrs_work;
                if (day == 1)
                {
                    g(10, 14);
                    p("%d", time_in_hrs);
                    g(11, 14);
                    p(":");
                    g(12, 14);
                    p("%d", time_in_min);
                    g(20, 14);
                    p("%d", time_out_hrs);
                    g(22, 14);
                    p(":");
                    g(23, 14);
                    p("%d", time_out_min);
                    g(31, 14);
                    p("%d", hrs_work_hrs);
                    g(32, 14);
                    p(":");
                    g(33, 14);
                    p("%d", hrs_work_min);
                    g(41, 14);
                    p("%d", late_in_hrs);
                    g(42, 14);
                    p(":");
                    g(43, 14);
                    p("%d", late_in_min);
                    g(51, 14);
                    p("%d", undertime_in_hrs);
                    g(52, 14);
                    p(":");
                    g(53, 14);
                    p("%d", undertime_in_min);
                    printf("  ");
                    g(16, 5);
                    printf("  ");
                    g(13, 6);
                    printf("  ");
                    g(16, 6);
                    printf("  ");
                }
                if (day == 2)
                {
                    g(10, 15);
                    p("%d", time_in_hrs);
                    g(11, 15);
                    p(":");
                    g(12, 15);
                    p("%d", time_in_min);
                    g(20, 15);
                    p("%d", time_out_hrs);
                    g(22, 15);
                    p(":");
                    g(23, 15);
                    p("%d", time_out_min);
                    g(31, 15);
                    p("4");
                    g(32, 15);
                    p(":");
                    g(33, 15);
                    p("0");
                    g(41, 15);
                    p("%d", late_in_hrs);
                    g(42, 15);
                    p(":");
                    g(43, 15);
                    p("%d", late_in_min);
                    g(51, 15);
                    p("%d", undertime_in_hrs);
                    g(52, 15);
                    p(":");
                    g(53, 15);
                    p("%d", undertime_in_min);
                    printf("  ");
                    g(16, 5);
                    printf("  ");
                    g(13, 6);
                    printf("  ");
                    g(16, 6);
                    printf("  ");
                }
                if (day == 3)
                {
                    g(10, 16);
                    p("%d", time_in_hrs);
                    g(11, 16);
                    p(":");
                    g(12, 16);
                    p("%d", time_in_min);
                    g(20, 16);
                    p("%d", time_out_hrs);
                    g(22, 16);
                    p(":");
                    g(23, 16);
                    p("%d", time_out_min);
                    g(31, 16);
                    p("4");
                    g(32, 16);
                    p(":");
                    g(33, 16);
                    p("0");
                    g(41, 16);
                    p("%d", late_in_hrs);
                    g(42, 16);
                    p(":");
                    g(43, 16);
                    p("%d", late_in_min);
                    g(51, 16);
                    p("%d", undertime_in_hrs);
                    g(52, 16);
                    p(":");
                    g(53, 16);
                    p("%d", undertime_in_min);
                    printf("  ");
                    g(16, 5);
                    printf("  ");
                    g(13, 6);
                    printf("  ");
                    g(16, 6);
                    printf("  ");
                }
                if (day == 4)
                {
                    g(10, 17);
                    p("%d", time_in_hrs);
                    g(11, 17);
                    p(":");
                    g(12, 17);
                    p("%d", time_in_min);
                    g(20, 17);
                    p("%d", time_out_hrs);
                    g(22, 17);
                    p(":");
                    g(23, 17);
                    p("%d", time_out_min);
                    g(31, 17);
                    p("4");
                    g(32, 17);
                    p(":");
                    g(33, 17);
                    p("0");
                    g(41, 17);
                    p("%d", late_in_hrs);
                    g(42, 17);
                    p(":");
                    g(43, 17);
                    p("%d", late_in_min);
                    g(51, 17);
                    p("%d", undertime_in_hrs);
                    g(52, 17);
                    p(":");
                    g(53, 17);
                    p("%d", undertime_in_min);
                    printf("  ");
                    g(16, 5);
                    printf("  ");
                    g(13, 6);
                    printf("  ");
                    g(16, 6);
                    printf("  ");
                }
                if (day == 5)
                {
                    g(10, 18);
                    p("%d", time_in_hrs);
                    g(11, 18);
                    p(":");
                    g(12, 18);
                    p("%d", time_in_min);
                    g(20, 18);
                    p("%d", time_out_hrs);
                    g(22, 18);
                    p(":");
                    g(23, 18);
                    p("%d", time_out_min);
                    g(31, 18);
                    p("4");
                    g(32, 18);
                    p(":");
                    g(33, 18);
                    p("0");
                    g(41, 18);
                    p("%d", late_in_hrs);
                    g(42, 18);
                    p(":");
                    g(43, 18);
                    p("%d", late_in_min);
                    g(51, 18);
                    p("%d", undertime_in_hrs);
                    g(52, 18);
                    p(":");
                    g(53, 18);
                    p("%d", undertime_in_min);
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
                    display_total();
                 }
                }
                //if there's undertime
                else if (to > 570 && to < 721)
                {
                late = 0;
                late_in_hrs = late / 60;
                late_in_min = late % 60;
                //
                undertime = 690 - to;
                undertime_in_hrs = undertime / 60;
                undertime_in_min = undertime % 60;
                //
                hrs_work = 240 - undertime;
                hrs_work_hrs = hrs_work / 60;
                hrs_work_min = hrs_work % 60;
                //
                total_hrs_work = total_hrs_work + hrs_work;    // in minutes form
                total_late = total_late + late;                // in minutes form
                total_undertime = total_undertime + undertime; // in minutes form
                final_hrs_work = total_late + final_hrs_work;
                if (day == 1)
                {
                    g(10, 14);
                    p("%d", time_in_hrs);
                    g(11, 14);
                    p(":");
                    g(12, 14);
                    p("%d", time_in_min);
                    g(20, 14);
                    p("%d", time_out_hrs);
                    g(22, 14);
                    p(":");
                    g(23, 14);
                    p("%d", time_out_min);
                    g(31, 14);
                    p("%d", hrs_work_hrs);
                    g(32, 14);
                    p(":");
                    g(33, 14);
                    p("%d", hrs_work_min);
                    g(41, 14);
                    p("%d", late_in_hrs);
                    g(42, 14);
                    p(":");
                    g(43, 14);
                    p("%d", late_in_min);
                    g(51, 14);
                    p("%d", undertime_in_hrs);
                    g(52, 14);
                    p(":");
                    g(53, 14);
                    p("%d", undertime_in_min);
                    g(13, 5);
                    printf("  ");
                    g(16, 5);
                    printf("  ");
                    g(13, 6);
                    printf("  ");
                    g(16, 6);
                    printf("  ");  
                }
                else if (day == 2)
                {
                    g(10, 15);
                    p("%d", time_in_hrs);
                    g(11, 15);
                    p(":");
                    g(12, 15);
                    p("%d", time_in_min);
                    g(20, 15);
                    p("%d", time_out_hrs);
                    g(22, 15);
                    p(":");
                    g(23, 15);
                    p("%d", time_out_min);
                    g(31, 15);
                    p("%d", hrs_work_hrs);
                    g(32, 15);
                    p(":");
                    g(33, 15);
                    p("%d", hrs_work_min);
                    g(41, 15);
                    p("%d", late_in_hrs);
                    g(42, 15);
                    p(":");
                    g(43, 15);
                    p("%d", late_in_min);
                    g(51, 15);
                    p("%d", undertime_in_hrs);
                    g(52, 15);
                    p(":");
                    g(53, 15);
                    p("%d", undertime_in_min);
                    g(13, 5);
                    printf("  ");
                    g(16, 5);
                    printf("  ");
                    g(13, 6);
                    printf("  ");
                    g(16, 6);
                    printf("  ");
                }
                else if (day == 3)
                {
                    g(10, 16);
                    p("%d", time_in_hrs);
                    g(11, 16);
                    p(":");
                    g(12, 16);
                    p("%d", time_in_min);
                    g(20, 16);
                    p("%d", time_out_hrs);
                    g(22, 16);
                    p(":");
                    g(23, 16);
                    p("%d", time_out_min);
                    g(31, 16);
                    p("%d", hrs_work_hrs);
                    g(32, 16);
                    p(":");
                    g(33, 16);
                    p("%d", hrs_work_min);
                    g(41, 16);
                    p("%d", late_in_hrs);
                    g(42, 16);
                    p(":");
                    g(43, 16);
                    p("%d", late_in_min);
                    g(51, 16);
                    p("%d", undertime_in_hrs);
                    g(52, 16);
                    p(":");
                    g(53, 16);
                    p("%d", undertime_in_min);
                    g(13, 5);
                    printf("  ");
                    g(16, 5);
                    printf("  ");
                    g(13, 6);
                    printf("  ");
                    g(16, 6);
                    printf("  ");
                }
                else if (day == 4)
                {
                    g(10, 17);
                    p("%d", time_in_hrs);
                    g(11, 17);
                    p(":");
                    g(12, 17);
                    p("%d", time_in_min);
                    g(20, 17);
                    p("%d", time_out_hrs);
                    g(22, 17);
                    p(":");
                    g(23, 17);
                    p("%d", time_out_min);
                    g(31, 17);
                    p("%d", hrs_work_hrs);
                    g(32, 17);
                    p(":");
                    g(33, 17);
                    p("%d", hrs_work_min);
                    g(41, 17);
                    p("%d", late_in_hrs);
                    g(42, 17);
                    p(":");
                    g(43, 17);
                    p("%d", late_in_min);
                    g(51, 17);
                    p("%d", undertime_in_hrs);
                    g(52, 17);
                    p(":");
                    g(53, 17);
                    p("%d", undertime_in_min);
                    g(13, 5);
                    printf("  ");
                    g(16, 5);
                    printf("  ");
                    g(13, 6);
                    printf("  ");
                    g(16, 6);
                    printf("  ");
                }
                else if (day == 5)
                {
                    g(10, 15);
                    p("%d", time_in_hrs);
                    g(11, 18);
                    p(":");
                    g(12, 18);
                    p("%d", time_in_min);
                    g(20, 18);
                    p("%d", time_out_hrs);
                    g(22, 18);
                    p(":");
                    g(23, 18);
                    p("%d", time_out_min);
                    g(31, 18);
                    p("%d", hrs_work_hrs);
                    g(32, 18);
                    p(":");
                    g(33, 18);
                    p("%d", hrs_work_min);
                    g(41, 18);
                    p("%d", late_in_hrs);
                    g(42, 18);
                    p(":");
                    g(43, 18);
                    p("%d", late_in_min);
                    g(51, 18);
                    p("%d", undertime_in_hrs);
                    g(52, 18);
                    p(":");
                    g(53, 18);
                    p("%d", undertime_in_min);
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
                    display_total();
                    }
                }
                else {
                    g(2, 8);
                    p("INVALID INPUT");
                    g(13, 5);
                    printf("  ");
                    g(16, 5);
                    printf("  ");
                    g(13, 6);
                    printf("  ");
                    g(16, 6);
                    printf("  ");
                    goto time_in_again;
                }
            }        
            if (ti > 450 && ti < 571)
            {
                if (to > 570 && to < 721)
                {
                late = ti - 240;
                late_in_hrs = late / 60;
                late_in_min = late % 60;
                //
                undertime = 690 - to;
                undertime_in_hrs = undertime / 60;
                undertime_in_min = undertime % 60;
                //
                hrs_work = undertime - late - 240;
                hrs_work_hrs = hrs_work / 60;
                hrs_work_min = hrs_work % 60;
                //
                total_hrs_work = total_hrs_work + hrs_work;    // in minutes form
                total_late = total_late + late;                // in minutes form
                total_undertime = total_undertime + undertime; // in minutes form
                final_hrs_work = total_late + final_hrs_work;
                if (day == 1)
                {
                    g(10, 14);
                    p("%d", time_in_hrs);
                    g(11, 14);
                    p(":");
                    g(12, 14);
                    p("%d", time_in_min);
                    g(20, 14);
                    p("%d", time_out_hrs);
                    g(22, 14);
                    p(":");
                    g(23, 14);
                    p("%d", time_out_min);
                    g(31, 14);
                    p("%d", hrs_work_hrs);
                    g(32, 14);
                    p(":");
                    g(33, 14);
                    p("%d", hrs_work_min);
                    g(41, 14);
                    p("%d", late_in_hrs);
                    g(42, 14);
                    p(":");
                    g(43, 14);
                    p("%d", late_in_min);
                    g(51, 14);
                    p("%d", undertime_in_hrs);
                    g(52, 14);
                    p(":");
                    g(53, 14);
                    p("%d", undertime_in_min);
                    g(13, 5);
                    printf("  ");
                    g(16, 5);
                    printf("  ");
                    g(13, 6);
                    printf("  ");
                    g(16, 6);
                    printf("  ");
                }
                else if (day == 2)
                {
                    g(10, 15);
                    p("%d", time_in_hrs);
                    g(11, 15);
                    p(":");
                    g(12, 15);
                    p("%d", time_in_min);
                    g(20, 15);
                    p("%d", time_out_hrs);
                    g(22, 15);
                    p(":");
                    g(23, 15);
                    p("%d", time_out_min);
                    g(31, 15);
                    p("%d", hrs_work_hrs);
                    g(32, 15);
                    p(":");
                    g(33, 15);
                    p("%d", hrs_work_min);
                    g(41, 15);
                    p("%d", late_in_hrs);
                    g(42, 15);
                    p(":");
                    g(43, 15);
                    p("%d", late_in_min);
                    g(51, 15);
                    p("%d", undertime_in_hrs);
                    g(52, 15);
                    p(":");
                    g(53, 15);
                    p("%d", undertime_in_min);
                    g(13, 5);
                    printf("  ");
                    g(16, 5);
                    printf("  ");
                    g(13, 6);
                    printf("  ");
                    g(16, 6);
                    printf("  ");
                }
                else if (day == 3)
                {
                    g(10, 16);
                    p("%d", time_in_hrs);
                    g(11, 16);
                    p(":");
                    g(12, 16);
                    p("%d", time_in_min);
                    g(20, 16);
                    p("%d", time_out_hrs);
                    g(22, 16);
                    p(":");
                    g(23, 16);
                    p("%d", time_out_min);
                    g(31, 16);
                    p("%d", hrs_work_hrs);
                    g(32, 16);
                    p(":");
                    g(33, 16);
                    p("%d", hrs_work_min);
                    g(41, 16);
                    p("%d", late_in_hrs);
                    g(42, 16);
                    p(":");
                    g(43, 16);
                    p("%d", late_in_min);
                    g(51, 16);
                    p("%d", undertime_in_hrs);
                    g(52, 16);
                    p(":");
                    g(53, 16);
                    p("%d", undertime_in_min);
                    g(13, 5);
                    printf("  ");
                    g(16, 5);
                    printf("  ");
                    g(13, 6);
                    printf("  ");
                    g(16, 6);
                    printf("  ");
                }
                else if (day == 4)
                {
                    g(10, 17);
                    p("%d", time_in_hrs);
                    g(11, 17);
                    p(":");
                    g(12, 17);
                    p("%d", time_in_min);
                    g(20, 17);
                    p("%d", time_out_hrs);
                    g(22, 17);
                    p(":");
                    g(23, 17);
                    p("%d", time_out_min);
                    g(31, 17);
                    p("%d", hrs_work_hrs);
                    g(32, 17);
                    p(":");
                    g(33, 17);
                    p("%d", hrs_work_min);
                    g(41, 17);
                    p("%d", late_in_hrs);
                    g(42, 17);
                    p(":");
                    g(43, 17);
                    p("%d", late_in_min);
                    g(51, 17);
                    p("%d", undertime_in_hrs);
                    g(52, 17);
                    p(":");
                    g(53, 17);
                    p("%d", undertime_in_min);
                    g(13, 5);
                    printf("  ");
                    g(16, 5);
                    printf("  ");
                    g(13, 6);
                    printf("  ");
                    g(16, 6);
                    printf("  ");
                }
                else if (day == 5)
                {
                    g(10, 15);
                    p("%d", time_in_hrs);
                    g(11, 18);
                    p(":");
                    g(12, 18);
                    p("%d", time_in_min);
                    g(20, 18);
                    p("%d", time_out_hrs);
                    g(22, 18);
                    p(":");
                    g(23, 18);
                    p("%d", time_out_min);
                    g(31, 18);
                    p("%d", hrs_work_hrs);
                    g(32, 18);
                    p(":");
                    g(33, 18);
                    p("%d", hrs_work_min);
                    g(41, 18);
                    p("%d", late_in_hrs);
                    g(42, 18);
                    p(":");
                    g(43, 18);
                    p("%d", late_in_min);
                    g(51, 18);
                    p("%d", undertime_in_hrs);
                    g(52, 18);
                    p(":");
                    g(53, 18);
                    p("%d", undertime_in_min);
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
                    display_total();
                }
                }
            }
            if (ti > 450 && ti < 571)
            {
                if (to > 689 && to < 721)
                {
                late = ti - 240;
                late_in_hrs = late / 60;
                late_in_min = late % 60;
                //
                undertime = 0;
                undertime_in_hrs = undertime / 60;
                undertime_in_min = undertime % 60;
                //
                hrs_work = 240 - late - undertime;
                hrs_work_hrs = hrs_work / 60;
                hrs_work_min = hrs_work % 60;
                //
                total_hrs_work = total_hrs_work + hrs_work;    // in minutes form
                total_late = total_late + late;                // in minutes form
                total_undertime = total_undertime + undertime; // in minutes form
                final_hrs_work = total_late + final_hrs_work;
                if (day == 1)
                {
                    g(10, 14);
                    p("%d", time_in_hrs);
                    g(11, 14);
                    p(":");
                    g(12, 14);
                    p("%d", time_in_min);
                    g(20, 14);
                    p("%d", time_out_hrs);
                    g(22, 14);
                    p(":");
                    g(23, 14);
                    p("%d", time_out_min);
                    g(31, 14);
                    p("%d", hrs_work_hrs);
                    g(32, 14);
                    p(":");
                    g(33, 14);
                    p("%d", hrs_work_min);
                    g(41, 14);
                    p("%d", late_in_hrs);
                    g(42, 14);
                    p(":");
                    g(43, 14);
                    p("%d", late_in_min);
                    g(51, 14);
                    p("%d", undertime_in_hrs);
                    g(52, 14);
                    p(":");
                    g(53, 14);
                    p("%d", undertime_in_min);
                    g(13, 5);
                    printf("  ");
                    g(16, 5);
                    printf("  ");
                    g(13, 6);
                    printf("  ");
                    g(16, 6);
                    printf("  ");
                }
                else if (day == 2)
                {
                    g(10, 15);
                    p("%d", time_in_hrs);
                    g(11, 15);
                    p(":");
                    g(12, 15);
                    p("%d", time_in_min);
                    g(20, 15);
                    p("%d", time_out_hrs);
                    g(22, 15);
                    p(":");
                    g(23, 15);
                    p("%d", time_out_min);
                    g(31, 15);
                    p("%d", hrs_work_hrs);
                    g(32, 15);
                    p(":");
                    g(33, 15);
                    p("%d", hrs_work_min);
                    g(41, 15);
                    p("%d", late_in_hrs);
                    g(42, 15);
                    p(":");
                    g(43, 15);
                    p("%d", late_in_min);
                    g(51, 15);
                    p("%d", undertime_in_hrs);
                    g(52, 15);
                    p(":");
                    g(53, 15);
                    p("%d", undertime_in_min);
                    g(13, 5);
                    printf("  ");
                    g(16, 5);
                    printf("  ");
                    g(13, 6);
                    printf("  ");
                    g(16, 6);
                    printf("  ");
                }
                else if (day == 3)
                {
                    g(10, 16);
                    p("%d", time_in_hrs);
                    g(11, 16);
                    p(":");
                    g(12, 16);
                    p("%d", time_in_min);
                    g(20, 16);
                    p("%d", time_out_hrs);
                    g(22, 16);
                    p(":");
                    g(23, 16);
                    p("%d", time_out_min);
                    g(31, 16);
                    p("%d", hrs_work_hrs);
                    g(32, 16);
                    p(":");
                    g(33, 16);
                    p("%d", hrs_work_min);
                    g(41, 16);
                    p("%d", late_in_hrs);
                    g(42, 16);
                    p(":");
                    g(43, 16);
                    p("%d", late_in_min);
                    g(51, 16);
                    p("%d", undertime_in_hrs);
                    g(52, 16);
                    p(":");
                    g(53, 16);
                    p("%d", undertime_in_min);
                    g(13, 5);
                    printf("  ");
                    g(16, 5);
                    printf("  ");
                    g(13, 6);
                    printf("  ");
                    g(16, 6);
                    printf("  ");
                }
                else if (day == 4)
                {
                    g(10, 17);
                    p("%d", time_in_hrs);
                    g(11, 17);
                    p(":");
                    g(12, 17);
                    p("%d", time_in_min);
                    g(20, 17);
                    p("%d", time_out_hrs);
                    g(22, 17);
                    p(":");
                    g(23, 17);
                    p("%d", time_out_min);
                    g(31, 17);
                    p("%d", hrs_work_hrs);
                    g(32, 17);
                    p(":");
                    g(33, 17);
                    p("%d", hrs_work_min);
                    g(41, 17);
                    p("%d", late_in_hrs);
                    g(42, 17);
                    p(":");
                    g(43, 17);
                    p("%d", late_in_min);
                    g(51, 17);
                    p("%d", undertime_in_hrs);
                    g(52, 17);
                    p(":");
                    g(53, 17);
                    p("%d", undertime_in_min);
                    g(13, 5);
                    printf("  ");
                    g(16, 5);
                    printf("  ");
                    g(13, 6);
                    printf("  ");
                    g(16, 6);
                    printf("  ");
                }
                else if (day == 5)
                {
                    g(10, 15);
                    p("%d", time_in_hrs);
                    g(11, 18);
                    p(":");
                    g(12, 18);
                    p("%d", time_in_min);
                    g(20, 18);
                    p("%d", time_out_hrs);
                    g(22, 18);
                    p(":");
                    g(23, 18);
                    p("%d", time_out_min);
                    g(31, 18);
                    p("%d", hrs_work_hrs);
                    g(32, 18);
                    p(":");
                    g(33, 18);
                    p("%d", hrs_work_min);
                    g(41, 18);
                    p("%d", late_in_hrs);
                    g(42, 18);
                    p(":");
                    g(43, 18);
                    p("%d", late_in_min);
                    g(51, 18);
                    p("%d", undertime_in_hrs);
                    g(52, 18);
                    p(":");
                    g(53, 18);
                    p("%d", undertime_in_min);
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
                    display_total();
                }
                }
                
            }
            /*else {
                g(2, 8);
                p("INVALID INPUT");
                g(13, 5);
                printf("  ");
                g(16, 5);
                printf("  ");
                g(13, 6);
                printf("  ");
                g(16, 6);
                printf("  ");
                goto time_in_again;
            }*/
        }
        else
        {
            g(2, 8);
            p("INVALID INPUT");
            g(13, 5);
            printf("  ");
            g(16, 5);
            printf("  ");
            g(13, 6);
            printf("  ");
            g(16, 6);
            printf("  ");
            goto time_in_again;
        }
    }
}

int main()
{
    system("cls");
    timein();
    display_total();
}
