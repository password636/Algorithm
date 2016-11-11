use strict;
use warnings;

open FH, $ARGV[0] or die "Failed to open $ARGV[0]\n";
open FH2, $ARGV[1] or die "Failed to open $ARGV[1]\n";

my @lines = <FH2>;
while (<FH>)
{
	my $line = $_;
	if (grep $_ eq $line, @lines)
	#if (grep $_ eq $line, <FH2>)	# 
	{
		print;
	}
}

close FH;
close FH2;
