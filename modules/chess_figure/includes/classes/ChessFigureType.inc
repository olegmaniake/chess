<?php
class ChessFigureType extends Entity{
  public $type;
  public $label;

  public function __construct($values = array()){
    parent::__construct($values,'chess_figure_type')  ;
  }

  protected function defaultUri(){
    return array('path' => 'chess/figure/type'.$this->type);
  }
}
