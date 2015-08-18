<?php
class ChessFigureTypeUIController extends EntityDefaultUIController {
  public function hook_menu() {
    $items = parent::hook_menu();
    $items[$this->path]['description'] = 'Manage chess figure entity types.';
    return $items;
  }
}
