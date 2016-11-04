use strict;
use warnings;

for (1..100)
{
	if (0 == $_ % 15)
	{
		print "FizzBuzz\n";
	}
	elsif ( 0 == $_ % 5 )
	{
		print "$_ 5izz\n";
	}
	elsif ( 0 == $_ % 3 )
	{
		print "$_ 3izz\n";
	}
	else
	{
		print "$_\n";
	}
}
