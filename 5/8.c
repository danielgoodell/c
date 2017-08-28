/* There is no error checking in da_of_year or month_day. Remedy this defect.
*/

// day_of_year: set day of year from month & day_of_year
#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
static char month_names[13][11] =
	{"January", "February", "March", "April", "May", "June", "July", 
	"August", "September", "October", "November", "December"};

int day_of_year(int year, int month, int day)
{
	int i, leap;
	
	leap = (year%4 == 0 && year%100 !=0) || year%400 == 0;
	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

//month_day: set month, day from day of the year
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;
	leap = (year%4 == 0 && year%100!=0) || year%400 == 0;
	for (i = 1;yearday > daytab[leap][i]; i++)
		yearday -=daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
}

int main(void)
{
	int year = 2009;
	int yearday = 365;
	int month, monthday;
	
	month_day(year, yearday, &month, &monthday);
	
	printf("In %d, the %d day of the year is %s %d\n", year, yearday, month_names[month-1], monthday);
}
