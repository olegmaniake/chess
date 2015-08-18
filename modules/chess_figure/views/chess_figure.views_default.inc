<?php

/**
 * Implements hook_views_default_views().
 */
function chess_figure_views_default_views() {
  $views = array();

  $view = new view;
  $view->name = 'chess_figure';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'chess_figure';
  $view->human_name = 'chess_figure';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'chess_figure';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '1';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Chess Figure: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'chess_figure';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  /* Field: Chess Figure: Chess figure ID */
  $handler->display->display_options['fields']['fid']['id'] = 'fid';
  $handler->display->display_options['fields']['fid']['table'] = 'chess_figure';
  $handler->display->display_options['fields']['fid']['field'] = 'fid';
  /* Field: Chess Figure: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'chess_figure';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Chess Figure: Color */
  $handler->display->display_options['fields']['color']['id'] = 'color';
  $handler->display->display_options['fields']['color']['table'] = 'chess_figure';
  $handler->display->display_options['fields']['color']['field'] = 'color';
  /* Field: Chess Figure: Cell_x */
  $handler->display->display_options['fields']['cell_x']['id'] = 'cell_x';
  $handler->display->display_options['fields']['cell_x']['table'] = 'chess_figure';
  $handler->display->display_options['fields']['cell_x']['field'] = 'cell_x';
  /* Field: Chess Figure: Cell_y */
  $handler->display->display_options['fields']['cell_y']['id'] = 'cell_y';
  $handler->display->display_options['fields']['cell_y']['table'] = 'chess_figure';
  $handler->display->display_options['fields']['cell_y']['field'] = 'cell_y';
  /* Field: Chess Figure: Changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'chess_figure';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';

  /* Display: List */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'chess_figure';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer chess';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Chess Figure: Chess figure ID */
  $handler->display->display_options['filters']['fid']['id'] = 'fid';
  $handler->display->display_options['filters']['fid']['table'] = 'chess_figure';
  $handler->display->display_options['filters']['fid']['field'] = 'fid';
  $handler->display->display_options['filters']['fid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['fid']['expose']['operator_id'] = 'fid_op';
  $handler->display->display_options['filters']['fid']['expose']['label'] = 'Chess figure ID';
  $handler->display->display_options['filters']['fid']['expose']['operator'] = 'fid_op';
  $handler->display->display_options['filters']['fid']['expose']['identifier'] = 'fid';
  $handler->display->display_options['filters']['fid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['fid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Chess Figure: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'chess_figure';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'pawn' => 'pawn',
  );
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Chess Figure: Uid */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'chess_figure';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['value']['value'] = '1';
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Uid';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['path'] = 'admin/content/chess-figures';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Chess figures list';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;


  $views[$view->name] = $view;
  return $views;
}


