<?php

	function fibbonacci($x) {
		$x = $x - 1;
		$last = 0;
	  $last2 = 1;
		$result = 0;
		for ($i=1;$i<=$x;$i++) {
			$result = $last + $last2;
			$last = $last2;
			$last2 = $result;
		}
	  return $result;
	}

?>