#include <ctype.h>
#include <stdio.h>

long double atof(char s[]);

//atof: convert string s to double

long double atof(char s[])
{
	long double val, power;
	int i, sign, exp, expsign;
	

	for (i = 0; isspace(s[i]); i++) //skip white space
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = (10.0 * val + s[i] - '0');
	if(s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++){
		val = (10.0 * val + s[i] - '0');
		power *= 10.0;
	}

	exp = expsign = 1;
	if (s[i] == 'e' || s[i] == 'E'){
		i++;
		expsign = (s[i] == '-') ? -1 : 1;
		if (s[i] == '+' || s[i] == '-')
			i++;
		for (exp = 0; isdigit(s[i]); i++)
			exp = (10 * exp + s[i]-'0');	
	}
	for(i=exp, exp=1;i>0; i--)
		exp *= 10;
	if(expsign > 0)
		return (sign * val / power) * exp;
	else	
		return sign * val / (power * exp);
}

int main(void)
{
	char s[] = "1234.56e-2";

	printf("Original string = %s\n", s);
	printf("After conversion to a long double = %Lf\n", atof(s));

}
