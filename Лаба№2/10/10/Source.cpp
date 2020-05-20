#include <stdio.h>

void main()
{
	int x, n, count;
	count = 0;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &x);
		if (x <= 45 && x >= -1)
			count++;
	}
	printf("count=%d", count);

}
