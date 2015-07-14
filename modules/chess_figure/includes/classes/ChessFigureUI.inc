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

    $items[$this->path.'/add'] = array(
      'title' => 'add a figure',
      'page callback' => 'chess_figure_type_form',
      'access callback' => 'chess_figure_access',
      'access arguments' => (array('admin own chess figure')),
      'type' => MENU_NORMAL_ITEM,
      'file' => 'chess_figure_ClassController.inc',
      'file path' => drupal_get_path('chess_figure', $this->entityInfo['chess_figure']),
    );

    return $items;
  }
}
