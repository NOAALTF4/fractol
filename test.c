int main(void)
{
    int	i;
	int i_temp;
	int	a;
	int	b;
    int r;
    int nb;

	a = 0;
	i = 0;
    r = 0;
	i_temp = i; //juste au depart;
	if(i_temp < 0)
		i_temp -= i_temp;
    r = 2 * a * i; // r = 2
	i = (i * i) * -1; // i = -1;
	nb = (a * a) + i;
	nb = nb - 1;
    printf("nb = %d\n", nb);
    printf("r = %d\n", r);

}

// 1 + i = 1 + 2i - 1 - 1

// 1 + i =  -1 + 2i

//1er tour = -1 0
//2eme tour = 0 0
//3eme tour = -1 0