<?php

class ChessFigure extends Entity {
  public function __construct ($values =array()){
    parent::__construct($values, 'chess_figure');
  }

  protected function defaultLabel(){
    return $this->type;
  }

  protected function defaultUri(){
    return array('path' => 'chess/figure/'.$this->id);
  }

  public function save() {
    return parent::save();
  }
}