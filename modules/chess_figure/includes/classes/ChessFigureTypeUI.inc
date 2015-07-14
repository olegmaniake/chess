<?php
class ChessFigureTypeUIController extends EntityDefaultUIController{
  public function hook_menu(){
    $items = parent::hook_menu();

    $items[$this->path]['description'] = 'manege chess figures types.';
    return $items;
  }
}
