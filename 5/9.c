/* 	Rewrite the routines day_of_year and month_day with pointers instead of indexing.
	
*/

#include <stdio.h>

int day_of_year(int year, int month, int day);
int month_day(int year, int yearday, int *pmonth, int *pday);

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
	
static char month_names[13][11] =
		{"January", "February", "March", "April", "May", "June", "July", 
		"August", "September", "October", "November", "December"};

// day_of_year: set day of year from month & day_of_year
int day_of_year(int year, int month, int day)
{
	int i, leap;
	char * pdaytab = &daytab[0][0];
	if (month > 12)
		return -1;
	
	leap = 12*((year%4 == 0 && year%100 !=0) || year%400 == 0);
	
	pdaytab+=leap;
	
	if(day > *(pdaytab+month))
		return -1;
	
	for (i = 1; i < month; i++)
		day += *(pdaytab+i);
		
	return day;
}

//month_day: set month, day from day of the year
int month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;
	char * pdaytab = &daytab[0][0];
	
	leap = (year%4 == 0 && year%100!=0) || year%400 == 0;
	
	pdaytab+=leap;
	
	for (i = 1;  yearday > *(pdaytab+i); i++)
		yearday -= *(pdaytab+1);
		
	if(i > 12 || i < 0)
		return -1;
	else{
		*pmonth = i;
		*pday = yearday;
	return 0;
	}
}

int main(void)
{
	int year = 2009;
	int yearday = 315;
	int month, monthday;
	
	if (month_day(year, yearday, &month, &monthday) < 0)
		printf("Error, value out of range\n");	
	else
		printf("In %d, the %d day of the year is %s %d\n", year, yearday, month_names[month-1], monthday);
		
	month = 11;
	monthday = 11;
	
	if ((yearday = day_of_year(year, month, monthday)) < 0)
		printf("Error, value out of range\n");	
	else
		printf("%s %d, %d is the %d day of the year.\n", month_names[month-1], monthday, year, yearday);
	
}
