<?php
class ChessFigureUIController extends EntityDefaultUIController {
  public function hook_menu(){
    $items = array();
    $id_count = count(explode('/', $this->path));
    $wildcard = isset($this->entityInfo['admin ui']['menu wildcard']) ? $this->entityInfo['admin ui']['menu wildcard'] : '%' . $this->entityType;

    $items[$this->path . '/add'] = array(
      'title' => 'Add a chess figure',
      'description' => 'Add a new figure',
      'page callback' => 'drupal_get_form',
      'page arguments' =>array('chess_figure_add_form'),
      'access callback' => 'chess_figure_access',
      'access argument' => array('create'),
      'type' => MENU_NORMAL_ITEM,
      'weight' => 20,
      'file' => 'includes/chess_figure.form.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module']),
    );

    $items[$this->path . '/' . $wildcard] = array(
      'page callback' => 'chess_figure_form_wrapper',
      'page arguments' => array($id_count + 1),
      'access callback' => 'chess_figure_access',
      'access argument' => array('edit', $id_count + 1),
      'weight' => 0,
      'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
      'file' => 'includes/chess_figure.form.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module']),
    );

    $items[$this->path . '/' . $wildcard . '/edit'] =array(
      'title' => 'Edit',
      'type' => MENU_DEFAULT_LOCAL_TASK,
      'weight' => -10,
      'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
    );

    $items[$this->path . '/' . $wildcard . '/delete'] = array(
      'title' => 'Delete',
      'page callback' => 'chess_figure_delete_form_wrapper',
      'page arguments' => array($id_count + 1),
      'access callback' => 'chess_figure_access',
      'access arguments' => array('edit', $id_count + 1),
      'type' => MENU_LOCAL_TASK,
      'context' => MENU_CONTEXT_INLINE,
      'wight' => 10,
      'file' => 'includes/chess_figure.form.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module']),
    );

    $items['chess_figure/' . $wildcard] = array(
      'page callback' => 'chess_figure_page_view',
      'page arguments' => array(1),
      'access callback' => 'user_is_logged_in',
      'type' => MENU_CALLBACK,
    );




    return $items;
  }


}
