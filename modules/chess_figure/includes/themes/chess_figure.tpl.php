<?php
function theme_chess_figure_template($variable){
  $output = '<div class ="chess-figure-wrapper">';
  $output .= '<div class = "body">';
  $flag_color = 'black';
  for ($i=1;$i<=8;$i++){
    for ($j=1;$j<=8;$j++){
      $output .= '<div id ="'.$i.$j.'" color = "'.$flag_color.'"></div>';
      $flag_color == 'black' ? $flag_color = 'white' : $flag_color = 'black';
    }
  }
  $output .= '</div>';
  $output .= '</div>';

  return $output;
}