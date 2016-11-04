use strict;
use warnings;
use Data::Dumper;

my @array;
my @t1 = 1..10;
my @t2 = 11..20;
$array[0] = \@t1;
$array[1] = \@t2;
my $ref = \@array;
print Dumper($ref);

print "$ref->[0]->[1]\n";
