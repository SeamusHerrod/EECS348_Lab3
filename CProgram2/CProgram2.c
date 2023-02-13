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

	for ( int TD_2pt = 0; TD_2pt <= score / 8; TD_2pt++ )
	{
		int num_TD_conv = score;
		num_TD_conv -= ( TD_2pt * 8 );

		for ( int TD_1pt = 0; TD_1pt <= num_TD_conv / 7; TD_1pt++ )
		{
			int num_TD_FG = num_TD_conv - ( TD_1pt * 7 ); 

			for ( int td = 0; td <= num_TD_FG / 6; td++ )
			{
				int num_TD = num_TD_FG - ( td * 6 );

				for ( int fg = 0; fg <= num_TD / 3; fg++ )
				{
					int num_FG = num_TD - ( fg * 3 );
					if ( num_FG % 2 == 0 )
					{
						for ( int safe = 0; safe <= num_FG / 2; safe++ )
						{
						
							int num_safe = num_FG - ( safe * 2 );
							int total = TD_2pt*8 + TD_1pt*7 + td*6 + fg*3 + safe*2;
							if ( total == score )
							{
								printf("TD_2pt = %d, TD_1pt = %d, TD = %d, FG = %d, safety = %d\n", TD_2pt, TD_1pt, td, fg, safe);
							}
						}
					}
				}
			}
		}

	}


	}

	return 0;
}
