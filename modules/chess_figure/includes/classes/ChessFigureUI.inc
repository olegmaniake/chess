<?php
class ChessFigureUIController extends EntityDefaultUIController{
  public function hook_menu(){
    $items = parent::hook_menu();

    $items[$this->path] = array(
      'title' => 'Chess figure',
      'description' => 'manege chess figures',
      'page callback' => 'system_admin_menu_block_page',
      'access arguments' => (array('administer chess figure')),
      'file path' => drupal_get_path('module', 'system'),
      'file' => 'system.admin.inc',
      'type' =>MENU_LOCAL_TASK,
    );
    return $items;
  }
}
