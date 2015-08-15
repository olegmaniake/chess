<?php
class ChessFigureController extends EntityAPIController{
  public function __construct($type){
    parent::__construct($type);
  }

  public function create(array $values=array()){
    global $user;
    $values += array(
      'fid' => '',
      'created' => REQUEST_TIME,
      'changed' => REQUEST_TIME,
      'cell_x' => 0,
      'cell_y' => 0,
      'uid' => $user->uid,
    );
    $chess_figure = parent:: create($values);
    return $chess_figure;
  }
}
