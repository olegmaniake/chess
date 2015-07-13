<?php
function chess_new_figure_form(){
  $form['chess_figure'] = array(
    '#type' => 'select',
    '#title' => t('chess figure'),
    '#default_value' => variable_get('chess_figure','3'),
    '#description'=> t('selection chess figure'),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#weigth' => 50,
    '#value' => t('Create new game'),
  );
  $form['#submit'] = array('chess_new_figure_form_submit');

  $types = chess_figure_get_types();
  foreach ($types as $type){
    $form['chess_figure']['#options'][$type] -> $type;
  }
  return $form;
}

function chess_new_figure_form_submit($form,&$form_state){
  $values = array(
    'type' => $form_state['values']['chess_figure'],
    'color'=> 'black',
    'cell_x' => 1,
    'cell_y' => 1,
  );
  $figure = entity_get_controller('chess_figure')->create($values);
  $figure->save();
  $form_state['redirect'] = 'chess/game';


}