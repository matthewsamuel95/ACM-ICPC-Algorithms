# populate @array with the even integers from 0 to 198
for ( $i = 0; $i < 100; ++$i ) {
   $array[ $i ] = 2 * $i;   
}

# prompt the user for a search key
print "Enter an integer search key: ";
chomp ( $searchKey = <STDIN> );

$found = 0;   # $found is initially false

for ( $i = 0; $i < @array && !$found; ++$i ) {

   if ( $array[ $i ] == $searchKey ) {
      $index = $i;   
      $found = 1;    
   }
}

if ( $found ) {      # $found == 1
   print "Found $searchKey at subscript $index \n";
}
else {               # $found == 0
   print "$searchKey not found \n";
}
