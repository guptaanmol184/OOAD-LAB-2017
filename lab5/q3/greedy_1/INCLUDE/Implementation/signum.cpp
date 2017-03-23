/*Calculate signum or sign of an number
INTPUT: An INTEGER
RETURN: num > 0 : 1
		num = 0 : 0
		num < 0 : -1*/
int signum(int a)
{
	int sign=0;

	if(a>0)
		sign=1;

	else if(a<0)
		sign=-1;

	return sign;
}

/*Calculate signum or sign of an FLOATING number
INTPUT: An INTEGER
RETURN: num > 0 : 1
		num = 0 : 0
		num < 0 : -1*/
int signum(float a)
{
	int sign=0;

	if(a>0.0)
		sign=1;

	else if(a<0.0)
		sign=-1;

	return sign;
}
