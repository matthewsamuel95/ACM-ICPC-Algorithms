<?php
$arr = array(2,5,6,1,9);
function bubble_sort($arr) {
    $size = count($arr)-1;
    for ($i = 0; $i < $size; $i++) {
        for ($j = 0; $j < $size - $i; $j++) {
            $k = $j + 1;
            if ($arr[$k] < $arr[$j]) {
                // Swap elements at indices: $j, $k
                list($arr[$j], $arr[$k]) = array($arr[$k], $arr[$j]);
            }
        }
    }
    for ($i = 0; $i < $size; $i++)
        echo $arr[$i];
}
?>
