use strict;
use warnings;

sub printDir
{
	my $rootdir = $_[0];
	opendir my $DIRHANDLE, $rootdir or die "failed to open $rootdir";	# my $DIRHANDLE
	for my $entry (readdir $DIRHANDLE)	# readdir() can't use handle returned by open()
	{
		if ( $entry !~ /^(\.|\.\.)$/ ) 	# metacharacter precedence
		{
			my $full_path = "$rootdir/$entry"; # return just entry by readdir()
			if (-d "$full_path")
			{
				print "$full_path\n";
				printDir($full_path);# printDir $entry fail to call? call itself inside definition
			}
		}
	}
	close $DIRHANDLE;
}

die "usage:\n$0 <dir>\n" if @ARGV < 1;
my $dir = $ARGV[0];
die "error: $dir is not a directory\n" if ! -d $dir;
print "$dir\n";
printDir $dir;

__END__
1. readdir() return value has . and ..
2. readdir() returns just filename, not pathname
