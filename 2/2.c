/*Original loop:


for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
	s[i] = c


Equivalent replacement without && or ||:
	
	i=0;
	b=1;
	while(b){
		if (i<lim-1)
			c=getchar();
			if(c == '\n')
				b=0;
			else if (c == EOF)
				b=0;
			else
				s[i] = c;
		else
			b=0;
		i++;}
*/
	
	
