<?php
?>
<div class ="body">
  <?php
  $flag_color = 'black';
  for ($i=1;$i<=8;$i++){
    print '<div class ="horizontal" id ="'.$i.'">';
    for ($j=1;$j<=8;$j++){
      $flag_color == 'black' ? $flag_color = 'white' : $flag_color = 'black';
      print '<span class = "cell" id ="'.$i.$j.'" color="'.$flag_color.'"></span>';
    }
    $flag_color == 'black' ? $flag_color = 'white' : $flag_color = 'black';
    print '</div>';
  }
  ?>
</div>
