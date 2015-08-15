<?php

function chess_figure_form_wrapper($figure) {
  chess_figure_set_breadcrumb();
  return drupal_get_form('chess_figure_edit_form', $figure);
}

function chess_figure_delete_form_wrapper($figure){
  return drupal_get_form('chess_figure_delete_form', $figure);
}

function chess_figure_edit_form($form, &$form_state, $figure) {
  $form = chess_figure_form_pattern();

  $form['figure_id'] = array(
    '#type' => 'textfield',
    '#title' => t('id of chess figure'),
    '#default_value' => $figure->fid,
    '#size' => 10,
    '#maxlength' => 10,
    '#required' => TRUE,
  );
  $form['type']['#default_value'] = $figure -> type;
  $form['color']['#default_value'] = $figure -> color;
  $form['cell_x']['#default_value'] = $figure -> cell_x;
  $form['cell_y']['#default_value'] = $figure -> cell_y;
  $form['submit']['#value'] = t('Save changes');
  $form['#submit'] = array('chess_figure_edit_form_submit');
  return $form;
}
function chess_figure_add_form($form, &$form_state) {
  $form = chess_figure_form_pattern();
  $form['type']['#default_value'] = variable_get('type','3');
  $form['color']['#default_value'] = variable_get('color','1');
  $form['cell_x']['#default_value'] = variable_get('cell_x','1');
  $form['cell_y']['#default_value'] = variable_get('cll_y','1');
  $form['submit']['#value'] = t('Create chess figure');
  $form['#submit'] = array('chess_figure_add_form_submit');

  return $form;
}

function chess_figure_add_form_submit ($form, &$form_state){
  $values = $form_state['values'];
  $figure = chess_figure_create($values);
  chess_figure_save($figure);
  $form_state['redirect'] = 'admin/content/chess-figures';
}

function chess_figure_edit_form_submit ($form, &$form_state){
  $figure = entity_ui_controller('chess_figure')->entityFormSubmitBuildEntity($form, $form_state);
  $figure->save;
  $form_state['redirect'] = 'admin/content/chess-figures' ;
}

function chess_figure_form_pattern(){
  $return = array(
    'type' => array(
      '#type' => 'select',
      '#title' => t('chess figure type'),
      '#description' => t('selection chess figure type'),
    ),
    'color' => array(
      '#type' => 'select',
      '#title' => t('color of figure'),
      '#description' => t('selection color of chess figure'),
      '#options' => array(
        'black' => t('black'),
        'white' => t('white'),
      ),
    ),
    'cell_x' => array(
      '#type' => 'select',
      '#title' => t('select numerical number cell'),
      '#description' => t('selection numerical of number cell of chess figure'),
      '#options' => array(
        1 => '1',
        2 => '2',
        3 => '3',
        4 => '4',
        5 => '5',
        6 => '6',
        7 => '7',
        8 => '8',
      ),
    ),
    'cell_y' => array('#type' => 'select',
      '#title' => t('select string number cell'),
      '#description' => t('selection string number of cell of chess figure'),
      '#options' => array(
        1 => 'A',
        2 => 'B',
        3 => 'C',
        4 => 'D',
        5 => 'E',
        6 => 'F',
        7 => 'G',
        8 => 'H',
      ),),
    'submit' =>array(
      '#type' => 'submit',
      '#waigth' => 50,
    ),
  );
  $types = chess_figure_get_types();
  foreach ($types as $type => $figure){
    $return['type']['#options'][$type] = $type;
  }
  return $return;
}

function chess_figure_delete_form ($form, &$form_state, $chess_figure) {
  $form_state['chess_figure'] = $chess_figure;

  $form['#submit'] = 'chess_figure_delete_form_submit';

  $form = confirm_form($form,
    t('Are you sure you want to delete chess figure ' . $chess_figure->fid . '?'),
    'admin/content/chess-figures/model',
    '<p>' . t('This action cannot be undone.') . '<p>',
    t('Delete'),
    t('Cancel'),
    'confirm'
    );
  return $form;
}

function chess_figure_form_submit_delete($form, &$form_state){
  $form_state['redirect'] = 'admin/content/chess-figures/chess-figure/' . $form_state['chess_figure']->fid . '/delete';
}

function chess_figure_delete_form_submit($form, &$form_state){
  $figure = $form_state['chess_figure'];
  chess_figure_delete($figure);

  drupal_set_message(t('The figure %fid has been deleted.',array('%fid' => $figure->fid)));
  watchdog('chess_figure', 'Deleted figure $fid', array('%fid' => $figure->fid));

  $form_state['redirect'] = 'admin/content/chess-figures';
}
