<?php
class ChessFigureTypeController extends EntityAPIControllerExportable{
  public function __construct($type){
    parent::__construct($type);
  }

  public function create(array $values = array()){
    $values += array(
      'id'=>'',
      'is_new'=>TRUE,
      'description'=>'',
    );
    $chess_type = parent::create($values);
    return $chess_type;
  }
}

