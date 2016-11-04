use strict;
use warnings;
use Data::Dumper;

my @nums = -10..10;
my @array;
for (1..10)
{
	my $index = int(rand($#nums+1));
	push @array, $nums[$index];
}
print "@array\n";

sub merge
{
	my @array = @_;
	my $ref;
	my $i = 0;
	my $j = 0;
	push @{$ref->[$j]}, $i;
	while ($i<$#array)
	{
		if($array[$i] * $array[++$i] > 0)
		{			
			push @{$ref->[$j]}, $i;
		}
		else
		{
			push @{$ref->[++$j]}, $i;
		}
	}
	return $ref;
}


my $ref = &merge(@array);
print Dumper($ref);

