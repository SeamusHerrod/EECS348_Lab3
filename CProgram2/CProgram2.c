#include <stdio.h>









int main()
{
	int score;

	while (score >= 2)
	{
	printf("Enter score of NFL game: \n");
	scanf("%d", &score);

	printf("score = %d\n", score);
	
	/*possible ways to score:
	  Touchdown 6 pt.
	  Field Goal 3 pt. 
	  safety 2pt. 
	  TD + 2-pt conversion 8 pt.
	  TD + 1-pt FG 7 pt. 
	*/

	int num_TD, num_FG, num_safe, num_TD_conv, num_TD_FG, current_total;

	for ( int TD_2pt = 0; TD_2pt <= score / 8; TD_2pt++ )
	{
		current_total = score - ( TD_2pt * 8 );
		for ( int TD_1pt = 0; TD_1pt <= score / 7; TD_1pt++ )
		{
	
		}
	}


	}

	return 0;
}
