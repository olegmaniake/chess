<?php
class ChessFigureController extends EntityAPIController{
  public function __construct($type){
    parent::__construct($type);
  }

  public function create(array $values = array()){
    global $user;
    $values += array(
      'fid' => '',
      'created' => REQUEST_TIME,
      'changed' => REQUEST_TIME,
      'cell_x' => 0,
      'cell_y' => 0,
      'uid' => $user->uid,
    );

    $chess_figure = parent::create($values);

    return $chess_figure;
  }
}

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
    );
    $items[$this->path]['description'] = 'manege chess figures.';
    $items[$this->path]['type'] = MENU_LOCAL_TASK;
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
class ChessFigureTypeUIController extends EntityDefaultUIController{
  public function hook_menu(){
    $items = parent::hook_menu();
    $items[$this->path]['description'] = 'manege chess figures types.';
    return $items;
  }
}