<?php
class ChessFigureTypeController extends EntityAPIControllerExportable {
  public function create(array $values = array()){
    $values += array(
      'tid' =>'',
      'is_new' => TRUE,
      'description' => '',
    );
    $chess_figure = parent::create($values);
    return $chess_figure;
  }
}
