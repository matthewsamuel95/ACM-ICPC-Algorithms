my @array = ( 5, 6, 3, 1, 7, 3, 2, 9, 10, 4 );

for my $x ( reverse 1 .. $#array ) {
    for my $y ( 0 .. $x - 1 ) {
        @array[ $y, $y + 1 ] = @array[ $y + 1, $y ]
            if $array[$y] > $array[ $y + 1 ];
    }
}

print "@array\n";